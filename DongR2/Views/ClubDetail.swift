//
//  ClubDetail.swift
//  DongR2
//
//  Created by wopark on 2021/01/07.
//

import SwiftUI

struct ClubDetail: View {
    var club: Club
    
    var body: some View {
        ScrollView {
            club.bgImg
                .resizable()
                .scaledToFit()
                .ignoresSafeArea(edges: .top)
            
            ClubMark(image: club.markImg)
                .offset(y: -130)
                .padding(.bottom, -130)
            
            VStack (alignment: .leading){
                Text(club.name)
                    .font(.title)
                    .bold()
                HStack{
                    Text(club.category)
                        .font(.subheadline)
                    Spacer()
                    Text("42 동아리")
                        .font(.subheadline)
                }
                .font(.subheadline)
                .foregroundColor(.secondary)
                Divider()
                
                Text("About 동앓이")
                    .font(.title2)
                Text(club.description)
                
            }
            .padding()
        }
        .navigationTitle(club.name)
        .navigationBarTitleDisplayMode(.inline)
    }
}

struct ClubDetail_Previews: PreviewProvider {
    static var previews: some View {
        ClubDetail(club: clubs[0])
    }
}

