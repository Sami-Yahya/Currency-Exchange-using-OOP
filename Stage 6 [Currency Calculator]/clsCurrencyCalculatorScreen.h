#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static float _ReadAmount()
	{
		cout << "Enter Amount to Exchange: ";
		float Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode = "";
		cout << Message;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::DoesCurrencyExist(CurrencyCode))
		{
			cout << "Currency Code is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return C1;
	}

	static void _DoTheyMatch(clsCurrency Currency1, clsCurrency& Currency2)
	{
		while (Currency1.CurrencyCode() == Currency2.CurrencyCode())
		{
			Currency2 = _GetCurrency("Please enter another currency, because they are mathing!: ");
		}
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card")
	{
		cout << "\n" << Title;
		cout << "\n------------------------";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n------------------------\n";
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		if (CurrencyFrom.CurrencyCode() != "USD")
		{
			_PrintCurrencyCard(CurrencyFrom, "Convert From:");

			//USD case
			float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

			cout << Amount << " " << CurrencyFrom.CurrencyCode()
				<< " = " << AmountInUSD << " USD\n";

			if (CurrencyTo.CurrencyCode() == "USD")
			{
				return;
			}
		}

		cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(CurrencyTo, "To: ");
		
		//other currency case
		float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() <<
			" = " << AmountInCurrency2 << " " << CurrencyTo.CurrencyCode() << endl;
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'Y';

		while (toupper(Answer) == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t  Currency Calculator");

			clsCurrency CurrencyFrom = _GetCurrency("Please Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("Please Enter Currency2 Code: ");
			_DoTheyMatch(CurrencyFrom, CurrencyTo);

			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? [Y/N]: ";
			cin >> Answer;
		}
	}

};
