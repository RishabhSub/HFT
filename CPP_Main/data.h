#ifndef DATA_H
#define DATA_H

#include <string>
#include <cstdint>
#include <map>
#include <vector>

struct StockData {
    std::string Date;
    double Price;
    double Close;
    double High;
    double Low;
    double Open;
    uint64_t Volume;
};

class DataCollector {

private:
    std::map<std::string, std::vector<StockData>> stockdata;

public:
    DataCollector();
    void ReadData(std::map<std::string, std::vector<StockData>>  &stockdata);

    void LineOfData(std::map<std::string, std::vector<StockData>>  &stockdata, std::string ticker);

    // std::string getTicker(std::map<std::string, std::vector<StockData>> &stockdata);
    // std::string getDate(std::map<std::string, std::vector<StockData>>&stockdata, std::string ticker);
    // double getClose(std::map<std::string, std::vector<StockData>> &stockdata, std::string ticker);
    // double getHigh(std::map<std::string, std::vector<StockData>> &stockdata, std::string ticker);
    // double getLow(std::map<std::string, std::vector<StockData>> &stockdata, std::string ticker);
    // double getOpen(std::map<std::string, std::vector<StockData>> &stockdata, std::string ticker);
    // uint64_t getVolume(std::map<std::string, std::vector<StockData>> &stockdata, std::string ticker);
    
};

#endif