#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:

	static string ReadString()
	{
		string S1 = "";

		// Usage of std::ws will extract all the whitespace character
		getline(cin >> ws, S1);

		return S1;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Input, Enter agian:\n")
	{
		int Number = 0;

		while (!(cin >> Number))
		{
			//user didn't input a number

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		float Number;

		while (!(cin >> Number))
		{
			//user didn't input a number

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Input, Enter agian:\n")
	{
		double Number = 0;

		while (!(cin >> Number))
		{
			//user didn't input a number

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static int ReadPositiveIntNumber(string ErrorMessage = "Enter a postive number!: ")
	{
		int Number = ReadIntNumber();

		while (Number < 0)
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static float ReadPositiveFloatNumber(string ErrorMessage = "Enter a postive number!: ")
	{
		float Number = ReadFloatNumber();

		while (Number < 0)
		{
			cout << ErrorMessage;
			Number = ReadFloatNumber();
		}

		return Number;
	}

	static double ReadPositiveDblNumber(string ErrorMessage = "Enter a postive number!: ")
	{
		double Number = ReadDblNumber();

		while (Number < 0)
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!isNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}
	
	static float ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (!isNumberBetween(Number, From, To)) 
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}
	
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!isNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static bool isNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool isNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool isNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool isNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool isDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualsDate2(Date, From)
			&&
			clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualsDate2(Date, To)))
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualsDate2(Date, To)
			&&
			clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualsDate2(Date, From)))
		{
			return true;
		}

		return false;
	}

	static bool isValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

};

