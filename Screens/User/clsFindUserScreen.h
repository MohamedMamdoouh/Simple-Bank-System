#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsUser.h"

class clsFindUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "The following are the User details:\n";
        cout << "Full Name      : " << User.GetFullName() << endl;
        cout << "Email          : " << User.GetEmail() << endl;
        cout << "Username       : " << User.GetUsername() << endl;
        cout << "Password       : " << User.GetPassword() << endl;
        cout << "Permissions    : " << User.GetPermissions() << endl;
        cout << "----------------------------------------------------------------\n";
    }

public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");

        cout << "Enter username to search for?\n";
        string Username = clsInputValidate::ReadName();

        if (!clsUser::IsUserExist(Username))
        {
            cout << "Username doesn't exist\n";
        }

        else
        {
            clsUser User = clsUser::Find(Username);
            if (!User.IsEmpty())
            {
                cout << "Username Found!\n";
                _PrintUser(User);
            }

            else
            {
                cout << "Username doesn't exist\n";
            }
        }
    }
};