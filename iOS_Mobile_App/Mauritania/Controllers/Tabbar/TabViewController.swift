//
//  TabViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 19/01/23.
//

import UIKit

class TabViewController: UITabBarController {

    override func viewDidLoad() {
        super.viewDidLoad()
        self.selectedIndex = 1
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)

        let tabBarItems = tabBar.items! as [UITabBarItem]
        tabBarItems[0].title = Localization(TranslationConstants.SCANNER)
        tabBarItems[1].title = Localization(TranslationConstants.HOME)
        tabBarItems[2].title = Localization(TranslationConstants.SETTING)
        tabBarItems[0].image = UIImage(named: "Scanner")
        tabBarItems[1].image = UIImage(named: "Home")
        tabBarItems[2].image = UIImage(named: "Setting")
        // Do any additional setup after loading the view.
    }
    
    @objc func receiveLanguageChangedNotification(notification:NSNotification) {
        if notification.name == kNotificationLanguageChanged {
            let tabBarItems = tabBar.items! as [UITabBarItem]
            tabBarItems[0].title = Localization(TranslationConstants.SCANNER)
            tabBarItems[1].title = Localization(TranslationConstants.HOME)
            tabBarItems[2].title = Localization(TranslationConstants.SETTING)
        }
    }
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
