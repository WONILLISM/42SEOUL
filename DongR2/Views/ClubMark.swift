//
//  ClubMark.swift
//  DongR2
//
//  Created by wopark on 2021/01/07.
//

import SwiftUI

struct ClubMark: View {
    var image: Image
    
    var body: some View {
        image
            .resizable()
            .scaledToFit()
            .frame(width:200, height:200)
            .clipShape(Circle())
            .overlay(Circle().stroke(Color.gray, lineWidth:  4))
            .shadow(radius: 7)
    }
}

struct ClubMark_Previews: PreviewProvider {
    static var previews: some View {
        ClubMark(image: Image("yamyamMark"))
    }
}
