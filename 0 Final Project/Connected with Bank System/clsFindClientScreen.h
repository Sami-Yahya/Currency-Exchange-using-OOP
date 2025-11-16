#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
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

    static void ShowFindClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enUserPermissions::pFindClient))
        {
            return; //this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber;
        char Answer = 'N';

        do
        {
            cout << "\nPlease enter client account number: ";
            AccountNumber = clsInputValidate::ReadString();

            clsBankClient Client1 = clsBankClient::Find(AccountNumber);

            if (!Client1.IsEmpty())
            {
                cout << "\nClient Found :-)\n";
                _PrintClient(Client1);
                return; //exit after finding the client
            }
            else
            {
                cout << "Client was not Found :-(\n";
                cout << "Do you want to search again? [Y/N]: ";
                cin >> Answer;
            }

        } while (toupper(Answer) == 'Y');
    };

    //Another way to find client - instructor's solution
    /*
    static void ShowFindClientScreen()
    {
        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber;
        cout << "Please enter client account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);
    }
    */
     
         
};
