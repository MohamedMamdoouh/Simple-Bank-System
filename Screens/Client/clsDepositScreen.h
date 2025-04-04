#include "Screens\Main\clsScreen.h"
#include "Core\clsBankClient.h"
#include "Lib\clsInputValidate.h"

class clsDepositScreen : protected clsScreen
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

    static string _ReadAccountNumber()
    {
        string AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

public:
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t  Deposit Screen");

        cout << "Enter account number to deposit?\n";
        string AccountNumber = _ReadAccountNumber();

        while (!(clsBankClient::IsClientExist(AccountNumber)))
        {
            cout << "Account number doesn't exist, try again\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "Enter amount to deposit?\n";
        float Amount = clsInputValidate::ReadNumber<float>();

        char Answer = 'n';
        cout << "Do you want to deposit (" << Amount << ") ? n/y\n";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);
            cout << "Amount deposited successfully!\n";
            cout << " The Balance now is: " << Client1.GetAccountBalance() << endl;
        }

        else
        {
            cout << "Operation was cancelled\n";
        }
    }
};