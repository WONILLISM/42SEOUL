//
//  SearchRow.swift
//  DongR2
//
//  Created by wopark on 2020/12/17.
//

import SwiftUI

struct SearchRow: View {
    var club: Club
    
    var body: some View {
        NavigationLink(destination: ClubDetail(club: club)){
            HStack {
                club.image.resizable()
                    .frame(width: 50, height: 50)
                Text(club.name)
                
                Spacer()
            }
        }
    }
}

struct SearchRow_Previews: PreviewProvider {
    static var previews: some View {
        SearchRow(club: clubs[0])
            .previewLayout(.fixed(width: 300, height: 70))
    }
}
