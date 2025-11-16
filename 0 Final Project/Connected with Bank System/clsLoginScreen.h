#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		string UserName, Password;
		bool LoginFailed = false;
        short TrialsToLogin = 3;

        do
        {
            if (LoginFailed)
            {
                TrialsToLogin--;

                cout << "\nInvalid Username/Password!\n";
                cout << "You have " << TrialsToLogin << " trial(s) to Login!\n\n";
            }

            if (TrialsToLogin == 0)
            {
                cout << "\nYou are locked after 3 failed trials!\n";
                return false;
            }

            cout << "Please Enter User Name: ";
            UserName = clsInputValidate::ReadString();
            cout << "Please Enter Password: ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenu();
        return true;
	}

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t     Login Screen");
        return _Login();
    }

};
