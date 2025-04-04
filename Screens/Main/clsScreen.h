#pragma once
#include <iostream>
#include "Core\clsUser.h"
#include "Global.h"
#include "Lib\clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        clsDate DateNow;
        cout << "\t\t\t\t\t\t  Date: " << clsDate::DateToString(DateNow) << endl;
        cout << "\t\t\t\t\t\t  Day: " << clsDate::DayShortName(DateNow.GetDay(), DateNow.GetMonth(), DateNow.GetYear()) << endl;
        cout << "\t\t\t\t\t\t  User: " << CurrentUser.GetUsername() << endl;
    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }

        else
        {
            return true;
        }
    }
};