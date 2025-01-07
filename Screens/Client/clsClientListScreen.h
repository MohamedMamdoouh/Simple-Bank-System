#pragma once
#include <iostream>
#include <iomanip>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsBankClient.h"

class clsClientListScreen : protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(20) << left << Client.GetFullName();
        cout << "| " << setw(12) << left << Client.GetPhone();
        cout << "| " << setw(20) << left << Client.GetEmail();
        cout << "| " << setw(10) << left << Client.GetPinCode();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();
    }

public:
    static void ShowClientsList()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pListClients))
            return;

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Client List Screen";
        string Subtitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        if (vClients.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In the System!";
        }

        else
        {
            for (clsBankClient &Client : vClients)
            {
                _PrintClientRecordLine(Client);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";
    }
};