//
//  GetImage.swift
//  DongR2
//
//  Created by hsw on 2020/12/18.
//

import SwiftUI

struct GetImage: View {
    var src : Image
    var body: some View {
        src
            .resizable()
            .frame(width: 100, height: 100)
    }
}

struct GetImage_Previews: PreviewProvider {
    static var previews: some View {
        GetImage(src: Image("crew"))
    }
}
