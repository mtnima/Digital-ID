//
//  UserDefaultsHelper.swift
//  Mauritania
//
//  Created by IOS on 29/08/21.
//

import Foundation

class UserDefaultsHelper{
    
    
    let DEFAULT_PITCH_THRESHOLD:Float = 15;
    let DEFAULT_YAW_THRESHOLD:Float = 15;
    let DEFAULT_ROLL_THRESHOLD:Float = 10;
    
//    let DEFAULT_EYES_Y_MIN_THRESHOLD:Float = 43;
//    let DEFAULT_EYES_Y_MAX_THRESHOLD :Float = 53;
//    let DEFAULT_EYES_X_MIN_THRESHOLD:Float = 17;
//    let DEFAULT_EYES_X_MAX_THRESHOLD:Float = 22;
    
    let DEFAULT_IMAGE_CENTRE_TO_FACE_CENTRE_TOLERANCE:Float = 6;
    let DEFAULT_MIN_FACE_WIDTH:Float = 180;
    
    let DEFAULT_MASK_THRESHOLD:Float = 0.5;
    let DEFAULT_SUNGLASS_THRESHOLD:Float = 0.5;
    let DEFAULT_BRISQUE_THRESHOLD:Float = 60;
    let DEFAULT_LIVENESS_THRESHOLD:Float = 0.5;
    let DEFAULT_EYE_CLOSE_THRESHOLD:Float = 0.4;
    let DEFAULT_ENABLE_CAPTURE_AFTER:Int = 6;
    let DEFAULT_IS_OCCLUSION_ENABLED :Bool = true
    let DEFAULT_IS_EYE_CLOSED_ENABLED:Bool = true
    let DEFAULT_IS_LIVENESS_ENABLED:Bool = false
    
    let DEFAULT_DELAY_BETWEEN_FRAMES:Int = 6;
    let DEFAULT_COMPRESSION_QUALITY:Int = 80;
    
    
    let DEFAULT_MIN_BLUR:Float = 0.0;
    let DEFAULT_MAX_BLUR:Float = 0.5;
    let DEFAULT_MIN_EXPOSURE:Float = 0.2;
    let DEFAULT_MAX_EXPOSURE:Float = 0.7;
    let DEFAULT_MIN_BRIGHTNESS:Float = 0.2;
    let DEFAULT_MAX_BRIGHTNESS:Float = 0.7;
    
    let DEFAULT_SKINTONE :Float = 0.5;
    let DEFAULT_HOTSPOTS:Float = 0.5;
    let DEFAULT_RED_EYES:Float = 0.5;
    let DEFAULT_MOUTH_OPEN:Float = 0.5;
    let DEFAULT_LAUGH:Float = 0.5;
    let DEFAULT_UNIFORM_BACKGROUND:Float = 0.5;
    let DEFAULT_UNIFORM_BACKGROUND_COLOR:Float = 0.5;
    let DEFAULT_UNIFORM_ILLUMINATION:Float = 0.5;
    
    
    let DEFAULT_FACE_WIDTH_TOLERANCE:Float = 10
    let FACE_WIDTH_TOLERANCE = "FACE_WIDTH_TOLERANCE"
    
    
  
    
    
    let IS_OCCLUSION_ENABLED = "IS_OCCLUSION_ENABLED";
    let IS_EYE_CLOSED_ENABLED = "IS_EYE_CLOSED_ENABLED";
    let IS_LIVENESS_ENABLED = "IS_LIVENESS_ENABLED ";
    let ENABLE_CAPTURE_AFTER = "ENABLE_CAPTURE_AFTER";
    let PITCH_THRESHOLD = "PITCH_THRESHOLD";
    let YAW_THRESHOLD = "YAW_THRESHOLD";
    let ROLL_THRESHOLD = "ROLL_THRESHOLD";
    
//    let EYES_Y_MIN_THRESHOLD = "EYES_Y_MIN_THRESHOLD";
//    let EYES_Y_MAX_THRESHOLD  = "EYES_Y_MAX_THRESHOLD";
//    let EYES_X_MIN_THRESHOLD = "EYES_X_MIN_THRESHOLD";
//    let EYES_X_MAX_THRESHOLD = "EYES_X_MAX_THRESHOLD";
    
