#include "data.h"
#include <cstdlib>
#include <iostream>

int main() {
    std::map<std::string, std::vector<StockData>> stockdata;
    DataCollector dc;
    std::string input;
    std::cin >> input;

    while (input != "S") {
        dc.ReadData(stockdata);
        dc.LineOfData(stockdata, "ITC.NS");
        std::cin >> input;
    }

    std::cout << "Done!" << std::endl;
    return 0;
}