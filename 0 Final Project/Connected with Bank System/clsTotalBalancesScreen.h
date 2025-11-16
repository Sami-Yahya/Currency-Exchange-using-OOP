#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <iomanip>
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(16) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

public:

    static void ShowTotalBalancesScreen()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t\t-------------------------------------------------";
        cout << "----------------------\n";

        cout << setw(25) << left << "" << "| " << left << setw(16) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";

        cout << setw(25) << left << "" << "\t\t\t-------------------------------------------------";
        cout << "----------------------\n";

        if (vClients.size() == 0)
        {
            cout << "\n\t\t\tNo Clients Available in the System!" << endl;
        }
        else
        {
            for (clsBankClient const& client : vClients)
            {
                _PrintClientRecordBalanceLine(client);
                cout << endl;
            }
        }

        cout << setw(25) << left << "" << "\n\t\t\t-------------------------------------------------";
        cout << "----------------------\n";

        double TotalBalances = clsBankClient::GetTotalBalances();
        string ts = clsUtil::Tabs(6);
        cout << setw(8) << left << "" << "\n" << ts << "Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;
    }
};
