#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsUtil
{
public:
    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };

    static void Srand()
    {
        // Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        return (rand() % (To - From + 1) + From);
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == enCharType::MixChars)
        {
            // Capital/Small/Digits only
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType)
        {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        default:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";

        for (int i = 1; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter, short SlotLength = 4)
    {
        string Key = "";

        Key = GenerateWord(CharType, SlotLength) + "-";
        Key += GenerateWord(CharType, SlotLength) + "-";
        Key += GenerateWord(CharType, SlotLength) + "-";
        Key += GenerateWord(CharType, SlotLength);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType = CapitalLetter, short SlotLength = 4)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType, SlotLength) << endl;
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType = CapitalLetter, short Wordlength = 4)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType = CapitalLetter, short Wordlength = 4)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType, Wordlength);
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t += "\t";
            cout << t;
        }
        return t;
    }

    static string EncryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }

        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }

        return Text;
    }

    static string NumberToText(int Number)
    {
        if (Number == 0)
        {
            return "Zero";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                            "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

            return arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number % 1000000000);
        }

        else
        {
            return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }
    }

    static string TrimSpacesEdges(string S1)
    {
        short start = S1.find_first_not_of(' ');

        if (start == string::npos)
            return "";

        short end = S1.find_last_not_of(' ');

        return S1.substr(start, end - start + 1);
    }
};
