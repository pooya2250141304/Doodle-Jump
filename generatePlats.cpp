
#include "generatePlats.h"
void generatePlats(point plat[], int n, float dy){
    for (int i=0;i<n;i++){
        plat[i].y = plat[i].y - dy;
        if (plat[i].y>533) {
            if (n>1){
                if (i<=n/4) plat[i].y = -rand()%41;
                else if (i<=n/2) plat[i].y = -82-rand()%82;
                else if (i<=3*n/4) plat[i].y = -168-rand()%82;
                else plat[i].y = -205-rand()%41;
            }
            else plat[i].y = -82-rand()%123;
            plat[i].x=rand()%332;
        }
    }
}