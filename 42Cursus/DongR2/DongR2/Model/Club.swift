//
//  Club.swift
//  DongR2
//
//  Created by wopark on 2021/01/06.
//

import Foundation
import SwiftUI

struct Club: Hashable, Codable, Identifiable {
    var id: Int
    var name: String
    var description: String
    
    var category: Category
    enum Category: String, CaseIterable, Codable {
        case Fellowship = "친목"
        case Hobby = "취미"
        case Study = "공부"
    }
    
    private var bgName: String
    var bgImg: Image{
        Image(bgName)
    }
    
    private var markName: String
    var markImg: Image {
        Image(markName)
    }
}
