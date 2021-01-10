//
//  MainHome.swift
//  DongR2
//
//  Created by wopark on 2021/01/09.
//

import SwiftUI

struct MainHome: View {
    @EnvironmentObject var modelData: ModelData
    
    var body: some View {
        List {
            ForEach(modelData.categories.keys.sorted(), id: \.self) { key in
                MainRow(categoryName: key, items: modelData.categories[key]!)
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
