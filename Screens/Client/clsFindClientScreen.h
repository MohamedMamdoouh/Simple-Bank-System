#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsBankClient.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
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

public:
    static void ShowFindClientScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pFindClient))
            return;

        _DrawScreenHeader("\t  Find Client Screen");

        cout << "Enter account number to find?\n";
        string AccountNumber = clsInputValidate::ReadString();

        while (!(clsBankClient::IsClientExist(AccountNumber)))
        {
            cout << "Account number doesn't exist, try again\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "Client Found\n";
        }

        else
        {
            cout << "Account Not found!\n";
        }

        _PrintClient(Client1);
    }
};