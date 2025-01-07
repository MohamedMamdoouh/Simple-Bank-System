#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Global.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
private:
    static bool _Login()
    {
        string Username, Password;
        short FailedLoginCounter = 3;
        bool LoginFailed = false;
        do
        {
            if (LoginFailed)
            {
                FailedLoginCounter--;
                cout << "Invalid username or password\n";
                cout << "You have " << FailedLoginCounter << " remaining trial(s)\n";

                if (FailedLoginCounter == 0)
                {
                    cout << "You are locked\n";
                    return false;
                    // exit(0);
                }
            }

            cout << "Enter username?\n";
            Username = clsInputValidate::ReadName();

            cout << "Enter password?\n";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(Username, Password);
            LoginFailed = (CurrentUser.IsEmpty());

        } while (LoginFailed);

        CurrentUser.LoginRegister();
        clsMainScreen::ShowMainMenu();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        _DrawScreenHeader("\t     Login Screen");
        return _Login();
    }
};