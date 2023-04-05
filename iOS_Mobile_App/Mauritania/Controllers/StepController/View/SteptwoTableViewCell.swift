//
//  SteptwoTableViewCell.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 23/01/23.
//

import UIKit

class SteptwoTableViewCell: UITableViewCell {
    @IBOutlet weak var number: UILabel!
    @IBOutlet weak var InfoLabel: UILabel!

    override func awakeFromNib() {
        super.awakeFromNib()
        number.layer.borderWidth = 1
        number.layer.borderColor = UIColor().appcolor().cgColor
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
