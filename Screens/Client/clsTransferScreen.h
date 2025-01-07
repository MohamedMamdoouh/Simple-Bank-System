#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsBankClient.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClientInfo(clsBankClient Client)
    {
        cout << "The following are the client details:\n";
        cout << "Name           : " << Client.GetFullName() << endl;
        cout << "Account Number : " << Client.GetAccountNumber() << endl;
        cout << "Account Balance: " << Client.GetAccountBalance() << endl;
        cout << "----------------------------------------------------------------\n";
    }

    static string _ReadAccountNumber(string Message)
    {
        cout << Message << endl;
        string AccountNumber = clsInputValidate::ReadString();

        while (!(clsBankClient::IsClientExist(AccountNumber)))
        {
            cout << "Account number doesn't exist, try again\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient)
    {
        float Amount = 0;
        cout << "Enter Amount to transfer?\n";
        Amount = clsInputValidate::ReadPositiveNumber<float>();

        while (Amount > SourceClient.GetAccountBalance())
        {
            cout << "Amount exceeds your balance, try again\n";
            cout << "Enter Amount to transfer?\n";
            Amount = clsInputValidate::ReadPositiveNumber<float>();
        }
        return Amount;
    }

public:
    static void ShowTransferScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pTransfer))
            return;

        _DrawScreenHeader("\t  Transfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Enter Account Number to Transfer From?"));
        _PrintClientInfo(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Enter Account Number to Transfer To?"));
        _PrintClientInfo(DestinationClient);

        float Amount = _ReadAmount(SourceClient);

        char Answer = 'n';
        cout << "Are you sure you want to perform this operation? n/y\n";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.GetUsername()))
            {
                cout << "Transfer Done Successfully!\n";
                _PrintClientInfo(SourceClient);
                _PrintClientInfo(DestinationClient);
            }

            else
            {
                cout << "Error operating transfer!\n";
            }
        }
    }
};