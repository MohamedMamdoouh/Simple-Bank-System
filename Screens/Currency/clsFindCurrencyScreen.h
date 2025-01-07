#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsCurrency.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency)
    {
        cout << "\n------------------------------------\n";
        cout << "Country        : " << Currency.GetCountry() << endl;
        cout << "Currency Code  : " << Currency.GetCurrencyCode() << endl;
        cout << "Currency Name  : " << Currency.GetCurrencyName() << endl;
        cout << "Rate(1$)       : " << Currency.GetRate() << endl;
        cout << "------------------------------------\n";
    }

    static void _ShowResult(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "Currency Found\n";
            _PrintCurrencyCard(Currency);
        }

        else
        {
            cout << "Currency was not found!\n";
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\tFind Currency Screen");

        short Choice = 0;
        cout << "Find by: [1] Code or [2] Country ?\n";
        Choice = clsInputValidate::ReadNumberBetween(1, 2, "Enter a number between 1 and 2 only");

        if (Choice == 1)
        {
            cout << "Enter Currency Code?\n";
            string CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResult(Currency);
        }

        else
        {
            cout << "Enter Country Name?\n";
            string CountryName = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
            _ShowResult(Currency);
        }
    }
};