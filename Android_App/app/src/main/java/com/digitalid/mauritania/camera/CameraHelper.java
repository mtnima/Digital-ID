package com.digitalid.mauritania.camera;

import static androidx.camera.core.ImageAnalysis.STRATEGY_KEEP_ONLY_LATEST;

import android.annotation.SuppressLint;
import android.content.Context;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.camera.core.AspectRatio;
import androidx.camera.core.CameraSelector;
import androidx.camera.core.ImageAnalysis;
import androidx.camera.core.ImageProxy;
import androidx.camera.core.Preview;
import androidx.camera.lifecycle.ProcessCameraProvider;
import androidx.camera.view.PreviewView;
import androidx.core.content.ContextCompat;
import androidx.lifecycle.LifecycleOwner;

import com.google.common.util.concurrent.ListenableFuture;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class CameraHelper {


    private static final String TAG = CameraHelper.class.getSimpleName();
    private final Context context;
    private final LifecycleOwner lifecycleOwner;
    private final ExecutorService cameraExecutor;
    private PreviewView mViewFinder;
    private static final int LENS_FACING = CameraSelector.LENS_FACING_BACK;
    private ProcessCameraProvider mCameraProvider = null;


    private final CameraListener cameraListener;


    public CameraHelper(Builder builder) {


        this.context = builder.context;

        this.mViewFinder = builder.previewView;

        this.cameraListener = builder.cameraListener;

        this.lifecycleOwner = builder.lifecycleOwner;

        // Initialize our background executor
        this.cameraExecutor = Executors.newSingleThreadExecutor();


    }


    public void start() {

        startCamera();
    }

    public void stop() {

        if (mCameraProvider != null) {
            mCameraProvider.unbindAll();
        }
        if (cameraExecutor != null) {
            cameraExecutor.shutdown();
        }

        mViewFinder = null;
    }


    /**
     * Initialize CameraX, and prepare to bind the camera use cases
     */
    private void startCamera() {


        Log.d(TAG, "view finder : " + mViewFinder);
        Log.d(TAG, "context : " + context);
        Log.d(TAG, "lifecycle owner : " + lifecycleOwner);


        ListenableFuture<ProcessCameraProvider> cameraProviderFuture = ProcessCameraProvider.getInstance(context);

        cameraProviderFuture.addListener(() -> {

            // CameraProvider
            try {
                mCameraProvider = cameraProviderFuture.get();
            } catch (ExecutionException | InterruptedException e) {

                Log.e("TAG", "InterruptedException: " + e.getLocalizedMessage());
                Thread.currentThread().interrupt();

            }


            // Build and bind the camera use cases
            bindCameraUseCases();


        }, ContextCompat.getMainExecutor(context));


    }


    /**
     * Declare and bind preview, capture and analysis use cases
     */
    @SuppressLint({"RestrictedApi", "UnsafeExperimentalUsageError", "UnsafeOptInUsageError"})
    private void bindCameraUseCases() {


        int rotation = mViewFinder.getDisplay().getRotation();

        CameraSelector cameraSelector = new CameraSelector.Builder().requireLensFacing(LENS_FACING).build();


        Preview preview = new Preview.Builder()

                .setTargetAspectRatio(AspectRatio.RATIO_16_9)

                .setTargetRotation(rotation).build();


        // Set initial target rotation, we will have to call
        // this again if rotation changes
        // during the lifecycle of this use case
        ImageAnalysis imageAnalysis = new ImageAnalysis.Builder().setBackpressureStrategy(STRATEGY_KEEP_ONLY_LATEST).setTargetAspectRatio(AspectRatio.RATIO_16_9)


                // Set initial target rotation, we will have to call
                // this again if rotation changes
                // during the lifecycle of this use case

                .setTargetRotation(rotation).build();

        imageAnalysis.setAnalyzer(cameraExecutor, new ImageAnalyzer());


        // Must unbind the use-cases before rebinding them
        mCameraProvider.unbindAll();

        try {
            // A variable number of use-cases can be passed here -
            // camera provides access to CameraControl & CameraInfo
            mCameraProvider.bindToLifecycle(lifecycleOwner, cameraSelector, preview, imageAnalysis);

            // Attach the viewfinder's surface provider to preview use case
            preview.setSurfaceProvider(mViewFinder.getSurfaceProvider());


        } catch (Exception exc) {
            Log.d(TAG, "bindCameraUseCases() failure :" + exc.getLocalizedMessage());
        }

        Log.d(TAG, "bindCameraUseCases() done");
    }

    public static final class Builder {

        private Context context;

        private PreviewView previewView;

        private CameraListener cameraListener;

        private LifecycleOwner lifecycleOwner;




        public Builder context(Context context) {

            this.context = context;
            return this;
        }

        public Builder lifeCycleOwner(LifecycleOwner lifecycleOwner) {
            this.lifecycleOwner = lifecycleOwner;
            return this;
        }


        public Builder previewOn(PreviewView previewView) {

            this.previewView = previewView;
            return this;
        }

        public Builder cameraListener(CameraListener listener) {
            this.cameraListener = listener;
            return this;
        }


        public CameraHelper build() throws CameraException {
            if (context == null) {
                throw new CameraException("context is null ");
            }

            if (lifecycleOwner == null) {
                throw new CameraException("lifecycleOwner is null ");
            }


            if (cameraListener == null) {
                throw new CameraException("cameraListener is null");
            }
            if (previewView == null) {
                throw new CameraException("you must preview on a preview");
            }
            return new CameraHelper(this);
        }


    }

    class ImageAnalyzer implements ImageAnalysis.Analyzer {


        @Override
        public void analyze(@NonNull ImageProxy image) {

            cameraListener.onFrameAvailableForAnalysis(image);

        }
    }

}




