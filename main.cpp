#include <iostream>
#include <vector>
#include "stock_gererator.h"
#include "day.h"
int main(){

    Day dayObj;
    int numOfDays;
    int orderThreshold, userDay, orderAmount; 
    double TotalInventory;
    int daysOut = 0;
    std::vector<Day> days;

    std::cout << "How many days: \n";
    std::cin >> numOfDays;

    std::cout << "starting Inventory: \n";
    std::cin >> dayObj.inventory;

    std::cout << "What day?: \n";
    std::cin >> userDay;

    std::cout << "reorder threshold: \n";
    std::cin >> orderThreshold;

    std::cout << "reorder amout: \n";
    std::cin >> orderAmount;


    int daysLeft = 14;
    for(dayObj.dayNum = 0; dayObj.dayNum < numOfDays; dayObj.dayNum++){
        dayObj.demand = demand_generator(dayObj.dayNum+1, 1000);
        dayObj.inventory = std::max(0, dayObj.inventory - dayObj.demand);
        
        dayObj.daysLeftForOrder = daysLeft;

        if (dayObj.inventory >= orderThreshold ) {
            dayObj.orderMessage = "";
            daysLeft = 14;
        }
        else if (dayObj.inventory <= orderThreshold) {
            dayObj.reorder = true;
            dayObj.orderMessage = "under Threshold ordering more";
            daysLeft -= 1;
            dayObj.order(orderAmount);
        }

        if (dayObj.inventory <= 0) {
            daysOut += 1;
        }
        
        TotalInventory += dayObj.inventory;
        dayObj.printInfo();
        days.push_back(dayObj);

    }


    days[userDay-1].printInfo();
    std::cout << "Days out of stock: " << daysOut << "\n";
    std::cout << "Average daily inventory level: " << TotalInventory/numOfDays << "\n";

    return 0;
}