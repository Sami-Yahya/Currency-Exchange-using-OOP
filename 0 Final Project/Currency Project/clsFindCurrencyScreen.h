#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enFindOption { eByCode = 1, eByCountry = 2 };

	static short _ReadFindOption()
	{
		cout << "Find by: [1]:Code or [2]:Country ? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 2, "[1]:Code or [2]:Country ? ");

		return Choice;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n________________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n________________________\n";
	}

	static bool _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
			return true;
		}
		else
		{
			cout << "Currency was not Found :-(\n";
			return false;
		}
	}

	static void _PerformFindOption(enFindOption FindOption)
	{
		switch (FindOption)
		{
		case clsFindCurrencyScreen::eByCode:
		{
			string CurrencyCode;
			char Answer = 'N';

			do
			{
				cout << "\nPlease enter Currency Code: ";
				CurrencyCode = clsInputValidate::ReadString();

				clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);

				if (_ShowResult(C1))
					return; //exit after finding the currency
				else
					cout << "Do you want to search again? [Y/N]: ";
					cin >> Answer;

			} while (toupper(Answer) == 'Y');

			break;
		}
		case clsFindCurrencyScreen::eByCountry:
		{
			string Country;
			char Answer = 'N';

			do
			{
				cout << "\nPlease enter Country Name: ";
				Country = clsInputValidate::ReadString();

				clsCurrency C1 = clsCurrency::FindByCountry(Country);

				if (_ShowResult(C1))
					return; //exit after finding the currency
				else
					cout << "Do you want to search again? [Y/N]: ";
					cin >> Answer;

			} while (toupper(Answer) == 'Y');

			break;
		}
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		_PerformFindOption((enFindOption)_ReadFindOption());
	}

};
