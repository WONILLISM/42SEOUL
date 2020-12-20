//
//  ContentView.swift
//  dongari
//
//  Created by jimkwon on 2020/12/17.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationView{
            test()
                .navigationBarItems(leading: NavigationLink(
                destination: ProfileHost()){
                    Image("mypage_2")
                        .resizable()
                        .frame(width: 50, height: 50)
                }, trailing: NavigationLink(destination: ClubList()){
                    Image("search")
                        .resizable()
                        .frame(width: 50, height: 50)
                })
        }
//        ClubList()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
