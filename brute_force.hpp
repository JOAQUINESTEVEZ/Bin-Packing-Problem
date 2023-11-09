#ifndef BRUTE_FORCE_HPP
#define BRUTE_FORCE_HPP
#include <vector>
#include <string>

class BruteForce{
    public:
        BruteForce();
        /*
        *  @brief: Brute Force approach to solve Bin Packing Problem
        *  @param itemSizes: The vector of sizes to be packed
        *  @param binCapacity: The maximum capacity of a bin
        *  @return: A 2D vector representing the optimal solution for the Bin Packing Problem
        */
        std::vector<std::vector<double>> bruteForceBinPacking(const std::vector<double>& itemSizes, double binCapacity);
};
#endif