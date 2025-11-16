#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include "clsTransactionsHistoryScreen.h"
#include <iomanip>
using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:

    enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,
        eTransfer = 4, eTransferLog = 5, eTransactionsHistory = 6, eBackMainMenu = 7
    };
	
    static short _ReadTransactionsOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 7]: ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 7, "Enter Number between [1 to 7]: ");

        return Choice;
    }

    static void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\nPress any key to go back to Transactions Menu... ";
        system("pause>0");
        ShowTransactionsMenu();
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }
    
    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _ShowTransactionsHistoryScreen()
    {
        clsTransactionsHistoryScreen::ShowTransactionsHistoryScreen();
    }

    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
    {
        switch (TransactionsMenuOption)
        {
        case clsTransactionsScreen::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsTransactionsScreen::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsTransactionsScreen::eTotalBalances:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsTransactionsScreen::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsTransactionsScreen::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsTransactionsScreen::eTransactionsHistory:
        {
            system("cls");
            _ShowTransactionsHistoryScreen();
            _GoBackToMainMenu();
            break;
        }
        case clsTransactionsScreen::eBackMainMenu:
        {
            //do nothing here the main screen will handle it :-) ;
            break;
        }
        }
    }

public:

    static void ShowTransactionsMenu()
    {
        if (!_CheckAccessRights(clsUser::enUserPermissions::pTransactions))
        {
            return; //this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");
        
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menu Screen\n";
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions History.\n";
        cout << setw(37) << left << "" << "\t[7] Go Back to Main Menu.\n";
        cout << setw(37) << left << "" << "==============================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsOption());
    }

};