    let IMAGE_CENTRE_TO_FACE_CENTRE_TOLERANCE = "IMAGE_CENTRE_TO_FACE_CENTRE_TOLERANCE";
    let MIN_FACE_WIDTH = "MIN_FACE_WIDTH";
    
    
    let MASK_THRESHOLD = "MASK_THRESHOLD";
    let SUNGLASS_THRESHOLD = "SUNGLASS_THRESHOLD";
    let BRISQUE_THRESHOLD = "BRISQUE_THRESHOLD";
    let LIVENESS_THRESHOLD = "LIVENESS_THRESHOLD";
    let EYE_CLOSE_THRESHOLD = "EYE_CLOSE_THRESHOLD";
    
    let DELAY_BETWEEN_FRAMES = "DELAY_BETWEEN_FRAMES";
    let COMPRESSION_QUALITY = "COMPRESSION_QUALITY";
    
    let MIN_BLUR = "MIN_BLUR"
    let MAX_BLUR = "MAX_BLUR"
    let MIN_EXPOSURE = "MIN_EXPOSURE"
    let MAX_EXPOSURE = "MAX_EXPOSURE"
    let MIN_BRIGHTNESS = "MIN_BRIGHTNESS"
    let MAX_BRIGHTNESS  = "MAX_BRIGHTNESS"
    
    let SKINTONE = "SKINTONE"
    let HOTSPOTS = "HOTSPOTS"
    let RED_EYES = "RED_EYES"
    let MOUTH_OPEN = "MOUTH_OPEN"
    let LAUGH = "LAUGH"
    let UNIFORM_BACKGROUND  = "UNIFORM_BACKGROUND"
    let UNIFORM_BACKGROUND_COLOR  = "UNIFORM_BACKGROUND_COLOR"
    let UNIFORM_ILLUSINATION  = "UNIFORM_ILLUSINATION"
    
    
    static let shared = UserDefaultsHelper()
    
    private var userDefaults:UserDefaults;
    
    private init()
    {
        userDefaults = UserDefaults()
    }
    
    
    
    
    
    func setIsLivenessEnabled( isLivenessEnabled:Bool) {
        userDefaults.setValue( isLivenessEnabled, forKey: IS_LIVENESS_ENABLED)
    }
    
    func getIsLivenessEnabled()->Bool {
        
        
        if(ifKeyExists(key: IS_LIVENESS_ENABLED)){
            return userDefaults.bool(forKey: IS_LIVENESS_ENABLED)
            
        }else{
            return DEFAULT_IS_LIVENESS_ENABLED
        }
        
        
    }
    
    
    func setIsOcculusionEnabled( isOcclusionEnabled:Bool) {
        userDefaults.setValue( isOcclusionEnabled, forKey: IS_OCCLUSION_ENABLED)
    }
    
    func getIsOcculusionEnabled()->Bool {
        
        
        if(ifKeyExists(key: IS_OCCLUSION_ENABLED)){
            return userDefaults.bool(forKey: IS_OCCLUSION_ENABLED)
            
        }else{
            return DEFAULT_IS_OCCLUSION_ENABLED
        }
        
        
    }
    
    
    
    func setIsEyeClosedEnabled( isEyeCloseEnabled:Bool) {
        userDefaults.setValue( isEyeCloseEnabled, forKey: IS_EYE_CLOSED_ENABLED)
    }
    
    func getIsEyeClosedEnabled()->Bool {
        
        
        if(ifKeyExists(key: IS_EYE_CLOSED_ENABLED)){
            return userDefaults.bool(forKey: IS_EYE_CLOSED_ENABLED)
            
        }else{
            return DEFAULT_IS_EYE_CLOSED_ENABLED
        }
        
        
    }
    
    
    
    func setPitchThreshold( pitchThreshold:Float) {
        userDefaults.setValue( pitchThreshold, forKey: PITCH_THRESHOLD)
    }
    
    func getPitchThreshold()->Float {
        
        
        if(ifKeyExists(key: PITCH_THRESHOLD)){
            return userDefaults.float(forKey: PITCH_THRESHOLD)
            
        }else{
            return DEFAULT_PITCH_THRESHOLD
        }
        
        
    }
    
    
    func setYawThreshold( yawThreshold:Float) {
        userDefaults.setValue( yawThreshold, forKey: YAW_THRESHOLD)
    }
    
