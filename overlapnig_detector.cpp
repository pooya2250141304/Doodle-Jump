//
// Created by Lenovo on 7/5/2023.
//

#include "overlapnig_detector.h"
void overlaping_detector(point plat_normal[], point plat_destruct[], point plat_floating[], point plat_bouncy[], int k, int l, int m, int n){
    int i, j;
    for(i=0; i<k; i++){
        for(j = i+1; j<k; j++)
            while ( (plat_normal[j].x-68<=plat_normal[i].x && plat_normal[i].x<=plat_normal[j].x+68) && ((plat_normal[j].y-14<=plat_normal[i].y && plat_normal[i].y<=plat_normal[j].y+14)) ){
                plat_normal[i].x=rand()%332;
                plat_normal[i].y=-rand()%76;
            }
        for (j=0; j<l; j++)
            if ( (plat_destruct[j].x-68<=plat_normal[i].x && plat_normal[i].x<=plat_destruct[j].x+68) && ((plat_destruct[j].y-14<=plat_normal[i].y && plat_normal[i].y<=plat_destruct[j].y+14)) ){
                plat_normal[i].x=rand()%332;
                plat_normal[i].y=-rand()%76;
            }
        for (j=0; j<m; j++)
            if ( (plat_floating[j].x-68<=plat_normal[i].x && plat_normal[i].x<=plat_floating[j].x+68) && ((plat_floating[j].y-14<=plat_normal[i].y && plat_normal[i].y<=plat_floating[j].y+14)) ){
                plat_normal[i].x=rand()%332;
                plat_normal[i].y=-rand()%76;
            }
        for (j=0; j<n; j++)
            if ( (plat_bouncy[j].x-68<=plat_normal[i].x && plat_normal[i].x<=plat_bouncy[j].x+68) && ((plat_bouncy[j].y-26<=plat_normal[i].y && plat_normal[i].y<=plat_bouncy[j].y+26)) ){
                plat_normal[i].x=rand()%332;
                plat_normal[i].y=-rand()%76;
            }
    }
    for(i=0; i<l; i++){
        for(j = i+1; j<l; j++)
            while ( (plat_destruct[j].x-68<=plat_destruct[i].x && plat_destruct[i].x<=plat_destruct[j].x+68) && ((plat_destruct[j].y-14<=plat_destruct[i].y && plat_destruct[i].y<=plat_destruct[j].y+14)) ){
                plat_destruct[i].x=rand()%332;
                plat_destruct[i].y=-rand()%76;
            }
        for (j=0; j<k; j++)
            if ( (plat_normal[j].x-68<=plat_destruct[i].x && plat_destruct[i].x<=plat_normal[j].x+68) && ((plat_normal[j].y-14<=plat_destruct[i].y && plat_destruct[i].y<=plat_normal[j].y+14)) ){
                plat_destruct[i].x=rand()%332;
                plat_destruct[i].y=-rand()%76;
            }
        for (j=0; j<m; j++)
            if ( (plat_floating[j].x-68<=plat_destruct[i].x && plat_destruct[i].x<=plat_floating[j].x+68) && ((plat_floating[j].y-14<=plat_destruct[i].y && plat_destruct[i].y<=plat_floating[j].y+14)) ){
                plat_destruct[i].x=rand()%332;
                plat_destruct[i].y=-rand()%76;
            }
        for (j=0; j<n; j++)
            if ( (plat_bouncy[j].x-68<=plat_destruct[i].x && plat_destruct[i].x<=plat_bouncy[j].x+68) && ((plat_bouncy[j].y-26<=plat_destruct[i].y && plat_destruct[i].y<=plat_bouncy[j].y+26)) ){
                plat_destruct[i].x=rand()%332;
                plat_destruct[i].y=-rand()%76;
            }
    }
    for(i=0; i<m; i++){
        for(j = i+1; j<m; j++)
            while ( (plat_floating[j].x-68<=plat_floating[i].x && plat_floating[i].x<=plat_floating[j].x+68) && ((plat_floating[j].y-14<=plat_floating[i].y && plat_floating[i].y<=plat_floating[j].y+14)) ){
                plat_floating[i].x=rand()%332;
                plat_floating[i].y=-rand()%76;
            }
        for (j=0; j<k; j++)
            if ( (plat_normal[j].x-68<=plat_floating[i].x && plat_floating[i].x<=plat_normal[j].x+68) && ((plat_normal[j].y-14<=plat_floating[i].y && plat_floating[i].y<=plat_normal[j].y+14)) ){
                plat_floating[i].x=rand()%332;
                plat_floating[i].y=-rand()%76;
            }
        for (j=0; j<l; j++)
            if ( (plat_destruct[j].x-68<=plat_floating[i].x && plat_floating[i].x<=plat_destruct[j].x+68) && ((plat_destruct[j].y-14<=plat_floating[i].y && plat_floating[i].y<=plat_destruct[j].y+14)) ){
                plat_floating[i].x=rand()%332;
                plat_floating[i].y=-rand()%76;
            }
        for (j=0; j<n; j++)
            if ( (plat_bouncy[j].x-68<=plat_floating[i].x && plat_floating[i].x<=plat_bouncy[j].x+68) && ((plat_bouncy[j].y-26<=plat_floating[i].y && plat_floating[i].y<=plat_bouncy[j].y+26)) ){
                plat_floating[i].x=rand()%332;
                plat_floating[i].y=-rand()%76;
            }
    }
    for(i=0; i<n; i++){
        for (j=i+1; j<n; j++)
            while ( (plat_bouncy[j].x-68<=plat_bouncy[i].x && plat_bouncy[i].x<=plat_bouncy[j].x+68) && ((plat_bouncy[j].y-26<=plat_bouncy[i].y && plat_bouncy[i].y<=plat_bouncy[j].y+26)) ){
                plat_bouncy[i].x=rand()%332;
                plat_bouncy[i].y=-rand()%76;
            }
        for (j=0; j<k; j++)
            if ( (plat_normal[j].x-68<=plat_bouncy[i].x && plat_bouncy[i].x<=plat_normal[j].x+68) && ((plat_normal[j].y-14<=plat_bouncy[i].y && plat_bouncy[i].y<=plat_normal[j].y+14)) ){
                plat_bouncy[i].x=rand()%332;
                plat_bouncy[i].y=-rand()%76;
            }
        for (j=0; j<l; j++)
            if ( (plat_destruct[j].x-68<=plat_bouncy[i].x && plat_bouncy[i].x<=plat_destruct[j].x+68) && ((plat_destruct[j].y-14<=plat_bouncy[i].y && plat_bouncy[i].y<=plat_destruct[j].y+14)) ){
                plat_bouncy[i].x=rand()%332;
                plat_bouncy[i].y=-rand()%76;
            }
        for (j=0; j<m; j++)
            if ( (plat_floating[j].x-68<=plat_bouncy[i].x && plat_bouncy[i].x<=plat_floating[j].x+68) && ((plat_floating[j].y-14<=plat_bouncy[i].y && plat_bouncy[i].y<=plat_floating[j].y+14)) ){
                plat_bouncy[i].x=rand()%332;
                plat_bouncy[i].y=-rand()%76;
            }
    }
}