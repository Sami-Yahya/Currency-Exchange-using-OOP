#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;

class clsTransactionsHistoryScreen : protected clsScreen
{
private:

    static void _PrintTransHistoyRecordLine(clsBankClient::stTransHistoryRecord TransHistoryRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << TransHistoryRecord.DateTime;
        cout << "| " << setw(20) << left << TransHistoryRecord.AccountNumber;
        cout << "| " << setw(25) << left << TransHistoryRecord.FullName;
        cout << "| " << setw(10) << left << TransHistoryRecord.Amount;
    }

public:

    static void ShowTransactionsHistoryScreen()
    {
        vector<clsBankClient::stTransHistoryRecord> vTransHistoryRecord = clsBankClient::GetTransactionsHistoryList();

        string Title = "    Transactions History Screen";
        string SubTitle = "\t    (" + to_string(vTransHistoryRecord.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "Account Number";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(10) << "Amount";
        
        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

        if (vTransHistoryRecord.size() == 0)
        {
            cout << "\n\t\t\tNo History Available in the System!" << endl;
        }
        else
        {
            for (clsBankClient::stTransHistoryRecord const& record : vTransHistoryRecord)
            {
                _PrintTransHistoyRecordLine(record);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

    }

};
