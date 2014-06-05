//
//  LayoutSelector.h
//  test
//
//  Created by shuning zhou on 2014-06-04.
//  Copyright (c) 2014 ZS. All rights reserved.
//

#ifndef test_LayoutSelector_h
#define test_LayoutSelector_h

#include <vector>

using namespace std;

typedef struct Area
{
    float height;
    float width;
    float ratio;
    int   index;
    Area(float width, float height, int index){
        this->height = height;
        this->width = width;
        ratio = width / height;
        this->index = index;
    }
}Area;

typedef struct Layout
{
    vector<Area> dropZones;
    Layout(vector<Area> dz){
        dropZones = dz;
    }
}Layout;


/*
 Crop photos[n] using dropZones[n], and return the total cropped area.
 @param dropZones The drop zones.
 @param photos The photos .
 */
float crop(vector<Area> &dropZones, vector<Area> &photos);


/*
 Sort photos and layouts by their ratios(width/height), then return the index of the best layout(layout that ensures minimal cropping).
 @param layouts The layouts.
 @param photos The photos.
 @param sortedlayouts Layouts after sorting.
 @param sortedPhotos Photos after sorting.
 */
int bestLayout(vector<Layout> &layouts, vector<Area> &photos,vector<Layout> &sortedlayouts,vector<Area> &sortedPhotos);


#endif
