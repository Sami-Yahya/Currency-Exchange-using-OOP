#pragma once

#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
        cout << "\t\t\t\t\t______________________________________";
        //cout << "\t\t\t\t\t--------------------------------------";
        cout << "\n\n\t\t\t\t\t  " << Title;

        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }

        cout << "\n\t\t\t\t\t______________________________________\n\n";
        //cout << "\n\t\t\t\t\t--------------------------------------\n\n";

        cout << "\t\t\t\t\tUser: " << CurrentUser.FullName() << endl;
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
	}

    static bool _CheckAccessRights(clsUser::enUserPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t--------------------------------------\n";
            cout << "\t\t\t\t\t\t   Access Denied,\n";
            cout << "\t\t\t\t\tYou don't have Permission to do this,\n";
            cout << "\t\t\t\t\t     Please contact your Admin.\n";
            cout << "\t\t\t\t\t--------------------------------------\n";
            
            return false;
        }
        else
        {
            return true;
        }
    }

};