    func getYawThreshold()->Float {
        
        
        if(ifKeyExists(key: YAW_THRESHOLD)){
            return userDefaults.float(forKey: YAW_THRESHOLD)
            
        }else{
            return DEFAULT_YAW_THRESHOLD
        }
        
        
    }
    
    
    func setMaskThreshold( maskThreshold:Float) {
        userDefaults.setValue( maskThreshold, forKey: MASK_THRESHOLD)
    }
    
    func getMaskThreshold()->Float {
        
        
        if(ifKeyExists(key: MASK_THRESHOLD)){
            return userDefaults.float(forKey: MASK_THRESHOLD)
            
        }else{
            return DEFAULT_MASK_THRESHOLD
        }
        
        
    }
    
    
    func setSunglassThreshold( sunglassTHreshold:Float) {
        userDefaults.setValue( sunglassTHreshold, forKey: SUNGLASS_THRESHOLD)
    }
    
    func getSunglassThreshold()->Float {
        
        
        if(ifKeyExists(key: SUNGLASS_THRESHOLD)){
            return userDefaults.float(forKey: SUNGLASS_THRESHOLD)
            
        }else{
            return DEFAULT_SUNGLASS_THRESHOLD
        }
        
        
    }
    
    
    func setBrisqueThreshold( brisquetHreshold:Float) {
        userDefaults.setValue( brisquetHreshold, forKey: BRISQUE_THRESHOLD)
    }
    
    func getBrisqueThreshold()->Float {
        
        
        if(ifKeyExists(key: BRISQUE_THRESHOLD)){
            return userDefaults.float(forKey: BRISQUE_THRESHOLD)
            
        }else{
            return DEFAULT_BRISQUE_THRESHOLD
        }
        
        
    }
    
    
    
    
    func setEnableCaptureAfter( enableCaptureAfter:Int) {
        userDefaults.setValue( enableCaptureAfter, forKey: ENABLE_CAPTURE_AFTER)
    }
    
    func getEnableCaptureAfter()->Int {
        
        
        if(ifKeyExists(key: ENABLE_CAPTURE_AFTER)){
            return userDefaults.integer(forKey: ENABLE_CAPTURE_AFTER)
            
        }else{
            return DEFAULT_ENABLE_CAPTURE_AFTER
        }
    }
    
    
    func setDelayBetweenFrames( delay:Int) {
        userDefaults.setValue( delay, forKey: DELAY_BETWEEN_FRAMES)
    }
    
    
    func getDelayBetweenFrames()->Int {
        
        
        if(ifKeyExists(key: DELAY_BETWEEN_FRAMES)){
            return userDefaults.integer(forKey: DELAY_BETWEEN_FRAMES)
            
        }else{
            return DEFAULT_DELAY_BETWEEN_FRAMES
        }
    }
    
    
    
    
    
    func setCompressionQuality( quality:Int) {
        userDefaults.setValue( quality, forKey: COMPRESSION_QUALITY)
    }
    
    
    func getCompressionQuality()->Int {
        
        if(ifKeyExists(key: COMPRESSION_QUALITY)){
            return userDefaults.integer(forKey: COMPRESSION_QUALITY)
            
        }else{
            return DEFAULT_COMPRESSION_QUALITY
        }
    }
    
    
    
    
    
    
    
    func setEyeCloseThreshold( eyeCloseThreshold:Float) {
        userDefaults.setValue( eyeCloseThreshold, forKey: EYE_CLOSE_THRESHOLD)
    }
    
    func getEyeCloseThreshold()->Float {
        
        
        if(ifKeyExists(key: EYE_CLOSE_THRESHOLD)){
            return userDefaults.float(forKey: EYE_CLOSE_THRESHOLD)
            
        }else{
            return DEFAULT_EYE_CLOSE_THRESHOLD
        }
        
        
    }
    
    
    func setLivenessThreshold( livenessTHreshold:Float) {
        userDefaults.setValue( livenessTHreshold, forKey: LIVENESS_THRESHOLD)
    }
    
