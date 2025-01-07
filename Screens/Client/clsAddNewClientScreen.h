#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsBankClient.h"

class clsAddNewClientScreen : protected clsScreen
{
private:
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

public:
    static void ShowAddNewClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pAddNewClient))
            return;

        _DrawScreenHeader("\t  Add New Client Screen");

        cout << "Enter account number to add?\n";
        string AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account number already exist, try again\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::AddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::eFailedEmptyObject:
            cout << "Error happened due to empty object\n";
            break;

        case clsBankClient::enSaveResults::eSucceededUpdateClient:
            cout << "Client Updated Successfully\n";
            break;

        case clsBankClient::enSaveResults::eFailedAccountNumberExist:
            cout << "Account Number already exist\n";
            break;

        case clsBankClient::enSaveResults::eSucceededAddNewClient:
            _PrintClient(NewClient);
            break;

        default:
            break;
        }
    }
};