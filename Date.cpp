
#include "Date.h"
#include <cctype>
#include <cstdlib>

// TODO: Implement isValid() and daysBetween() below.
//
// You may create your own helper functions in this .cpp file for tasks such as:
//   - leap-year detection
//   - determining the number of days in a month
//   - converting a Date to a serial-day value
//
// These helpers are implementation details. They do NOT need to be declared
// in Date.h. Do not add a constructor or member functions to Date.

namespace DateUtil {
    // MY HELPER FUNCTIONS
    // ---------------------------------------------------------------------------------
    bool isLeapYear(const int year)
    {
        bool isTrue = false;
        if (year % 4 != 0)
            isTrue = false;
        else if (year % 100 != 0)
            isTrue = true;
        else if (year % 400 == 0)
            isTrue = true;
        return isTrue;
    }

    int monthLength(const int year, const int month)
    {
        int dayCount = 0;
        if (month == 2 && isLeapYear(year))
            dayCount = 29;
        else if (month == 2)
            dayCount = 28;
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            dayCount = 30;
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            dayCount = 31;
        return dayCount;
    }

    int toSerial(const Date &a)
    {
        // Gregorian to Julian Date Number Conversion
        int year = a.y;
        int month = a.m;
        int day = a.d;
        int julianNumber = (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;
        return julianNumber;
    }
    // END OF HELPER FUNCTIONS
    //---------------------------------------------

    bool parseISO(const std::string& s, Date& out) {
        // Enforce "YYYY-MM-DD" with digits in the correct positions
        if (s.size() != 10 || s[4] != '-' || s[7] != '-')
            return false;
        for (int i : {0,1,2,3,5,6,8,9}) 
            if (!std::isdigit((unsigned char)s[i])) 
                return false;
        out.y = std::atoi(s.substr(0,4).c_str());
        out.m = std::atoi(s.substr(5,2).c_str());
        out.d = std::atoi(s.substr(8,2).c_str());
        return true;
    }

    bool isValid(const Date& dt) {
        // TODO: return true only if dt is a real calendar date (handle leap years)
        // Replace the placeholder below.
        int year = dt.y;
        int month = dt.m;
        int day = dt.d;
        bool isValid = false;
        if (month == 2 && isLeapYear(year) && day <= 29)
            isValid = true;
        else if (month == 2 && day <= 28)
            isValid = true;
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30)
            isValid = true;
        else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31)
            isValid = true;
        if (year < 1 || day < 1)
            isValid = false;
        return isValid;
    }

    bool sameDay(const Date& a, const Date& b) {
        // Exact same calendar date
        return (a.y == b.y) && (a.m == b.m) && (a.d == b.d);
    }

    int daysBetween(const Date& a, const Date& b) {
        // TODO: compute nonnegative difference in days between a and b.
        // You may implement via a serial-day function (e.g., Rata Die).
        // Replace the placeholder below.

        int julianA = toSerial(a);
        int julianB = toSerial(b);
        int difference = julianA - julianB; 
        if(difference < 0)
        {
            difference *= -1;
        }
        //std::cout << "Julian A: " << julianA << std::endl << "Julian B: " << julianB << std::endl << "Difference: " <<  difference << std::endl; 
        return difference;
    }
} // namespace DateUtil
