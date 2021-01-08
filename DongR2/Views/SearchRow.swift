//
//  SearchRow.swift
//  DongR2
//
//  Created by wopark on 2021/01/07.
//

import SwiftUI

struct SearchRow: View {
    var club: Club
    var body: some View {
        HStack {
            club.markImg
                .resizable()
                .frame(width: 50, height: 50)
            Text(club.name)
            
            Spacer()
        }
    }
}

struct SearchRow_Previews: PreviewProvider {
    static var previews: some View {
        Group {
            SearchRow(club: clubs[0])
            SearchRow(club: clubs[1])
        }
        .previewLayout(.fixed(width: 300, height: 70))
    }
}
