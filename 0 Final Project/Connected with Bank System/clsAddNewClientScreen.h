#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter First Name: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "Enter Last Name: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "Enter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "Enter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "Enter Pin Code: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "Enter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadPositiveFloatNumber("Enter a positive number: ");
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

    static void ShowAddNewClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enUserPermissions::pAddNewClient))
        {
            return; //this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t  Add New Client");

        string AccountNumber = "";

        cout << "Please enter client account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is already used, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Created Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError, account was not saved because it's Empty.";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!";
            break;
        }
        }
    }

};
