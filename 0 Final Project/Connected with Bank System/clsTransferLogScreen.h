#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:

    static void _PrintTransferRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(28) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(10) << left << TransferLogRecord.sourceAccNum;
        cout << "| " << setw(10) << left << TransferLogRecord.destinAccNum;
        cout << "| " << setw(10) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.sourceBalance;
        cout << "| " << setw(10) << left << TransferLogRecord.destinBalance;
        cout << "| " << setw(10) << left << TransferLogRecord.UserName;
    }

public:

    static void ShowTransferLogScreen()
    {
        vector<clsBankClient::stTransferLogRecord> vTransferLog = clsBankClient::GetTransferLogList();

        string Title = "\t   Transfer Log Screen";
        string SubTitle = "\t    (" + to_string(vTransferLog.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

        cout << setw(8) << left << "" << "| " << left << setw(28) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acc";
        cout << "| " << left << setw(10) << "d.Acc";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

        if (vTransferLog.size() == 0)
        {
            cout << "\n\t\t\tNo Logs Available in the System!" << endl;
        }
        else
        {
            for (clsBankClient::stTransferLogRecord const& record : vTransferLog)
            {
                _PrintTransferRecordLine(record);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-----------------------------------------------\n";

    }

};
