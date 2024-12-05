# COSC1030Final
A program that simulates inventory management for a product. 

The program will ask for a user-defined number of days, it will track demand and inventory and calculate statistics inventory metrics.  

 

Main.cpp 

Main simulation  

 

day.h 

The day class, handles daily data 

    DayNum 

    Inventory  

    Demand 

    Days remain for an order to arrive  

    Order status message 

    Day methods 

    printInfo(): Prints detailed info for the day. 

    printDayNum(): Prints the current day number. 

    printOnHandAtStart(): Prints on-hand inventory at the start of the day. 

    printDaysLeft(): Prints the days remaining for a reorder. 

    setInventory(int inventory): Sets the starting inventory. 

    addInventory(int add): Adds inventory to the current stock. 

    CalcInventory(): Adjusts inventory after accounting for demand. 

    getInventory(): Returns the current inventory level. 

    setDemand(): Generates random demand for the day. 

    getDemand(): Returns the current demand. 

    setDay(int num): Sets the day number. 

    nextDay(): Advances the day number. 

    getDay(): Returns the current day number. 

    setDaysLeftForOrder(int days): Sets the days left for an order to arrive. 

    order(int orderThreshold, int orderAmount, int& daysLeft): Places an order if below the threshold. 

    suggestedThreshold(double totalDemand, std::vector<Day> Days): Suggests an optimal reorder threshold using historical demand and statistical deviation. 

 

demand_generator(int iter, int day) 

Generates random demand values 

    Iter: Number of times a random demand is pulled for average calculation.  

    day: Current day. 

