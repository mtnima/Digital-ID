//
//  SettingTableViewCell.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 27/01/23.
//

import UIKit

class SettingTableViewCell: UITableViewCell {

    @IBOutlet weak var optionValue: UILabel!
    @IBOutlet weak var optionLabel: UILabel!
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}

