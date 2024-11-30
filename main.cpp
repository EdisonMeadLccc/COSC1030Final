#include <iostream>
#include <vector>
#include "stock_gererator.h"
#include "day.h"
int main(){

    Day dayObj;
    double numOfDays;
    int orderThreshold, userDay, orderAmount; 
    double TotalInventory;
    double totalDemand;
    int daysOut = 0;
    std::vector<Day> days;

    //prompts user
    std::cout << "How many days: \n";
    std::cin >> numOfDays;

    std::cout << "starting Inventory: \n";
    std::cin >> dayObj.inventory;

    std::cout << "What day?(0 for all): \n";
    std::cin >> userDay;

    std::cout << "reorder threshold: \n";
    std::cin >> orderThreshold;

    std::cout << "reorder amout: \n";
    std::cin >> orderAmount;



    int daysLeft = 14;

    // Main simulation
    for(dayObj.setDay(0); dayObj.getDay()< numOfDays; dayObj.nextDay()){

        // Generate daily demand and calculates inventory after demand
        dayObj.setDemand();
        //dayObj.demand = demand_generator(1000);

        dayObj.CalcInventory();
        //dayObj.inventory = std::max(0, dayObj.inventory - dayObj.demand);
        
        dayObj.setDaysLeftForOrder(daysLeft);
        //dayObj.daysLeftForOrder = daysLeft;

        //tracking inventory levels 
        if (dayObj.getInventory() > orderThreshold ) {
            //dayObj.orderMessage = "";
            dayObj.setDaysLeftForOrder(daysLeft);
            //daysLeft = 14;
            //dayObj.reorder = false;
        }
        if (dayObj.getInventory() <= orderThreshold) {
            //dayObj.reorder = true;
            //dayObj.orderMessage = "under Threshold ordering more";
            daysLeft -= 1;
            dayObj.order(orderThreshold, orderAmount, daysLeft);
        }

        if (dayObj.getInventory() <= 0) {
            daysOut += 1;
        }

        
        TotalInventory += dayObj.getInventory();
        totalDemand += dayObj.getDemand();


        if (userDay == 0) {
            dayObj.printInfo();
            days.push_back(dayObj);
        }


        else if(userDay > 0) {
            days[userDay-1].printInfo();
        }

    }

    std::cout << "Days out of stock: " << daysOut << "\n";
    std::cout << "Average daily inventory level: " << TotalInventory/numOfDays << "\n";
    std::cout << "suggested reorder threshold: " << suggestedThreshold(totalDemand/numOfDays) << "\n";

    return 0;
}
