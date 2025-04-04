#pragma once
#include <iomanip>
#include "Screens\Main\clsScreen.h"
#include "Lib\clsInputValidate.h"
#include "Screens\Client\clsDepositScreen.h"
#include "Screens\Client\clsWithdrawScreen.h"
#include "Screens\Client\clsTotalBalancesScreen.h"
#include "Screens\Client\clsTransferScreen.h"
#include "Screens\User\clsTransferLogScreen.h"

class clsTransactionMenu : protected clsScreen
{
private:
    enum _enTransactionMenuOption
    {
        eDeposit = 1,
        eWithdraw = 2,
        eShowTotalBalance = 3,
        eTransfer = 4,
        eTransferLog = 5,
        eShowMainMenu = 6
    };

    static short _ReadTransactionMenuOption()
    {
        cout << "Enter a choice? [1 to 6]\n";
        short Option = clsInputValidate::ReadNumberBetween(1, 6, "Enter a number between 1 and 6");
        return Option;
    }

    static void _GoBackToMainTransactionMenu()
    {
        ShowTransactionMenu();
    }

    static void _ShowDepositMenu()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowTotalBalance()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowWithdrawMenu()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        cslTransferLogScreen::ShowTransferLogScreen();
    }

    static void _PerfromTransactionMenuOption(_enTransactionMenuOption TransactionMenuOption)
    {
        switch (TransactionMenuOption)
        {
        case _enTransactionMenuOption::eDeposit:
            _ShowDepositMenu();
            _GoBackToMainTransactionMenu();
            break;

        case _enTransactionMenuOption::eShowMainMenu:
            // Do Nothing, it will go back to main menu
            break;

        case _enTransactionMenuOption::eShowTotalBalance:
            _ShowTotalBalance();
            _GoBackToMainTransactionMenu();
            break;

        case _enTransactionMenuOption::eTransfer:
            _ShowTransferScreen();
            _GoBackToMainTransactionMenu();
            break;

        case _enTransactionMenuOption::eTransferLog:
            _ShowTransferLogScreen();
            _GoBackToMainTransactionMenu();
            break;

        case _enTransactionMenuOption::eWithdraw:
            _ShowWithdrawMenu();
            _GoBackToMainTransactionMenu();
            break;

        default:
            break;
        }
    }

public:
    static void ShowTransactionMenu()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pTransactions))
            return;

        _DrawScreenHeader("\t  Transaction Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances\n";
        cout << setw(37) << left << "" << "\t[4] Transfer\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionMenuOption((_enTransactionMenuOption)_ReadTransactionMenuOption());
    }
};