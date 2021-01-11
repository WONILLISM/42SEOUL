//
//  ContentView.swift
//  DongR2
//
//  Created by wopark on 2021/01/06.
//

import SwiftUI

struct ContentView: View {
    @State private var selection: Tab = .home
    enum Tab {
        case home
        case search
        case profile
    }
    
    var body: some View {
        TabView(selection: $selection){
            MainHome()
                .tabItem {
                    Label("Home", systemImage: "house")
                }
                .tag(Tab.home)
            SearchList()
                .tabItem{
                    Label("Search", systemImage: "magnifyingglass")
                }
                .tag(Tab.search)
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
            .environmentObject(ModelData())
    }
}
