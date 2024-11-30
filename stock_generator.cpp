#include "stock_gererator.h"
int demand_generator(int iter){
    int demand = 0;

    for(int c = 0; c < iter; ++c){
        demand += rand() % (1200 - 701) + 701;

    }

    return demand/iter;
}

double suggestedThreshold(int ADD){
    return (ADD*14)+62;
}
