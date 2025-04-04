#pragma once
#include <iostream>
#include <iomanip>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Client\clsClientListScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Client\clsAddNewClientScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Client\clsDeleteClientScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Client\clsUpdateClientScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Client\clsFindClientScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Client\clsTransactionMenu.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\User\clsManageUsersMenu.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Global.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\User\clsLoginRegisterScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Currency\clsCurrencyExchangeScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]?\n";
        short Choice = clsInputValidate::ReadNumberBetween(1, 10, "Enter Number between 1 to 10?");
        return Choice;
    }

    enum _enMainMenuOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenu = 6,
        eManageUsers = 7,
        eLoginRegister = 8,
        eCurrencyExchange = 9,
        eExit = 10
    };

    static void _GoBackToMainMenu()
    {
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::UpdateClient();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenu()
    {
        clsTransactionMenu::ShowTransactionMenu();
    }

    static void _ShowManageUsersMenu()
    {
        clsManageUsersMenu::ShowManageUsersMenu();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        // Then it will go back to main function
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
    }

    static void _PerfromMainMenuOption(_enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case _enMainMenuOptions::eListClients:
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;

        case _enMainMenuOptions::eAddNewClient:
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;

        case _enMainMenuOptions::eDeleteClient:
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;

        case _enMainMenuOptions::eUpdateClient:
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;

        case _enMainMenuOptions::eFindClient:
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;

        case _enMainMenuOptions::eShowTransactionsMenu:
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;

        case _enMainMenuOptions::eManageUsers:
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;

        case _enMainMenuOptions::eLoginRegister:
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();
            break;

        case _enMainMenuOptions::eCurrencyExchange:
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenu();
            break;

        case _enMainMenuOptions::eExit:
            _Logout();
            break;

        default:
            break;
        }
    }

public:
    static void ShowMainMenu()
    {
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info\n";
        cout << setw(37) << left << "" << "\t[5] Find Client\n";
        cout << setw(37) << left << "" << "\t[6] Transactions\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users\n";
        cout << setw(37) << left << "" << "\t[8] Login Register\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange\n";
        cout << setw(37) << left << "" << "\t[10] Logout\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenuOption((_enMainMenuOptions)_ReadMainMenuOption());
    }
};
