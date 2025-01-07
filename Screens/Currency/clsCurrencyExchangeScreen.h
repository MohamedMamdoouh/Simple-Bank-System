#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsCurrency.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Currency\clsCurrenciesListScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Currency\clsFindCurrencyScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Currency\clsUpdateRateScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\Currency\clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
    enum _enCurrencyExchangeMenu
    {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateRate = 3,
        eCurrencyCalculator = 4,
        eMainMenu = 5
    };

    static short _ReadCurrencyExchangeMenu()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]?\n";
        short Choice = clsInputValidate::ReadNumberBetween(1, 5, "Enter Number between 1 to 5?");
        return Choice;
    }

    static void _GoBackToCurrencyExchangeMainMenu()
    {
        ShowCurrencyExchangeScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowListCurrenciesScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }

    static void _PerfromCurrencyExchangeOption(_enCurrencyExchangeMenu CurrencyExchangeMenu)
    {
        switch (CurrencyExchangeMenu)
        {
        case _enCurrencyExchangeMenu::eCurrencyCalculator:
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMainMenu();
            break;

        case _enCurrencyExchangeMenu::eFindCurrency:
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMainMenu();
            break;

        case _enCurrencyExchangeMenu::eListCurrencies:
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMainMenu();
            break;

        case _enCurrencyExchangeMenu::eMainMenu:
            // Do nothing, it will go back to main menu
            break;

        case _enCurrencyExchangeMenu::eUpdateRate:
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMainMenu();
            break;

        default:
            break;
        }
    }

public:
    static void ShowCurrencyExchangeScreen()
    {
        _DrawScreenHeader("\t Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyExchangeOption((_enCurrencyExchangeMenu)_ReadCurrencyExchangeMenu());
    }
};