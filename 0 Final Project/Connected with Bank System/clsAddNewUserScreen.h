#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter First Name: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "Enter Last Name: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "Enter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "Enter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "Enter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "Enter Permissions: \n";
        User.Permissions = _ReadPermissionToSet();
    }

    static int _ReadPermissionToSet()
    {
        int Permission = 0;
        char Answer = 'N';

        cout << "\nDo you want to give full access? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to: \n";

        cout << "\nShow Client List? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pListClients;
        }

        cout << "\nAdd New Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pUpdateClient;
        }

        cout << "\nFind Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pFindClient;
        }

        cout << "\nTransactions? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pTransactions;
        }

        cout << "\nManage Users? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pManageUsers;
        }

        cout << "\nLogin Register? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pLoginRegsiter;
        }

        cout << "\nCurrency Exchange? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enUserPermissions::pCurrencyExchange;
        }

        return Permission;
    }

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

    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\t  Add New User Screen");

        string Username = "";

        cout << "Please enter user name: ";
        Username = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(Username))
        {
            cout << "\nUser name is already used, choose another one: ";
            Username = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(Username);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Created Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError, user was not saved because it's Empty.";
            break;
        }
        case clsUser::enSaveResults::svFaildUserNameExists:
        {
            cout << "\nError user was not saved because user name is used!";
            break;
        }
        }
    }

};
