#include "online.hpp"
#include <numeric>
#include <cmath>

Online::Online(const std::vector<double> &itemSizes_, int numItems_)
    : itemSizes(itemSizes_), numItems(numItems_) {}

std::vector<std::vector<double>> Online::nextFit(){
    std::vector<std::vector<double>> bins;

    for(double size : itemSizes){
        if(bins.empty()) bins.push_back({size});
        
        else{
            double lastBinSize = std::accumulate(bins.back().begin(), bins.back().end(), 0.0);
            double remainingSize = 1.0 - lastBinSize;

            if(remainingSize >= size) bins.back().push_back(size);

            else bins.push_back({size});
        }
    }
    return bins;
}

std::vector<std::vector<double>> Online::firstFit(){
    std::vector<std::vector<double>> bins;

    for(double size : itemSizes){
        bool placed = false;

        for(std::vector<double> &bin : bins){
            double lastBinSize = std::accumulate(bin.begin(), bin.end(), 0.0);
            double availableSpace = 1.0 - lastBinSize;

            // round both numbers to compare them
            availableSpace = std::round(availableSpace * 100.0) / 100.0;
            size = std::round(size * 100.0) / 100.0;
    
            if(availableSpace >= size){
                bin.push_back(size);
                placed = true;
                break;
            }
        }

        if(!placed) bins.push_back({size});
    }
    return bins;
}

std::vector<std::vector<double>> Online::bestFit(){
    std::vector<std::vector<double>> bins;

    for(double size : itemSizes){
        int index = -1;
        double minSpaceLeft = 100.0; // initialize with a large value;

        for(int i = 0; i < bins.size(); i++){
            double lastBinSize = std::accumulate(bins[i].begin(), bins[i].end(), 0.0);
            double availableSpace = 1.0 - lastBinSize;

            // set values to 2 decimal places to compare them
            availableSpace = std::round(availableSpace * 100.0) / 100.0;
            size = std::round(size * 100.0) / 100.0;
           
            if(availableSpace >= size && availableSpace < minSpaceLeft){
                index = i;
                minSpaceLeft = availableSpace;
            }
        }

        if(index == -1) bins.push_back({size});
        else bins[index].push_back(size);
    }
    return bins;
}
