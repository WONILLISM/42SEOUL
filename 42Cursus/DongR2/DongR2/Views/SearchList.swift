//
//  SearchList.swift
//  DongR2
//
//  Created by wopark on 2021/01/07.
//

import SwiftUI

struct SearchList: View {
    @EnvironmentObject var modelData: ModelData
    @State private var searchText = ""
    @State private var isSearching = false
    
    
    var body: some View {
        NavigationView {
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
                    ForEach(modelData.clubs.filter({$0.name.contains(searchText) || searchText.isEmpty})){club in
                        NavigationLink(destination: ClubDetail(club: club)){
                            SearchRow(club: club)
                        }
                    }
                    .navigationTitle("검색")
                }
            }
        }
    }
}

struct SearchList_Previews: PreviewProvider {
    static var previews: some View {
        SearchList()
            .environmentObject(ModelData())
    }
}
