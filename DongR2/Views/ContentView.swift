//
//  ContentView.swift
//  DongR2
//
//  Created by wopark on 2021/01/06.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationView{
            MainHome()
//            SearchList()
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
            .environmentObject(ModelData())
    }
}
