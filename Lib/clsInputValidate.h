#pragma once
#include <limits>
#include <iostream>
#include <string>
#include "Lib\clsDate.h"
using namespace std;

class clsInputValidate
{
private:
    static bool _IsValidName(string Name)
    {
        if (Name.empty() || Name.length() < 2 || Name.length() > 50) // Check length
            return false;

        for (short i = 0; i < Name.length(); i++)
        {
            if (!isalpha(Name[i]) && Name[i] != ' ' && Name[i] != '-' && !isdigit(Name[i])) // Allow letters, spaces, digits, and hyphens only
                return false;

            if ((i == 0 || i == Name.length() - 1) && Name[i] == ' ') // Check for leading or trailing spaces
                return false;

            if (i > 0 && Name[i] == ' ' && Name[i - 1] == ' ') // Check for consecutive spaces
                return false;
        }

        return true;
    }

public:
    template <typename T>
    static T ReadNumber(string ErrorMessage = "Invalid input, try again")
    {
        T Num = 0;
        cin >> Num;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage << endl;
            cin >> Num;
        }
        return Num;
    }

    template <typename T>
    static T ReadPositiveNumber(string ErrorMessage = "Enter a positive number only")
    {
        T Num = 0;
        do
        {
            Num = ReadNumber<T>();

            if (Num <= 0)
                cout << ErrorMessage << endl;

        } while (Num <= 0);

        return Num;
    }

    template <typename T>
    static bool IsNumberBetween(T NumToCheck, T Num1, T Num2)
    {
        if (Num1 > Num2)
            swap(Num1, Num2);

        return (NumToCheck >= Num1 && NumToCheck <= Num2);
    }

    template <typename T>
    static T ReadNumberBetween(T Num1, T Num2, string ErrorMessage = "Number not in range, try again")
    {
        T NumToRead = ReadNumber<T>();

        while (!IsNumberBetween<T>(NumToRead, Num1, Num2))
        {
            cout << ErrorMessage << endl;
            NumToRead = ReadNumber<T>();
        }

        return NumToRead;
    }

    static string ReadString()
    {
        string S1 = "";
        getline(cin >> ws, S1);

        return S1;
    }

    static string ReadName()
    {
        string S1 = "";
        getline(cin >> ws, S1);

        while (!_IsValidName(S1))
        {
            cout << "Enter a valid name: letters, digits, hyphens only, with NO leading or trailing or consecutive spaces\n";
            getline(cin >> ws, S1);
        }

        return S1;
    }

    static bool IsDateBetween(clsDate Date1, clsDate Date2)
    {
        if (clsDate::IsDate1AfterDate2(Date1, Date2))
            swap(Date1, Date2);

        if ((clsDate::IsDate1AfterDate2(clsDate::GetSystemDate(), Date1) || clsDate::IsDate1EqualDate2(clsDate::GetSystemDate(), Date1)) && (clsDate::IsDate1BeforeDate2(clsDate::GetSystemDate(), Date2) || clsDate::IsDate1EqualDate2(clsDate::GetSystemDate(), Date2)))
            return true;

        else
            return false;
    }

    static bool IsVslidDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }
};
