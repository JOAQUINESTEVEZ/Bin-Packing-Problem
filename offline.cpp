#include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>
#include "offline.hpp"

Offline::Offline(const std::vector<double> &itemSizes_, int numItems_)
    : itemSizes(itemSizes_), numItems(numItems_){}

bool Offline::descendingOrder(double a, double b){
    return a > b;
}

std::vector<std::vector<double>> Offline::firstFit(){
    std::vector<std::vector<double>> bins;

    std::vector<double> itemSizesSorted = itemSizes;
    std::sort(itemSizesSorted.begin(), itemSizesSorted.end(), descendingOrder);

    for(double size : itemSizesSorted){
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

std::vector<std::vector<double>> Offline::bestFit(){
    std::vector<std::vector<double>> bins;

    std::vector<double> itemSizesSorted = itemSizes;
    std::sort(itemSizesSorted.begin(), itemSizesSorted.end(), descendingOrder);

    for(double size : itemSizesSorted){
        int index = -1;
        double minSpaceLeft = 100.0; // initialize with a large value;

        for(int i = 0; i < bins.size(); i++){
            double lastBinSize = std::accumulate(bins[i].begin(), bins[i].end(), 0.0);
            double availableSpace = 1.0 - lastBinSize;

            // round values to compare them
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