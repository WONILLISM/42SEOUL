//
//  MainHome.swift
//  DongR2
//
//  Created by wopark on 2021/01/09.
//

import SwiftUI

struct MainHome: View {
    @EnvironmentObject var modelData: ModelData
    @State private var showingProfile = false
    
    var body: some View {
        NavigationView {
            List {
                ForEach(modelData.categories.keys.sorted(), id: \.self) { key in
                    MainRow(categoryName: key, items: modelData.categories[key]!)
                }
                .listRowInsets(EdgeInsets())
            }
            .listStyle(InsetListStyle())
            .navigationTitle("DongR2")
            .toolbar {
                Button(action: { showingProfile.toggle() }) {
                    Image(systemName: "person.crop.circle")
                        .accessibilityLabel("User Profile")
                }
            }
            .sheet(isPresented: $showingProfile) {
                Profile()
                    .environmentObject(modelData)
            }
        }
    }
}

struct MainHome_Previews: PreviewProvider {
    static var previews: some View {
        MainHome()
            .environmentObject(ModelData())
    }
}
