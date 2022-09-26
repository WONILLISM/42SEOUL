//
//  ClubDetail.swift
//  DongR2
//
//  Created by wopark on 2020/12/17.
//

import SwiftUI

struct ClubDetail: View {
    var club: Club
    
    var body: some View{
      //  VStack{
            ScrollView(.vertical, showsIndicators: false)
            {
                //동아리 마크
                ImageView(image: club.image)
                    .offset(y:0)
                    .padding(.bottom, 0)
                VStack(alignment: .leading)
                {
                    //동아리 명
                    Text(club.name)
                        .font(.title)
                        .foregroundColor(.primary)
                    
                    Divider()
                    //동아리 상새설명
                    Text(club.description)
                }
                .padding()
                .padding(.bottom, -30)
                ////동아리 활동 사진
                ScrollView(.horizontal, showsIndicators: false){
                    HStack(alignment: .top, spacing: 0, content: {
                        club.image
                            .resizable()
                            .scaledToFit()
                            .frame(width: 100, height: 100)
                            .clipped()
                            .padding()
                    })
                    .padding()
                }
                Button(action:{
                    
                }) {
                    Text("가입 신청")
                }
            }
            .navigationTitle(club.name)
            .navigationBarTitleDisplayMode(.inline)
        }
   // }
}

struct ClubDetail_Previews: PreviewProvider {
    static var previews: some View {
        ClubDetail(club: clubs[0])
    }
}
