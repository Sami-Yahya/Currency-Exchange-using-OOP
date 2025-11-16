#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n________________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n________________________\n";
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");

		string SourceAccountNumber = "";
		cout << "Please enter Account Number to transfer From: ";
		SourceAccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(SourceAccountNumber))
		{
			cout << "\nClient with [" << SourceAccountNumber << "] does not exist!\n";
			cout << "Please try again: ";
			SourceAccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient SourceClient = clsBankClient::Find(SourceAccountNumber);
		_PrintClientCard(SourceClient);

		string DestinationAccountNumber = "";
		cout << "\nPlease enter Account Number to transfer To: ";
		DestinationAccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(DestinationAccountNumber) || DestinationAccountNumber == SourceAccountNumber)
		{
			cout << "\nClient with [" << DestinationAccountNumber << "] does not exist!\n";
			cout << "Please try again: ";
			DestinationAccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient DestinationClient = clsBankClient::Find(DestinationAccountNumber);
		_PrintClientCard(DestinationClient);

		double Amount = 0;
		cout << "\nPlease enter transfer amount: ";
		Amount = clsInputValidate::ReadPositiveDblNumber("Enter a postive number! : ");

		//Validate that the amount does not exceeds the balance
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the balance, you can withdraw up to : " << SourceClient.AccountBalance << endl;
			cout << "Please enter another amount: ";
			Amount = clsInputValidate::ReadPositiveDblNumber("Enter a postive number! : ");
		}

		char Answer = 'N';
		cout << "\n\nAre you sure you want to perform this operation? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName()))
			{
				cout << "\nTransfer done Successfully.\n";
				_PrintClientCard(SourceClient);
				_PrintClientCard(DestinationClient);
			}
			else
				cout << "\nTransfer Faild.\n";
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}

};
