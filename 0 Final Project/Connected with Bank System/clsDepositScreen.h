#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsDepositScreen : protected clsScreen
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

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

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
        cout << "\nPlease enter deposit amount: ";
        Amount = clsInputValidate::ReadPositiveDblNumber("Enter a postive number! : ");

        char Answer = 'N';
        cout << "\n\nAre you sure you want to perform this transaction? [Y/N]: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Client1.Deposit(Amount);
            Client1.SaveToTransHistoy(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "New Balance is: " << Client1.AccountBalance << endl;
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }

};
