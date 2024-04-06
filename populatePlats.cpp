#include "stru.h"
#include <time.h>
#include <iostream>




void populatePlats(point plat[], int n){
    for(int i=0; i<n; i++){
        plat[i].x=rand()%332;
        plat[i].y=rand()%533;
        if (n>5 && i==n-1){
            plat[i].x = 150;
            plat[i].y = 500;
        }
    }
}