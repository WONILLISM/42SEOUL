//
//  ClubImage.swift
//  dongari
//
//  Created by jimkwon on 2020/12/17.
//

import SwiftUI

struct ClubImage: View {
    var body: some View {
        VStack() {
            YamCrew()
            Text("냠냠크루")
                .font(.title)
                .fontWeight(.bold)
        }
    }
}

struct ClubImage_Previews: PreviewProvider {
    static var previews: some View {
        ClubImage()
    }
}
