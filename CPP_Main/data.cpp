#include "data.h"
#include <iostream>
#include <fstream>
#include <string>

DataCollector::DataCollector()
{
}

void DataCollector::ReadData(std::map<std::string, std::vector<StockData>> &stockdata) {
    std::map<std::string, std::vector<StockData>>* sdptr = &stockdata;
    std::ifstream fd;
    std::string wholeLine = "";
    int commaLocation = 0;
    std::string first = "";
    std::string ticker = "";

    std::string date;
    double price, close, high, low, open;
    uint64_t volume;

    fd.open("../HistoricalFinancialData/ITC.csv");

    // checking for file correctness
    if (!fd) {
        return;
    }
    // skip the first line, this is a line of headers
    std::getline(fd, wholeLine);

    // Get the Ticker
    std::getline(fd, wholeLine);
    commaLocation = wholeLine.find(',');
    wholeLine = wholeLine.substr(commaLocation + 1, wholeLine.length());
    commaLocation = wholeLine.find(',');
    ticker = wholeLine.substr(0, commaLocation);
    stockdata.emplace(ticker, std::vector<StockData>{});

    // continue reading CSV file until its complete
    while (fd) {
        StockData sd;
        getline(fd, wholeLine);

        if (wholeLine == "") {
            return;
        }

        // get date
        commaLocation = wholeLine.find(",");
        date = wholeLine.substr(0, commaLocation);
        sd.Date = date;
        wholeLine = wholeLine.substr(commaLocation + 1, wholeLine.length());

        // get price
        commaLocation = wholeLine.find(",");
        price = stod(wholeLine.substr(0, commaLocation));
        sd.Price = price;
        wholeLine = wholeLine.substr(commaLocation + 1, wholeLine.length());

        // get close 
        commaLocation = wholeLine.find(",");
        close = stod(wholeLine.substr(0, commaLocation));
        sd.Close = close;
        wholeLine = wholeLine.substr(commaLocation + 1, wholeLine.length());

        // get high
        commaLocation = wholeLine.find(",");
        high = stod(wholeLine.substr(0, commaLocation));
        sd.High = high;
        wholeLine = wholeLine.substr(commaLocation + 1, wholeLine.length());

        // get low
        commaLocation = wholeLine.find(",");
        low = stod(wholeLine.substr(0, commaLocation));
        sd.Low = low;
        wholeLine = wholeLine.substr(commaLocation + 1, wholeLine.length());

        // get open
        commaLocation = wholeLine.find(",");
        open = stod(wholeLine.substr(0, commaLocation));
        sd.Open = open;
        wholeLine = wholeLine.substr(commaLocation + 1, wholeLine.length());

        // volume
        commaLocation = wholeLine.find(",");
        volume = stoull(wholeLine.substr(0, commaLocation));
        sd.Volume = volume;
        wholeLine = wholeLine.substr(commaLocation + 1, wholeLine.length());

        stockdata[ticker].push_back(sd);
    }

    fd.close();
}

void DataCollector::LineOfData(std::map<std::string, std::vector<StockData>> &stockdata, std::string ticker) {
    std::vector<StockData> line = stockdata[ticker];
    std::cout   << "One line of stock data: "
                << line[0].Date << ", "
                << std::to_string(line[0].Price) << ", "
                << std::to_string(line[0].Close) << "," 
                << std::to_string(line[0].High) << ", "
                << std::to_string(line[0].Low) << ", "
                << std::to_string(line[0].Open) << ", "
                << std::to_string(line[0].Volume) 
                << std::endl;
}

// std::string DataCollector::getTicker(std::map<std::string, std::vector<StockData>> &stockdata) {
//     return "";
// }

// std::string DataCollector::getDate(std::map<std::string, std::vector<StockData>> &stockdata, std::string ticker) {
//     return stockdata[ticker].Date;
// }

// double DataCollector::getClose(std::map<std::string, std::vector<StockData>> &stockdata) {
//     return;
// }

// double DataCollector::getHigh(std::map<std::string, std::vector<StockData>> &stockdata) {
//     return;
// }

// double DataCollector::getLow(std::map<std::string, std::vector<StockData>> &stockdata) {
//     return;
// }

// double DataCollector::getOpen(std::map<std::string, std::vector<StockData>> &stockdata) {
//     return;
// }

// uint64_t DataCollector::getVolume(std::map<std::string, std::vector<StockData>> &stockdata) {
//     return;
// }