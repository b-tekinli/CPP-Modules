#ifndef BTC_H
#define BTC_H

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>

class BitcoinExchange
{
private:
    struct
    {
        float value;
        std::string date;
    } sData;

    std::map<std::string, float> btcData;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void fillData(std::string string);
    void handleInputFile(std::string fileName);
    void checkValues(float value);
    void checkDate(int year, int month, int day);
    void findDateAndCalculate();
    void printMap();
    int isLeap(int year);
};

#endif
