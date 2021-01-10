//
//  MainItem.swift
//  DongR2
//
//  Created by wopark on 2021/01/11.
//

import SwiftUI

struct MainItem: View {
    var club: Club
    
    var body: some View {
        VStack(alignment: .leading) {
            club.markImg
                .resizable()
                .frame(width: 155, height: 155)
                .cornerRadius(5)
            Text(club.name)
                .font(.caption)
        }
        .padding(.leading, 15)
    }
}

struct MainItem_Previews: PreviewProvider {
    static var previews: some View {
        MainItem(club: ModelData().clubs[0])
    }
}
