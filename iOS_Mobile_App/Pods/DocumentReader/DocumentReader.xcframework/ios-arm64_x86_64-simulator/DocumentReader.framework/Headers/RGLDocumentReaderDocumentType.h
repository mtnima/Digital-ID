#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RGLDiDocType) {
    /**
     An unknown document type
     */
    RGLDiDocTypeNotDefined = 0,
    /**
     Passport
     */
    RGLDiDocTypePassport = 11,
    /**
     Identity Card
     */
    RGLDiDocTypeIdentityCard = 12,
    /**
     Diplomatic Passport
     */
    RGLDiDocTypeDiplomaticPassport = 13,
    /**
     Service Passport
     */
    RGLDiDocTypeServicePassport = 14,
    /**
     Seaman's Identity Document
     */
    RGLDiDocTypeSeamanIdentityDocument = 15,
    /**
     Identity Card for Residence
     */
    RGLDiDocTypeIdentityCardForResidence = 16,
    /**
     Travel Document
     */
    RGLDiDocTypeTravelDocument = 17,
    /**
     Other
     */
    RGLDiDocTypeOther = 99,
    /**
     Visa ID-2
     */
    RGLDiDocTypeVisaID2 = 29,
    /**
     Visa ID-3
     */
    RGLDiDocTypeVisaID3 = 30,
    /**
     National Identity Card
     */
    RGLDiDocTypeNationalIdentityCard = 20,
    /**
     Social Identity Card
     */
    RGLDiDocTypeSocialIdentityCard = 21,
    /**
     Alien's Identity Card
     */
    RGLDiDocTypeAliensIdentityCard = 22,
    /**
     Privileged Identity Card
     */
    RGLDiDocTypePrivilegedIdentityCard = 23,
    /**
     Residence Permit Identity Card
     */
    RGLDiDocTypeResidencePermitIdentityCard = 24,
    /**
     Origin Card
     */
    RGLDiDocTypeOriginCard = 25,
    /**
     Emergency Passport
     */
    RGLDiDocTypeEmergencyPassport = 26,
    /**
     Alien's Passport
     */
    RGLDiDocTypeAliensPassport = 27,
    /**
     Alternative Identity Card
     */
    RGLDiDocTypeAlternativeIdentityCard = 28,
    /**
     Authorization Card
     */
    RGLDiDocTypeAuthorizationCard = 32,
    /**
     Beginner Permit
     */
    RGLDiDocTypeBeginnerPermit = 33,
    /**
     Border Crossing Card
     */
    RGLDiDocTypeBorderCrossingCard = 34,
    /**
     Chauffeur License
     */
    RGLDiDocTypeChauffeurLicense = 35,
    /**
     Chauffeur License under 18
     */
    RGLDiDocTypeChauffeurLicenseUnder18 = 36,
    /**
     Chauffeur License under 21
     */
    RGLDiDocTypeChauffeurLicenseUnder21 = 37,
    /**
     Commercial Driving License
     */
    RGLDiDocTypeCommercialDrivingLicense = 38,
    /**
     Commercial Driving License Instructional Permit
     */
    RGLDiDocTypeCommercialDrivingLicenseInstructionalPermit = 39,
    /**
     Commercial Driving License under 18
     */
    RGLDiDocTypeCommercialDrivingLicenseUnder18 = 40,
    /**
     Commercial Driving License under 21
     */
    RGLDiDocTypeCommercialDrivingLicenseUnder21 = 41,
    /**
     Commercial Indtuction Permit
     */
    RGLDiDocTypeCommercialInstructionPermit = 42,
    /**
     Commercial New Permit
     */
    RGLDiDocTypeCommercialNewPermit = 43,
    /**
     Concealed Carry License
     */
    RGLDiDocTypeConcealedCarryLicense = 44,
    /**
     Concealed Firearm Permit
     */
    RGLDiDocTypeConcealedFirearmPermit = 45,
    /**
     Conditional Driving License
     */
    RGLDiDocTypeConditionalDrivingLicense = 46,
    /**
     Department of Veterans Affairs Identity Card
     */
    RGLDiDocTypeDepartmentOfVeteransAffairsIdentityCard = 47,
    /**
     Diplomatic Driving License
     */
    RGLDiDocTypeDiplomaticDrivingLicense = 48,
    /**
     Driving License
     */
    RGLDiDocTypeDrivingLicense = 49,
    /**
     Driving License Instructional Permit
     */
    RGLDiDocTypeDrivingLicenseInstructionalPermit = 50,
    /**
     Driving License Instructional Permit under 18
     */
    RGLDiDocTypeDrivingLicenseInstructionalPermitUnder18 = 51,
    /**
     Driving License Instructional Permit under 21
     */
    RGLDiDocTypeDrivingLicenseInstructionalPermitUnder21 = 52,
    /**
     Driving License Learners Permit
     */
    RGLDiDocTypeDrivingLicenseLearnersPermit = 53,
    /**
     Driving License Learners Permit under 18
     */
    RGLDiDocTypeDrivingLicenseLearnersPermitUnder18 = 54,
    /**
     Driving License Learners Permit under 21
     */
    RGLDiDocTypeDrivingLicenseLearnersPermitUnder21 = 55,
    /**
     Driving License Novice
     */
    RGLDiDocTypeDrivingLicenseNovice = 56,
    /**
     Driving License Novice under 18
     */
    RGLDiDocTypeDrivingLicenseNoviceUnder18 = 57,
    /**
     Driving License Novice under 21
     */
    RGLDiDocTypeDrivingLicenseNoviceUnder21 = 58,
    /**
     Driving License Registered Offender
     */
    RGLDiDocTypeDrivingLicenseRegisteredOffender = 59,
    /**
     Driving License Redticted under 18
     */
    RGLDiDocTypeDrivingLicenseRestrictedUnder18 = 60,
    /**
     Driving License Redticted under 21
     */
    RGLDiDocTypeDrivingLicenseRestrictedUnder21 = 61,
    /**
     Driving License Temporary Visitor
     */
    RGLDiDocTypeDrivingLicenseTemporaryVisitor = 62,
    /**
     Driving License Temporary Visitor under 18
     */
    RGLDiDocTypeDrivingLicenseTemporaryVisitorUnder18 = 63,
    /**
     Driving License Temporary Visitor under 21
     */
    RGLDiDocTypeDrivingLicenseTemporaryVisitorUnder21 = 64,
    /**
     Driving License under 18
     */
    RGLDiDocTypeDrivingLicenseUnder18 = 65,
    /**
     Driving License under 21
     */
    RGLDiDocTypeDrivingLicenseUnder21 = 66,
    /**
     Employment Driving Permit
     */
    RGLDiDocTypeEmploymentDrivingPermit = 67,
    /**
     Enhanced Chauffeur License
     */
    RGLDiDocTypeEnhancedChauffeurLicense = 68,
    /**
     Enhanced Chauffeur License under 18
     */
    RGLDiDocTypeEnhancedChauffeurLicenseUnder18 = 69,
    /**
     Enhanced Chauffeur License under 21
     */
    RGLDiDocTypeEnhancedChauffeurLicenseUnder21 = 70,
    /**
     Enhanced Commercial Driving License
     */
    RGLDiDocTypeEnhancedCommercialDrivingLicense = 71,
    /**
     Enhanced Driving License
     */
    RGLDiDocTypeEnhancedDrivingLicense = 72,
    /**
     Enhanced Driving License under 18
     */
    RGLDiDocTypeEnhancedDrivingLicenseUnder18 = 73,
    /**
     Enhanced Driving License under 21
     */
    RGLDiDocTypeEnhancedDrivingLicenseUnder21 = 74,
    /**
     Enhanced Identity Card
     */
    RGLDiDocTypeEnhancedIdentityCard = 75,
    /**
     Enhanced Identity Card under 18
     */
    RGLDiDocTypeEnhancedIdentityCardUnder18 = 76,
    /**
     Enhanced Identity Card under 21
     */
    RGLDiDocTypeEnhancedIdentityCardUnder21 = 77,
    /**
     Enhanced Operators License
     */
    RGLDiDocTypeEnhancedOperatorsLicense = 78,
    /**
     Firearms Permit
     */
    RGLDiDocTypeFirearmsPermit = 79,
    /**
     Full Provisional License
     */
    RGLDiDocTypeFullProvisionalLicense = 80,
    /**
     Full Provisional License under 18
     */
    RGLDiDocTypeFullProvisionalLicenseUnder18 = 81,
    /**
     Full Provisional License under 21
     */
    RGLDiDocTypeFullProvisionalLicenseUnder21 = 82,
    /**
     Geneva Conventions Identity Card
     */
    RGLDiDocTypeGenevaConventionsIdentityCard = 83,
    /**
     Graduated Driving License under 18
     */
    RGLDiDocTypeGraduatedDrivingLicenseUnder18 = 84,
    /**
     Graduated Driving License under 21
     */
    RGLDiDocTypeGraduatedDrivingLicenseUnder21 = 85,
    /**
     Graduated Indtuction Permit under 18
     */
    RGLDiDocTypeGraduatedIndtuctionPermitUnder18 = 86,
    /**
     Graduated Indtuction Permit under 21
     */
    RGLDiDocTypeGraduatedIndtuctionPermitUnder21 = 87,
    /**
     Graduated License under 18
     */
    RGLDiDocTypeGraduatedLicenseUnder18 = 88,
    /**
     Graduated License under 21
     */
    RGLDiDocTypeGraduatedLicenseUnder21 = 89,
    /**
     Handgun Carry Permit
     */
    RGLDiDocTypeHandgunCarryPermit = 90,
    /**
     Identity and Privilege Card
     */
    RGLDiDocTypeIdentityAndPrivilegeCard = 91,
    /**
     Identity Card Mobility Impaired
     */
    RGLDiDocTypeIdentityCardMobilityImpaired = 92,
    /**
     Identity Card Registered Offender
     */
    RGLDiDocTypeIdentityCardRegisteredOffender = 93,
    /**
     Identity Card Temporary Visitor
     */
    RGLDiDocTypeIdentityCardTemporaryVisitor = 94,
    /**
     Identity Card Temporary Visitor under 18
     */
    RGLDiDocTypeIdentityCardTemporaryVisitorUnder18 = 95,
    /**
     Identity Card Temporary Visitor under 21
     */
    RGLDiDocTypeIdentityCardTemporaryVisitorUnder21 = 96,
    /**
     Identity Card under 18
     */
    RGLDiDocTypeIdentityCardUnder18 = 97,
    /**
     Identity Card under 21
     */
    RGLDiDocTypeIdentityCardUnder21 = 98,
    /**
     Ignition Interlock Permit
     */
    RGLDiDocTypeIgnitionInterlockPermit = 100,
    /**
     Immigrant Visa
     */
    RGLDiDocTypeImmigrantVisa = 101,
    /**
     Indtuction Permit
     */
    RGLDiDocTypeIndtuctionPermit = 102,
    /**
     Indtuction Permit under 18
     */
    RGLDiDocTypeIndtuctionPermitUnder18 = 103,
    /**
     Indtuction Permit under 21
     */
    RGLDiDocTypeIndtuctionPermitUnder21 = 104,
    /**
     Interim Driving License
     */
    RGLDiDocTypeInterimDrivingLicense = 105,
    /**
     Interim Identity Card
     */
    RGLDiDocTypeInterimIdentityCard = 106,
    /**
     Intermediate Driving License
     */
    RGLDiDocTypeIntermediateDrivingLicense = 107,
    /**
     Intermediate Driving License under 18
     */
    RGLDiDocTypeIntermediateDrivingLicenseUnder18 = 108,
    /**
     Intermediate Driving License under 21
     */
    RGLDiDocTypeIntermediateDrivingLicenseUnder21 = 109,
    /**
     Junior Driving License
     */
    RGLDiDocTypeJuniorDrivingLicense = 110,
    /**
     Learner Instructional Permit
     */
    RGLDiDocTypeLearnerInstructionalPermit = 111,
    /**
     Learner License
     */
    RGLDiDocTypeLearnerLicense = 112,
    /**
     Learner License under 18
     */
    RGLDiDocTypeLearnerLicenseUnder18 = 113,
    /**
     Learner License under 21
     */
    RGLDiDocTypeLearnerLicenseUnder21 = 114,
    /**
     Learner Permit
     */
    RGLDiDocTypeLearnerPermit = 115,
    /**
     Learner Permit under 18
     */
    RGLDiDocTypeLearnerPermitUnder18 = 116,
    /**
     Learner Permit under 21
     */
    RGLDiDocTypeLearnerPermitUnder21 = 117,
    /**
     Limited License
     */
    RGLDiDocTypeLimitedLicense = 118,
    /**
     Limited Permit
     */
    RGLDiDocTypeLimitedPermit = 119,
    /**
     Limited Term Driving License
     */
    RGLDiDocTypeLimitedTermDrivingLicense = 120,
    /**
     Limited Term Identity Card
     */
    RGLDiDocTypeLimitedTermIdentityCard = 121,
    /**
     Liquor Identity Card
     */
    RGLDiDocTypeLiquorIdentityCard = 122,
    /**
     New Permit
     */
    RGLDiDocTypeNewPermit = 123,
    /**
     New Permit under 18
     */
    RGLDiDocTypeNewPermitUnder18 = 124,
    /**
     New Permit under 21
     */
    RGLDiDocTypeNewPermitUnder21 = 125,
    /**
     Non-US Citizen Driving License
     */
    RGLDiDocTypeNonUsCitizenDrivingLicense = 126,
    /**
     Occupational Driving License
     */
    RGLDiDocTypeOccupationalDrivingLicense = 127,
    /**
     Oneida Tribe of Indians Identity Card
     */
    RGLDiDocTypeOneidaTribeOfIndiansIdentityCard = 128,
    /**
     Operator License
     */
    RGLDiDocTypeOperatorLicense = 129,
    /**
     Operator License under 18
     */
    RGLDiDocTypeOperatorLicenseUnder18 = 130,
    /**
     Operator License under 21
     */
    RGLDiDocTypeOperatorLicenseUnder21 = 131,
    /**
     Permanent Driving License
     */
    RGLDiDocTypePermanentDrivingLicense = 132,
    /**
     Permit to Re-enter
     */
    RGLDiDocTypePermitToReEnter = 133,
    /**
     Probationary Auto License
     */
    RGLDiDocTypeProbationaryAutoLicense = 134,
    /**
     Probationary Auto License under 18
     */
    RGLDiDocTypeProbationaryDrivingLicenseUnder18 = 135,
    /**
     Probationary Auto License under 21
     */
    RGLDiDocTypeProbationaryDrivingLicenseUnder21 = 136,
    /**
     Probationary Vehicle Salesperson License
     */
    RGLDiDocTypeProbationaryVehicleSalespersonLicense = 137,
    /**
     Provisional Driving License
     */
    RGLDiDocTypeProvisionalDrivingLicense = 138,
    /**
     Provisional Driving License under 18
     */
    RGLDiDocTypeProvisionalDrivingLicenseUnder18 = 139,
    /**
     Provisional Driving License under 21
     */
    RGLDiDocTypeProvisionalDrivingLicenseUnder21 = 140,
    /**
     Provisional License
     */
    RGLDiDocTypeProvisionalLicense = 141,
    /**
     Provisional License under 18
     */
    RGLDiDocTypeProvisionalLicenseUnder18 = 142,
    /**
     Provisional License under 21
     */
    RGLDiDocTypeProvisionalLicenseUnder21 = 143,
    /**
     Public Passenger Chauffeur License
     */
    RGLDiDocTypePublicPassengerChauffeurLicense = 144,
    /**
     Racing and Gaming Comission Card
     */
    RGLDiDocTypeRacingAndGamingComissionCard = 145,
    /**
     Refugee Travel Document
     */
    RGLDiDocTypeRefugeeTravelDocument = 146,
    /**
     Renewal Permit
     */
    RGLDiDocTypeRenewalPermit = 147,
    /**
     Restricted Commercial Driving License
     */
    RGLDiDocTypeRestrictedCommercialDrivingLicense = 148,
    /**
     Restricted Driving License
     */
    RGLDiDocTypeRestrictedDrivingLicense = 149,
    /**
     Restricted Permit
     */
    RGLDiDocTypeRestrictedPermit = 150,
    /**
     Seasonal Permit
     */
    RGLDiDocTypeSeasonalPermit = 151,
    /**
     Seasonal Resident Identity Card
     */
    RGLDiDocTypeSeasonalResidentIdentityCard = 152,
    /**
     Senior Citizen Identity Card
     */
    RGLDiDocTypeSeniorCitizenIdentityCard = 153,
    /**
     Sex Offender
     */
    RGLDiDocTypeSexOffender = 154,
    /**
     Social Security Card
     */
    RGLDiDocTypeSocialSecurityCard = 155,
    /**
     Temporary Driving License
     */
    RGLDiDocTypeTemporaryDrivingLicense = 156,
    /**
     Temporary Driving License under 18
     */
    RGLDiDocTypeTemporaryDrivingLicenseUnder18 = 157,
    /**
     Temporary Driving License under 21
     */
    RGLDiDocTypeTemporaryDrivingLicenseUnder21 = 158,
    /**
     Temporary Identity Card
     */
    RGLDiDocTypeTemporaryIdentityCard = 159,
    /**
     Temporary Instruction Permit Identity Card
     */
    RGLDiDocTypeTemporaryInstructionPermitIdentityCard = 160,
    /**
     Temporary Instruction Permit Identity Card under 18
     */
    RGLDiDocTypeTemporaryInstructionPermitIdentityCardUnder18 = 161,
    /**
     Temporary Instruction Permit Identity Card under 21
     */
    RGLDiDocTypeTemporaryInstructionPermitIdentityCardUnder21 = 162,
    /**
     Temporary Visitor Driving License
     */
    RGLDiDocTypeTemporaryVisitorDrivingLicense = 163,
    /**
     Temporary Visitor Driving License under 18
     */
    RGLDiDocTypeTemporaryVisitorDrivingLicenseUnder18 = 164,
    /**
     Temporary Visitor Driving License under 21
     */
    RGLDiDocTypeTemporaryVisitorDrivingLicenseUnder21 = 165,
    /**
     Uniformed Services Identity Card
     */
    RGLDiDocTypeUniformedServicesIdentityCard = 166,
    /**
     Vehicle Salesperson License
     */
    RGLDiDocTypeVehicleSalespersonLicense = 167,
    /**
     Worker Identification Credential
     */
    RGLDiDocTypeWorkerIdentificationCredential = 168,
    /**
     Commercial Driving License Novice
     */
    RGLDiDocTypeCommercialDrivingLicenseNovice = 169,
    /**
     Commercial Driving License Novice under 18
     */
    RGLDiDocTypeCommercialDrivingLicenseNoviceUnder18 = 170,
    /**
     Commercial Driving License Novice under 21
     */
    RGLDiDocTypeCommercialDrivingLicenseNoviceUnder21 = 171,
    /**
     Passport Card
     */
    RGLDiDocTypePassportCard = 172,
    /**
     Permanent Resident Card
     */
    RGLDiDocTypePermanentResidentCard = 173,
    /**
     Personal Identification Verification
     */
    RGLDiDocTypePersonalIdentificationVerification = 174,
    /**
     Temporary Operator License
     */
    RGLDiDocTypeTemporaryOperatorLicense = 175,
    /**
     Driving License under 19
     */
    RGLDiDocTypeDrivingLicenseUnder19 = 176,
    /**
     Identity Card under 19
     */
    RGLDiDocTypeIdentityCardUnder19 = 177,
    /**
     Visa
     */
    RGLDiDocTypeVisa = 178,
    /**
     Temporary Passport
     */
    RGLDiDocTypeTemporaryPassport = 179,
    /**
     Voting Card
     */
    RGLDiDocTypeVotingCard = 180,
    /**
     Health Card
     */
    RGLDiDocTypeHealthCard = 181,
    /**
     Certificate of Citizenship
     */
    RGLDiDocTypeCertificateOfCitizenship = 182,
    /**
     Address Card
     */
    RGLDiDocTypeAddressCard = 183,
    /**
     Airport Immigration Card
     */
    RGLDiDocTypeAirportImmigrationCard = 184,
    /**
     Alien Regidtation Card
     */
    RGLDiDocTypeAlienRegistrationCard = 185,
    /**
     APEH Card
     */
    RGLDiDocTypeAPEHCard = 186,
    /**
     Coupon To Driving License
     */
    RGLDiDocTypeCouponToDrivingLicense = 187,
    /**
     Crew Member Certificate
     */
    RGLDiDocTypeCrewMemberCertificate = 188,
    /**
     Document for Return
     */
    RGLDiDocTypeDocumentForReturn = 189,
    /**
     E-Card
     */
    RGLDiDocTypeECard = 190,
    /**
     Employment Card
     */
    RGLDiDocTypeEmploymentCard = 191,
    /**
     HKSAR Immigration Form
     */
    RGLDiDocTypeHKSARImmigrationForm = 192,
    /**
     Immigrant Card
     */
    RGLDiDocTypeImmigrantCard = 193,
    /**
     Labour Card
     */
    RGLDiDocTypeLabourCard = 194,
    /**
     Laissez Passer
     */
    RGLDiDocTypeLaissezPasser = 195,
    /**
     Lawyer Identity Certificate
     */
    RGLDiDocTypeLawyerIdentityCertificate = 196,
    /**
     License Card
     */
    RGLDiDocTypeLicenseCard = 197,
    /**
     Passport Stateless
     */
    RGLDiDocTypePassportStateless = 198,
    /**
     Passport Child
     */
    RGLDiDocTypePassportChild = 199,
    /**
     Passport Consular
     */
    RGLDiDocTypePassportConsular = 200,
    /**
     Passport Diplomatic Service
     */
    RGLDiDocTypePassportDiplomaticService = 201,
    /**
     Passport Official
     */
    RGLDiDocTypePassportOfficial = 202,
    /**
     Passport Provisional
     */
    RGLDiDocTypePassportProvisional = 203,
    /**
     Passport Special
     */
    RGLDiDocTypePassportSpecial = 204,
    /**
     Permission to the Local Border Traffic
     */
    RGLDiDocTypePermissionToTheLocalBorderTraffic = 205,
    /**
     Registration Certificate
     */
    RGLDiDocTypeRegistrationCertificate = 206,
    /**
     SEDESOL Card
     */
    RGLDiDocTypeSEDESOLCard = 207,
    /**
     Social Card
     */
    RGLDiDocTypeSocialCard = 208,
    /**
     TB Card
     */
    RGLDiDocTypeTBCard = 209,
    /**
     Vehicle Passport
     */
    RGLDiDocTypeVehiclePassport = 210,
    /**
     W Document
     */
    RGLDiDocTypeWDocument = 211,
    /**
     Diplomatic Identity Card
     */
    RGLDiDocTypeDiplomaticIdentityCard = 212,
    /**
     Consular Identity Card
     */
    RGLDiDocTypeConsularIdentityCard = 213,
    /**
     Income Tax Card
     */
    RGLDiDocTypeIncomeTaxCard = 214,
    /**
     Residence Permit
     */
    RGLDiDocTypeResidencePermit = 215,
    /**
     Document of Identity
     */
    RGLDiDocTypeDocumentOfIdentity = 216,
    /**
     Border Crossing Permit
     */
    RGLDiDocTypeBorderCrossingPermit = 217,
    /**
     Passport Limited Validity
     */
    RGLDiDocTypePassportLimitedValidity = 218,
    /**
     SIM Card
     */
    RGLDiDocTypeSIMCard = 219,
    /**
     Tax Card
     */
    RGLDiDocTypeTaxCard = 220,
    /**
     Company Card
     */
    RGLDiDocTypeCompanyCard = 221,
    /**
     Domestic Passport
     */
    RGLDiDocTypeDomesticPassport = 222,
    /**
     Identity Certificate
     */
    RGLDiDocTypeIdentityCertificate = 223,
    /**
     Resident Id Card
     */
    RGLDiDocTypeResidentIdCard = 224,
    /**
     Armed Forces Identity Card
     */
    RGLDiDocTypeArmedForcesIdentityCard = 225,
    /**
     Professional Card
     */
    RGLDiDocTypeProfessionalCard = 226,
    /**
     Registration Stamp
     */
    RGLDiDocTypeRegistrationStamp = 227,
    /**
     Driver Card
     */
    RGLDiDocTypeDriverCard = 228,
    /**
     Driver Training Certificate
     */
    RGLDiDocTypeDriverTrainingCertificate = 229,
    /**
     Qualification Driving License
     */
    RGLDiDocTypeQualificationDrivingLicense = 230,
    /**
     Membership Card
     */
    RGLDiDocTypeMembershipCard = 231,
    /**
     Public Vehicle Driver Authority Card
     */
    RGLDiDocTypePublicVehicleDriverAuthorityCard = 232,
    /**
     Marine License
     */
    RGLDiDocTypeMarineLicense = 233,
    /**
     Temporary Learner Driving License
     */
    RGLDiDocTypeTemporaryLearnerDrivingLicense = 234,
    /**
     Temporary Commercial Driving License
     */
    RGLDiDocTypeTemporaryCommercialDrivingLicense = 235,
    /**
     Interim Instructional Permit
     */
    RGLDiDocTypeInterimInstructionalPermit = 236,
    /**
     Certificate of Competency
     */
    RGLDiDocTypeCertificateOfCompetency = 237,
    /**
     Certificate of Proficiency
     */
    RGLDiDocTypeCertificateOfProficiency = 238,
    RGLDiDocTypeTradeLicense = 239,
    RGLDiDocTypePassportPage = 240,
    RGLDiDocTypeInvoice = 241,
    RGLDiDocTypePassengerLocatorForm = 242,
} NS_SWIFT_NAME(DiDocType);

