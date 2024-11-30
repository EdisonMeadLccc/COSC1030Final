#include <iostream>
#include "stock_gererator.h"
#ifndef day_H
#define day_H

class Day{
    private:
    public:
        int dayNum, inventory, demand, daysLeftForOrder;
        bool reorder;
        std::string orderMessage = "";

        // prints all days infor
        void printInfo(){
            std::cout << "\n--Day: " << dayNum + 1 << "--\n";
            std::cout << "Inventory: " << inventory << "\n";
            std::cout << "demand: " << demand << "\n";
            std::cout << orderMessage << "";
            if (daysLeftForOrder > 0 && reorder == true) {
                std::cout << "Days tell order arrives: " << daysLeftForOrder << "\n";
            }
        }

        // prints day number
        void printDayNum(){
            std::cout << "Day: " << dayNum + 1 << "\n";
        }

        // prints On hand at the start of the day
        void printOnHandAtStart(){
            std::cout << "On-hand monitors at the start of the day: " << inventory + demand << "\n";
        }

        // prints the days left for the order
        void printDaysLeft(){
            if (daysLeftForOrder > 0 && reorder == true) {
                std::cout << "Days tell order arrives: " << daysLeftForOrder << "\n";
            }
        }

        void setInventory(int inventory){
            this->inventory = inventory;
        }

        void addInventory(int add){
            this->inventory += add;
        }

        void CalcInventory(){
            inventory = std::max(0, inventory - demand);
        }
        
        int getInventory(){
            return inventory;
        }

        void setDemand(){
            this->demand = demand_generator(1000);
        }

        int getDemand(){
            return demand;
        }

        void setDay(int num){
            dayNum = num;
        }

        int nextDay(){
            return ++dayNum;
        }

        int getDay(){
            return dayNum;
        }

        void setDaysLeftForOrder(int days){
            this->daysLeftForOrder = days;
        }


        // prints the demand for that day
        void printDemand(){
            std::cout << "Demand: " << demand << "\n";
        }

        void order(int orderThreshold, int orderAmount, int& daysLeft){
            reorder = true;
            orderMessage = "under Threshold ordering more\n";
            if (daysLeftForOrder <= 0) {
                daysLeft = 14;
                inventory = (orderAmount - demand) + inventory;

                if (inventory > orderThreshold) {
                    orderMessage = "";
                    reorder = false;
                }
            }
        }

};

#endif
