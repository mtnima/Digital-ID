package com.digitalid.mauritania.viewmodel;

import android.app.Application;
import android.media.Image;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.OptIn;
import androidx.camera.core.ExperimentalGetImage;
import androidx.camera.core.ImageProxy;
import androidx.camera.view.PreviewView;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LifecycleOwner;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;

import com.digitalid.mauritania.camera.CameraException;
import com.digitalid.mauritania.camera.CameraHelper;
import com.digitalid.mauritania.camera.CameraListener;
import com.google.android.gms.tasks.Task;
import com.google.mlkit.vision.barcode.BarcodeScanner;
import com.google.mlkit.vision.barcode.BarcodeScannerOptions;
import com.google.mlkit.vision.barcode.BarcodeScanning;
import com.google.mlkit.vision.barcode.common.Barcode;
import com.google.mlkit.vision.common.InputImage;

import java.lang.ref.WeakReference;
import java.util.List;

@OptIn(markerClass = ExperimentalGetImage.class)
public class QRCodeReaderViewModel extends AndroidViewModel {

    private static final String TAG = QRCodeReaderViewModel.class.getSimpleName();

    private MutableLiveData<Barcode> barcodeMutableLiveData = new MutableLiveData<>();


    private Application application;
    private CameraHelper cameraHelper;
    private BarcodeScanner scanner;


    public QRCodeReaderViewModel(@NonNull Application application) {
        super(application);

        this.application = application;


        BarcodeScannerOptions options =
                new BarcodeScannerOptions.Builder()
                        .setBarcodeFormats(Barcode.FORMAT_QR_CODE)
                        .build();

        scanner = BarcodeScanning.getClient(options);


    }

    public LiveData<Barcode> getBarcode() {
        return barcodeMutableLiveData;
    }


    public void startCapture(LifecycleOwner lifecycleOwner, PreviewView previewView) throws CameraException {

        Log.d("TAG", "scanFragment startCapture display : " + previewView.getDisplay());


        startCamera(lifecycleOwner, previewView);

    }

    private void startCamera(LifecycleOwner lifecycleOwner, PreviewView previewView) throws CameraException {

        Log.d(TAG, "start camera " + previewView);

        cameraHelper = new CameraHelper.Builder()
                .context(application)
                .cameraListener(new CameraListenerImpl(this))
                .lifeCycleOwner(lifecycleOwner).
                previewOn(previewView).build();

        cameraHelper.start();

    }

    public void stopCamera() {

        if (cameraHelper != null) {

            cameraHelper.stop();
            cameraHelper = null;

            barcodeMutableLiveData.postValue(null);

        }

    }

    private static class CameraListenerImpl implements CameraListener {


        private final WeakReference<QRCodeReaderViewModel> weakReference;


        public CameraListenerImpl(QRCodeReaderViewModel cameraViewModel) {
            weakReference = new WeakReference<>(cameraViewModel);
        }


        @Override
        public void
        onFrameAvailableForAnalysis(ImageProxy imageProxy) {

            Log.d(TAG, "onFrameAvailableForAnalysis format" + imageProxy.getFormat());

            QRCodeReaderViewModel cameraViewModel = weakReference.get();


            if (cameraViewModel != null) {
                try {


                    Image mediaImage = imageProxy.getImage();

                    if (mediaImage != null) {
                        InputImage image =
                                InputImage.fromMediaImage(mediaImage, imageProxy.getImageInfo().getRotationDegrees());

                        Task<List<Barcode>> task = cameraViewModel.scanner.process(image);


                        if (!task.isComplete()) {
                            Thread.sleep(100);
                        }

                        List<Barcode> result = task.getResult();

                        if (task.isSuccessful() && !result.isEmpty()) {
                            cameraViewModel.barcodeMutableLiveData.postValue(result.get(0));

                        }


                    }


                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    Log.d(TAG, "error in onFrameAvailableForAnalysis  " + e.getLocalizedMessage());

                } catch (Exception e) {

                    Log.d(TAG, "error in onFrameAvailableForAnalysis  " + e.getLocalizedMessage());

                } finally {


                    imageProxy.close();
                }
            }

        }


    }
}
