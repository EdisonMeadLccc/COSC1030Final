#include "stock_gererator.h"
#include <cmath>
#include <cstdlib>
int demand_generator(int iter, int day){
    int demand = 0;

    for(int c = 0; c < iter; ++c){
        srand(time(0)*(day+1));
        demand += rand() % (1200 - 701) + 701;

    }

    return demand/iter;
}

