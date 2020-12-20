//
//  ImageView.swift
//  test
//
//  Created by hsw on 2020/12/17.
//

import SwiftUI

struct ImageView: View {
    var image: Image
    
    var body: some View {
        //Image("crew")
        image
            .resizable()
            .scaledToFit()
            .frame(width: 200, height: 200)
            .clipped()
    }
}

struct ImageView_Previews: PreviewProvider {
    static var previews: some View {
        ImageView(image: Image("crew"))
    }
}
