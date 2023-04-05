# Add project specific ProGuard rules here.
# You can control the set of applied configuration files using the
# proguardFiles setting in build.gradle.
#
# For more details, see
#   http://developer.android.com/guide/developing/tools/proguard.html

# If your project uses WebView with JS, uncomment the following
# and specify the fully qualified class name to the JavaScript interface
# class:
#-keepclassmembers class fqcn.of.javascript.interface.for.webview {
#   public *;
#}

# Uncomment this to preserve the line number information for
# debugging stack traces.
#-keepattributes SourceFile,LineNumberTable

# If you keep the line number information, uncomment this to
# hide the original source file name.
#-renamesourcefileattribute SourceFile

#Airsnap Face

-keep class com.phoenixcapture.** { *; }
-keepclassmembers class com.phoenixcapture.** { *; }

-keep class net.idrnd.facesdk.** { *; }
-keepclassmembers class net.idrnd.facesdk.** { *; }


#Omnimatch
-keep class Tech5.OmniMatch.** { *; }
-keepclassmembers class Tech5.OmniMatch.** { *; }

-keep class Tech5.OmniMatch.JNI.TemplateCreators.** { *; }
-keepclassmembers class Tech5.OmniMatch.JNI.TemplateCreators.** { *; }

-keep class Tech5.OmniMatch.JNI.Matchers.** { *; }
-keepclassmembers class Tech5.OmniMatch.JNI.Matchers.** { *; }

#Cryptograph
-keep class ai.tech5.sdk.abis.cryptograph.** { *; }
-keepclassmembers class ai.tech5.sdk.abis.cryptograph.** { *; }


#exclude models
-keep class com.digitalid.mauritania.models.** { *; }
-keepclassmembers class com.digitalid.mauritania.models.** { *; }

