#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

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

	static float _ReadRate()
	{
		cout << "Enter New Rate: ";
		float NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Rate");

		string CurrencyCode = "";
		cout << "Please Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::DoesCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(C1);

		char Answer = 'N';
		cout << "\nAre you sure you want to update the rate of this currency? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpdate Currency Rate:\n";
			cout << "---------------------\n";

			C1.UpdateRate(_ReadRate());
			
			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrency(C1);
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}

};
