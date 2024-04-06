//
// Created by Lenovo on 7/5/2023.
//

#include "movePlats.h"

void movePlats(point plat[], int n, int direction[], int i, point plat_normal[], point plat_destruct[], point plat_bouncy[], int k, int l, int m){


    if (direction[i] == 0) plat[i].x += 1;
    else plat[i].x -= 1;


    if (plat[i].x > 330) direction[i] = 1;
    else if (plat[i].x < 0) direction[i] = 0;

    int j;

    for (j=0; j<k; j++)
        if ( (plat_normal[j].x-72<=plat[i].x && plat[i].x<=plat_normal[j].x+72) && ((plat_normal[j].y-14<=plat[i].y && plat[i].y<=plat_normal[j].y+14)) ){
            if (direction[i] == 0) direction[i] = 1;
            else direction[i] = 0;
            break;
        }
    for (j=0; j<l; j++)
        if ( (plat_destruct[j].x-72<=plat[i].x && plat[i].x<=plat_destruct[j].x+72) && ((plat_destruct[j].y-14<=plat[i].y && plat[i].y<=plat_destruct[j].y+14)) ){
            if (direction[i] == 0) direction[i] = 1;
            else direction[i] = 0;
            break;
        }
    for (j=0; j<m; j++)
        if ( (plat_bouncy[j].x-72<=plat[i].x && plat[i].x<=plat_bouncy[j].x+72) && ((plat_bouncy[j].y-26<=plat[i].y && plat[i].y<=plat_bouncy[j].y+26)) ){
            if (direction[i] == 0) direction[i] = 1;
            else direction[i] = 0;
            break;
        }
    for (j=0; j<n; j++)
        if ( (plat[j].x-72<=plat[i].x && plat[i].x<=plat[j].x+72) && ((plat[j].y-14<=plat[i].y && plat[i].y<=plat[j].y+14)) ){
            if (direction[i] == 0) direction[i] = 1;
            else direction[i] = 0;
            if (direction[j] == 0) direction[j] = 1;
            else direction[j] = 0;
            break;
        }

}