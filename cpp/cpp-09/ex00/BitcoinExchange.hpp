#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <map>
#include <iostream>

class BitcoinExchange
{
	typedef struct
	{
		std::string date;
		float value;
	} DatabaseStruct;

private:
	std::string _input;
	std::map<std::string, float> _database;
	void parseDatabase(std::string database);
	std::string parseDate(std::string line);
	float parseValue(std::string line);
	void calculValue(std::string date, float value);
	// bool Parse

public:
	BitcoinExchange();
	BitcoinExchange(std::string _filename);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &copy);

	bool exchange(std::string _input);

	class InvalidFormat : public std::exception
	{
	public:
		const char *what() const throw() { return "Invalid Format."; };
	};

	class InvalidDate : public std::exception
	{
	public:
		explicit InvalidDate(std::string InvalidDate)
		{
			std::cout << "Error: Bad Input => " << InvalidDate << std::endl;
		};
	};

	class TooHighValue : public std::exception
	{
	public:
		const char *what() const throw() { return "Too Large a number."; };
	};

	class TooLowValue : public std::exception
	{
	public:
		const char *what() const throw() { return "Not a positive number."; };
	};

	class InvalidFile : public std::exception
	{
	public:
		const char *what() const throw() { return "Invaid File."; };
	};

	class ErrorData : public std::exception
	{
	public:
		const char *what() const throw() { return "Error occurred with the database."; };
	};
};

#endif