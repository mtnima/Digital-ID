//
//  InfoTableViewCell.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 11/01/23.
//

import UIKit

class InfoTableViewCell: UITableViewCell {

    @IBOutlet weak var inforamationLable: UILabel!
    @IBOutlet weak var infoIcon: UIImageView!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
