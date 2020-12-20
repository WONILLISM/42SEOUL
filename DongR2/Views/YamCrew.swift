//
//  YamCrew.swift
//  dongari
//
//  Created by jimkwon on 2020/12/17.
//

import SwiftUI

struct YamCrew: View {
    var body: some View {
        Image("crew")
            .resizable()
            .frame(width: 100, height: 100)
    }
}

struct YamCrew_Previews: PreviewProvider {
    static var previews: some View {
        YamCrew()
    }
}
