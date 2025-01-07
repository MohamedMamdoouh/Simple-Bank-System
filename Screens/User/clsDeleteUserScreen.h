#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsUser.h"

class clsDeleteUserScreen : protected clsScreen
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
    static void ShowDeleteUserScreen()
    {
        cout << "Enter username to delete?\n";
        string Username = clsInputValidate::ReadName();

        while (!(clsUser::IsUserExist(Username)))
        {
            cout << "Username doesn't exist, try again\n";
            Username = clsInputValidate::ReadName();
        }

        clsUser User = clsUser::Find(Username);
        _PrintUser(User);

        cout << "Do you want to delete this user? y/n\n";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "User deleted successfully\n";
                _PrintUser(User);
            }

            else
            {
                cout << "Error deleteing account\n";
            }
        }
    }
};