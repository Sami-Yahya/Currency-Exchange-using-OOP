#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
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

	static void ShowDeleteClientScreen()
	{
        if (!_CheckAccessRights(clsUser::enUserPermissions::pDeleteClient))
        {
            return; //this will exit the function and it will not continue
        }

		_DrawScreenHeader("\tDelete Client Screen");

        string AccountNumber = "";

        cout << "Please enter client account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient DeletedClient = clsBankClient::Find(AccountNumber);
        _PrintClient(DeletedClient);

        cout << "\nAre you sure you want to delete this client? [Y/N]: ";
        char Answer = 'N';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (DeletedClient.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClient(DeletedClient); //The object will be empty
            }
            else
            {
                cout << "\nError Client was not deleted\n";
            }
        }
	}
    
};
