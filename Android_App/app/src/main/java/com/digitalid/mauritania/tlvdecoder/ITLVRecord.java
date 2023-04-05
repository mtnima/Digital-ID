package com.digitalid.mauritania.tlvdecoder;

public interface ITLVRecord {
    enum IDEncodeFieldType
    {
        NONE(0),

        // Face related
        FACES_FIRST (1),
        FACE_IMAGE(2),
        FACE_TEMPLATE(3),
        FACE_COMPRESSED_IMAGE(4),
        FACES_LAST(5),

        // Fingers related
        FINGERS_FIRST(50),
        RIGHT_SLAP(51),
        FINGER_IMAGE_R_1(52),
        FINGER_TEMPLATE_R_1(53),
        FINGER_IMAGE_R_2(54),
        FINGER_TEMPLATE_R_2(55),
        FINGER_IMAGE_R_3(56),
        FINGER_TEMPLATE_R_3(57),
        FINGER_IMAGE_R_4(58),
        FINGER_TEMPLATE_R_4(59),
        FINGER_IMAGE_R_5(60),
        FINGER_TEMPLATE_R_5(61),
        LEFT_SLAP(62),
        FINGER_IMAGE_L_1(63),
        FINGER_TEMPLATE_L_1(64),
        FINGER_IMAGE_L_2(65),
        FINGER_TEMPLATE_L_2(66),
        FINGER_IMAGE_L_3(67),
        FINGER_TEMPLATE_L_3(68),
        FINGER_IMAGE_L_4(69),
        FINGER_TEMPLATE_L_4(70),
        FINGER_IMAGE_L_5(71),
        FINGER_TEMPLATE_L_5(72),
        FINGERS_LAST(73),

        // Eyes related
        EYES_FIRST(100),
        IRIS_IMAGE_R(101),
        IRIS_TEMPLATE_R(102),
        IRIS_IMAGE_L(103),
        IRIS_TEMPLATE_L(104),
        EYES_LAST(105),

        // Voice related
        VOICE_FIRST(150),
        VOICE_SAMPLE(151),
        VOICE_TEMPLATE(152),
        VOICE_LAST(153),

        // Others
        EXTRA_FIRST(1000),
        EXTRA(1001),
        DEMOG(1002),
        DIGITAL_CERTIFICATE(1003),
        BINARY_BLOB(1004),
        EXTRA_LAST(1005),
        CRYPTOGRAPH_ID(1006);

        public final int val;

        IDEncodeFieldType(int val)
        {
            this.val = val;
        }

        public static IDEncodeFieldType fromInteger(int x) {
            IDEncodeFieldType[] values = IDEncodeFieldType.values();
            for (IDEncodeFieldType v : values ) {
                if(v.val == x){
                    return v;
                }
            }
            return null;
        }
    }

    IDEncodeFieldType getType();
    byte[] getData();
}