    func getLivenessThreshold()->Float {
        
        
        if(ifKeyExists(key: LIVENESS_THRESHOLD)){
            return userDefaults.float(forKey: LIVENESS_THRESHOLD)
            
        }else{
            return DEFAULT_LIVENESS_THRESHOLD
        }
        
    }
    
    
    
    private func ifKeyExists(key: String) -> Bool {
        return userDefaults.object(forKey: key) != nil
    }
    
    
    func setMinBlur( minBlur:Float) {
        userDefaults.setValue( minBlur, forKey:MIN_BLUR)
    }
    
    func getMinBlur()->Float {
        
        
        if(ifKeyExists(key: MIN_BLUR)){
            return userDefaults.float(forKey: MIN_BLUR)
            
        }else{
            return DEFAULT_MIN_BLUR
        }
        
        
    }
    
    
    
    
    func setMaxBlur( maxBlur:Float) {
        userDefaults.setValue( maxBlur, forKey:MAX_BLUR)
    }
    
    func getMaxBlur()->Float {
        
        
        if(ifKeyExists(key: MAX_BLUR)){
            return userDefaults.float(forKey: MAX_BLUR)
            
        }else{
            return DEFAULT_MAX_BLUR
        }
        
        
    }
    
    
    
    
    //MIN_EXPOSURE
    
    
    func setMinExposure( minexposure:Float) {
        userDefaults.setValue( minexposure, forKey:MIN_EXPOSURE)
    }
    
    func getMinExposure()->Float {
        
        
        if(ifKeyExists(key: MIN_EXPOSURE)){
            return userDefaults.float(forKey: MIN_EXPOSURE)
            
        }else{
            return DEFAULT_MIN_EXPOSURE
            
        }
        
        
    }
    
    func setMaxExposure( maxexposure:Float) {
        userDefaults.setValue( maxexposure, forKey:MAX_EXPOSURE)
    }
    
    func getMaxExposure()->Float {
        
        
        if(ifKeyExists(key: MAX_EXPOSURE)){
            return userDefaults.float(forKey: MAX_EXPOSURE)
            
        }else{
            return DEFAULT_MAX_EXPOSURE
            
        }
        
        
    }
    
    func setMinBrightness( minbrightness:Float) {
        userDefaults.setValue( minbrightness, forKey:MIN_BRIGHTNESS)
    }
    
    func getMinBrightness()->Float {
        
        
        if(ifKeyExists(key: MIN_BRIGHTNESS)){
            return userDefaults.float(forKey: MIN_BRIGHTNESS)
            
        }else{
            return DEFAULT_MIN_BRIGHTNESS
            
        }
        
        
    }
    
    func setMaxBrightness( maxbrightness:Float) {
        userDefaults.setValue( maxbrightness, forKey:MAX_BRIGHTNESS)
    }
    
    func getMaxBrightness()->Float {
        
        
        if(ifKeyExists(key: MAX_BRIGHTNESS)){
            return userDefaults.float(forKey: MAX_BRIGHTNESS)
            
        }else{
            return DEFAULT_MAX_BRIGHTNESS
            
        }
        
        
    }
    
    func setSkintone( skintone:Float) {
        userDefaults.setValue( skintone, forKey:SKINTONE)
    }
    
    func getSkintone()->Float {
        
        
        if(ifKeyExists(key: SKINTONE)){
            return userDefaults.float(forKey: SKINTONE)
            
        }else{
            return DEFAULT_SKINTONE
            
        }
        
    }
    
    func setHotspots( hotspots:Float) {
        userDefaults.setValue( hotspots, forKey:HOTSPOTS)
    }
    
    func getHotspots()->Float {
        
        
        if(ifKeyExists(key: HOTSPOTS)){
            return userDefaults.float(forKey: HOTSPOTS)
            
        }else{
            return DEFAULT_HOTSPOTS
            
        }
        
        
    }
    
    
    func setRedEyes( redeyes:Float) {
        userDefaults.setValue( redeyes, forKey:RED_EYES)
    }
    
    func getRedEyes()->Float {
        
        
        if(ifKeyExists(key: RED_EYES)){
            return userDefaults.float(forKey: RED_EYES)
            
        }else{
            return DEFAULT_RED_EYES
            
        }
        
        
    }
    
