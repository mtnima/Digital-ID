//
//  SettingViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 19/01/23.
//

import UIKit
import ActionSheetPicker_3_0
class SettingViewController: BaseViewController {

    @IBOutlet weak var versionLabel: UILabel!
    @IBOutlet weak var settingTableView: UITableView!
    @IBOutlet weak var LanguagetextField: UITextField!
    let generalCellContents = ["LANGUAGE","CONTACT_US"]
    let securityCellContents = ["CHANGE_PIN","PRIVACY_POLICY","LOG_OUT"]
    let languagePickerValues = ["English_en":"English", "French_fr":"French"]
    let languageKeys = ["English_en","French_fr"]
    var gradePicker: UIPickerView!
    var languageSelectedKey : String?
    override func viewDidLoad() {
        super.viewDidLoad()
        self.settingTableView.reloadData()
        gradePicker = UIPickerView()

        gradePicker.dataSource = self
        gradePicker.delegate = self

        LanguagetextField.inputView = gradePicker
        LanguagetextField.text = languagePickerValues["en"]
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)
        // Do any additional setup after loading the view.
    }
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.navigationBar.isHidden = true
        versionLabel.text = version()
    }
    override func viewWillDisappear(_ animated: Bool) {
        self.navigationController?.navigationBar.isHidden = true
        
    }
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */
    
    @objc func receiveLanguageChangedNotification(notification:NSNotification) {
        if notification.name == kNotificationLanguageChanged {
            self.settingTableView.reloadData()
        }
    }
    


}

extension SettingViewController:UIPickerViewDelegate, UIPickerViewDataSource {
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return languagePickerValues[languageKeys[row]]
    }
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int{
        return languagePickerValues.count
    }
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        let index = IndexPath(row: 0, section: 0)
        languageSelectedKey = languageKeys[row]
        self.showConfirmationAlert(with: "", andWith: Localization(TranslationConstants.CHANGE_LANGUAGE))
        
        //"English_en", "French_fr"
        
        self.view.endEditing(true)
    }
    

}

extension SettingViewController:UITableViewDataSource, UITableViewDelegate {
    func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if section == 0{
            return 2
        }
        else{
            return 3
        }
    }
    func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        switch section {
        case 0:
            return Localization(TranslationConstants.GENERAL)
        default :
            return Localization(TranslationConstants.SECURITY)
        }
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "setting", for: indexPath) as! SettingTableViewCell
        cell.backgroundColor = .clear
        cell.optionValue.isHidden = true
        switch indexPath.section {
        case 0:
            if indexPath.row == 0 {
                cell.optionValue.text = Localization(TranslationConstants.SELECTED_LANGUAGE)//UserDefaults.standard.getAppLanguage() == "French_fr" ? "French":"English"
                cell.optionValue.isHidden = false
            }
            cell.optionLabel.text = Localization(generalCellContents[indexPath.row])
        default:
//            if indexPath.row == 3 {
//                cell.optionLabel.text = version()
//                return cell
//            }
            cell.optionLabel.text = Localization(securityCellContents[indexPath.row])
        }
        return cell
    }
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 50
    }
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        if indexPath.section == 0 && indexPath.row == 0{
            self.LanguagetextField.becomeFirstResponder()
        }
        if indexPath.section == 1 && indexPath.row == 2{
            //logout
            self.showConfirmationAlert(with: Localization(""), andWith: Localization(TranslationConstants.LOG_OUT_CONFIRMATION))
//            clearController()
        }
    }
    func clearController(){
        UserDefaults.standard.clearSession()
        guard let navigationController = self.navigationController else { return }
        var navigationArray = navigationController.viewControllers // To get all UIViewController stack as Array
        let temp = navigationArray.last
        navigationArray.removeAll()
        let homeModule = HomeRouter.createTutorialModule()
//        self.navigationController?.pushViewController(homeModule,animated: true)

        navigationArray.append(homeModule) //To remove all previous UIViewController except the last one
        self.navigationController?.viewControllers = navigationArray

    }
    
    func showConfirmationAlert(with tittle:String?, andWith message:String?){
        let refreshAlert = UIAlertController(title: tittle, message: message, preferredStyle: UIAlertController.Style.alert)

        refreshAlert.addAction(UIAlertAction(title: Localization(TranslationConstants.OK), style: .default, handler: { (action: UIAlertAction!) in
            self.LanguagetextField.resignFirstResponder()
            if refreshAlert.message == Localization(TranslationConstants.LOG_OUT_CONFIRMATION){
                self.clearController()
            }
            else{
                self.LanguagetextField.resignFirstResponder()
                let index = IndexPath(row: 0, section: 0)
                let cell = self.settingTableView.cellForRow(at: index) as? SettingTableViewCell
                if let lang = self.languageSelectedKey{
                    cell?.optionValue.text = Localization(TranslationConstants.SELECTED_LANGUAGE)
                _ = SetLanguage(lang)
                UserDefaults.standard.setAppLanguage(withLang: lang)
                self.settingTableView.reloadData()
                
             }
            }
        }))

        refreshAlert.addAction(UIAlertAction(title: Localization(TranslationConstants.CANCEL), style: .cancel, handler: { (action: UIAlertAction!) in
              print("Handle Cancel Logic here")
        }))

        present(refreshAlert, animated: true, completion: nil)

    }
    func version() -> String {
        let dictionary = Bundle.main.infoDictionary!
        let version = dictionary["CFBundleShortVersionString"] as! String
        let build = dictionary["CFBundleVersion"] as! String
        return "Version - \(version)(\(build))"
    }
    
}
