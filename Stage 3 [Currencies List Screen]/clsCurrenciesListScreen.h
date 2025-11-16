#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:

	static void ShowCurrenciesList()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencis List Screen";
		string SubTitle = "\t  (" + to_string(vCurrencies.size()) + ") Currencies.";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
		cout << "-----------------------------------------------\n";

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name of Currency";
		cout << "| " << left << setw(10) << "Rate/(1$)";

		cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
		cout << "-----------------------------------------------\n";

		if (vCurrencies.size() == 0)
		{
			cout << "\n\t\t\tNo Currencies Available in the System!" << endl;
		}
		else
		{
			for (clsCurrency const& currency : vCurrencies)
			{
				_PrintCurrencyRecordLine(currency);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
		cout << "-----------------------------------------------\n";
	}

};
