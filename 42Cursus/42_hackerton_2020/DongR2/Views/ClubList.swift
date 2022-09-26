//
//  ClubList.swift
//  DongR2
//
//  Created by wopark on 2020/12/17.
//

import SwiftUI

struct ClubList: View {
    @State private var searchText = ""
    @State private var isSearching = false
    
    var body: some View {
//        NavigationView {
        VStack {
            ScrollView {
                HStack {
                    TextField("Search ...", text: $searchText)
                        .padding(.leading, 24)
                }
                .padding()
                .background(Color(.systemGray5))
                .cornerRadius(6)
                .padding(.horizontal)
                .onTapGesture(perform: {
                    isSearching = true
                })
                .overlay(
                    HStack {
                        Image(systemName: "magnifyingglass")
                        Spacer()
                        
                        if isSearching {
                            Button(action: {searchText = ""}, label: {
                                Image(systemName: "xmark.circle.fill")
                            })
                        }
                    }.padding(.horizontal, 32)
                    .foregroundColor(.gray)
                )
                ForEach(clubs.filter({$0.name.contains(searchText) || searchText.isEmpty})){club in
                    SearchRow(club: club)
                }
                .navigationTitle("검색")
            }
        }
    }
//    }
}

struct ClubList_Previews: PreviewProvider {
    static var previews: some View {
        ClubList()
    }
}
