import Foundation

@objc public enum IDEncodeFieldType : UInt16 {
    case None = 0

    // Face related
    case Faces__First = 1
    case FaceImage = 2
    case FaceTemplate = 3
    case FaceCompressedImage = 4
    case Faces__Last = 5

    // Fingers related
    case Fingers__First = 50
    case RightSlap = 51
    case FingerImageR1 = 52
    case FingerTemplateR1 = 53
    case FingerImageR2 = 54
    case FingerTemplateR2 = 55
    case FingerImageR3 = 56
    case FingerTemplateR3 = 57
    case FingerImageR4 = 58
    case FingerTemplateR4 = 59
    case FingerImageR5 = 60
    case FingerTemplateR5 = 61
    case LeftSlap = 62
    case FingerImageL1 = 63
    case FingerTemplateL1 = 64
    case FingerImageL2 = 65
    case FingerTemplateL2 = 66
    case FingerImageL3 = 67
    case FingerTemplateL3 = 68
    case FingerImageL4 = 69
    case FingerTemplateL4 = 70
    case FingerImageL5 = 71
    case FingerTemplateL5 = 72
    case Fingers__Last = 73

    // Eyes related
    case Eyes__First = 100
    case IrisImageR = 101
    case IrisTemplateR = 102
    case IrisImageL = 103
    case IrisTemplateL = 104
    case Eyes__Last = 105

    // Voice related
    case Voice__First = 150
    case VoiceSample = 151
    case VoiceTemplate = 152
    case Voice__Last = 153

    // Others
    case Extra__First = 1000
    case Extra = 1001
    case Demog = 1002
    case DigitalCertificate = 1003
    case BinaryBlob = 1004
    case CryptographId = 1005
    case Extra__Last = 1006
}

@objc public protocol ITLVRecord {
    var type: IDEncodeFieldType { get }
    var data: [UInt8] { get }
}
