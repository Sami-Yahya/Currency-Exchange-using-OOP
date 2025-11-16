#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen
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

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "Please enter user name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser DeletedUser = clsUser::Find(UserName);
        _PrintUser(DeletedUser);

        cout << "\nAre you sure you want to delete this user? [Y/N]: ";
        char Answer = 'N';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (DeletedUser.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";

                _PrintUser(DeletedUser); //The object will be empty
            }
            else
            {
                cout << "\nError User was not deleted\n";
            }
        }
    }

};