/// Defining the geometric format of documents in accordance with ISO / IEC 7810
typedef NS_ENUM(NSInteger, RGLDocFormat) {
  /// ID1 document format.
  RGLDocFormatID1 = 0,
  /// ID2 document format.
  RGLDocFormatID2 = 1,
  /// ID3 document format.
  RGLDocFormatID3 = 2,
  /// Undefined document format.
  RGLDocFormatNON = 3,
  /// A4 document format.
  RGLDocFormatA4 = 4,
  /// ID3 double document format.
  RGLDocFormatID3_x2 = 5,
  /// ID2 Turkey document format.
  RGLDocFormatID2_Turkey = 6,
  /// ID1 format document rotated 90 degrees.
  RGLDocFormatID1_90 = 10,
  /// ID1 format document rotated 180 degrees.
  RGLDocFormatID1_180 = 11,
  /// ID1 format document rotated 270 degrees.
  RGLDocFormatID1_270 = 12,
  /// ID2 format document rotated 180 degrees.
  RGLDocFormatID2_180 = 13,
  /// ID3 format document rotated 180 degrees.
  RGLDocFormatID3_180 = 14,
  /// Arbitrary format.
  RGLDocFormatCustom = 1000,
  /// Photo format.
  RGLDocFormatPhoto = 1001,
  /// Flexible format. Standard formats can be resized during cropping, depending on various factors: light, background etc.
  RGLDocFormatFlexible  = 1002,
  /// Unknown format.
  RGLDocFormatUnknown = -1,
} NS_SWIFT_NAME(DocFormat);

