#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange &obj)
{
    _data = obj._data;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &obj)
{
    this->_data = obj._data;
    return *this;
}

std::string BitcoinExchange::getKeyAtIndex(int index)
{
    std::map<std::string, float>::iterator end = this->_data.end();

    int counter = 0;
    for (std::map<std::string, float>::iterator it = this->_data.begin(); it != this->_data.end(); ++it)
    {
        if (counter == index)
            return it->first;
        counter++;
    }

    return (0);
}

float BitcoinExchange::getValueAtIndex(int index)
{
    std::map<std::string, float>::iterator end = this->_data.end();

    int counter = 0;
    for (std::map<std::string, float>::iterator it = this->_data.begin(); it != this->_data.end(); ++it)
    {
        if (counter == index)
            return it->second;
        counter++;
    }

    return (0);
}

BitcoinExchange::BitcoinExchange(int ac, char **av)
{
    if (ac == 2)
    {
        std::ifstream a("data.csv");
        std::ifstream in(av[1]);
        std::string date;
        std::string dateIn;
        std::string coinIn;
        std::string coinL;
        std::map<std::string, float>::iterator it;
        float coin;
        size_t n;

        it = this->_data.begin();
        if (!in.good())
        {
            std::cerr << "file error" << std::endl;
            exit(1);
        }

        std::getline(a, date);
        std::getline(in, dateIn);

        dateIn.erase(dateIn.find(','));

        if ("date" == date)
        {
            for (int i = 0; std::getline(a, date); i++)
            {
                coinL = date;
                date.erase(date.find(','));
                coinL.erase(0, coinL.find(',') + 1);
                coin = stof(coinL);
                this->_data[date] = coin;
            }

        label:

            while (std::getline(in, dateIn))
            {
                coinIn = dateIn;
                n = coinIn.find('|');
                if (n > coinIn.length())
                {
                    std::cerr << "Error: bad input => " << coinIn << std::endl;
                    std::getline(in, dateIn);
                    coinIn = dateIn;
                    n = coinIn.find('|');
                }
                dateIn.erase(dateIn.find('|'));
                dateIn.erase(dateIn.find(' '));
                coinIn.erase(0, n + 1);
                coinIn.erase(0, coinIn.find(' ') + 1);
                if (stof(coinIn) < 1)
                {
                    std::cerr << "Error: not a positive number." << std::endl;
                    goto label;
                }
                if (coinIn == "2147483648")
                {
                    std::cerr << "Error: too large a number." << std::endl;
                    goto label;
                }
                it = this->_data.upper_bound(dateIn);
                it--;
                std::cout << dateIn << " => " << coinIn << " = " << it->second * std::stof(coinIn) << std::endl;
            }
        }
        else if ("exchange_rate" == date)
        {
            std::cout << date << std::endl;
        }
        else
        {
            std::cout << "',' in the wrong place or the file is incorrect " << std::endl;
            std::cout << "file example\n"
                      << "------------\n"
                      << "date,exchange_rate\n"
                      << "2009-01-02,0\n"
                      << "2009-01-05,0\n"
                      << "2009-01-08,0" << std::endl;
        }
    }
    else
        std::cerr << "Error: could not open file." << std::endl;
}
