#pragma once
#include <iomanip>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsBankClient.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsUser.h"

class clsListUsersScreen : protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << User.GetUsername();
        cout << "| " << setw(20) << left << User.GetFullName();
        cout << "| " << setw(12) << left << User.GetPhone();
        cout << "| " << setw(20) << left << User.GetEmail();
        cout << "| " << setw(10) << left << User.GetPassword();
        cout << "| " << setw(12) << left << User.GetPermissions();
    }

public:
    static void ShowUsersListScreen()
    {
        vector<clsUser> vUsers = clsUser::GetUsersList();
        string Title = "\t User List Screen";
        string Subtitle = "\t    (" + to_string(vUsers.size()) + ") User(s)";

        _DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Username";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\tNo Users Available In the System!";
        }

        else
        {
            for (clsUser &User : vUsers)
            {
                _PrintUserRecordLine(User);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";
    }
};