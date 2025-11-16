#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:

    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName();
        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;
    }

public:

    static void ShowUsersList()
    {
        vector<clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

        if (vUsers.size() == 0)
        {
            cout << "\n\t\t\tNo Users Available in the System!" << endl;
        }
        else
        {
            for (clsUser const& user : vUsers)
            {
                _PrintUserRecordLine(user);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";
    }

};
