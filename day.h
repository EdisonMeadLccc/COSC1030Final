#include <iostream>
#ifndef day_H
#define day_H

class Day{
    private:
    public:
        int dayNum, inventory, demand, daysLeftForOrder;
        bool reorder;
        std::string orderMessage = "";

        void printInfo(){
            std::cout << "Day: "<< dayNum + 1 << "\n";
            std::cout << "Inventory: " << inventory << "\n";
            std::cout << "demand: " << demand << "\n";
            std::cout << orderMessage << "\n";
            if (daysLeftForOrder >= 2 && reorder == true) {
                std::cout << "Days tell order arrives: " << daysLeftForOrder << "\n";
            
            }
        }
        void order(int orderThreshold, int orderAmount, int& daysLeft){
            //orderMessage = "under Threshold ordering more";
            //daysLeftForOrder -= 1;
            if (daysLeftForOrder <= 1) {
                daysLeft = 14;
                inventory = std::max(0, (orderAmount - demand) + inventory);

                if (inventory > orderThreshold) {
                    orderMessage = "";
                    reorder = false;
                }
            }
        }

};

#endif
