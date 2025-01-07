#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"
#include <iomanip>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\User\clsListUsersScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\User\clsAddNewUserScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\User\clsDeleteUserScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\User\clsUpdateUserScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\User\clsFindUserScreen.h"

class clsManageUsersMenu : protected clsScreen
{
private:
    enum _enManageUsersMenuOptions
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenu = 6
    };

    static short _ReadManageUsersMenuOption()
    {
        cout << "Enter a choice? [1 to 6]\n";
        short Choice = clsInputValidate::ReadNumberBetween(1, 6, "Enter number between 1 to 6");
        return Choice;
    }

    static void _GoBackToManageUsersMenu()
    {
        ShowManageUsersMenu();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersListScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _PerformManageUsersMenuOption(_enManageUsersMenuOptions ManageUsersMenuOptions)
    {
        switch (ManageUsersMenuOptions)
        {
        case _enManageUsersMenuOptions::eAddNewUser:
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case _enManageUsersMenuOptions::eFindUser:
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case _enManageUsersMenuOptions::eDeleteUser:
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case _enManageUsersMenuOptions::eListUsers:
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;

        case _enManageUsersMenuOptions::eMainMenu:
            // Do nothing here, it will go back to main menu
            break;

        case _enManageUsersMenuOptions::eUpdateUser:
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;

        default:
            break;
        }
    }

public:
    static void ShowManageUsersMenu()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pManageUsers))
            return;

        _DrawScreenHeader("\t  Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users\n";
        cout << setw(37) << left << "" << "\t[2] Add New User\n";
        cout << setw(37) << left << "" << "\t[3] Delete User\n";
        cout << setw(37) << left << "" << "\t[4] Update User\n";
        cout << setw(37) << left << "" << "\t[5] Find User\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenuOption((_enManageUsersMenuOptions)_ReadManageUsersMenuOption());
    }
};