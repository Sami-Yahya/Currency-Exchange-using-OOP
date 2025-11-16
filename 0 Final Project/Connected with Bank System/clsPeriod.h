#pragma once

#include <iostream>
#include "clsDate.h"
using namespace std;

class clsPeriod
{
public:

	clsDate StartDate;
	clsDate EndDate;


	clsPeriod(clsDate StartDate, clsDate EndDay)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDay;
	}

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {
        return !(clsDate::IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate)
			|| clsDate::IsDate1BeforeDate2(Period2.EndDate, Period1.StartDate));
    }

	bool IsOverlapWith(clsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	static int PeriodLength(clsPeriod Period, bool includingEndDay = false)
	{
		return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, includingEndDay);
	}

	int PeriodLength(bool includingEndDay = false)
	{
		return PeriodLength(*this, includingEndDay);
	}

	static bool IsDateInPeriod(clsPeriod Period1, clsDate DateToCheck)
	{
		return (clsDate::IsDate1BeforeDate2(Period1.StartDate, DateToCheck) 
			&& clsDate::IsDate1BeforeDate2(DateToCheck, Period1.EndDate));
	}

	bool IsDateInPeriod(clsDate DateToCheck)
	{
		return IsDateInPeriod(*this, DateToCheck);
	}

	static int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
	{
		int Period1Length = PeriodLength(Period1, true);
		int Period2Length = PeriodLength(Period2, true);
		int OverlapDays = 0;

		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length)
		{
			while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateInPeriod(Period2, Period1.StartDate))
					OverlapDays++;

				Period1.StartDate = clsDate::IncreaseDateByOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateInPeriod(Period1, Period2.StartDate))
					OverlapDays++;

				Period2.StartDate = clsDate::IncreaseDateByOneDay(Period2.StartDate);
			}
		}

		return OverlapDays;
	}

	int CountOverlapDays(clsPeriod Period2)
	{
		return CountOverlapDays(*this, Period2);
	}

	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();

		cout << "Period End: ";
		EndDate.Print();
	}

};
