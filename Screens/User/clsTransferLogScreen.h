#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include <iomanip>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsBankClient.h"

class cslTransferLogScreen : protected clsScreen
{
private:
    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountBalance;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountBalance;
        cout << "| " << setw(8) << left << TransferLogRecord.Username;
    }

public:
    static void ShowTransferLogScreen()
    {
        if (!clsScreen::_CheckAccessRights(clsUser::enPermissions::pTransferLog))
            return;

        vector<clsBankClient::stTransferLogRecord> vTransferLog = clsBankClient::GetTransferLogData();

        string Title = "\tTransfer Log List Screen";
        string Subtitle = "\t(" + to_string(vTransferLog.size()) + ") Record(s)";
        _DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "S.AccountNumber";
        cout << "| " << left << setw(8) << "D.AccountNumber";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "S.AccountBalance";
        cout << "| " << left << setw(10) << "D.AccountBalance";
        cout << "| " << left << setw(8) << "Username";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        if (vTransferLog.size() == 0)
        {
            cout << "\t\t\t\tNo Transfers Available In the System!";
        }

        else
        {
            for (clsBankClient::stTransferLogRecord &Data : vTransferLog)
            {
                _PrintTransferLogRecordLine(Data);
                cout << endl;
            }
        }
    }
};