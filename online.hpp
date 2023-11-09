#ifndef ONLINE_HPP
#define ONLINE_HPP
#include <vector>

class Online{
    private:
        const std::vector<double> &itemSizes;
        int numItems;
    public:
        Online(const std::vector<double> &itemSizes, int numItems);

        /*
        *  @brief: Calculate the solution for the Bin Packing Problem using a Greedy Algorithm with an Online Next Fit heuristic
        *  @return: A 2D vector representing the solution for the Bin Packing Problem using this approach
        */
        std::vector<std::vector<double>> nextFit();

        /*
        *  @brief: Calculate the solution for the Bin Packing Problem using a Greedy Algorithm with an Online First Fit heuristic
        *  @return: A 2D vector representing the solution for the Bin Packing Problem using this approach
        */
        std::vector<std::vector<double>> firstFit();

        /*
        *  @brief: Calculate the solution for the Bin Packing Problem using a Greedy Algorithm with an Online Best Fit heuristic
        *  @return: A 2D vector representing the solution for the Bin Packing Problem using this approach
        */
        std::vector<std::vector<double>> bestFit();
};
#endif