    func setMouthOpen( mouthopen:Float) {
        userDefaults.setValue( mouthopen, forKey:MOUTH_OPEN)
    }
    
    func getMouthOpen()->Float {
        
        
        if(ifKeyExists(key: MOUTH_OPEN)){
            return userDefaults.float(forKey: MOUTH_OPEN)
            
        }else{
            return DEFAULT_MOUTH_OPEN
            
        }
        
        
    }
    
    
    
    func setLaugh( laugh:Float) {
        userDefaults.setValue( laugh, forKey:LAUGH)
    }
    
    func getLaugh()->Float {
        
        
        if(ifKeyExists(key: LAUGH)){
            return userDefaults.float(forKey: LAUGH)
            
        }else{
            return DEFAULT_LAUGH
            
        }
        
        
    }
    
    
    func setUnifromBackGround( unifrombackground:Float) {
        userDefaults.setValue( unifrombackground, forKey:UNIFORM_BACKGROUND)
    }
    
    func getUnifromBackGround()->Float {
        
        
        if(ifKeyExists(key: UNIFORM_BACKGROUND)){
            return userDefaults.float(forKey: UNIFORM_BACKGROUND)
            
        }else{
            return DEFAULT_UNIFORM_BACKGROUND
        }
        
        
    }
    
    
    func setRollThreshold( rollThreshold:Float) {
        userDefaults.setValue( rollThreshold, forKey:ROLL_THRESHOLD)
    }
    
    func getRollThreshold()->Float {
        
        
        if(ifKeyExists(key: ROLL_THRESHOLD)){
            return userDefaults.float(forKey: ROLL_THRESHOLD)
            
        }else{
            return DEFAULT_ROLL_THRESHOLD
        }
        
        
    }
    
    
    
    
    
    
    
    func setUnifromBackGroundColor( unifrombackgroundColor:Float) {
        userDefaults.setValue( unifrombackgroundColor, forKey:UNIFORM_BACKGROUND_COLOR)
    }
    
    func getUnifromBackGroundColor()->Float {
        
        
        if(ifKeyExists(key: UNIFORM_BACKGROUND_COLOR)){
            return userDefaults.float(forKey: UNIFORM_BACKGROUND_COLOR)
            
        }else{
            return DEFAULT_UNIFORM_BACKGROUND_COLOR
        }
        
        
    }
    
    
    func setUnifromIllumination( unifromIllumination:Float) {
        userDefaults.setValue( unifromIllumination, forKey:UNIFORM_ILLUSINATION)
    }
    
