#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange()
{
	parseDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(std::string _database)
{
	parseDatabase(_database);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	return *this;
}

void BitcoinExchange::parseDatabase(std::string database)
{
	std::string line;

	std::ifstream db("data.csv");
	if (!db.is_open())
		throw ErrorData();
	std::getline(db, line);
	while (std::getline(db, line))
	{
		if (line.empty())
			continue;
		std::string date = line.substr(0, 10);
		std::string value = line.substr(11, line.length());
		_database[date] = std::stof(value);
	}
	db.close();
}

std::string BitcoinExchange::parseDate(std::string line)
{

	// between 2009 to 2022
	// month between 1 to 12
	// day between 1 to 31
	int year;
	int month;
	int day;

	year = std::stoi(line.substr(0, 4));
	month = std::stoi(line.substr(5, 2));
	day = std::stoi(line.substr(8, 2));

	if (year < 2007 || month < 1 || month > 12 || day < 1 || day > 31)
		throw InvalidDate();

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		throw InvalidDate();

	return line.substr(0, 10);
}

float BitcoinExchange::parseValue(std::string line)
{
	int pos = line.find("|");
	if (pos == std::string::npos || line[pos - 1] != ' ' || line[pos + 1] != ' ' || !line[pos + 2])
		throw InvalidFormat();
	float value = std::stof(line.substr(pos + 1, line.length()));
	if (value < 0)
		throw TooLowValue();
	else if (value > 1000)
		throw TooHighValue();
	return value;
}

void BitcoinExchange::calculValue(std::string date, float value)
{
	std::map<std::string, float>::iterator it = _database.lower_bound(date);
	if (it == _database.end())
	{
		--it;
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
	else if (it == _database.begin())
	{
		std::cout << "Error: No previous data." << std::endl;
	}
	else
	{
		if (it->first != date)
			--it;
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}

bool BitcoinExchange::exchange(std::string _filename)
{
	std::ifstream f(_filename);
	std::string line;
	if (!f)
		throw InvalidFile();
	std::getline(f, line);
	while (std::getline(f, line))
	{
		if (line.empty())
			continue;
		try
		{
			std::string date = parseDate(line);
			float value = parseValue(line);
			calculValue(date, value);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	f.close();
	return true;
}