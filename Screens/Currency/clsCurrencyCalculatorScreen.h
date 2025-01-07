#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsCurrency.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency, string Message)
    {
        cout << "\n------------------------------------\n";
        cout << Message << endl;
        cout << "Country        : " << Currency.GetCountry() << endl;
        cout << "Currency Code  : " << Currency.GetCurrencyCode() << endl;
        cout << "Currency Name  : " << Currency.GetCurrencyName() << endl;
        cout << "Rate(1$)       : " << Currency.GetRate() << endl;
        cout << "------------------------------------\n";
    }

    static clsCurrency _GetCurrency(string Message)
    {
        cout << Message << endl;
        string CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "Currency doesn't exist, try again\n";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;
    }

    static float _ReadAmount()
    {
        float Amount = 0;
        cout << "Enter Amount ?\n";
        Amount = clsInputValidate::ReadPositiveNumber<float>();
        return Amount;
    }

    static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
    {
        float ConvertedAmount = 0;
        if (CurrencyTo.GetCurrencyCode() == "USD")
        {
            ConvertedAmount = CurrencyFrom.ConvertToUSD(Amount);
            cout << Amount << " " << CurrencyFrom.GetCurrencyName() << " = " << CurrencyTo.GetCurrencyName() << endl;
        }

        else
        {
            ConvertedAmount = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
            cout << Amount << " " << CurrencyFrom.GetCurrencyName() << " = " << ConvertedAmount << " " << CurrencyTo.GetCurrencyName() << endl;
        }
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        char Answer = 'y';
        while (Answer == 'y' || Answer == 'Y')
        {
            _DrawScreenHeader("\tCurrency Calculator Screen");

            clsCurrency CurrencyFrom = _GetCurrency("Enter Currency Code to Convert From");
            clsCurrency CurrencyTo = _GetCurrency("Enter Currency Code to Convert To");
            float Amount = _ReadAmount();

            _PrintCurrencyCard(CurrencyFrom, "From");
            _PrintCurrencyCard(CurrencyTo, "To");

            _PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

            cout << "Do you want to do another operation ? n/y\n";
            cin >> Answer;
        }
    }
};