package com.digitalid.mauritania.camera;

import androidx.camera.core.ImageProxy;

public interface CameraListener {
   void onFrameAvailableForAnalysis(ImageProxy imageProxy);
}
