#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;

class clsClientListScreen : protected clsScreen
{
private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

public:

    static void ShowClientsList()
    {
        if (!_CheckAccessRights(clsUser::enUserPermissions::pListClients))
        {
            return; //this will exit the function and it will not continue
        }

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-------------------------------------------\n";

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-------------------------------------------\n";

        if (vClients.size() == 0)
        {
            cout << "\n\t\t\tNo Clients Available in the System!" << endl;
        }
        else
        {
            for (clsBankClient const& client : vClients)
            {
                _PrintClientRecordLine(client);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t------------------------------------------------------";
        cout << "-------------------------------------------\n";
    }

};
