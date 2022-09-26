//
//  ProfileSummary.swift
//  DongR2
//
//  Created by jimkwon on 2020/12/18.
//

import SwiftUI

struct ProfileSummary: View {
    @State var showDetails = false
    var body: some View {
        VStack(alignment: .leading, spacing: 10) {
            Text("Profile for: \n권지민(방탄지민아님ㅎ)")
                .bold()
                .font(.title)
            
            Text("coalition : Gon")
            Text("동앓이 : 냠냠크루")
            Text("status : 죽겠어요")
            Divider()
            VStack(alignment: .leading, spacing: 10) {
                Text("badge")
                    .font(.headline)
                ScrollView(.horizontal) {
                    HStack() {
                        BadgeToggle(img: "badge_friend", img_ex: "ex_friend")
                        BadgeToggle(img: "badge_winner", img_ex: "ex_winner")
                        BadgeToggle(img: "badge_class", img_ex: "ex_class")
                    }
                }
                
            }
        }
        
    }
}

struct ProfileSummary_Previews: PreviewProvider {
    static var previews: some View {
        ProfileSummary()
    }
}
