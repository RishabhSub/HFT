#include "data.h"
#include <iostream>
#include <fstream>
#include <string>

DataCollector::DataCollector()
{
}

void DataCollector::ReadData(std::vector<StockData> &stockdata) {
    std::ifstream fd;
    std::string line = "";
    int commaLocation = 0;
    std::string first = "";

    fd.open("../HistoricalFinancialData/ITC.csv");
    std::getline(fd, line);
    std::getline(fd, line);
    std::getline(fd, line);
    commaLocation = line.find(',');
    first = line.substr(0, commaLocation);
    line = line.substr(commaLocation + 1, line.length());

    std::cout << first << std::endl;
}

// void DataCollector::EnterData(std::vector<StockData> &stockdata) {

// }

// void DataCollector::StoreValues(std::vector<StockData> &stockdata) {

// }

// // std::string DataCollector::getTicker(std::vector<StockData> &stockdata) {
// //     return;
// // }

// std::string DataCollector::getDate(std::vector<StockData> &stockdata) {
//     return;
// }

// double DataCollector::getClose(std::vector<StockData> &stockdata) {
//     return;
// }

// double DataCollector::getHigh(std::vector<StockData> &stockdata) {
//     return;
// }

// double DataCollector::getLow(std::vector<StockData> &stockdata) {
//     return;
// }

// double DataCollector::getOpen(std::vector<StockData> &stockdata) {
//     return;
// }

// uint64_t DataCollector::getVolume(std::vector<StockData> &stockdata) {
//     return;
// }