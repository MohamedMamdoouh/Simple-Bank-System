#pragma once
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Screens\clsScreen.h"
#include <iomanip>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsCurrency.h"

class clsCurrenciesListScreen : protected clsScreen
{
private:
    static void _PrintCurrenciesRecordLine(clsCurrency CurrenciesListData)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << CurrenciesListData.GetCountry();
        cout << "| " << setw(8) << left << CurrenciesListData.GetCurrencyCode();
        cout << "| " << setw(45) << left << CurrenciesListData.GetCurrencyName();
        cout << "| " << setw(10) << left << CurrenciesListData.GetRate();
    }

public:
    static void ShowCurrenciesListScreen()
    {
        vector<clsCurrency> vCurrenciesData = clsCurrency::GetCurrenciesList();

        string Title = "\tCurrencies List Screen";
        string Subtitle = "\t(" + to_string(vCurrenciesData.size()) + ") Currency";
        _DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Currency Code";
        cout << "| " << left << setw(45) << "Currency Name";
        cout << "| " << left << setw(10) << "Rate(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        if (vCurrenciesData.size() == 0)
        {
            cout << "\t\t\t\tNo Currencies Data Available In the System!";
        }

        else
        {
            for (clsCurrency &Data : vCurrenciesData)
            {
                _PrintCurrenciesRecordLine(Data);
                cout << endl;
            }
        }
    }
};