#pragma once
#include <string>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Core\clsPerson.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsString.h"
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsUtil.h"
#include <fstream>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsDate.h"
using namespace std;

class clsUser : public clsPerson
{
public:
    struct stLoginRegisterRecord;

private:
    enum enMode
    {
        eEmptyMode = 0,
        eUpdateMode = 1,
        eAddMode = 2
    };

    enMode _Mode;
    string _Username;
    string _Password;
    int _Permissions;
    bool _MarkForDelete = false;

    string _PrepareLoginRegister(string Separator = "#//#")
    {
        string LoginRecord = "";

        LoginRecord += clsDate::GetSystemDateTimeString() + Separator;
        LoginRecord += _Username + Separator;
        LoginRecord += clsUtil::EncryptText(_Password) + Separator;
        LoginRecord += to_string(_Permissions);

        return LoginRecord;
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
    }

    static clsUser _ConvertLineToUserObject(string Line, string Delimeter = "#//#")
    {
        vector<string> vUserData = clsString::Split(Line, Delimeter);
        return clsUser(enMode::eUpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3],
                       vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));
    }

    static stLoginRegisterRecord _ConvertLineToLoginRegisterStruct(string Line, string Delimeter = "#//#")
    {
        stLoginRegisterRecord DataRecord;
        vector<string> vLoginRegisterData = clsString::Split(Line, Delimeter);

        DataRecord.DateTime = vLoginRegisterData[0];
        DataRecord.Username = vLoginRegisterData[1];
        DataRecord.Password = clsUtil::DecryptText(vLoginRegisterData[2]);
        DataRecord.Permission = stoi(vLoginRegisterData[3]);

        return DataRecord;
    }

    static vector<clsUser> _LoadUsersDataFromFile()
    {
        vector<clsUser> vUsers;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }

    static vector<stLoginRegisterRecord> _LoadLoginRegisterDataFromFile()
    {
        vector<stLoginRegisterRecord> vLoginRegisterData;
        stLoginRegisterRecord DataRecord;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\LoginRegister.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                DataRecord = _ConvertLineToLoginRegisterStruct(Line);
                vLoginRegisterData.push_back(DataRecord);
            }
            MyFile.close();
        }
        return vLoginRegisterData;
    }

    string _ConvertUserObjectToLine(clsUser User, string Delimeter = "#//#")
    {
        string UserRecord = "";
        UserRecord += User.GetFirstName() + Delimeter;
        UserRecord += User.GetLastName() + Delimeter;
        UserRecord += User.GetEmail() + Delimeter;
        UserRecord += User.GetPhone() + Delimeter;
        UserRecord += User._Username + Delimeter;
        UserRecord += clsUtil::EncryptText(User._Password) + Delimeter;
        UserRecord += to_string(User._Permissions);

        return UserRecord;
    }

    void _SaveUsersDataToFile(vector<clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Users.txt", ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsUser &U : vUsers)
            {
                if (U._MarkForDelete == false)
                {
                    DataLine = _ConvertUserObjectToLine(U);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser &U : vUsers)
        {
            if (U._Username == this->_Username)
            {
                U = *this;
                break;
            }
        }
        _SaveUsersDataToFile(vUsers);
    }

    void _AddDataLineToFile(string DataLine)
    {
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }

    void _AddNewUser()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

public:
    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, int Permissions)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _Username = Username;
        _Password = Password;
        _Permissions = Permissions;
    }

    void SetUsername(string Username)
    {
        _Username = Username;
    }

    string GetUsername()
    {
        return _Username;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::eEmptyMode);
    }

    enum enSaveResults
    {
        eFailedEmptyObject = 1,
        eSucceededUpdateUser = 2,
        eFailedUsernameExist = 3,
        eSucceededAddNewUser = 4
    };

    enum enPermissions
    {
        eAll = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClients = 8,
        pFindClient = 16,
        pTransactions = 32,
        pManageUsers = 64,
        pShowLoginRegister = 128,
        pTransfer = 256,
        pTransferLog = 512,
        pUpdateRate = 1024
    };

    struct stLoginRegisterRecord
    {
        string DateTime;
        string Username;
        string Password;
        int Permission;
    };

    static clsUser Find(string Username)
    {
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User._Username == Username)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static clsUser Find(string Username, string Password)
    {
        vector<clsUser> vUsers;
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User._Username == Username && User._Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static bool IsUserExist(string Username)
    {
        clsUser User = clsUser::Find(Username);
        return !(User.IsEmpty());
    }

    static bool IsUserExist(string Username, string Password)
    {
        clsUser User = clsUser::Find(Username, Password);
        return !User.IsEmpty();
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
            if (clsUser::IsUserExist(_Username))
            {
                _Update();
                return enSaveResults::eSucceededUpdateUser;
            }
            break;

        case enMode::eAddMode:
            if (clsUser::IsUserExist(_Username))
            {
                return enSaveResults::eFailedUsernameExist;
            }

            else
            {
                _AddNewUser();
                _Mode = enMode::eUpdateMode;
                return enSaveResults::eSucceededAddNewUser;
            }
            break;

        default:
            break;
        }
        return enSaveResults::eFailedEmptyObject;
    }

    static clsUser AddNewUserObject(string Username)
    {
        return clsUser(enMode::eAddMode, "", "", "", "", Username, "", 0);
    }

    bool Delete()
    {
        bool IsUsernameFound = false;
        vector<clsUser> vUsers = _LoadUsersDataFromFile();
        for (clsUser &U : vUsers)
        {
            if (U._Username == _Username)
            {
                U._MarkForDelete = true;
                IsUsernameFound = true;
                break;
            }
        }

        _SaveUsersDataToFile(vUsers);
        *this = _GetEmptyUserObject();

        return IsUsernameFound;
    }

    static vector<clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    static vector<stLoginRegisterRecord> GetLoginRegisterData()
    {
        return _LoadLoginRegisterDataFromFile();
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->_Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->_Permissions) == Permission)
            return true;

        else
            return false;
    }

    void LoginRegister()
    {
        string DataLine = _PrepareLoginRegister();
        fstream MyFile;
        MyFile.open("C:\\Users\\Mohamed Mamdouh\\Documents\\MyGitHub\\Course 9\\Text Files\\LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }
};