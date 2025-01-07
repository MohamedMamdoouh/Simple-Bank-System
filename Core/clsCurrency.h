#pragma once
#include <string>
#include <fstream>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsString.h"

class clsCurrency
{
private:
    enum enMode
    {
        eEmptyMode = 1,
        eUpdateMode = 2
    };

    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;
    enMode _Mode;
    bool _MarkForDelete = false;

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
    }

    static clsCurrency _ConvertLineToCurrencyObject(string Line, string Delimeter = "#//#")
    {
        vector<string> vCurrencyData = clsString::Split(Line, Delimeter);
        return clsCurrency(enMode::eUpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
    }

    static vector<clsCurrency> _LoadCurrenciesDataFromFile()
    {
        vector<clsCurrency> vCurrencies;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Currencies.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                vCurrencies.push_back(Currency);
            }
            MyFile.close();
        }
        return vCurrencies;
    }

    string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Delimeter = "#//#")
    {
        string CurrencyRecord = "";
        CurrencyRecord += Currency.GetCountry() + Delimeter;
        CurrencyRecord += Currency.GetCurrencyCode() + Delimeter;
        CurrencyRecord += Currency.GetCurrencyName() + Delimeter;
        CurrencyRecord += to_string(Currency.GetRate());

        return CurrencyRecord;
    }

    void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrencies)
    {
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Currencies.txt", ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsCurrency &C : vCurrencies)
            {
                if (C._MarkForDelete == false)
                {
                    DataLine = _ConvertCurrencyObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsCurrency> _vCurrencies = _LoadCurrenciesDataFromFile();

        for (clsCurrency &C : _vCurrencies)
        {
            if (C._CurrencyCode == this->_CurrencyCode)
            {
                C._Rate = _Rate;
                // break; -> We removed 'break' here as some countries are using the same currency.
            }
        }
        _SaveCurrenciesDataToFile(_vCurrencies);
    }

public:
    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    string GetCountry()
    {
        return _Country;
    }

    string GetCurrencyName()
    {
        return _CurrencyName;
    }

    string GetCurrencyCode()
    {
        return _CurrencyCode;
    }

    float GetRate()
    {
        return _Rate;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);
        vector<clsCurrency> vCurrencies;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Currencies.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency CurrencyObj = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(CurrencyObj._Country) == Country)
                {
                    MyFile.close();
                    return CurrencyObj;
                }
            }

            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);
        vector<clsCurrency> vCurrencies;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Currencies.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency CurrencyObj = _ConvertLineToCurrencyObject(Line);
                if (CurrencyObj._CurrencyCode == CurrencyCode)
                {
                    MyFile.close();
                    return CurrencyObj;
                }
            }

            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    bool IsEmpty()
    {
        return _Mode == enMode::eEmptyMode;
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C1 = FindByCode(CurrencyCode);
        return !C1.IsEmpty();
    }

    static vector<clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrenciesDataFromFile();
    }

    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / _Rate);
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.GetCurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return (float)(AmountInUSD * Currency2.GetRate());
    }
};