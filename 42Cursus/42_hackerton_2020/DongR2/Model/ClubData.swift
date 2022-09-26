//
//  ClubData.swift
//  DongR2
//
//  Created by wopark on 2020/12/17.
//

import Foundation
import SwiftUI

struct Club: Hashable, Codable, Identifiable {
    var id: Int
    var name: String
    var category: String
    var description: String
    var recruiting: Int
    
    private var imageName: String
    var image: Image{
        Image(imageName)
    }
}

struct Category: Hashable, Codable, Identifiable {
    var id: Int
    var name: String
}
