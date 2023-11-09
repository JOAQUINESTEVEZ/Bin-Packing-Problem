#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "online.hpp"
#include "offline.hpp"
#include "brute_force.hpp"

void print(std::string description, const std::vector<std::vector<double>> &bins){
    int count = 0;

    std::cout << description << std::endl;
    for (const auto& row : bins) {
        std::cout << "Bin " << count << ": ";
        for (const auto& element : row) {
            std::cout << std::fixed << std::setprecision(2) << element << " ";
        }
        count++;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(){
    std::ifstream reader("items.txt");

    // if not opened, terminate program
    if(!reader.is_open()){
        std::cout << "Unable to open file" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    std::vector<double> itemSizes;

    // read items and store them in the vector
    while (std::getline(reader, line)){
        try{
            double size = std::stod(line);
            itemSizes.push_back(size);
        }catch(const std::exception& e){
            std::cout << line << " is not a double type" << std::endl;
        }
    }

    int numItems = itemSizes.size();
    
    // create Brute Force object
    BruteForce bruteForce;
    std::vector<std::vector<double>> bf = bruteForce.bruteForceBinPacking(itemSizes, 1.0);

    // create Online object
    Online online(itemSizes, numItems);
    std::vector<std::vector<double>> onlineNextFit= online.nextFit();
    std::vector<std::vector<double>> onlineFirstFit= online.firstFit();
    std::vector<std::vector<double>> onlineBestFit = online.bestFit();
    // create Offline objects
    Offline offline(itemSizes, numItems);
    std::vector<std::vector<double>> offlineFirstFit = offline.firstFit();
    std::vector<std::vector<double>> offlineBestFit = offline.bestFit();

    /*
    *   OUTPUT: PRINT AS SHOWN IN THE DEMO
    */
   std::cout << "Total items: " << numItems << std::endl;
   std::cout << "Policy              | Total Bins Used" << std::endl <<"--------------------" << "|-----------------" << std::endl;
   std::cout << "Optimal Solution    | " << bf.size() << std::endl;
   std::cout << "Online - First Fit  | " << onlineFirstFit.size() << std::endl;
   std::cout << "Online - Next Fit   | " << onlineNextFit.size() << std::endl;
   std::cout << "Online - Best Fit   | " << onlineBestFit.size() << std::endl;
   std::cout << "Offline - First Fit | " << offlineFirstFit.size() << std::endl;
   std::cout << "Offline - Best Fit  | " << offlineBestFit.size() << std::endl << std::endl;

    // print results
    print("Optimal: ", bf);
    print("Online - First Fit: ", onlineFirstFit);
    print("Online - Next Fit: ", onlineNextFit);
    print("Online - Best Fit: ", onlineBestFit);
    print("Offline - First Fit: ", offlineFirstFit);
    print("Offline - Best Fit: ", offlineBestFit);

}