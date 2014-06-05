//
//  main.cpp
//  test
//
//  Created by shuning zhou on 2014-06-04.
//  Copyright (c) 2014 ZS. All rights reserved.
//

#include <iostream>
#include "LayoutSelector.h"

int main(int argc, const char * argv[])
{
    vector<Layout> layouts, sortedLayout;

    vector<Area> dropZones0;
    dropZones0.push_back(Area(130.0, 100.0, 0));
    dropZones0.push_back(Area(130.0, 100.0, 1));
    dropZones0.push_back(Area(130.0, 100.0, 2));
    dropZones0.push_back(Area(130.0, 100.0, 3));
    
    layouts.push_back(Layout(dropZones0));
    
    vector<Area> dropZones1;
    dropZones1.push_back(Area(60.0, 100.0, 0));
    dropZones1.push_back(Area(60.0, 100.0, 1));
    dropZones1.push_back(Area(60.0, 100.0, 2));
    dropZones1.push_back(Area(60.0, 100.0, 3));
    
    layouts.push_back(Layout(dropZones1));
    
    vector<Area> dropZones2;
    dropZones2.push_back(Area(80.0, 60.0, 0));
    dropZones2.push_back(Area(80.0, 60.0, 1));
    dropZones2.push_back(Area(80.0, 140.0, 2));
    dropZones2.push_back(Area(80.0, 140.0, 3));
    
    layouts.push_back(Layout(dropZones2));
    
    vector<Area> dropZones3;
    dropZones3.push_back(Area(180.0, 120.0, 0));
    dropZones3.push_back(Area(80.0, 120.0, 1));
    dropZones3.push_back(Area(100.0, 80.0, 2));
    dropZones3.push_back(Area(100.0, 80.0, 3));
    
    layouts.push_back(Layout(dropZones3));
    
    vector<Area> photos, sortedPhotos;
    photos.push_back(Area(200.0, 150.0, 0));
    photos.push_back(Area(210.0, 100.0, 1));
    photos.push_back(Area(80.0, 100.0, 2));
    photos.push_back(Area(70.0, 120.0, 3));
    
    int bestLaytouIndex = bestLayout(layouts, photos,sortedLayout,sortedPhotos);
    
    printf("best layout index: %d\n", bestLaytouIndex);
    
    Layout bestLayout = sortedLayout[bestLaytouIndex];
    int size = (int)sortedPhotos.size();
    
    for(int i = 0; i < size ; i ++ ) {
        printf("photo[%d] should appear in dropZone[%d] in layout[%d]\n",
               sortedPhotos[i].index,bestLayout.dropZones[i].index, bestLaytouIndex);
    }
    
    return 0;
}

