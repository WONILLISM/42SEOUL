//
//  DongR2App.swift
//  DongR2
//
//  Created by wopark on 2021/01/06.
//

import SwiftUI

@main
struct DongR2App: App {
    @StateObject private var modelData = ModelData()
    
    var body: some Scene {
        WindowGroup {
            ContentView()
                .environmentObject(modelData)
        }
    }
}