    func getUnifromIllumination()->Float {
        
        
        if(ifKeyExists(key: UNIFORM_ILLUSINATION)){
            return userDefaults.float(forKey: UNIFORM_ILLUSINATION)
            
        }else{
            return DEFAULT_UNIFORM_ILLUMINATION
        }
        
        
    }
    
    
//    @objc
//    public func setMinEyeDistanceToImageWidthRatio( minThreshold:Float) {
//        //EYES_X_MIN_THRESHOLD = minThreshold;
//
//        userDefaults.setValue( minThreshold, forKey:EYES_X_MIN_THRESHOLD)
//    }
//
//
//    @objc
//    public func getMinEyeDistanceToImageWidthRatio()->Float {
//        //return EYES_X_MIN_THRESHOLD;
//
//        if(ifKeyExists(key: EYES_X_MIN_THRESHOLD)){
//            return userDefaults.float(forKey: EYES_X_MIN_THRESHOLD)
//
//        }else{
//            return DEFAULT_EYES_X_MIN_THRESHOLD
//        }
//
//    }
//
    
//    @objc
//    public func setMaxEyeDistanceToImageWidthRatio( maxThreshold:Float) {
//       // EYES_X_MAX_THRESHOLD = maxThreshold;
//
//        userDefaults.setValue( maxThreshold, forKey:EYES_X_MAX_THRESHOLD)
//    }
//
//    @objc
//    public func getMaxEyeDistanceToImageWidthRatio()->Float {
//       // return EYES_X_MAX_THRESHOLD;
//
//        if(ifKeyExists(key: EYES_X_MAX_THRESHOLD)){
//            return userDefaults.float(forKey: EYES_X_MAX_THRESHOLD)
//
//        }else{
//            return DEFAULT_EYES_X_MAX_THRESHOLD
//        }
//    }
//
//
//    public func setMinEyePositionToImageHeightRatio(minThreshold:Float) {
//       // EYES_Y_MIN_THRESHOLD = minThreshold;
//
//        userDefaults.setValue( minThreshold, forKey:EYES_Y_MIN_THRESHOLD)
//    }
//
//    @objc
//    public func  getMinEyePositionToImageHeightRatio()->Float {
//       // return EYES_Y_MIN_THRESHOLD;
//
//        if(ifKeyExists(key: EYES_Y_MIN_THRESHOLD)){
//            return userDefaults.float(forKey: EYES_Y_MIN_THRESHOLD)
//
//        }else{
//            return DEFAULT_EYES_Y_MIN_THRESHOLD
//        }
//    }
    
//    @objc
//    public func setMaxEyePositionToImageHeightRatio( maxThreshold:Float) {
//       // EYES_Y_MAX_THRESHOLD = maxThreshold;
//
//        userDefaults.setValue( maxThreshold, forKey:EYES_Y_MAX_THRESHOLD)
//    }
    
//    @objc
//    public func getMaxEyePositionToImageHeightRatio()->Float {
//       // return EYES_Y_MAX_THRESHOLD;
//
//        if(ifKeyExists(key: EYES_Y_MAX_THRESHOLD)){
//            return userDefaults.float(forKey: EYES_Y_MAX_THRESHOLD)
//
//        }else{
//            return DEFAULT_EYES_Y_MAX_THRESHOLD
//        }
//    }
    
    @objc
    public func setImageCentreToFaceCentreTolerance( tolerancePercentage:Float) {
       // IMAGE_CENTRE_TO_EYE_CENTRE_TOLERANCE = tolerancePercentage;
        
        userDefaults.setValue( tolerancePercentage, forKey:IMAGE_CENTRE_TO_FACE_CENTRE_TOLERANCE)
    }
    
    @objc
    public func getImageCentreToFaceCentreTolerance()->Float {
       // return IMAGE_CENTRE_TO_EYE_CENTRE_TOLERANCE;
        
        if(ifKeyExists(key: IMAGE_CENTRE_TO_FACE_CENTRE_TOLERANCE)){
            return userDefaults.float(forKey: IMAGE_CENTRE_TO_FACE_CENTRE_TOLERANCE)
            
        }else{
            return DEFAULT_IMAGE_CENTRE_TO_FACE_CENTRE_TOLERANCE
        }
    }
    
    
    
    @objc
    public func setFaceWidthTolerance( percentage:Float) {
       // IMAGE_CENTRE_TO_EYE_CENTRE_TOLERANCE = tolerancePercentage;
        
        userDefaults.setValue( percentage, forKey:FACE_WIDTH_TOLERANCE)
    }
    
    @objc
    public func getFaceWidthTolerance()->Float {
       // return IMAGE_CENTRE_TO_EYE_CENTRE_TOLERANCE;
        
        if(ifKeyExists(key: FACE_WIDTH_TOLERANCE)){
            return userDefaults.float(forKey: FACE_WIDTH_TOLERANCE)
            
        }else{
            return DEFAULT_FACE_WIDTH_TOLERANCE
        }
    }
    
    
    
//    @objc
//    public func setMinFaceWidth( percentage:Float) {
//       // IMAGE_CENTRE_TO_EYE_CENTRE_TOLERANCE = tolerancePercentage;
//
//        userDefaults.setValue( percentage, forKey:MIN_FACE_WIDTH)
//    }
//
//    @objc
//    public func getMinFaceWidt()->Float {
//       // return IMAGE_CENTRE_TO_EYE_CENTRE_TOLERANCE;
//
//        if(ifKeyExists(key: MIN_FACE_WIDTH)){
//            return userDefaults.float(forKey: MIN_FACE_WIDTH)
//
//        }else{
//            return DEFAULT_MIN_FACE_WIDTH
//        }
//    }
    
    
}
