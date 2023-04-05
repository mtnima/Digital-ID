//
//  Step1TableViewCell.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 23/01/23.
//

import UIKit

class Step1TableViewCell: UITableViewCell {

    @IBOutlet weak var fieldName: UILabel!
    @IBOutlet weak var fieldValue: UILabel!

    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
