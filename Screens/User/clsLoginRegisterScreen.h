#pragma once
#include "Screens\Main\clsScreen.h"
#include "Core\clsUser.h"
#include <iomanip>

class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Username;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permission;
    }

public:
    static void ShowLoginRegisterScreen()
    {
        if (!clsScreen::_CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
            return;

        vector<clsUser::stLoginRegisterRecord> vUserRegisterData = clsUser::GetLoginRegisterData();

        string Title = "\tLogin Register List Screen";
        string Subtitle = "\t(" + to_string(vUserRegisterData.size()) + ") Record(s)";
        _DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "Username";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        if (vUserRegisterData.size() == 0)
        {
            cout << "\t\t\t\tNo Logins Available In the System!";
        }

        else
        {
            for (clsUser::stLoginRegisterRecord &Data : vUserRegisterData)
            {
                _PrintLoginRegisterRecordLine(Data);
                cout << endl;
            }
        }
    }
};