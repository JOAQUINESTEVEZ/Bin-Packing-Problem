#ifndef OFFLINE_HPP
#define OFFLINE_HPP
#include <vector>

class Offline{
    private:
        const std::vector<double> &itemSizes;
        int numItems;
        /*
        *  @brief: Calculate if the first number is greater than the second number
        *  @param a: first number to be compared
        *  @param b: second number to be compared
        *  @return true if 'a' is greater than 'b', otherwise false
        */
        static bool descendingOrder(double a, double b);
    public:
        Offline(const std::vector<double> &itemSizes_, int numItems);
        /*
        *  @brief: Calculate the solution for the Bin Packing Problem using a Greedy Algorithm with an Offline First Fit heuristic
        *  @return: A 2D vector representing the solution for the Bin Packing Problem using this approach
        */
        std::vector<std::vector<double>> firstFit();
        /*
        *  @brief: Calculate the solution for the Bin Packing Problem using a Greedy Algorithm with an Offline Best Fit heuristic
        *  @return: A 2D vector representing the solution for the Bin Packing Problem using this approach
        */
        std::vector<std::vector<double>> bestFit();
};
#endif