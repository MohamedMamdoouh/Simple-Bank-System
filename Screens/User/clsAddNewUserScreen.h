#pragma once
#include "Screens\Main\clsScreen.h"
#include "Lib\clsInputValidate.h"
#include "Core\clsUser.h"

class clsAddNewUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "The following are the User details:\n";
        cout << "Full Name      : " << User.GetFullName() << endl;
        cout << "Email          : " << User.GetEmail() << endl;
        cout << "Username       : " << User.GetUsername() << endl;
        cout << "Password       : " << User.GetPassword() << endl;
        cout << "Permissions    : " << User.GetPermissions() << endl;
        cout << "----------------------------------------------------------------\n";
    }

    static int _ReadPermissionToSet()
    {
        int Permission = 0;
        char Option = 'n';

        cout << "Do you want to give full access? y/n \n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            return -1;

        cout << "Add Client? y/n\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pAddNewClient;

        cout << "Show Clients list? y/n\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pListClients;

        cout << "Delete Client? y/n\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pDeleteClient;

        cout << "Update Client? y/n\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pUpdateClients;

        cout << "Find Client? y/n\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pFindClient;

        cout << "Transactions? y/n?\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pTransactions;

        cout << "Manage Users? y/n?\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pManageUsers;

        cout << "Show Login Register? y/n?\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pShowLoginRegister;

        cout << "Transfer? y/n?\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pTransfer;

        cout << "Show Transfer Log? y/n?\n";
        cin >> Option;
        if (Option == 'y' || Option == 'Y')
            Permission += clsUser::enPermissions::pTransferLog;

        return Permission;
    }
    static void _ReadUserInfo(clsUser &User)
    {
        cout << "Enter First Name?\n";
        User.SetFirstName(clsInputValidate::ReadName());

        cout << "Enter Last Name?\n";
        User.SetLastName(clsInputValidate::ReadName());

        cout << "Enter Email?\n";
        User.SetEmail(clsInputValidate::ReadString());

        cout << "Enter Phone?\n";
        User.SetPhone(clsInputValidate::ReadString());

        cout << "Enter Password?\n";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "Enter Permission?\n";
        User.SetPermissions(_ReadPermissionToSet());
    }

public:
    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\t  Add New User Screen");

        cout << "Enter username to add?\n";
        string Username = clsInputValidate::ReadName();

        while (clsUser::IsUserExist(Username))
        {
            cout << "Username already exist, try again\n";
            Username = clsInputValidate::ReadName();
        }

        clsUser NewUser = clsUser::AddNewUserObject(Username);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::eFailedEmptyObject:
            cout << "Error happened due to empty object\n";
            break;

        case clsUser::enSaveResults::eSucceededUpdateUser:
            cout << "User Updated Successfully\n";
            break;

        case clsUser::enSaveResults::eFailedUsernameExist:
            cout << "Username already exist\n";
            break;

        case clsUser::enSaveResults::eSucceededAddNewUser:
            cout << "User added successfully\n";
            _PrintUser(NewUser);
            break;

        default:
            break;
        }
    }
};