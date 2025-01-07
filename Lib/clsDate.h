#pragma once
#include <iostream>
#include <string>
#include "C:\Users\Mohamed Mamdouh\Documents\MyGitHub\Course 9\Lib\clsString.h"
using namespace std;

class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:
    clsDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    clsDate(string Date)
    {
        vector<string> vDate;
        vDate = clsString::Split(Date, "/");

        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);
    }

    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(short DateOrderInYear, short Year)
    {
        clsDate Date = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = Date._Day;
        _Month = Date._Month;
        _Year = Date._Year;
    }

    void SetDay(short Day)
    {
        _Day = Day;
    }

    short GetDay()
    {
        return _Day;
    }

    void SetMonth(short Month)
    {
        _Month = Month;
    }

    short GetMonth()
    {
        return _Month;
    }

    void SetYear(short Year)
    {
        _Year = Year;
    }

    short GetYear()
    {
        return _Year;
    }

    void Print()
    {
        cout << DateToString() << endl;
    }

    static clsDate GetSystemDate()
    {
        short Day, Month, Year;
        time_t t = time(0);
        tm *now = localtime(&t);

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;

        return clsDate(Day, Month, Year);
    }

    static string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm *now = localtime(&t);

        short Day, Month, Year, Hour, Minute, Second;

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;
        Hour = now->tm_hour;
        Minute = now->tm_min;
        Second = now->tm_sec;

        return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year)
        + " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
    }

    static bool IsValidDate(clsDate Date)
    {
        if (Date._Day < 1 || Date._Day > 31)
            return false;

        if (Date._Month < 1 || Date._Month > 12)
            return false;

        if (Date._Month == 2)
        {
            if (isLeapYear(Date._Year))
            {
                if (Date._Day > 29)
                    return false;
            }
            else
            {
                if (Date._Day > 28)
                    return false;
            }
        }

        short DaysInMonth = NumberOfDaysInMonth(Date._Month, Date._Year);

        if (Date._Day > DaysInMonth)
            return false;

        return true;
    }

    bool IsValid()
    {
        return IsValidDate(*this);
    }

    static string DateToString(clsDate Date)
    {
        return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
    }

    string DateToString()
    {
        return DateToString(*this);
    }

    static bool isLeapYear(short Year)
    {
        // if year is divisible by 4 AND not divisible by 100
        // OR if year is divisible by 400
        // then it is a leap year
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear()
    {
        return isLeapYear(_Year);
    }

    static short NumberOfDaysInYear(short Year)
    {
        return isLeapYear(Year) ? 365 : 364;
    }

    short NumberOfDaysInAYear()
    {
        return NumberOfDaysInYear(_Year);
    }

    static short NumberOfHoursInYear(short Year)
    {
        return NumberOfDaysInYear(Year) * 24;
    }

    short NumberOfHoursInYear()
    {
        return NumberOfHoursInYear(_Year);
    }

    static int NumberOfMinutesInYear(short Year)
    {
        return NumberOfHoursInYear(Year) * 60;
    }

    int NumberOfMinutesInYear()
    {
        return NumberOfMinutesInYear(_Year);
    }

    static int NumberOfSecondsInYear(short Year)
    {
        return NumberOfMinutesInYear(Year) * 60;
    }

    int NumberOfSecondsInAYear()
    {
        return NumberOfSecondsInAYear();
    }

    static short NumberOfDaysInMonth(short Month, short Year)
    {

        if (Month < 1 || Month > 12)
            return 0;

        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    short NumberOfDaysInMonth()
    {
        return NumberOfDaysInMonth(_Month, _Year);
    }

    static short NumberOfHoursInMonth(short Month, short Year)
    {
        return NumberOfDaysInMonth(Month, Year) * 24;
    }

    short NumberOfHoursInMonth()
    {
        return NumberOfDaysInMonth(_Month, _Year) * 24;
    }

    static int NumberOfMinutesInMonth(short Month, short Year)
    {
        return NumberOfHoursInMonth(Month, Year) * 60;
    }

    int NumberOfMinutesInAMonth()
    {
        return NumberOfHoursInMonth(_Month, _Year) * 60;
    }

    static int NumberOfSecondsInMonth(short Month, short Year)
    {
        return NumberOfMinutesInMonth(Month, Year) * 60;
    }

    int NumberOfSecondsInMonth()
    {
        return NumberOfMinutesInMonth(_Month, _Year) * 60;
    }

    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;
        // Gregorian:
        // 0:sun, 1:Mon, 2:Tue, etc..
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        return arrDayNames[DayOfWeekOrder];
    }

    static string DayShortName(short Day, short Month, short Year)
    {
        string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        return arrDayNames[DayOfWeekOrder(Day, Month, Year)];
    }

    string DayShortName()
    {
        string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];
    }

    static string MonthShortName(short MonthNumber)
    {
        string Months[12] = {"Jan", "Feb", "Mar",
                             "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep",
                             "Oct", "Nov", "Dec"};

        return (Months[MonthNumber - 1]);
    }

    string MonthShortName()
    {
        return MonthShortName(_Month);
    }

    static void PrintMonthCalendar(short Month, short Year)
    {
        int NumberOfDays;

        // Index of the day from 0 to 6
        int current = DayOfWeekOrder(1, Month, Year);

        NumberOfDays = NumberOfDaysInMonth(Month, Year);

        // Print the current month name
        printf("\n  _______________%s_______________\n\n",
               MonthShortName(Month).c_str());

        // Print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces
        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        printf("\n  _________________________________\n");
        return;
    }

    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Month, _Year);
    }

    static void PrintYearCalendar(int Year)
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");

        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, Year);
        }
        return;
    }

    void PrintYearCalendar()
    {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", _Year);
        printf("  _________________________________\n");

        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, _Year);
        }
        return;
    }

    static short DaysFromTheBeginingOfYear(short Day, short Month, short Year)
    {
        short TotalDays = 0;

        for (int i = 1; i <= Month - 1; i++)
        {
            TotalDays += NumberOfDaysInMonth(i, Year);
        }

        TotalDays += Day;

        return TotalDays;
    }

    short DaysFromTheBeginingOfYear()
    {
        return DaysFromTheBeginingOfYear(_Day, _Month, _Year);
    }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate Date;
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;

        // Date.SetYear(Year);
        Date._Year = Year;
        Date._Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInMonth(Date._Month, Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date._Month++;
            }
            else
            {
                Date._Day = RemainingDays;
                break;
            }
        }

        return Date;
    }

    void AddDays(short Days)
    {
        // This function update the Date object directly
        short RemainingDays = Days + DaysFromTheBeginingOfYear(_Day, _Month, _Year);
        short MonthDays = 0;

        _Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInMonth(_Month, _Year);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                _Month++;

                if (_Month > 12)
                {
                    _Month = 1;
                    _Year++;
                }
            }
            else
            {
                _Day = RemainingDays;
                break;
            }
        }
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
    }

    bool IsDateBeforeDate2(clsDate Date2)
    {
        // "*this" sends the current object
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
    }

    bool IsDateEqualDate2(clsDate Date2)
    {
        return IsDate1EqualDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {
        return (Date._Day == NumberOfDaysInMonth(Date._Month, Date._Year));
    }

    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(_Month);
    }

    static clsDate AddOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date._Month))
            {
                Date._Month = 1;
                Date._Day = 1;
                Date._Year++;
            }
            else
            {
                Date._Day = 1;
                Date._Month++;
            }
        }
        else
        {
            Date._Day++;
        }

        return Date;
    }

    void AddOneDay()
    {
        // The function update the current object directly
        *this = AddOneDay(*this);
    }

    static void SwapDates(clsDate &Date1, clsDate &Date2)
    {
        clsDate TempDate;
        TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1; // this will take care of negative diff

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = AddOneDay(Date1);
        }

        return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
    }

    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    // NO need to have a non-static function for the object, as it doesn't depend on any data from it
    static short CalculateMyAgeInDays(clsDate DateOfBirth)
    {
        return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
    }

    static clsDate IncreaseDateByOneWeek(clsDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = AddOneDay(Date);
        }

        return Date;
    }

    void IncreaseDateByOneWeek()
    {
        *this = IncreaseDateByOneWeek(*this);
    }

    clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void IncreaseDateByXWeeks(short Weeks)
    {
        *this = IncreaseDateByXWeeks(Weeks, *this);
    }

    clsDate IncreaseDateByOneMonth(clsDate Date)
    {
        if (Date._Month == 12)
        {
            Date._Month = 1;
            Date._Year++;
        }
        else
        {
            Date._Month++;
        }

        // last check day in date should not exceed max days in the current month
        //  example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
        //  be 28/2/2022

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }

    void IncreaseDateByOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
    }

    clsDate IncreaseDateByXDays(short Days, clsDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = AddOneDay(Date);
        }
        return Date;
    }

    void IncreaseDateByXDays(short Days)
    {
        *this = IncreaseDateByXDays(Days, *this);
    }

    clsDate IncreaseDateByXMonths(short Months, clsDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void IncreaseDateByXMonths(short Months)
    {
        *this = IncreaseDateByXMonths(Months, *this);
    }

    static clsDate IncreaseDateByOneYear(clsDate Date)
    {
        Date._Year++;
        return Date;
    }

    void IncreaseDateByOneYear()
    {
        *this = IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByXYears(short Years, clsDate Date)
    {
        Date._Year += Years;
        return Date;
    }

    void IncreaseDateByXYears(short Years)
    {
        *this = IncreaseDateByXYears(Years, *this);
    }

    static clsDate IncreaseDateByOneDecade(clsDate Date)
    {
        Date._Year += 10;
        return Date;
    }

    void IncreaseDateByOneDecade()
    {
        *this = IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecades(short Decades, clsDate Date)
    {
        Date._Year += Decades * 10;
        return Date;
    }

    void IncreaseDateByXDecades(short Decades)
    {
        *this = IncreaseDateByXDecades(Decades, *this);
    }

    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date._Day == 1)
        {
            if (Date._Month == 1)
            {
                Date._Month = 12;
                Date._Day = 31;
                Date._Year--;
            }
            else
            {
                Date._Month--;
                Date._Day = NumberOfDaysInMonth(Date._Month, Date._Year);
            }
        }
        else
        {
            Date._Day--;
        }

        return Date;
    }

    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByOneWeek(clsDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }

        return Date;
    }

    void DecreaseDateByOneWeek()
    {
        *this = DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void DecreaseDateByXWeeks(short Weeks)
    {
        *this = DecreaseDateByXWeeks(Weeks, *this);
    }

    static clsDate DecreaseDateByOneMonth(clsDate Date)
    {
        if (Date._Month == 1)
        {
            Date._Month = 12;
            Date._Year--;
        }
        else
            Date._Month--;

        // last check day in date should not exceed max days in the current month
        // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
        // be 28/2/2022

        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }

    void DecreaseDateByOneMonth()
    {
        *this = DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXDays(short Days, clsDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    void DecreaseDateByXDays(short Days)
    {
        *this = DecreaseDateByXDays(Days, *this);
    }

    static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void DecreaseDateByXMonths(short Months)
    {
        *this = DecreaseDateByXMonths(Months, *this);
    }

    static clsDate DecreaseDateByOneYear(clsDate Date)
    {
        Date._Year--;
        return Date;
    }

    void DecreaseDateByOneYear()
    {
        *this = DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYears(short Years, clsDate Date)
    {
        Date._Year -= Years;
        return Date;
    }

    void DecreaseDateByXYears(short Years)
    {
        *this = DecreaseDateByXYears(Years, *this);
    }

    static clsDate DecreaseDateByOneDecade(clsDate Date)
    {
        Date._Year -= 10;
        return Date;
    }

    void DecreaseDateByOneDecade()
    {
        *this = DecreaseDateByOneDecade(*this);
    }

    static clsDate DecreaseDateByXDecades(short Decades, clsDate Date)
    {
        Date._Year -= Decades * 10;
        return Date;
    }

    void DecreaseDateByXDecades(short Decades)
    {
        *this = DecreaseDateByXDecades(Decades, *this);
    }

    static short IsEndOfWeek(clsDate Date)
    {
        return DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 6;
    }

    short IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date)
    {
        // Weekends are Fri and Sat
        short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
        return (DayIndex == 5 || DayIndex == 6);
    }

    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
    }

    short DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(clsDate Date1)
    {
        clsDate EndOfMontDate;
        EndOfMontDate._Day = NumberOfDaysInMonth(Date1._Month, Date1._Year);
        EndOfMontDate._Month = Date1._Month;
        EndOfMontDate._Year = Date1._Year;

        return GetDifferenceInDays(Date1, EndOfMontDate, true);
    }

    short DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    static short DaysUntilTheEndOfYear(clsDate Date1)
    {
        clsDate EndOfYearDate;
        EndOfYearDate._Day = 31;
        EndOfYearDate._Month = 12;
        EndOfYearDate._Year = Date1._Year;

        return GetDifferenceInDays(Date1, EndOfYearDate, true);
    }

    short DaysUntilTheEndOfYear()
    {
        return DaysUntilTheEndOfYear(*this);
    }

    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {
        short Days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;

            DateFrom = AddOneDay(DateFrom);
        }

        return Days;
    }

    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        return CalculateBusinessDays(DateFrom, DateTo);
    }

    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
    {
        short WeekEndCounter = 0;

        for (short i = 1; i <= VacationDays; i++)
        {
            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = AddOneDay(DateFrom);
        }

        // To add the weekends, as it's not considered from the vacation
        for (short i = 1; i <= WeekEndCounter; i++)
            DateFrom = AddOneDay(DateFrom);

        return DateFrom;
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }

    bool IsDateAfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;

        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }

    enDateCompare CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }
};
