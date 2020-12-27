//
//  test.swift
//  DongR2
//
//  Created by wopark on 2020/12/17.
//

import SwiftUI

struct MainView: View {
    
    var body: some View {
        VStack
        {
            ScrollView(.vertical, showsIndicators: false){
                ClubScroll(category : "모집중")
                ForEach(categories) {category in
                    ClubScroll(category: category.name)
                }
            }
        }
    }
}

struct MainView_Previews: PreviewProvider {
    static var previews: some View {
        MainView()
    }
}
