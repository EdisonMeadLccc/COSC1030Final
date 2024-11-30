#include "../stock_gererator.h"
#include "../day.h"
#include <cassert>
#include <iostream>

// storck generator test
// test random in range
void testRandomRange(int times){
    for (int tests = 0; tests < times ; tests++) {
        int val = demand_generator(time(0)*(tests+1), 100);
        assert(val <= 1200 && val >= 701);
        std::cout << tests + 1 << " test passed \n";
    }
    std::cout << "all test passed\n";
}

// test if reorder is made if days left for 0 and under order threshold
void testReorder(){
    Day day;
    day.inventory = 2000;
    day.daysLeftForOrder = 0;
    int daysLeft;
    day.order(1000, 1000, daysLeft);
    assert(day.inventory = 1900);
    std::cout << "test pass \n";
}

int main(){
    //testRandomRange(10);

    testReorder();
}
