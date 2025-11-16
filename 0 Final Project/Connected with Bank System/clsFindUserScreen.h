#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n________________________";
        cout << "\nFirst Name  : " << User.FirstName;
        cout << "\nLast Name   : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName();
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n________________________\n";
    }

public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind User Screen");

        string UserName;
        char Answer = 'N';

        do
        {
            cout << "\nPlease enter user name: ";
            UserName = clsInputValidate::ReadString();

            clsUser User1 = clsUser::Find(UserName);

            if (!User1.IsEmpty())
            {
                cout << "\nUser Found :-)\n";
                _PrintUser(User1);
                return; //exit after finding the user
            }
            else
            {
                cout << "Client was not Found :-(\n";
                cout << "Do you want to search again? [Y/N]: ";
                cin >> Answer;
            }

        } while (toupper(Answer) == 'Y');
    };

};
