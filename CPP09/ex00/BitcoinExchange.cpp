#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream data("./data.csv");
	if (!data.is_open())
		throw(std::string) "cannot open data base";
	std::string line;
	getline(data, line);
	while (getline(data, line))
	{
		fillData(line);
	};
	data.close();
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->sData.value = other.sData.value;
	this->sData.date = other.sData.date;

	for (std::map<std::string, float>::const_iterator it = other.btcData.begin(); it != other.btcData.end(); ++it)
	{
		this->btcData[it->first] = it->second;
	}
};

BitcoinExchange::~BitcoinExchange(){};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->sData.value = other.sData.value;
		this->sData.date = other.sData.date;

		this->btcData.clear();
		std::map<std::string, float>::const_iterator it;
		for (it = other.btcData.begin(); it != other.btcData.end(); ++it)
		{
			this->btcData[it->first] = it->second;
		}
	}
	return *this;
};

void BitcoinExchange::fillData(std::string line)
{
	int i = 0;
	std::string key;
	std::stringstream ss(line);
	std::string token;
	while (getline(ss, token, ','))
	{
		if (i == 0)
		{
			sData.date = token;
			i = 1;
		}
		else
			sData.value = atof(token.c_str());
	}
	this->btcData.insert(std::make_pair(sData.date, sData.value));
}

void BitcoinExchange::handleInputFile(std::string fileName)
{
	int year;
	int month;
	int day;
	float value;
	char extra;

	std::string line;
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		throw(std::string) "cannot open file";
	getline(file, line);
	if (line != "date | value")
		throw(std::string) "Invalid first line in data file. Expected 'date | value'.";
	bool firstLine = true;
	while (getline(file, line))
	{
		if (firstLine)
			firstLine = false;
		if (line.length() < 14)
		{
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		else if (sscanf((line.c_str()), "%d-%d-%d | %f%c", &year, &month, &day,
						&value, &extra) == 4)
		{
			if (std::isspace(line[13]) || line[11] != '|' || line[line.length() - 1] == '.')
			{
				std::cout << "Error : bad input => " << line << std::endl;
				continue;
			}
			try
			{
				checkValues(value);
				checkDate(year, month, day);
			}
			catch (std::string error)
			{
				std::cout << "Error: " << error << std::endl;
				continue;
			}
		}
		else
		{
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}
		size_t pos;

		pos = line.find(' ');
		sData.date = line.substr(0, pos);
		sData.value = value;
		findDateAndCalculate();
	}
	if (firstLine)
		throw(std::string) "file is empty";
}

void BitcoinExchange::checkValues(float value)
{
	if (value > 1000)
		throw(std::string) "too large number.";
	if (value < 0)
		throw(std::string) "not a positive number.";
}
int BitcoinExchange::isLeap(int year)
{
	bool ReturnValue = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? true : false;
	return (ReturnValue);
}
void BitcoinExchange::checkDate(int year, int month, int day)
{

	if (month < 1 || month > 12 || day < 1)
		throw(std::string) "invalid date";
	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && (isLeap(year) == true))
		months[1] = 29;
	(day > months[month - 1]) ? throw(std::string) "invalid day" : 0;
	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
	{
		throw(std::string) "min year : (2009-01-02)";
	}
}

void BitcoinExchange::findDateAndCalculate()
{
	std::map<std::string, float>::iterator it;
	it = this->btcData.lower_bound(sData.date);
	if (it == this->btcData.end())
	{
		it--;
		std::cout << std::setprecision(7) << sData.date << " => " << std::setprecision(7) << sData.value << " = " << sData.value * (*it).second << std::endl;
		return;
	}
	if (it == this->btcData.begin())
	{
		std::cerr << "cannot find any closer data" << std::endl;
		return;
	}
	else
	{
		if ((*it).first != sData.date)
			it--;
		std::cout << std::setprecision(7) << sData.date << " => " << std::setprecision(7) << sData.value << " = " << std::setprecision(7) << (float)(sData.value * (*it).second) << std::endl;
	}
}

void BitcoinExchange::printMap()
{
	std::map<std::string, float>::const_iterator it;
	for (it = btcData.begin(); it != btcData.end(); ++it)
	{
		std::cout << it->first << std::endl;
	}
}