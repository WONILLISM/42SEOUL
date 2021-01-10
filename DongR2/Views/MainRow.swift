//
//  MainRow.swift
//  DongR2
//
//  Created by wopark on 2021/01/10.
//

import SwiftUI

struct MainRow: View {
    var categoryName: String
    var items: [Club]
    
    var body: some View {
        VStack(alignment: .leading){
            Text(categoryName)
                .font(.headline)
                .padding(.leading, 15)
                .padding(.top, 5)
            
            ScrollView(.horizontal, showsIndicators: false) {
                HStack(alignment: .top, spacing: 0) {
                    ForEach(items) { club in
                        MainItem(club: club)
                    }
                }
            }
            .frame(height: 185)
        }
    }
}

struct MainRow_Previews: PreviewProvider {
    static var clubs = ModelData().clubs
    
    static var previews: some View {
        MainRow(
            categoryName: clubs[0].category.rawValue,
            items: Array(clubs.prefix(3))
        )
    }
}
