#ifndef DATA_H
#define DATA_H

#include <string>
#include <cstdint>
#include <vector>

struct StockData {
    // std::string Ticker;
    std::string Date;
    double Close;
    double High;
    double Low;
    double Open;
    uint64_t Volume;
};

class DataCollector {

private:
    std::vector<StockData> stockdata;
    // void EnterData(std::vector<StockData> &stockdata);

public:
    DataCollector();
    void ReadData(std::vector<StockData> &stockdata);
    // void StoreValues(std::vector<StockData> &stockdata);

    // std::string getTicker(std::vector<StockData> &stockdata);
    // std::string getDate(std::vector<StockData> &stockdata);
    // double getClose(std::vector<StockData> &stockdata);
    // double getHigh(std::vector<StockData> &stockdata);
    // double getLow(std::vector<StockData> &stockdata);
    // double getOpen(std::vector<StockData> &stockdata);
    // uint64_t getVolume(std::vector<StockData> &stockdata);
    
};

#endif