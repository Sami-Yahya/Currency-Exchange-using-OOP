#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        string UserInput;

        cout << "\nEnter -99 to skip: ";
        cout << "\nEnter First Name: ";
        UserInput = clsInputValidate::ReadString();
        if (UserInput != "-99")
        {
            Client.FirstName = UserInput;
        }

        cout << "Enter Last Name: ";
        UserInput = clsInputValidate::ReadString();
        if (UserInput != "-99")
        {
            Client.LastName = UserInput;
        }

        cout << "Enter Email: ";
        UserInput = clsInputValidate::ReadString();
        if (UserInput != "-99")
        {
            Client.Email = UserInput;
        }

        cout << "Enter Phone: ";
        UserInput = clsInputValidate::ReadString();
        if (UserInput != "-99")
        {
            Client.Phone = UserInput;
        }

        cout << "Enter Pin Code: ";
        UserInput = clsInputValidate::ReadString();
        if (UserInput != "-99")
        {
            Client.PinCode = UserInput;
        }

        cout << "Enter Account Balance: ";
        float Balance = clsInputValidate::ReadFloatNumber();
        if (Balance > 0)
        {
            Client.AccountBalance = Balance;
        }
    }

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

    static void ShowUpdateClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enUserPermissions::pUpdateClient))
        {
            return; //this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tUpdate Client Screen");
        
        string AccountNumber = "";
        cout << "Please enter client account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client1);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError, account was not saved because it's Empty.";
            break;
        }
        }
    }

};
