package com.digitalid.mauritania.utils;

import com.regula.documentreader.api.enums.eVisualFieldType;
import com.regula.documentreader.api.results.DocumentReaderResults;

public class DocumentResultsUtil {

private DocumentResultsUtil(){

}

    public static  String getFirstName(DocumentReaderResults documentReaderResults) {


        String firstName = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_GIVEN_NAMES);


        if (firstName == null) {

            firstName = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_FIRST_NAME);
        }

        if (firstName == null) {

            firstName = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_SURNAME_AND_GIVEN_NAMES);
        }

        if (firstName != null && firstName.length() > 15) {
            firstName = Utils.trimString(firstName, 15);
        }

        if (firstName == null || firstName.isEmpty()) {
            firstName = "-";
        }


        return firstName;
    }


    public static String getLastName(DocumentReaderResults documentReaderResults) {

        String lastName = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_SURNAME);

        if (lastName == null) {

            lastName = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_LAST_NAME);

        }

        if (lastName == null) {

            lastName = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_FAMILY_NAME);

        }

        if (lastName == null) {

            lastName = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_SECOND_NAME);

        }

        if (lastName != null && lastName.length() > 10) {
            lastName = Utils.trimString(lastName, 10);
        }
        if (lastName == null || lastName.isEmpty()) {
            lastName = "-";
        }
        return lastName;
    }


    public static  String getDocumentNumber(DocumentReaderResults documentReaderResults) {

        String documentNumber = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_PERSONAL_NUMBER);

        if (documentNumber == null || documentNumber.trim().isEmpty()) {
            documentNumber = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_OPTIONAL_DATA);
        }

        if (documentNumber == null || documentNumber.trim().isEmpty()) {
            documentNumber = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_DOCUMENT_NUMBER);
        }


        if (documentNumber != null && documentNumber.length() > 10) {
            documentNumber = Utils.trimString(documentNumber, 10);
        }

        return documentNumber;
    }


    public static String getIssueDate(DocumentReaderResults documentReaderResults) {


        String issueDate = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_DATE_OF_ISSUE);
        if (issueDate == null) {

            issueDate = documentReaderResults.getTextFieldValueByType(eVisualFieldType.FT_FIRST_ISSUE_DATE);

        }

        if (issueDate == null || issueDate.isEmpty()) {
            issueDate = "-";
        }

        return issueDate;
    }

    public static  String getValueByFieldType(DocumentReaderResults documentReaderResults, int visualFieldType) {

        String value = documentReaderResults.getTextFieldValueByType(visualFieldType);

        if (value == null || value.isEmpty()) {
            value = "-";
        }
        return value;
    }
}
