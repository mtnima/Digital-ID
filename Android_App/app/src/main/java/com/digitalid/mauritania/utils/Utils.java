package com.digitalid.mauritania.utils;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.os.Build;
import android.util.Log;

import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;

public class Utils {

    private Utils() {

    }


    public static String makeStringOfLength(String str, int n) {

        if (str == null) {
            str = "";
        }
        if (str.length() < n) {
            // Append "-" to the end of the string until it reaches the desired length
            StringBuilder strBuilder = new StringBuilder(str);
            while (strBuilder.length() < n) {
                strBuilder.append("-");
            }
            str = strBuilder.toString();
        } else if (str.length() > n) {
            // Make a substring of the desired length
            str = str.substring(0, n);
        }
        return str;
    }


    public static String trimString(String str, int n) {

        if (str.length() > n) {
            // Make a substring of the desired length
            str = str.substring(0, n);
        }
        return str;
    }


    public static byte[] bitmapToBytes(Bitmap bitmap) {

        if (bitmap == null) {
            return new byte[0];
        }

        try (ByteArrayOutputStream stream = new ByteArrayOutputStream()) {
            bitmap.compress(Bitmap.CompressFormat.JPEG, 100, stream);
            return stream.toByteArray();
        } catch (Exception e) {
            return new byte[0];
        }


    }


    public static byte[] readFileFromAssets(AssetManager assetManager, String fileName) throws IOException {


        try (InputStream inputStream = assetManager.open(fileName); ByteArrayOutputStream output = new ByteArrayOutputStream()) {


            byte[] buffer = new byte[8192];
            int bytesRead;

            while ((bytesRead = inputStream.read(buffer)) != -1) {
                output.write(buffer, 0, bytesRead);
            }

            return output.toByteArray();


        }

    }


    public static byte[] readFileBytes(String path) {
        File file = new File(path);
        int size = (int) file.length();
        byte[] bytes = new byte[size];
        try (InputStream inputStream = new FileInputStream(file); BufferedInputStream buf = new BufferedInputStream(inputStream)) {

            buf.read(bytes, 0, bytes.length);
        } catch (IOException e) {
            Log.d("TAG", "Unable to read file");
        }
        return bytes;
    }


    @SuppressWarnings("java:S4042")
    public static void deleteFile(File file) {

        if (file.exists()) {

            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                try {
                    Files.delete(file.toPath());
                } catch (IOException ie) {
                    Log.e("TAG", "Unable to delete file:" + file.getName());

                }
            } else {
                boolean isFileDeleted = file.delete();

                Log.e("TAG", "is file deleted" + isFileDeleted);
            }
        }
    }


    @SuppressWarnings("java:S6300")
    public static String writeFile(byte[] data, String path) throws IOException {

        File myFile = new File(path);
        if (myFile.getParentFile() != null && !myFile.getParentFile().exists()) {
            boolean isDirsCreated = myFile.getParentFile().mkdirs();
            Log.d("TAG", "isDirsCreated : " + isDirsCreated);
        }

        try (FileOutputStream outPut = new FileOutputStream(myFile)) {
            outPut.write(data);
            return path;
        }
    }
}
