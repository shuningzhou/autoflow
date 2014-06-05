//
//  LayoutSelector.cpp
//  test
//
//  Created by shuning zhou on 2014-06-04.
//  Copyright (c) 2014 ZS. All rights reserved.
//

#include "LayoutSelector.h"
#include <limits>
#include <math.h>
#include <algorithm>
#include <assert.h>

bool sortByRatio(const Area &lhs, const Area &rhs) { return lhs.ratio < rhs.ratio; }

int bestLayout(vector<Layout> &layouts, vector<Area> &photos,vector<Layout> &sortedLayouts,vector<Area> &sortedPhotos){
    
    sortedLayouts = layouts;
    sortedPhotos = photos;
    
    int numberOfLayouts = (int)sortedLayouts.size();
    int numberOfPhotos = (int)sortedPhotos.size();
    
    for (int i = 0; i < numberOfLayouts; i++) {
        std::sort(sortedLayouts[i].dropZones.begin(), sortedLayouts[i].dropZones.end(), sortByRatio);
    }
    
    for (int i = 0; i < numberOfPhotos; i++) {
        std::sort(sortedPhotos.begin(), sortedPhotos.end(), sortByRatio);
    }
    
    float min = numeric_limits<float>::max();
    int layoutIndex = -1;
    
    for (int i = 0; i < numberOfLayouts; i++) {
        float cut = crop(sortedLayouts[i].dropZones, sortedPhotos);
        printf("Total cropped area for layout[%d] is %f\n",i,cut);
        if (cut < min) {
            min = cut;
            layoutIndex = i;
        }
    }
    
    return layoutIndex;
}

float crop(vector<Area> &dropZones, vector<Area> &photos){
    assert(dropZones.size() == photos.size());
    float cut = 0.0;
    int numberOfPhotos = (int)photos.size();
    for (int i = 0; i < numberOfPhotos; i++) {
        cut = cut + fabsf(dropZones[i].ratio - photos[i].ratio);
    }
    return cut;
}
