#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"
using namespace std;

class clsDate
{
private:
    short _Year;
    short _Month;
    short _Day;

public:

    //Constructors
    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        _Year = now->tm_year + 1900;
        _Month = now->tm_mon + 1;
        _Day = now->tm_mday;
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
        _Year = Year;
        _Month = Month;
        _Day = Day;
    }

    clsDate(short DayOrder, short Year)
    {
        clsDate Date;

        Date = GetDateFromDayOrderInYear(DayOrder, Year);

        _Day = Date.Day;
        _Month = Date.Month;
        _Year = Date.Year;
    }


    //Properties
    void setDay(short Day)
    {
        _Day = Day;
    }

    short getDay()
    {
        return _Day;
    }

    __declspec(property(get = getDay, put = setDay))short Day;

    void setMonth(short Month)
    {
        _Month = Month;
    }

    short getMonth()
    {
        return _Month;
    }

    __declspec(property(get = getMonth, put = setMonth))short Month;

    void setYear(short Year)
    {
        _Year = Year;
    }

    short getYear()
    {
        return _Year;
    }

    __declspec(property(get = getYear, put = setYear))short Year;


    //Date Members
    void Print()
    {
        cout << DateToString() << endl;
    }

    static string DateToString(clsDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string DateToString()
    {
        return DateToString(*this);
    }

    static clsDate GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year;

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;

        return clsDate(Day, Month, Year);
    }

    static string GetSystemDateTimeString()
    {
        //system date-time string
        time_t t = time(0);
        tm* now = localtime(&t);

        short Day, Month, Year, Hour, Minute, Second;

        Year = now->tm_year + 1900;
        Month = now->tm_mon + 1;
        Day = now->tm_mday;
        Hour = now->tm_hour;
        Minute = now->tm_min;
        Second = now->tm_sec;

        return (to_string(Day) + "/" + to_string(Month) + "/"
            + to_string(Year) + " - "
            + to_string(Hour) + ":" + to_string(Minute)
            + ":" + to_string(Second));
    }

    static bool IsValidDate(clsDate Date)
    {
        if (Date.Day < 1 || Date.Day > 31)
            return false;

        if (Date.Day > DaysInMonth(Date.Year, Date.Month))
            return false;

        return true;
    }

    bool IsValidDate()
    {
        return IsValidDate(*this);
    }
   
    static bool isLeapYear(short Year)
    {
        return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
    }

    bool isLeapYear()
    {
        return isLeapYear(_Year);
    }

    static short DaysInYear(short Year)
    {
        return isLeapYear(Year) ? 366 : 365;
    }

    short DaysInYear()
    {
        return DaysInYear(_Year);
    }

    static int HoursInYear(short Year)
    {
        return DaysInYear(Year) * 24;
    }

    int HoursInYear()
    {
        return HoursInYear(_Year);
    }

    static int MinutesInYear(short Year)
    {
        return HoursInYear(Year) * 60;
    }

    int MinutesInYear()
    {
        return MinutesInYear(_Year);
    }

    static int SecondsInYear(short Year)
    {
        return MinutesInYear(Year) * 60;
    }

    int SecondsInYear()
    {
        return SecondsInYear(_Year);
    }

    static short DaysInMonth(short Year, short Month)
    {
        if (Month < 1 || Month>12)
            return 0;

        int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
    }

    short DaysInMonth()
    {
        return DaysInMonth(_Year, _Month);
    }

    static int HoursInMonth(short Year, short Month)
    {
        return DaysInMonth(Year, Month) * 24;
    }

    int HoursInMonth()
    {
        return HoursInMonth(_Year, _Month);
    }

    static int MinutesInMonth(short Year, short Month)
    {
        return HoursInMonth(Year, Month) * 60;
    }

    int MinutesInMonth()
    {
        return MinutesInMonth(_Year, _Month);
    }

    static int SecondsInMonth(short Year, short Month)
    {
        return MinutesInMonth(Year, Month) * 60;
    }

    int SecondsInMonth()
    {
        return SecondsInMonth(_Year, _Month);
    }

    static int DayIndex(int Day, short Month, short Year)
    {
        short a, y, m;

        a = ((14 - Month) / 12);
        y = Year - a;
        m = Month + 12 * a - 2;

        //Gregorian
        //0:Sun, 1:Mon, 2:Tue...etc
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    int DayIndex()
    {
        return DayIndex(_Day, _Month, _Year);
    }

    static string DayIndexToName(short DayIndex)
    {
        string arr7Days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arr7Days[DayIndex];
    }

    string DayIndexToName()
    {
        return DayIndexToName(DayIndex());
    }

    static string GetMonthName(short Month)
    {
        string arrMonthsNames[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Agu","Sep",
        "Oct","Nov","Dec" };

        return arrMonthsNames[Month - 1];
    }

    string GetMonthName()
    {
        return GetMonthName(_Month);
    }

    static void PrintMonthCalendar(short Year, short Month)
    {
        short NumberOfDays = DaysInMonth(Year, Month);
        string MonthN = GetMonthName(Month);

        int current = DayIndex(1, Month, Year);

        //print the name month
        printf("\n ________________%s________________\n\n", MonthN.c_str());

        //print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        //print appropriate spaces
        short i;
        for (i = 0; i < current; i++)
        {
            printf("     ");
        }

        for (short j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        printf("\n ___________________________________\n");
    }

    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Year, _Month);
    }

    static void PrintYearCalendar(short Year)
    {
        printf("\n -----------------------------------\n");
        printf("           Calendar - %d", Year);
        printf("\n -----------------------------------\n");

        for (short i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(Year, i);
        }
    }

    void PrintYearCalendar()
    {
        PrintYearCalendar(_Year);
    }

    static int NumberOfDaysFromBeginningOfYear(short Day, short Month, short Year)
    {
        int TotalDays = 0;

        for (short i = 1; i < Month; i++)
        {
            TotalDays += DaysInMonth(Year, i);
        }

        return (TotalDays + Day);
    }

    int NumberOfDaysFromBeginningOfYear()
    {
        return NumberOfDaysFromBeginningOfYear(_Day, _Month, _Year);
    }

    static clsDate GetDateFromDayOrderInYear(short DayOrder, short Year)
    {
        clsDate Date;
        short Remainder = DayOrder;
        short MonthDays = 0;

        Date.Year = Year;
        Date.Month = 1;

        while (true)
        {
            MonthDays = DaysInMonth(Year, Date.Month);

            if (Remainder > MonthDays)
            {
                Remainder -= MonthDays;
                Date.Month++;
            }
            else
            {
                Date.Day = Remainder;
                break;
            }
        }

        return Date;
    }

    clsDate GetDateFromDayOrderInYear(short DayOrder)
    {
        return GetDateFromDayOrderInYear(DayOrder, _Year);
    }

    //check from the techer
    static clsDate DateAddDays(short DaysToAdd, clsDate &Date)
    {
        // if you send 'Date' by reference you cannot call this function directly 
        // from the class without creat an object of it.

        short Remainder = DaysToAdd + NumberOfDaysFromBeginningOfYear(Date.Day, Date.Month, Date.Year);
        short MonthDays = 0;

        Date.Month = 1;

        while (true)
        {
            MonthDays = DaysInMonth(Date.Year, Date.Month);

            if (Remainder > MonthDays)
            {
                Remainder -= MonthDays;
                Date.Month++;

                if (Date.Month > 12)
                {
                    Date.Month = 1;
                    Date.Year++;
                }
            }
            else
            {
                Date.Day = Remainder;
                break;
            }
        }

        return Date;
    }

    clsDate AddDays(short DaysToAdd)
    {
        return DateAddDays(DaysToAdd, *this);

       // *this = DateAddDays(DaysToAdd, *this); use void
        // if you send 'Date' above by value, you should use last line.
    }
    //--------

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.Year < Date2.Year) ? true : ((Date1.Month < Date2.Month) ? true : ((Date1.Day < Date2.Day) ? true : false));
    }

    bool IsDateBeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualsDate2(clsDate Date1, clsDate Date2)
    {
        return((Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day));
    }

    bool IsDateEqualsDate2(clsDate Date2)
    {
        return IsDate1EqualsDate2(*this, Date2);
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualsDate2(Date1, Date2));
    }

    bool IsDateAfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {
        return (Date.Day == DaysInMonth(Date.Year, Date.Month));
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

    //------
    static clsDate IncreaseDateByOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Day = 1;
                Date.Month = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else
        {
            Date.Day++;
        }

        return Date;
    }

    void IncreaseOneDay()
    {
       // return IncreaseDateByOneDay(*this);
        *this = IncreaseDateByOneDay(*this);
    }
    //------

    static void Swap2Dates(clsDate& Date1, clsDate& Date2)
    {
        clsDate TempDate;

        TempDate.Day = Date1.Day;
        TempDate.Month = Date1.Month;
        TempDate.Year = Date1.Year;

        Date1.Day = Date2.Day;
        Date1.Month = Date2.Month;
        Date1.Year = Date2.Year;

        Date2.Day = TempDate.Day;
        Date2.Month = TempDate.Month;
        Date2.Year = TempDate.Year;
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool includeEndDay = false)
    {
        int DaysToCount = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            //Swap Dates
            Swap2Dates(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            DaysToCount++;
            Date1 = IncreaseDateByOneDay(Date1);
        }

        return includeEndDay ? ++DaysToCount * SwapFlagValue : DaysToCount * SwapFlagValue;
    }

    int GetDifferenceInDays(clsDate Date2, bool includeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, includeEndDay);
    }

    static short CalculateMyAgeInDays(clsDate DateOfBirth)
    {
        return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
    } 
    //above no need to have nonstatic function for the object because it does not depend on any data from it

    static clsDate IncreaseDateByXDay(clsDate Date, short DaysToAdd)
    {
        for (short i = 1; i <= DaysToAdd; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }

        return Date;
    }

    void IncreaseByXDay(short DaysToAdd)
    {
        *this = IncreaseDateByXDay(*this, DaysToAdd);
    }

    static clsDate IncreaseDateByOneWeek(clsDate Date)
    {
        for (short i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }

        return Date;
    }

    void IncreaseOneWeek()
    {
        *this = IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeek(clsDate Date, short WeeksToAdd)
    {
        for (short i = 1; i <= WeeksToAdd; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }

        return Date;
    }

    void IncreaseByXWeek(short WeeksToAdd)
    {
        *this = IncreaseDateByXWeek(*this, WeeksToAdd);
    }

    static clsDate IncreaseDateByOneMonth(clsDate Date)
    {
        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }

        //last day in date should not exceed max days in the current month
        short NumberOfDaysInCurrentMonth = DaysInMonth(Date.Year, Date.Month);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }

    void IncreaseOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXMonth(clsDate Date, short MonthsToAdd)
    {
        for (short i = 1; i <= MonthsToAdd; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }

        return Date;
    }

    void IncreaseByXMonth(short MonthsToAdd)
    {
        *this = IncreaseDateByXMonth(*this, MonthsToAdd);
    }

    static clsDate IncreaseDateByOneYear(clsDate Date)
    {
        Date.Year++;

        return Date;
    }

    void IncreaseOneYear()
    {
        *this = IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByXYear(clsDate Date, short YearsToAdd)
    {
        for (short i = 1; i <= YearsToAdd; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }

        return Date;
    }

    void IncreaseByXYear(short YearsToAdd)
    {
        *this = IncreaseDateByXYear(*this, YearsToAdd);
    }

    static clsDate IncreaseDateByOneDecade(clsDate Date)
    {
        Date.Year += 10;

        return Date;
    }

    void IncreaseOneDecade()
    {
        *this = IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecade(clsDate Date, short DecadesToAdd)
    {
        for (short i = 1; i <= DecadesToAdd; i++)
        {
            Date = IncreaseDateByOneDecade(Date);
        }

        return Date;
    }

    void IncreaseByXDecade(short DecadesToAdd)
    {
        *this = IncreaseDateByXDecade(*this, DecadesToAdd);
    }

    static clsDate IncreaseDateByOneCentury(clsDate Date)
    {
        Date.Year += 100;

        return Date;
    }

    void IncreaseOneCentury()
    {
        *this = IncreaseDateByOneCentury(*this);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate Date)
    {
        //Period of 1000 years
        Date.Year += 1000;

        return Date;
    }

    void IncreaseOneMillennium()
    {
        *this = IncreaseDateByOneMillennium(*this);
    }

    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Day = 31;
                Date.Month = 12;
                Date.Year--;
            }
            else
            {
                Date.Month--;
                Date.Day = DaysInMonth(Date.Year, Date.Month);
            }
        }
        else
        {
            Date.Day--;
        }

        return Date;
    }

    void DecreaseOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByXDay(clsDate Date, short DaysToSubtract)
    {
        for (short i = 1; i <= DaysToSubtract; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }

        return Date;
    }

    void DecreaseByXDay(short DaysToSubtract)
    {
        *this = DecreaseDateByXDay(*this, DaysToSubtract);
    }

    static clsDate DecreaseDateByOneWeek(clsDate Date)
    {
        for (short i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }

        return Date;
    }

    void DecreaseOneWeek()
    {
        *this = DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeek(clsDate Date, short WeeksToSubtract)
    {
        for (short i = 1; i <= WeeksToSubtract; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }

        return Date;
    }

    void DecreaseByXWeek(short WeeksToSubtract)
    {
        *this = DecreaseDateByXWeek(*this, WeeksToSubtract);
    }

    static clsDate DecreaseDateByOneMonth(clsDate Date)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
        }

        //last day in date should not exceed max days in the current month
        short NumberOfDaysInCurrentMonth = DaysInMonth(Date.Year, Date.Month);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }

    void DecreaseOneMonth()
    {
        *this = DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXMonth(clsDate Date, short MonthsToSubtract)
    {
        for (short i = 1; i <= MonthsToSubtract; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }

        return Date;
    }

    void DecreaseByXMonth(short MonthsToSubtract)
    {
        *this = DecreaseDateByXMonth(*this, MonthsToSubtract);
    }

    static clsDate DecreaseDateByOneYear(clsDate Date)
    {
        Date.Year--;

        return Date;
    }

    void DecreaseOneYear()
    {
        *this = DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYear(clsDate Date, short YearsToSubtract)
    {
        for (short i = 1; i <= YearsToSubtract; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }

        return Date;
    }

    void DecreaseByXYear(short YearsToSubtract)
    {
        *this = DecreaseDateByXYear(*this, YearsToSubtract);
    }

    static clsDate DecreaseDateByOneDecade(clsDate Date)
    {
        //Period of 10 years
        Date.Year -= 10;

        return Date;
    }

    void DecreaseOneDecade()
    {
        *this = DecreaseDateByOneDecade(*this);
    }

    static clsDate DecreaseDateByXDecade(clsDate Date, short DecadesToSubtract)
    {
        for (short i = 1; i <= DecadesToSubtract; i++)
        {
            Date = DecreaseDateByOneDecade(Date);
        }

        return Date;
    }

    void DecreaseByXDecade(short DecadesToSubtract)
    {
        *this = DecreaseDateByXDecade(*this, DecadesToSubtract);
    }

    static clsDate DecreaseDateByOneCentury(clsDate Date)
    {
        //Period of 100 years
        Date.Year -= 100;

        return Date;
    }

    void DecreaseOneCentury()
    {
        *this = DecreaseDateByOneCentury(*this);
    }

    static clsDate DecreaseDateByOneMillennium(clsDate Date)
    {
        //Period of 1000 years
        Date.Year -= 1000;

        return Date;
    }

    void DecreaseOneMillennium()
    {
        *this = DecreaseDateByOneMillennium(*this);
    }

    static bool IsEndOfWeek(clsDate Date)
    {
        return DayIndex(Date.Day, Date.Month, Date.Year) == 6;
    }

    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date)
    {
        //weekends are Fri and Sat
        short DayOfWeekIndex = DayIndex(Date.Day, Date.Month, Date.Year);
        return (DayOfWeekIndex == 5 || DayOfWeekIndex == 6);
    }

    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        return (!IsWeekEnd(Date));
    }

    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilEndOfWeek(clsDate Date)
    {
        return 6 - DayIndex(Date.Day, Date.Month, Date.Year);
    }

    short DaysUntilEndOfWeek()
    {
        return DaysUntilEndOfWeek(*this);
    }

    static short DaysUntilEndOfMonth(clsDate Date)
    {
        clsDate EndOfMonthDate;
        EndOfMonthDate.Day = DaysInMonth(Date.Year, Date.Month);
        EndOfMonthDate.Month = Date.Month;
        EndOfMonthDate.Year = Date.Year;

        return GetDifferenceInDays(Date, EndOfMonthDate, true);
    }

    short DaysUntilEndOfMonth()
    {
        return DaysUntilEndOfMonth(*this);
    }

    static short DaysUntilEndOfYear(clsDate Date)
    {
        clsDate EndOfYearDate;
        EndOfYearDate.Day = 31;
        EndOfYearDate.Month = 12;
        EndOfYearDate.Year = Date.Year;

        return GetDifferenceInDays(Date, EndOfYearDate, true);
    }

    short DaysUntilEndOfYear()
    {
        return DaysUntilEndOfYear(*this);
    }

    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {
        short DaysCounter = 0;

        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                DaysCounter++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        return DaysCounter;
    }

    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        /*short DaysCounter = 0;

        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                DaysCounter++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        return DaysCounter;*/

        return CalculateBusinessDays(DateFrom, DateTo);
    }

    short CalculateVacationDays(clsDate DateTo)
    {
        return CalculateVacationDays(*this, DateTo);
    }

    static clsDate CalculateReturnDate(clsDate DateFrom, short VacationDays)
    {
        short WeekendCounter = 0;

        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        for (short i = 1; i <= VacationDays + WeekendCounter; i++)
        {
            if (IsWeekEnd(DateFrom))
                WeekendCounter++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        return DateFrom;
    }

    void CalculateReturnDate(short VacationDays)
    {
        *this = CalculateReturnDate(*this, VacationDays);
    }

    enum enCompareDates { Before = -1, Equal = 0, After = 1 };

    static enCompareDates CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enCompareDates::Before;

        if (IsDate1EqualsDate2(Date1, Date2))
            return enCompareDates::Equal;

        /*if (IsDate1AfterDate2(Date1, Date2))
            return enCompareDatesChoices::After;*/

            // this is faster
        return enCompareDates::After;
    }

    enCompareDates CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }


};
