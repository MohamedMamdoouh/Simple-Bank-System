#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsCurrency.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"

class clsUpdateRateScreen : protected clsScreen
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

public:
    static void ShowUpdateRateScreen()
    {
        if (!_CheckAccessRights(clsUser::enPermissions::pUpdateRate))
            return;

        _DrawScreenHeader("\t Update Rate Screen");

        cout << "Enter Currency Code ?\n";
        string CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "This Currency Code doesn't exist!\n";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrencyCard(Currency);

        char Answer = 'n';
        cout << "Are you sure you want to update this currency rate? n/y\n";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "Enter the new rate ?\n";
            float Rate = clsInputValidate::ReadPositiveNumber<float>();
            Currency.UpdateRate(Rate);
            cout << "Rate updated successfully\n";
            _PrintCurrencyCard(Currency);
        }
    }
};