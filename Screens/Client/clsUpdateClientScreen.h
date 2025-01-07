#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsBankClient.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"

class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "The following are the client details:\n";
        cout << "Name           : " << Client.GetFullName() << endl;
        cout << "Phone          : " << Client.GetPhone() << endl;
        cout << "Email          : " << Client.GetEmail() << endl;
        cout << "Account Number : " << Client.GetAccountNumber() << endl;
        cout << "Pin Code       : " << Client.GetPinCode() << endl;
        cout << "Account Balance: " << Client.GetAccountBalance() << endl;
        cout << "----------------------------------------------------------------\n";
    }

    static void _ReadClientInfo(clsBankClient &Client)
    {
        cout << "Enter First Name?\n";
        Client.SetFirstName(clsInputValidate::ReadName());

        cout << "Enter Last Name?\n";
        Client.SetLastName(clsInputValidate::ReadName());

        cout << "Enter Email?\n";
        Client.SetEmail(clsInputValidate::ReadString());

        cout << "Enter Phone?\n";
        Client.SetPhone(clsInputValidate::ReadString());

        cout << "Enter PinCode?\n";
        Client.SetPinCode(clsInputValidate::ReadString());

        cout << "Enter Account Balance?\n";
        Client.SetAccountBalance(clsInputValidate::ReadNumber<float>());
    }

public:
    static void UpdateClient()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClients))
            return;

        _DrawScreenHeader("\t  Edit Client Screen");

        cout << "Enter account number to update?\n";
        string AccountNumber = clsInputValidate::ReadString();

        while (!(clsBankClient::IsClientExist(AccountNumber)))
        {
            cout << "Account number doesn't exist, try again\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        clsBankClient::enSaveResults SaveResult;

        cout << "Are you sure you want to update this clinet? y/n\n";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            _ReadClientInfo(Client1);
            SaveResult = Client1.Save();
        }

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::eFailedEmptyObject:
            cout << "Error happened due to empty object\n";
            break;

        case clsBankClient::enSaveResults::eSucceededUpdateClient:
            cout << "Client Updated Successfully\n";
            break;

        default:
            break;
        }
    }
};