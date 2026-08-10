#include "data.h"
#include <cstdlib>

int main() {
    std::vector<StockData> stockdata;
    DataCollector dc;
    
    dc.ReadData(stockdata);

    return 0;
}