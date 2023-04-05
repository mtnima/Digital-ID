//
//  TutorialViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 20/01/23.
//

import UIKit

class TutorialViewController: BaseViewController {
    
    var isHeightCalculated: Bool = false

    @IBOutlet weak var skipbutton: UIButton!
    @IBOutlet weak var continueButton: UIButton!
    let stepsTitle = [TranslationConstants.WELCOM,TranslationConstants.TUTORIAL,TranslationConstants.TUTORIAL_1,TranslationConstants.TUTORIAL_2]
    let steps = [TranslationConstants.WELCOME_NOTE,TranslationConstants.TUTORIAL_NOTE,TranslationConstants.TUTORIAL_NOTE_1,TranslationConstants.TUTORIAL_NOTE_2]
    let images = ["Welcome","Tutorial","Tutorial1","Tutorial2"]
    
    @IBOutlet weak var paging: UIPageControl!
    var index = IndexPath(row: 0, section: 0)
    private let sectionInsets = UIEdgeInsets(
        top: 0.0,
        left: 0.0,
      bottom: 0.0,
      right: 0.0)

    @IBOutlet weak var tutorialCollectionView: UICollectionView!
    override func viewDidLoad() {
        super.viewDidLoad()
        skipbutton.layer.borderWidth = 2
        skipbutton.layer.borderColor = UIColor().appcolor().cgColor
        skipbutton.tintColor = UIColor().appcolor()
        paging.numberOfPages = 4
        paging.currentPage = 0
        updateWithLanguage()
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)
        
//        if let flowLayout = tutorialCollectionView?.collectionViewLayout as? UICollectionViewFlowLayout {
//              flowLayout.estimatedItemSize = UICollectionViewFlowLayout.automaticSize
//           }
        tutorialCollectionView.reloadData()
        // Do any additional setup after loading the view.
    }
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.interactivePopGestureRecognizer?.isEnabled = false
    }
    @IBAction func continueAction(_ sender: Any) {
        if index.row >= 3{
            self.navigationController?.pushViewController(HomeRouter.createHomeModele(), animated: true)
        }
        else{
            tutorialCollectionView.scrollToNextItem()
            paging.currentPage = index.row + 1
            index.row = index.row + 1
            
        }
    }
    
    @IBAction func skipAction(_ sender: Any) {
        self.navigationController?.pushViewController(HomeRouter.createHomeModele(), animated: true)
    }
    @objc func receiveLanguageChangedNotification(notification:NSNotification) {
        if notification.name == kNotificationLanguageChanged {
            updateWithLanguage()
        }
    }
    func updateWithLanguage(){
        skipbutton.setTitle(Localization(TranslationConstants.SKIP), for: .normal)
        continueButton.setTitle(Localization(TranslationConstants.CONTINUE), for: .normal)
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
extension TutorialViewController:UICollectionViewDataSource, UICollectionViewDelegate{
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 4
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell", for: indexPath) as! TutorialCollectionViewCell
        cell.tutorialImage.image = UIImage(named: images[indexPath.row])
        cell.tutorialImage.clipsToBounds = true
        cell.tutorialImage.contentMode = .scaleAspectFit
        cell.tutorialLabl.text = Localization(steps[indexPath.row])
        cell.tutorialTitle.text = Localization(stepsTitle[indexPath.row])
        return cell
    }
}
extension TutorialViewController:UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let paddingSpace = sectionInsets.left * (1 + 1)
        let availableWidth = view.frame.width - paddingSpace
        let widthPerItem = availableWidth / 1

        return CGSize(width: availableWidth, height: self.view.frame.size.height * 0.60)
    }
    func collectionView(
        _ collectionView: UICollectionView,
        layout collectionViewLayout: UICollectionViewLayout,
        insetForSectionAt section: Int
      ) -> UIEdgeInsets {
        return sectionInsets
      }
    func collectionView(
        _ collectionView: UICollectionView,
        layout collectionViewLayout: UICollectionViewLayout,
        minimumLineSpacingForSectionAt section: Int
      ) -> CGFloat {
        return sectionInsets.left
      }
    

}
extension UICollectionView {
    func scrollToNextItem() {
        let contentOffset = CGFloat(floor(self.contentOffset.x + self.bounds.size.width))
        self.moveToFrame(contentOffset: contentOffset)
    }

    func scrollToPreviousItem() {
        let contentOffset = CGFloat(floor(self.contentOffset.x - self.bounds.size.width))
        self.moveToFrame(contentOffset: contentOffset)
    }

    func moveToFrame(contentOffset : CGFloat) {
        self.setContentOffset(CGPoint(x: contentOffset, y: self.contentOffset.y), animated: true)
    }
}
