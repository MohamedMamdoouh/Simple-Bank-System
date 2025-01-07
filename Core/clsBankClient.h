#pragma once
#include <string>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsPerson.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsString.h"
#include <fstream>
using namespace std;

class clsBankClient : public clsPerson
{
public:
    struct stTransferLogRecord;

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "The following are the client details:\n";
        cout << "Name           : " << Client.GetFullName() << endl;
        cout << "Phone          : " << Client.GetPhone() << endl;
        cout << "Email          : " << Client.GetEmail() << endl;
        cout << "Account Number : " << Client.GetAccountNumber() << endl;
        cout << "Pin Code       : " << Client.GetPinCode() << endl;
        cout << "Account Balance: " << Client.GetAccountBalance() << endl;
        cout << "----------------------------------------------------------------\n";
    }

    enum enMode
    {
        eEmptyMode = 0,
        eUpdateMode = 1,
        eAddMode = 2
    };

    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance = 0;
    bool _MarkForDelete = false;

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::eEmptyMode, "", "", "", "", "", "", 0);
    }

    static clsBankClient _ConvertLineToClientObject(string Line, string Delimeter = "#//#")
    {
        vector<string> vClientData = clsString::Split(Line, Delimeter);
        return clsBankClient(enMode::eUpdateMode, vClientData[0], vClientData[1],
                             vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }

    string _ConvertClientObjectToLine(clsBankClient Client, string Delimeter = "#//#")
    {
        string ClientRecord = "";
        ClientRecord += Client.GetFirstName() + Delimeter;
        ClientRecord += Client.GetLastName() + Delimeter;
        ClientRecord += Client.GetEmail() + Delimeter;
        ClientRecord += Client.GetPhone() + Delimeter;
        ClientRecord += Client._AccountNumber + Delimeter;
        ClientRecord += Client._PinCode + Delimeter;
        ClientRecord += to_string(Client._AccountBalance);

        return ClientRecord;
    }

    void _SaveClientsDataToFile(vector<clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Clients.txt", ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient &C : vClients)
            {
                if (C._MarkForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsBankClient> _vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClients)
        {
            if (C._AccountNumber == this->_AccountNumber)
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);
    }

    void _AddDataLineToFile(string DataLine)
    {
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

    void _AddNewClient()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    string _PrepareTransferLog(float Amount, clsBankClient DestinationClient, string Username, string Separator = "#//#")
    {
        string TransferLog = "";

        TransferLog += clsDate::GetSystemDateTimeString() + Separator;
        TransferLog += _AccountNumber + Separator;
        TransferLog += DestinationClient.GetAccountNumber() + Separator;
        TransferLog += to_string(Amount) + Separator;
        TransferLog += to_string(_AccountBalance) + Separator;
        TransferLog += to_string(DestinationClient.GetAccountBalance()) + Separator;
        TransferLog += Username;

        return TransferLog;
    }

    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string Username)
    {
        string DataLine = _PrepareTransferLog(Amount, DestinationClient, Username);
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

    static stTransferLogRecord _ConvertLineToTransferLogStruct(string Line, string Delimeter = "#//#")
    {
        stTransferLogRecord DataRecord;
        vector<string> vTransferLog = clsString::Split(Line, Delimeter);

        DataRecord.DateTime = vTransferLog[0];
        DataRecord.SourceAccountNumber = vTransferLog[1];
        DataRecord.DestinationAccountNumber = vTransferLog[2];
        DataRecord.Amount = stof(vTransferLog[3]);
        DataRecord.SourceAccountBalance = stof(vTransferLog[4]);
        DataRecord.DestinationAccountBalance = stof(vTransferLog[5]);
        DataRecord.Username = vTransferLog[6];

        return DataRecord;
    }

    static vector<stTransferLogRecord> _LoadTransferLogDataFromFile()
    {
        vector<stTransferLogRecord> vTransferLogData;
        stTransferLogRecord DataRecord;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\TransferLog.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                DataRecord = _ConvertLineToTransferLogStruct(Line);
                vTransferLogData.push_back(DataRecord);
            }
            MyFile.close();
        }
        return vTransferLogData;
    }

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
        _Mode = Mode;
    }

    string GetAccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode()
    {
        return _PinCode;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::eEmptyMode);
    }

    enum enSaveResults
    {
        eFailedEmptyObject = 1,
        eSucceededUpdateClient = 2,
        eFailedAccountNumberExist = 3,
        eSucceededAddNewClient = 4
    };

    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float SourceAccountBalance;
        float DestinationAccountBalance;
        string Username;
    };

    static clsBankClient Find(string AccountNumber)
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client._AccountNumber == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    // void Print()
    // {
    //     cout << "The following are the client details:\n";
    //     cout << "Name           : " << GetFullName() << endl;
    //     cout << "Phone          : " << GetPhone() << endl;
    //     cout << "Email          : " << GetEmail() << endl;
    //     cout << "Account Number : " << _AccountNumber << endl;
    //     cout << "Pin Code       : " << _PinCode << endl;
    //     cout << "Account Balance: " << _AccountBalance << endl;
    //     cout << "----------------------------------------------------------------\n";
    // }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return !(Client1.IsEmpty());
    }

    static bool IsClientExist(string AccountNumber, string PinCode)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber, PinCode);
        return !Client1.IsEmpty();
    }

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::eEmptyMode:
            if (IsEmpty())
            {
                return enSaveResults::eFailedEmptyObject;
            }
            break;

        case enMode::eUpdateMode:
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                _Update();
                return enSaveResults::eSucceededUpdateClient;
            }
            break;

        case enMode::eAddMode:
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::eFailedAccountNumberExist;
            }

            else
            {
                _AddNewClient();
                _Mode = enMode::eUpdateMode;
                return enSaveResults::eSucceededAddNewClient;
            }
            break;

        default:
            break;
        }
        return enSaveResults::eFailedEmptyObject;
    }

    static clsBankClient AddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::eAddMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        bool IsAccountNumberFound = false;
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        for (clsBankClient &C : vClients)
        {
            if (C._AccountNumber == _AccountNumber)
            {
                C._MarkForDelete = true;
                IsAccountNumberFound = true;
                break;
            }
        }

        _SaveClientsDataToFile(vClients);
        *this = _GetEmptyClientObject();

        return IsAccountNumberFound;
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static float GetTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        double TotalBalances = 0;

        for (clsBankClient &Client : vClients)
        {
            TotalBalances += Client.GetAccountBalance();
        }

        return TotalBalances;
    }

    void Deposit(float Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(float Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }

        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    bool Transfer(float Amount, clsBankClient &DestinationClient, string Username)
    {
        if (!Withdraw(Amount))
            return false;

        DestinationClient.Deposit(Amount);

        _RegisterTransferLog(Amount, DestinationClient, Username);

        return true;
    }

    static vector<stTransferLogRecord> GetTransferLogData()
    {
        return _LoadTransferLogDataFromFile();
    }
};