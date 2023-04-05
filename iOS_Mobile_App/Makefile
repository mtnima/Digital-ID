OUTPUT_APP = /Mauritania/build
IPA_ARCHIVE_NAME := ios_digital_id.xcarchive
IPA_ARCHIVE_FOLDER := ios_digital_id


build: $(OUTPUT_APP)

$(OUTPUT_APP):
	security unlock-keychain -p qGwsE6j3 ~/Library/Keychains/login.keychain
	xcodebuild -workspace Mauritania.xcworkspace -scheme Mauritania -archivePath ios_digital_id.xcarchive archive
	
	xcodebuild -exportArchive -archivePath ios_digital_id.xcarchive -exportPath ios_digital_id -exportOptionsPlist ExportOptions.plist
	
	xcrun altool --upload-app -f ios_digital_id/Mauritania.ipa -t iOS -u yuvraj.kale@tech5-sa.com -p ykbd-cfqu-atwn-twuu --verbose

clean:
	rm -Rf $(IPA_ARCHIVE_NAME)
	rm -Rf $(IPA_ARCHIVE_FOLDER)

