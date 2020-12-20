//
//  test.swift
//  DongR2
//
//  Created by wopark on 2020/12/17.
//

import SwiftUI

struct test: View {
    
    var body: some View {
//        NavigationView {
            VStack
            {
                ScrollView(.vertical, showsIndicators: false){
                   
                    ClubScroll(category : "모집중")
    //                ClubScroll(category: clubs.recruiting)
                    ForEach(categories) {category in
                        ClubScroll(category: category.name)
                    }
    //                List (categories) { category in
    //                    ClubScroll(category: category)
    //                }
    //                List(clubs){club in
    //                    ClubScroll(category : club.category)
    //                }
                }
                NavBar()
            }
//        }
    }
}

struct test_Previews: PreviewProvider {
    static var previews: some View {
        test()
    }
}
