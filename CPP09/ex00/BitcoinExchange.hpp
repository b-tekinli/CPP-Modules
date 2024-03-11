#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <map>

class BitcoinExchange
{
private:
    BitcoinExchange();
    std::map<std::string, float> _data;

public:
    BitcoinExchange(int ac, char **av);
    ~BitcoinExchange();
    std::string getKeyAtIndex(int index);
    float getValueAtIndex(int index);
    BitcoinExchange(BitcoinExchange &obj);
    BitcoinExchange &operator=(BitcoinExchange &obj);
};

#endif
