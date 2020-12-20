//
//  BadgeToggle.swift
//  DongR2
//
//  Created by jimkwon on 2020/12/18.
//

import SwiftUI

struct BadgeToggle: View {
    @State var showDetails = true
    var img : String
    var img_ex : String
    var body: some View {
            Button(action: {
                self.showDetails.toggle()
            }) {
                if showDetails {
                    Image(img)
                        .resizable()
                        .frame(width: 150, height: 150)
                }
            }
        if !showDetails {
            Button(action: {
                self.showDetails.toggle()
            }) {
            Image(img_ex)
                .resizable()
                .frame(width: 150, height: 150)
            }
        }
        
    }
}

struct BadgeToggle_Previews: PreviewProvider {
    static var previews: some View {
        BadgeToggle(img: "badge_winner", img_ex: "badge_friend")
    }
}
