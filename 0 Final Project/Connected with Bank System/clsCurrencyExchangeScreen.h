#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>
using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:

	enum enCurrencyExchangeOptions { eListCurrencies = 1,eFindCurrency = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4, eBackMainMenu = 5 };

	static short _ReadCurrencyExchangeOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]: ";

		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between [1 to 5]: ");

		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Currency Exchange Menu... ";
		system("pause>0");
		ShowCurrencyExchangeMenu();
	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyExchangeOption(enCurrencyExchangeOptions CurrencyExchangeOption)
	{
		switch (CurrencyExchangeOption)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case clsCurrencyExchangeScreen::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case clsCurrencyExchangeScreen::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case clsCurrencyExchangeScreen::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}
		case clsCurrencyExchangeScreen::eBackMainMenu:
		{
			//do nothing here the main screen will handle it :-)
			break;
		}
		}
	}

public:

	static void ShowCurrencyExchangeMenu()
	{
		if (!_CheckAccessRights(clsUser::enUserPermissions::pCurrencyExchange))
		{
			return; //this will exit the function and it will not continue
		}

		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Screen");

		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\t Currency Exchange Menu\n";
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Currencies List.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Go Back to Main Menu.\n";
		cout << setw(37) << left << "" << "==============================================\n";

		_PerformCurrencyExchangeOption((enCurrencyExchangeOptions)_ReadCurrencyExchangeOption());
	}

};
