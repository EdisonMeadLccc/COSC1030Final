#include "stock_gererator.h"
int demand_generator(int seed, int iter){
    int demand = 0;
    int testd;

    srand(time(0)*seed); 

    for(int c = 0; c < iter; c++){
        demand += rand() % (1200 - 701);
    }

    return demand/iter;
}
