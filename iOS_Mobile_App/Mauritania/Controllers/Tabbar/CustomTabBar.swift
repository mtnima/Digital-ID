//
//  CustomTabBar.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 19/01/23.
//

import UIKit

@IBDesignable class CustomTabBar: UITabBar {
    @IBInspectable var color: UIColor?
    @IBInspectable var radii: CGFloat = 18
    
    private var shapeLayer: CALayer?
    
    override func draw(_ rect: CGRect) {
        addShape()
    }
    
    private func addShape() {
        let shapeLayer = CAShapeLayer()
        
        shapeLayer.path = createPath()
        shapeLayer.strokeColor = UIColor.black.cgColor
        shapeLayer.fillColor = color?.cgColor ?? UIColor.white.cgColor
        shapeLayer.lineWidth = 0
        shapeLayer.shadowColor = UIColor.black.cgColor
        shapeLayer.shadowOffset = CGSize(width: 0, height: -2);
        shapeLayer.shadowOpacity = 0.21
        shapeLayer.shadowRadius = 8
        shapeLayer.shadowPath =  UIBezierPath(roundedRect: bounds, cornerRadius: radii).cgPath
        
        if let oldShapeLayer = self.shapeLayer {
            layer.replaceSublayer(oldShapeLayer, with: shapeLayer)
        } else {
            layer.insertSublayer(shapeLayer, at: 0)
        }
        
        self.shapeLayer = shapeLayer
    }
    
    private func createPath() -> CGPath {
        let path = UIBezierPath(
            roundedRect: bounds,
            byRoundingCorners: [.topLeft, .topRight,.bottomLeft,.bottomRight],
            cornerRadii: CGSize(width: radii, height: 0.0))
        
        return path.cgPath
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        self.isTranslucent = true
        var tabFrame = self.frame
        tabFrame.size.height = 80
//        tabFrame.size.width = self.frame.size.width * 0.80
        tabFrame.origin.y = self.frame.origin.y + self.frame.height - 90
//        tabFrame.origin.x = self.frame.origin.x + self.frame.width - (self.frame.size.width * 0.10)
//        self.layer.cornerRadius = 18
        self.frame = tabFrame
        self.items?.forEach({ $0.titlePositionAdjustment = UIOffset(horizontal: 0.0, vertical: -5.0) })
    }
    
}
