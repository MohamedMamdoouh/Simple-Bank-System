#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsBankClient.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
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

    static int _ReadAmountToWithdraw()
    {
        cout << "Enter amount to withdraw, multiples of 5 only\n";
        int Num = clsInputValidate::ReadNumber<int>();

        while (Num % 5 != 0)
        {
            cout << "Enter amount to withdraw, multiples of 5 only\n";
            Num = clsInputValidate::ReadNumber<int>();
        }
        return Num;
    }

public:
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t  Withdraw Screen");

        cout << "Enter account number to Withdraw?\n";
        string AccountNumber = _ReadAccountNumber();

        while (!(clsBankClient::IsClientExist(AccountNumber)))
        {
            cout << "Account number doesn't exist, try again\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        int Amount = _ReadAmountToWithdraw();

        char Answer = 'n';
        cout << "Do you want to Withdraw (" << Amount << ") ? n/y\n";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "Amount withdrew successfully!\n";
                cout << " The Balance now is: " << Client1.GetAccountBalance() << endl;
            }

            else
            {
                cout << "Insufficient Balance, your balance is: " << Client1.GetAccountBalance() << endl;
            }
        }

        else
        {
            cout << "Operation was cancelled\n";
        }
    }
};