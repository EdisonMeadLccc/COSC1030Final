#include <iostream>
#include <vector>
#include "stock_gererator.h"
#include "day.h"
int main(){

    Day dayObj;
    int orderThreshold, userDay, orderAmount, startInv; 
    double TotalInventory, totalDemand, numOfDays;
    int daysOut = 0;
    std::vector<Day> days;

    //prompts user
    std::cout << "How many days: \n";
    std::cin >> numOfDays;

    std::cout << "starting Inventory: \n";
    std::cin >> startInv;
    dayObj.setInventory(startInv);

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

        dayObj.CalcInventory();
        
        dayObj.setDaysLeftForOrder(daysLeft);

        //tracking inventory levels 
        if (dayObj.getInventory() > orderThreshold ) {
            dayObj.setDaysLeftForOrder(daysLeft);
        }
        if (dayObj.getInventory() <= orderThreshold) {
            daysLeft -= 1;
            dayObj.order(orderThreshold, orderAmount, daysLeft);
        }

        if (dayObj.getInventory() <= 0) {
            daysOut += 1;
        }

        
        TotalInventory += dayObj.getInventory();
        totalDemand += dayObj.getDemand();


        days.push_back(dayObj);
        if (userDay == 0) {
            dayObj.printInfo();
        }



    }
        if(userDay > 0) {
            days[userDay-1].printInfo();
        }

    std::cout << "Days out of stock: " << daysOut << "\n";
    std::cout << "Average daily inventory level: " << TotalInventory/numOfDays << "\n";
    std::cout << "suggested reorder threshold: " << dayObj.suggestedThreshold(totalDemand, days) << "\n";

    return 0;
}
