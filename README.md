# Mauritania Digital ID Pilot (Mauritania eID)


[![General badge](https://img.shields.io/badge/✔︎version-1.1.0-blue.svg)](https://shields.io/)
[![General badge](https://img.shields.io/badge/⚠️License-GPL-orange.svg)](https://shields.io/)

![architecture](Media/mtnima.png) ![architecture](Media/UNDP-s.png) 
## Description and Framework of the project

This GitHub repository hosts the source code of the different system components of the Mauritania Digital ID Pilot; A project that aims to develop a mobile application for password less login using a secure, user-friendly, and privacy-preserving digital identity system. The app allows users to enroll by scanning the demographic data from their ID card and performing a verification with a liveness-based face match.

Once enrolled, users can easily log in to various websites that support this password less login methodology, eliminating the need to remember and manage multiple passwords. 
The project This approach supports the goals of the Mauritanian government's "Digital Agenda 2022-2025" by providing inclusive access to government services for all citizens and residents, promoting economic growth, and enhancing efficiency gains while improving cybersecurity and integrity in digital transactions.

By leveraging advanced security measures and cutting-edge technologies, this pilot project paves the road to the creation of a complete digital identity solution that enhances trust and reduces the risks of fraud while having a broader accessibility. A system that will benefit all Mauritanians, including the most vulnerable, by providing a secure and seamless digital experience that saves time and money while improving the quality and accessibility of public services.

## Demo

The following demo uses the eID app to login to the "Khidmaty" Portal (currently under developpement itself),


https://user-images.githubusercontent.com/28960489/230099915-5bdf7f66-ab82-49e8-bf89-596736f4ed18.mp4

## Brief architecture of the project : 

The system of this project relies on three main ends that interact with each other : 

  * The Mobile App : it is the visual part of the project that the user can use and iteract with. aside for the base code, the mobile interacts with the backend and have some integrated proprietary SDK that are used for the OCR reading and the facematch liveness check.
  
  * The middleware of two main components : 
  
    * The backend which is the maestro of the different interconnections  in the project it provides API to be used by the mobile app in order to perform the diffrent functionalities. 

    * The IdP (Keycloack) : The keycloack IdP is used to provide authentication and authorization services for all the integrated clients, that are compatible with the Open ID Connect.
  
  * The client : any client that is comptible with Open ID Connect can be integrated in the IdP to be able to use the app as a login option for the users, (simply the option to login with digital IdP will be available on the login page, the same way conventional social login options appear.)
    
**The following image shows a simplified archtecture of the project :**

![architecture](Media/simplified_architecture.svg)

## The code in this repository : 
[![General badge](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=java&logoColor=white)](https://shields.io/) 
[![General badge](https://img.shields.io/badge/SpringBoot-6DB33F?style=for-the-badge&logo=Spring&logoColor=white)](https://shields.io/) 
[![General badge](https://img.shields.io/badge/Swift-FA7343?style=for-the-badge&logo=swift&logoColor=white)](https://shields.io/) 

This repository contains the code for the different componenet of the project, each component is relatively independent and can be installed/deployed in a standalone mode as all the communication happens through API calls.

The components present in this repository include : 

* The android App: the code for the android version of the app developped in Java.
* the iOS Mobile App : the code for the iOS version of the App developped in Swift.
* The Keycloak IdP : Contains a customised version of the openSource Identity management application which is used to connect the project with other different systems that are compatible with the OIDC. the base code is in JAVA.
* The Backend : contains the code of the backend of the project including the the different APIs,Developped in SpringBoot(Java)

each component has it's own documentation included in it's folder for any further required details.

## Various relevant technical details : 

### MOSIP Compliance :
The main functionality of MOSIP mobile application are as below: 

#### Generating and storing of credentials :

As per  [MOSIP](https://mosip.io/about.php) (Modular Open Source Identity Platform) website, a resident can generate a Verifiable Credential(VC) by either using a UIN or a VID. Also, they can generate credentials for their family or friends on the same phone.
   
The Mauritania eID app is allowing user for generating a credential based on Mauritania ID card and storing the credential in a secure container called Cryptograph, which is the credential in Mauritania case. The cryptograph contains the details of the user such as name, date of birth etc and it contains a face template which is the feature points of the face image and is irreversible, meaning the face image cannot be reconstructed from face template. The face template provides a strong identity binding to the user which makes the ID stronger and in case even if the phone is stolen, the ID created can’t be misused as the verification will fail.

The cryptograph contains the digital signature, which makes it tamper proof and authentic.

Tomorrow if some other vendor wants to replace the cryptograph with their technology its very much possible.

#### Sharing of credentials :

As per MOSIP website, the credentials are shared in peer-to-peer model with another instance of the application. The data exchange between devices is done using Google Nearby Connections API. This API uses a combination of Bluetooth (BT), Bluetooth Low energy (BLE) and Wifi to achieve seamless, low-latency, high-throughput communications without requiring pairing of devices. The user has the option for selective disclosure of the PII data.

In case of Mauritania eID app, the provision has been made for selective disclosure as we are displaying to the user what all data are shared with user, so it’s only a matter of making the
option available to the user.

During user authentication, liveness detection is performed, to make sure that somebody is not using your photo to gain access to the system.

And before sharing the credential details with a third party, user authentication is performed to make sure that the owner is the presenter and thereby preventing fraudulent practices.



### Face liveness detection : 

The eID app is performing face liveness first and if the liveness check is successful it performs the
face matching.

1. We are using passive liveness and not active liveness. Regarding active liveness, it is easy to spoof head movements using animation software. Our passive liveness capability works without requiring it.

2. A separate validation test for the Mobile SDK has not been conducted, but it uses the same algorithm for a version that passed [iBeta](https://www.ibeta.com/biometric-testing/) with zero errors for impostors getting through and zero errors for genuine users getting rejected.

3. Accuracy of the FaceMatch detection,

#### NIST Ranking : 
NIST FRVT 1:1 assesses face recognition performance for verification (1:1) applications. It evaluates the performance and accuracy of templates. NIST report only includes companies with the 3 modalities offering (face, finger and iris). NIST Performance
* In terms of improved accuracy, the used algorithm clocks an FNMR of 0.0034 @ FMR =
0.000001.
* Our algorithm also demonstrated better performance in terms of lower FMR in FRVT tests
verifying effects in Face Recognition of Imposters paired together with varying
demographics, age, and gender.

The Face Match SDK : 

* Provides enhanced capabilities of highly accurate face detection, capturing standards
compliant images and providing on-device recognition functions supported by liveness
detection technology for fraud prevention.
* Enables fast and secure Digital Onboarding and verification by face within seconds, just by
using the camera on a mobile device.
* The Face recognition algorithm, powered by Al and deep learning, has been trained on
diverse databases, and as such, it remains invariant across different nations, ages and
genders, to demonstrate higher accuracies.
* Real-time field deployments have demonstrated very good performance when matching
poor quality face images or facial images taken at different points in time (5-10 years or
more)


#### Versions used of the proprietary solutions : 

These SDK are dependencies used in order to perform the different AI based functionalities : 
all theses SDK are proprietary solutions easily permutable with other solutions that perform the same tasks whenever needed be.

| SDK | Android version | iOS version |
|---|---|---|
| Regula SDK | 6.6.8231 | 6.6.2753 |
| AirSnap Face | 1.1.3 | 1.1.1 |
| Ondevice Liveness Module | 1.36.0 | 1.36.0 |
| Omnimatch BioSDK | 4.0.0.978 | 4.0.0.946 |
| T5-Cryptograph | 1.0.0.5 | 1.0.0.8 |



## Support
Tell people where they can go to for help. It can be any combination of an issue tracker, a chat room, an email address, etc.

## Roadmap
If you have ideas for releases in the future, it is a good idea to list them in the README.

## Contributing
State if you are open to contributions and what your requirements are for accepting them.

For people who want to make changes to your project, it's helpful to have some documentation on how to get started. Perhaps there is a script that they should run or some environment variables that they need to set. Make these steps explicit. These instructions could also be useful to your future self.

You can also document commands to lint the code or run tests. These steps help to ensure high code quality and reduce the likelihood that the changes inadvertently break something. Having instructions for running tests is especially helpful if it requires external setup, such as starting a Selenium server for testing in a browser.

## Authors and acknowledgment
Show your appreciation to those who have contributed to the project.

## License
Our recommended Licence is Eclipse Public License - v 2.0: This is a slightly more restrictive license that allows for reuse, modification, and distribution of the licensed software, as long as the license terms are met. It requires any modifications or derivative works to be released under the same license, which can be seen as a slightly more restrictive condition.

Check the software bill of material in the software bill of materials in the Media folder for more info