NS_SWIFT_NAME(DocumentReaderDocumentType)
@interface RGLDocumentReaderDocumentType : NSObject

/**
 Document type name
 */
@property(nonatomic, strong, readonly, nullable) NSString *name;
/**
 Document type numeric code
 */
@property(nonatomic, assign, readonly) NSInteger documentID;
/**
 Document issuing country ICAO code
 */
@property(nonatomic, strong, readonly, nullable) NSString *ICAOCode;
/**
 An array of IRS document identifiers
 */
@property(nonatomic, strong, readonly, nonnull) NSArray<NSNumber *> *FDSID;
/**
 Document type, one of RGLDiDocType enumeration values
 */
@property(nonatomic, assign, readonly) RGLDiDocType dType;
/**
 Document format, one of RGLDocFormat enumeration values
 */
@property(nonatomic, assign, readonly) RGLDocFormat dFormat;
/**
 Flag for MRZ presence on a document
 */
@property(nonatomic, assign, readonly) BOOL dMRZ;
/**
 Document description text
 */
@property(nonatomic, strong, readonly, nullable) NSString *dDescription;
/**
 Document issue year
 */
@property(nonatomic, strong, readonly, nullable) NSString *dYear;
/**
 Document issuing country name
 */
@property(nonatomic, strong, readonly, nullable) NSString *dCountryName;
/**
 An index of the document page whence results are received
 */
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end
