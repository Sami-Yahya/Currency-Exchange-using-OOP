#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegister.h"
#include "clsCurrencyExchangeScreen.h"
#include "Global.h"
#include <iomanip>
using namespace std;

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenuOptions { eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eTransactions = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eLogout = 10 };

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]: ";
	
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between [1 to 10]: ");

		return Choice;
	}

	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Main Menu... ";
		system("pause>0");
        ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
        clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
        clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
        clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
        clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowFindClientScreen()
	{
        clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu()
	{
        clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersScreen()
	{
        clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowExitScreen()
	{
		cout << "End Screen will be here...\n";
	}

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegister::ShowLoginRegisterScreen();
    }

    static void _ShowCurrnecyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeMenu();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        //then it will go back to main function.
    }

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
	{
        switch (MainMenuOption)
        {
        case enMainMenuOptions::eShowClientList:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eTransactions:
        {
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eManageUsers:
        {
            system("cls");
            _ShowManageUsersScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eLoginRegister:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eCurrencyExchange:
        {
            system("cls");
            _ShowCurrnecyExchangeScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eLogout:
        {
            system("cls");
           // _ShowExitScreen();
            _Logout();
            break;
        }
        }
	}

public:

    static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Menu");

        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t\t    Main Menu Screen\n";
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "==============================================\n";

        _PerformMainMenuOption((enMainMenuOptions) _ReadMainMenuOption());
    }

};
