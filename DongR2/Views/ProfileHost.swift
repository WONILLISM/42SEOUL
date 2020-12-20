//
//  ProfileHost.swift
//  DongR2
//
//  Created by jimkwon on 2020/12/18.
//

import SwiftUI

struct ProfileHost: View {
    var body: some View {
        VStack(alignment: .leading, spacing: 20) {
            ProfileSummary()
        }
        .padding()
    }
}

struct ProfileHost_Previews: PreviewProvider {
    static var previews: some View {
        ProfileHost()
    }
}
