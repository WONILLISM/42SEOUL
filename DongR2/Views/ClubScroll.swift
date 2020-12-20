//
//  ClubScroll.swift
//  dongari
//
//  Created by jimkwon on 2020/12/17.
//

import SwiftUI

struct ClubScroll: View {
    var category: String
    
    var body: some View {
        VStack(alignment: .leading) {
            Text(category)
                .font(.title)
                .fontWeight(.bold)
                .multilineTextAlignment(.leading)
                .padding()
            ScrollView(.horizontal, showsIndicators: false) {
                HStack() {//clubs
                    if category == "모집중"{
                        ForEach(clubs) {club in
                            if club.recruiting == 1{
                                NavigationLink(destination: ClubDetail(club: club)) {
                                    GetImage(src: club.image)
                                }
                            }
                        }
                    }
                    else{
                        ForEach(clubs) { club in
                            if club.category == category{
                                NavigationLink(destination: ClubDetail(club: club)) {
                                    GetImage(src: club.image)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

struct ClubScroll_Previews: PreviewProvider {
    static var previews: some View {
        ClubScroll(category: "ㅇㅇㅇㅇ")
    }
}
