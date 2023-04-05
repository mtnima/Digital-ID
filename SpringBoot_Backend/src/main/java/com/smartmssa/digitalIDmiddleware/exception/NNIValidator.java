package com.smartmssa.digitalIDmiddleware.exception;

import javax.validation.ConstraintValidator;
import javax.validation.ConstraintValidatorContext;

public class NNIValidator implements ConstraintValidator<NNIValidation, String>
{
    public boolean isValid(String nniString, ConstraintValidatorContext cxt) {
        try{
            Long nni = Long.parseLong(nniString);
            if((nni % 97) == 1)
                return true;
            else
                return false;
        }catch (Exception e){
            return false;
        }
    }
}