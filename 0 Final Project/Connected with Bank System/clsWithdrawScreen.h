#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n________________________";
        cout << "\nFirst Name  : " << Client.FirstName;
        cout << "\nLast Name   : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n________________________\n";
    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = "";
        cout << "Please enter client account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist!\n";
            cout << "Please try again: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter withdraw amount: ";
        Amount = clsInputValidate::ReadPositiveDblNumber("Enter a postive number! : ");

        //Validate that the amount does not exceeds the balance
        while (Amount > Client1.AccountBalance)
        {
            cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client1.AccountBalance << endl;
            cout << "Please enter another amount: ";
            Amount = clsInputValidate::ReadPositiveDblNumber("Enter a postive number! : ");
        }

        char Answer = 'N';
        cout << "\n\nAre you sure you want to perform this transaction? [Y/N]: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Client1.Withdraw(Amount);
            Client1.SaveToTransHistoy(Amount * -1);
            cout << "\nAmount Withdrawed Successfully.\n";
            cout << "New Balance is: " << Client1.AccountBalance << endl;
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }

};
