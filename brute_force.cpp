#include "brute_force.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>

BruteForce::BruteForce(){

}

std::vector<std::vector<double>> BruteForce::bruteForceBinPacking(const std::vector<double>& itemSizes, double binCapacity) {
    std::vector<double> permutation(itemSizes.begin(), itemSizes.end());
    std::vector<std::vector<double>> bestBins;
    int minBins = itemSizes.size(); // Set it to maximum possible bins initially

    do {
        std::vector<std::vector<double>> currentSolution;
        
        for (int i = 0; i < permutation.size(); i++) {
            bool placed = false;

            for (int j = 0; j < currentSolution.size(); j++) {
                double spaceLeft = binCapacity - std::accumulate(currentSolution[j].begin(), currentSolution[j].end(), 0.0);
                double itemSize = permutation[i];

                // round both numbers to compare them
                spaceLeft = std::round(spaceLeft * 100.0) / 100.0;
                itemSize = std::round(itemSize * 100.0) / 100.0;

                if (spaceLeft >= itemSize) {
                    currentSolution[j].push_back(permutation[i]);
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                currentSolution.push_back({ permutation[i] });
            }
        }

        if (currentSolution.size() < minBins) {
            minBins = currentSolution.size();
            bestBins = currentSolution;
        }
    } while (std::next_permutation(permutation.begin(), permutation.end()));

    return bestBins;
}
