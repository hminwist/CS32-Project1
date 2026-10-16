
#include "VacationAccount.h"
#include <cassert>

#include <iostream>

int main() {
    // Minimal starter; you must add >= 15 assertions to cover all rules.
    // Suggested coverage: calendar/leap-year cases; validation boundaries;
    // successful donation; ID mismatch; SAME_DAY; TOO_SOON; exactly 180 days;
    // copy construction; copy assignment; and independent copies.

    // --- Example tests (uncomment after you implement the corresponding functions) ---
    // {
    //     BloodDonation good("123456", 30, 150.0, "2026-10-15");
    //     Date d = {2026, 10, 16};
    //     DateUtil::daysBetween(good.date(), d);
    //     std::cout<< "In Section"<< std::endl;
    // }
    // VacationAccount acc("123456");
    // BloodDonation good("123456", 30, 150.0, "2025-01-01");
    // assert(good.validate() == Result::OK);               // field validation
    // assert(acc.add(good) == Result::OK);                 // account-level acceptance
    // assert(acc.size() == 1);                       // size increments
    // assert(acc.balanceHours() == 4.0);             // +4 hours credit

    // BloodDonation badIdFmt("12A456", 30, 150.0, "2025-01-02");
    // assert(badIdFmt.validate() == Result::BAD_ID);       // invalid ID format

    // BloodDonation mismatch("654321", 30, 150.0, "2025-07-01");
    // assert(mismatch.validate() == Result::OK);
    // assert(acc.add(mismatch) == Result::BAD_ID);         // account-level id mismatch

    // BloodDonation sameDay("123456", 30, 150.0, "2025-01-01");
    // assert(acc.add(sameDay) == Result::SAME_DAY);        // duplicate calendar date

    // BloodDonation tooSoon("123456", 30, 150.0, "2025-06-29");
    // assert(tooSoon.validate() == Result::OK);
    // assert(acc.add(tooSoon) == Result::TOO_SOON);        // < 180 days since last accepted
    // std::cout <<"Hello"; 

    // ====================================================================
    // DateUtil::isValid -- leap years
    // ====================================================================
    assert(!DateUtil::isValid(Date{1, 2, 29}));   // not leap
    assert(DateUtil::isValid(Date{4, 2, 29}));   // leap
    assert(!DateUtil::isValid(Date{100, 2, 29}));   // not leap
    assert(DateUtil::isValid(Date{400, 2, 29}));   // leap
    assert(DateUtil::isValid(Date{1600, 2, 29}));   // leap
    assert(!DateUtil::isValid(Date{1700, 2, 29}));   // not leap
    assert(!DateUtil::isValid(Date{1800, 2, 29}));   // not leap
    assert(!DateUtil::isValid(Date{1900, 2, 29}));   // not leap
    assert(DateUtil::isValid(Date{2000, 2, 29}));   // leap
    assert(DateUtil::isValid(Date{2004, 2, 29}));   // leap
    assert(DateUtil::isValid(Date{2020, 2, 29}));   // leap
    assert(!DateUtil::isValid(Date{2021, 2, 29}));   // not leap
    assert(!DateUtil::isValid(Date{2022, 2, 29}));   // not leap
    assert(!DateUtil::isValid(Date{2023, 2, 29}));   // not leap
    assert(DateUtil::isValid(Date{2024, 2, 29}));   // leap
    assert(!DateUtil::isValid(Date{2025, 2, 29}));   // not leap
    assert(!DateUtil::isValid(Date{2026, 2, 29}));   // not leap
    assert(DateUtil::isValid(Date{2028, 2, 29}));   // leap
    assert(DateUtil::isValid(Date{2096, 2, 29}));   // leap
    assert(!DateUtil::isValid(Date{2100, 2, 29}));   // not leap
    assert(!DateUtil::isValid(Date{2200, 2, 29}));   // not leap
    assert(DateUtil::isValid(Date{2400, 2, 29}));   // leap
    assert(DateUtil::isValid(Date{2023, 2, 28}));
    assert(DateUtil::isValid(Date{2024, 2, 28}));
    assert(DateUtil::isValid(Date{1900, 2, 28}));
    assert(DateUtil::isValid(Date{2000, 2, 28}));
    assert(DateUtil::isValid(Date{2025, 2, 28}));
    assert(!DateUtil::isValid(Date{2024, 2, 30}));
    assert(!DateUtil::isValid(Date{2025, 2, 30}));
 
    // ====================================================================
    // DateUtil::isValid -- month lengths (2025 = non-leap)
    // ====================================================================
    assert(DateUtil::isValid(Date{2025, 1, 1}));
    assert(DateUtil::isValid(Date{2025, 1, 31}));
    assert(!DateUtil::isValid(Date{2025, 1, 32}));
    assert(DateUtil::isValid(Date{2025, 2, 1}));
    assert(DateUtil::isValid(Date{2025, 2, 28}));
    assert(!DateUtil::isValid(Date{2025, 2, 29}));
    assert(DateUtil::isValid(Date{2025, 3, 1}));
    assert(DateUtil::isValid(Date{2025, 3, 31}));
    assert(!DateUtil::isValid(Date{2025, 3, 32}));
    assert(DateUtil::isValid(Date{2025, 4, 1}));
    assert(DateUtil::isValid(Date{2025, 4, 30}));
    assert(!DateUtil::isValid(Date{2025, 4, 31}));
    assert(DateUtil::isValid(Date{2025, 5, 1}));
    assert(DateUtil::isValid(Date{2025, 5, 31}));
    assert(!DateUtil::isValid(Date{2025, 5, 32}));
    assert(DateUtil::isValid(Date{2025, 6, 1}));
    assert(DateUtil::isValid(Date{2025, 6, 30}));
    assert(!DateUtil::isValid(Date{2025, 6, 31}));
    assert(DateUtil::isValid(Date{2025, 7, 1}));
    assert(DateUtil::isValid(Date{2025, 7, 31}));
    assert(!DateUtil::isValid(Date{2025, 7, 32}));
    assert(DateUtil::isValid(Date{2025, 8, 1}));
    assert(DateUtil::isValid(Date{2025, 8, 31}));
    assert(!DateUtil::isValid(Date{2025, 8, 32}));
    assert(DateUtil::isValid(Date{2025, 9, 1}));
    assert(DateUtil::isValid(Date{2025, 9, 30}));
    assert(!DateUtil::isValid(Date{2025, 9, 31}));
    assert(DateUtil::isValid(Date{2025, 10, 1}));
    assert(DateUtil::isValid(Date{2025, 10, 31}));
    assert(!DateUtil::isValid(Date{2025, 10, 32}));
    assert(DateUtil::isValid(Date{2025, 11, 1}));
    assert(DateUtil::isValid(Date{2025, 11, 30}));
    assert(!DateUtil::isValid(Date{2025, 11, 31}));
    assert(DateUtil::isValid(Date{2025, 12, 1}));
    assert(DateUtil::isValid(Date{2025, 12, 31}));
    assert(!DateUtil::isValid(Date{2025, 12, 32}));
    assert(DateUtil::isValid(Date{2024, 2, 29}));    // leap-year February
    assert(!DateUtil::isValid(Date{2024, 2, 30}));
 
    // ====================================================================
    // DateUtil::isValid -- out-of-range fields
    // ====================================================================
    assert(!DateUtil::isValid(Date{2025, 0, 10}));
    assert(!DateUtil::isValid(Date{2025, 13, 10}));
    assert(!DateUtil::isValid(Date{2025, -1, 10}));
    assert(!DateUtil::isValid(Date{2025, 1, 0}));
    assert(!DateUtil::isValid(Date{2025, 1, -1}));
    assert(!DateUtil::isValid(Date{2025, 1, 32}));
    assert(!DateUtil::isValid(Date{2025, 2, 0}));
    assert(!DateUtil::isValid(Date{0, 1, 1}));
    assert(!DateUtil::isValid(Date{-1, 1, 1}));
    assert(!DateUtil::isValid(Date{-2025, 6, 15}));
    assert(!DateUtil::isValid(Date{0, 0, 0}));
    assert(DateUtil::isValid(Date{1, 1, 1}));
    assert(DateUtil::isValid(Date{9999, 12, 31}));
    assert(!DateUtil::isValid(Date{}));              // default-constructed Date
 
    // ====================================================================
    // DateUtil::parseISO (format only) and its hand-off to isValid
    // ====================================================================
    {
        Date d;
        assert(DateUtil::parseISO("2025-01-31", d));
        assert(d.y == 2025 && d.m == 1 && d.d == 31);
        assert(DateUtil::parseISO("0001-01-01", d));
        assert(d.y == 1 && d.m == 1 && d.d == 1);
        assert(!DateUtil::parseISO("", d));
        assert(!DateUtil::parseISO("2025-1-01", d));
        assert(!DateUtil::parseISO("2025-01-1", d));
        assert(!DateUtil::parseISO("2025/01/01", d));
        assert(!DateUtil::parseISO("20250101", d));
        assert(!DateUtil::parseISO("2025-01-011", d));
        assert(!DateUtil::parseISO("2025-01-0a", d));
        assert(!DateUtil::parseISO(" 2025-01-01", d));
        assert(!DateUtil::parseISO("2025-01-01 ", d));
        assert(!DateUtil::parseISO("25-01-2025", d));
        assert(!DateUtil::parseISO("abcd-ef-gh", d));
        assert(DateUtil::parseISO("2025-02-30", d));            // shape is fine...
        assert(!DateUtil::isValid(d));            // ...calendar check decides
        assert(DateUtil::parseISO("2025-02-29", d));            // shape is fine...
        assert(!DateUtil::isValid(d));            // ...calendar check decides
        assert(DateUtil::parseISO("2025-13-01", d));            // shape is fine...
        assert(!DateUtil::isValid(d));            // ...calendar check decides
        assert(DateUtil::parseISO("2025-00-10", d));            // shape is fine...
        assert(!DateUtil::isValid(d));            // ...calendar check decides
        assert(DateUtil::parseISO("2025-01-00", d));            // shape is fine...
        assert(!DateUtil::isValid(d));            // ...calendar check decides
        assert(DateUtil::parseISO("0000-01-01", d));            // shape is fine...
        assert(!DateUtil::isValid(d));            // ...calendar check decides
        assert(DateUtil::parseISO("2024-02-29", d));            // shape is fine...
        assert(DateUtil::isValid(d));            // ...calendar check decides
    }
 
    // ====================================================================
    // DateUtil::sameDay
    // ====================================================================
    assert(DateUtil::sameDay(Date{2025, 1, 1}, Date{2025, 1, 1}));
    assert(!DateUtil::sameDay(Date{2025, 1, 1}, Date{2025, 1, 2}));
    assert(!DateUtil::sameDay(Date{2025, 1, 1}, Date{2025, 2, 1}));
    assert(!DateUtil::sameDay(Date{2025, 1, 1}, Date{2026, 1, 1}));
    assert(!DateUtil::sameDay(Date{2025, 3, 4}, Date{2025, 4, 3}));
 
    // ====================================================================
    // DateUtil::daysBetween -- hand-picked cases (expected values from Python datetime)
    // ====================================================================
    assert(DateUtil::daysBetween(Date{2025, 1, 1}, Date{2025, 1, 1}) == 0);
    assert(DateUtil::daysBetween(Date{2025, 1, 1}, Date{2025, 1, 2}) == 1);
    assert(DateUtil::daysBetween(Date{2025, 1, 2}, Date{2025, 1, 1}) == 1);
    assert(DateUtil::daysBetween(Date{2025, 1, 31}, Date{2025, 2, 1}) == 1);
    assert(DateUtil::daysBetween(Date{2025, 2, 28}, Date{2025, 3, 1}) == 1);
    assert(DateUtil::daysBetween(Date{2024, 2, 28}, Date{2024, 3, 1}) == 2);
    assert(DateUtil::daysBetween(Date{2024, 2, 28}, Date{2024, 2, 29}) == 1);
    assert(DateUtil::daysBetween(Date{2000, 2, 28}, Date{2000, 3, 1}) == 2);
    assert(DateUtil::daysBetween(Date{1900, 2, 28}, Date{1900, 3, 1}) == 1);
    assert(DateUtil::daysBetween(Date{2100, 2, 28}, Date{2100, 3, 1}) == 1);
    assert(DateUtil::daysBetween(Date{2024, 12, 31}, Date{2025, 1, 1}) == 1);
    assert(DateUtil::daysBetween(Date{2025, 12, 31}, Date{2026, 1, 1}) == 1);
    assert(DateUtil::daysBetween(Date{2025, 12, 1}, Date{2026, 1, 15}) == 45);
    assert(DateUtil::daysBetween(Date{2024, 11, 15}, Date{2025, 2, 15}) == 92);
    assert(DateUtil::daysBetween(Date{2025, 1, 1}, Date{2026, 1, 1}) == 365);
    assert(DateUtil::daysBetween(Date{2024, 1, 1}, Date{2025, 1, 1}) == 366);
    assert(DateUtil::daysBetween(Date{2023, 3, 1}, Date{2025, 3, 1}) == 731);
    assert(DateUtil::daysBetween(Date{2024, 2, 29}, Date{2025, 2, 28}) == 365);
    assert(DateUtil::daysBetween(Date{2024, 2, 29}, Date{2028, 2, 29}) == 1461);
    assert(DateUtil::daysBetween(Date{1, 1, 1}, Date{1, 12, 31}) == 364);
    assert(DateUtil::daysBetween(Date{1900, 1, 1}, Date{2000, 1, 1}) == 36524);
    assert(DateUtil::daysBetween(Date{2000, 1, 1}, Date{2100, 1, 1}) == 36525);
    assert(DateUtil::daysBetween(Date{1970, 1, 1}, Date{2000, 1, 1}) == 10957);
    assert(DateUtil::daysBetween(Date{2000, 1, 1}, Date{1970, 1, 1}) == 10957);
    assert(DateUtil::daysBetween(Date{2025, 3, 1}, Date{2025, 12, 31}) == 305);
 
    // The 179 / 180 / 181-day boundary (assignment example + leap year + year crossing)
    assert(DateUtil::daysBetween(Date{2025, 1, 1}, Date{2025, 6, 29}) == 179);
    assert(DateUtil::daysBetween(Date{2025, 1, 1}, Date{2025, 6, 30}) == 180);
    assert(DateUtil::daysBetween(Date{2025, 1, 1}, Date{2025, 7, 1}) == 181);
    assert(DateUtil::daysBetween(Date{2024, 1, 1}, Date{2024, 6, 28}) == 179);
    assert(DateUtil::daysBetween(Date{2024, 1, 1}, Date{2024, 6, 29}) == 180);
    assert(DateUtil::daysBetween(Date{2024, 12, 31}, Date{2025, 6, 29}) == 180);
    assert(DateUtil::daysBetween(Date{2023, 12, 15}, Date{2024, 6, 11}) == 179);
    assert(DateUtil::daysBetween(Date{2023, 12, 15}, Date{2024, 6, 12}) == 180);
 
    // 40 more pairs from a fixed random seed, spanning 1850-2150, in random order
    assert(DateUtil::daysBetween(Date{1877, 10, 13}, Date{1926, 8, 30}) == 17852);
    assert(DateUtil::daysBetween(Date{1901, 11, 28}, Date{1958, 10, 13}) == 20773);
    assert(DateUtil::daysBetween(Date{2100, 8, 12}, Date{1935, 5, 4}) == 60366);
    assert(DateUtil::daysBetween(Date{2028, 2, 1}, Date{1858, 9, 23}) == 61857);
    assert(DateUtil::daysBetween(Date{2108, 6, 20}, Date{1863, 11, 1}) == 89351);
    assert(DateUtil::daysBetween(Date{1885, 12, 21}, Date{1966, 7, 13}) == 29423);
    assert(DateUtil::daysBetween(Date{2032, 8, 20}, Date{1968, 7, 19}) == 23408);
    assert(DateUtil::daysBetween(Date{1870, 6, 24}, Date{2037, 8, 12}) == 61045);
    assert(DateUtil::daysBetween(Date{2097, 10, 26}, Date{2018, 3, 23}) == 29072);
    assert(DateUtil::daysBetween(Date{1983, 2, 15}, Date{2065, 10, 2}) == 30180);
    assert(DateUtil::daysBetween(Date{1850, 4, 8}, Date{2044, 8, 25}) == 70997);
    assert(DateUtil::daysBetween(Date{2121, 1, 14}, Date{2130, 6, 19}) == 3443);
    assert(DateUtil::daysBetween(Date{1895, 5, 13}, Date{2038, 4, 13}) == 52200);
    assert(DateUtil::daysBetween(Date{1853, 5, 18}, Date{2024, 3, 20}) == 62398);
    assert(DateUtil::daysBetween(Date{2112, 3, 20}, Date{2127, 5, 26}) == 5545);
    assert(DateUtil::daysBetween(Date{1922, 11, 3}, Date{2150, 3, 20}) == 83048);
    assert(DateUtil::daysBetween(Date{1953, 4, 17}, Date{1922, 5, 17}) == 11293);
    assert(DateUtil::daysBetween(Date{2010, 2, 22}, Date{1879, 4, 1}) == 47809);
    assert(DateUtil::daysBetween(Date{1969, 12, 6}, Date{1893, 5, 1}) == 27977);
    assert(DateUtil::daysBetween(Date{1862, 8, 14}, Date{2038, 7, 27}) == 64265);
    assert(DateUtil::daysBetween(Date{1890, 3, 2}, Date{2111, 2, 19}) == 80707);
    assert(DateUtil::daysBetween(Date{1907, 4, 4}, Date{2007, 6, 28}) == 36610);
    assert(DateUtil::daysBetween(Date{1857, 3, 19}, Date{2004, 10, 22}) == 53908);
    assert(DateUtil::daysBetween(Date{1867, 9, 15}, Date{1863, 9, 25}) == 1451);
    assert(DateUtil::daysBetween(Date{2049, 5, 14}, Date{1976, 9, 9}) == 26545);
    assert(DateUtil::daysBetween(Date{1931, 5, 22}, Date{1908, 8, 4}) == 8326);
    assert(DateUtil::daysBetween(Date{2017, 12, 13}, Date{1961, 2, 17}) == 20753);
    assert(DateUtil::daysBetween(Date{2111, 5, 29}, Date{2026, 9, 13}) == 30938);
    assert(DateUtil::daysBetween(Date{1910, 2, 8}, Date{2041, 11, 11}) == 48124);
    assert(DateUtil::daysBetween(Date{2142, 3, 30}, Date{2141, 8, 4}) == 238);
    assert(DateUtil::daysBetween(Date{2114, 12, 20}, Date{1957, 5, 28}) == 57549);
    assert(DateUtil::daysBetween(Date{2054, 1, 8}, Date{2056, 9, 10}) == 976);
    assert(DateUtil::daysBetween(Date{2056, 8, 5}, Date{1879, 7, 26}) == 64659);
    assert(DateUtil::daysBetween(Date{2126, 5, 18}, Date{1861, 11, 22}) == 96601);
    assert(DateUtil::daysBetween(Date{2060, 9, 7}, Date{1954, 2, 23}) == 38913);
    assert(DateUtil::daysBetween(Date{1932, 4, 15}, Date{1953, 7, 2}) == 7748);
    assert(DateUtil::daysBetween(Date{1968, 3, 28}, Date{1878, 3, 27}) == 32873);
    assert(DateUtil::daysBetween(Date{1937, 7, 27}, Date{2087, 11, 27}) == 54910);
    assert(DateUtil::daysBetween(Date{1993, 10, 11}, Date{1953, 10, 30}) == 14591);
    assert(DateUtil::daysBetween(Date{2003, 2, 23}, Date{2099, 12, 30}) == 35374);
 
    // ====================================================================
    // BloodDonation -- accessors
    // ====================================================================
    {
        BloodDonation b("004321", 44, 175.5, "2025-03-09");
        assert(b.id() == "004321");
        assert(b.age() == 44);
        assert(b.weight() == 175.5);
        assert(b.date().y == 2025 && b.date().m == 3 && b.date().d == 9);
        assert(b.validate() == Result::OK);
        assert(b.validate() == Result::OK);   // repeatable, no side effects
    }
 
    // ====================================================================
    // BloodDonation -- ID (exactly 6 digits)
    // ====================================================================
    assert(BloodDonation("123456", 30, 150.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("000000", 30, 150.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("000001", 30, 150.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("999999", 30, 150.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("12345", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("1234567", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("12A456", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("abcdef", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("12 456", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation(" 23456", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("12345 ", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("-12345", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("+12345", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("12.456", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
 
    // ====================================================================
    // BloodDonation -- age 21..65 inclusive
    // ====================================================================
    assert(BloodDonation("123456", 20, 150.0, "2025-01-01").validate() == Result::BAD_AGE);
    assert(BloodDonation("123456", 21, 150.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("123456", 22, 150.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("123456", 64, 150.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("123456", 65, 150.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("123456", 66, 150.0, "2025-01-01").validate() == Result::BAD_AGE);
    assert(BloodDonation("123456", 0, 150.0, "2025-01-01").validate() == Result::BAD_AGE);
    assert(BloodDonation("123456", -30, 150.0, "2025-01-01").validate() == Result::BAD_AGE);
    assert(BloodDonation("123456", 200, 150.0, "2025-01-01").validate() == Result::BAD_AGE);
 
    // ====================================================================
    // BloodDonation -- weight 101.0..280.0 inclusive
    // ====================================================================
    assert(BloodDonation("123456", 30, 100.0, "2025-01-01").validate() == Result::BAD_WEIGHT);
    assert(BloodDonation("123456", 30, 100.9, "2025-01-01").validate() == Result::BAD_WEIGHT);
    assert(BloodDonation("123456", 30, 100.99, "2025-01-01").validate() == Result::BAD_WEIGHT);
    assert(BloodDonation("123456", 30, 101.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("123456", 30, 101.01, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("123456", 30, 279.99, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("123456", 30, 280.0, "2025-01-01").validate() == Result::OK);
    assert(BloodDonation("123456", 30, 280.01, "2025-01-01").validate() == Result::BAD_WEIGHT);
    assert(BloodDonation("123456", 30, 281.0, "2025-01-01").validate() == Result::BAD_WEIGHT);
    assert(BloodDonation("123456", 30, 0.0, "2025-01-01").validate() == Result::BAD_WEIGHT);
    assert(BloodDonation("123456", 30, -150.0, "2025-01-01").validate() == Result::BAD_WEIGHT);
    assert(BloodDonation("123456", 30, 1000.0, "2025-01-01").validate() == Result::BAD_WEIGHT);
 
    // ====================================================================
    // BloodDonation -- date
    // ====================================================================
    assert(BloodDonation("123456", 30, 150.0, "2024-02-29").validate() == Result::OK);
    assert(BloodDonation("123456", 30, 150.0, "2000-02-29").validate() == Result::OK);
    assert(BloodDonation("123456", 30, 150.0, "2025-12-31").validate() == Result::OK);
    assert(BloodDonation("123456", 30, 150.0, "2025-02-29").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "1900-02-29").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "2025-04-31").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "2025-13-01").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "2025-00-10").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "2025-01-00").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "2025-01-32").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "0000-01-01").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "2025/01/01").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "20250101").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "2025-1-1").validate() == Result::BAD_DATE);
    assert(BloodDonation("123456", 30, 150.0, "not-a-date").validate() == Result::BAD_DATE);
 
    // ====================================================================
    // BloodDonation -- check order: ID, then age, then weight, then date
    // ====================================================================
    assert(BloodDonation("bad", 10, 50.0, "2025-02-30").validate() == Result::BAD_ID);
    assert(BloodDonation("123456", 10, 50.0, "2025-02-30").validate() == Result::BAD_AGE);
    assert(BloodDonation("123456", 30, 50.0, "2025-02-30").validate() == Result::BAD_WEIGHT);
    assert(BloodDonation("123456", 30, 150.0, "2025-02-30").validate() == Result::BAD_DATE);
    assert(BloodDonation("bad", 30, 150.0, "2025-01-01").validate() == Result::BAD_ID);
    assert(BloodDonation("123456", 99, 50.0, "2025-01-01").validate() == Result::BAD_AGE);
    assert(BloodDonation("123456", 30, 300.0, "garbage").validate() == Result::BAD_WEIGHT);
 
    // ====================================================================
    // VacationAccount -- basics
    // ====================================================================
    {   // brand-new account
        VacationAccount acc("123456");
        assert(acc.id() == "123456");
        assert(acc.size() == 0);
        assert(acc.balanceHours() == 0.0);
        assert(acc.at(0) == nullptr);
        assert(acc.at(-1) == nullptr);
        assert(acc.at(1) == nullptr);
    }
 
    {   // first donation accepted
        VacationAccount acc("123456");
        BloodDonation first("123456", 30, 150.0, "2025-01-01");
        assert(acc.add(first) == Result::OK);
        assert(acc.size() == 1);
        assert(acc.balanceHours() == 4.0);
        assert(acc.at(0) != nullptr);
        assert(acc.at(0)->id() == "123456");
        assert(acc.at(0)->age() == 30);
        assert(acc.at(0)->weight() == 150.0);
        assert(DateUtil::sameDay(acc.at(0)->date(), Date{2025, 1, 1}));
        assert(acc.at(1) == nullptr);
        assert(acc.at(-1) == nullptr);
    }
 
    {   // add() stores its OWN copy, not the caller's object
        VacationAccount acc("123456");
        {
            BloodDonation temp("123456", 41, 188.5, "2025-02-03");
            assert(acc.add(temp) == Result::OK);
            assert(acc.at(0) != &temp);
        }   // temp destroyed here; the account's copy must survive
        assert(acc.at(0) != nullptr);
        assert(acc.at(0)->id() == "123456");
        assert(acc.at(0)->age() == 41);
        assert(acc.at(0)->weight() == 188.5);
        assert(DateUtil::sameDay(acc.at(0)->date(), Date{2025, 2, 3}));
    }
 
    // ====================================================================
    // VacationAccount::add -- field rejections (nothing stored, no credit)
    // ====================================================================
    {
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("12345", 30, 150.0, "2025-01-01")) == Result::BAD_ID);
        assert(acc.add(BloodDonation("12A456", 30, 150.0, "2025-01-01")) == Result::BAD_ID);
        assert(acc.add(BloodDonation("123456", 20, 150.0, "2025-01-01")) == Result::BAD_AGE);
        assert(acc.add(BloodDonation("123456", 66, 150.0, "2025-01-01")) == Result::BAD_AGE);
        assert(acc.add(BloodDonation("123456", 30, 100.9, "2025-01-01")) == Result::BAD_WEIGHT);
        assert(acc.add(BloodDonation("123456", 30, 280.1, "2025-01-01")) == Result::BAD_WEIGHT);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-02-29")) == Result::BAD_DATE);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "garbage")) == Result::BAD_DATE);
        assert(acc.size() == 0);
        assert(acc.balanceHours() == 0.0);
        assert(acc.at(0) == nullptr);
        // none of that poisoned the account: a good donation still works
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.size() == 1);
        assert(acc.balanceHours() == 4.0);
    }
 
    // ====================================================================
    // VacationAccount::add -- account ID mismatch, and check ORDER
    // ====================================================================
    {
        VacationAccount acc("123456");
        BloodDonation other("654321", 30, 150.0, "2025-01-01");
        assert(other.validate() == Result::OK);
        assert(acc.add(other) == Result::BAD_ID);
        assert(acc.size() == 0);
        assert(acc.balanceHours() == 0.0);
 
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("654321", 30, 150.0, "2025-09-01")) == Result::BAD_ID);   // mismatch with a non-empty account
        assert(acc.size() == 1);
        assert(acc.balanceHours() == 4.0);
 
        // field validation outranks the ID-mismatch check (step 1 before step 2)
        assert(acc.add(BloodDonation("654321", 10, 150.0, "2025-09-01")) == Result::BAD_AGE);
        assert(acc.add(BloodDonation("654321", 30, 50.0, "2025-09-01")) == Result::BAD_WEIGHT);
        assert(acc.add(BloodDonation("654321", 30, 150.0, "2025-02-30")) == Result::BAD_DATE);
        // ID mismatch outranks SAME_DAY / TOO_SOON (step 2 before steps 3 and 4)
        assert(acc.add(BloodDonation("654321", 30, 150.0, "2025-01-01")) == Result::BAD_ID);   // same date as existing
        assert(acc.add(BloodDonation("654321", 30, 150.0, "2025-01-15")) == Result::BAD_ID);   // too soon
        assert(acc.size() == 1);
    }
 
    // ====================================================================
    // VacationAccount::add -- SAME_DAY and TOO_SOON
    // ====================================================================
    {   // SAME_DAY
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::SAME_DAY);
        assert(acc.add(BloodDonation("123456", 55, 220.0, "2025-01-01")) == Result::SAME_DAY);   // other age/weight, same date
        assert(acc.size() == 1);
        assert(acc.balanceHours() == 4.0);
    }
 
    {   // TOO_SOON
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-02")) == Result::TOO_SOON);   // 1 day
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-03-01")) == Result::TOO_SOON);   // 59 days
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-06-29")) == Result::TOO_SOON);   // 179 days
        assert(acc.size() == 1);
        assert(acc.balanceHours() == 4.0);
    }
 
    {   // exactly 180 days is allowed (assignment example)
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-06-29")) == Result::TOO_SOON);   // 179
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);         // exactly 180
        assert(acc.size() == 2);
        assert(acc.balanceHours() == 8.0);
        assert(acc.at(1) != nullptr);
        assert(DateUtil::sameDay(acc.at(1)->date(), Date{2025, 6, 30}));
    }
 
    {   // 181 days
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-07-01")) == Result::OK);
        assert(acc.size() == 2);
    }
 
    {   // 179 / 180 in a leap year
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2024-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2024-06-28")) == Result::TOO_SOON);   // 179
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2024-06-29")) == Result::OK);         // 180
    }
 
    {   // 179 / 180 crossing a calendar year
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2024-12-31")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-06-28")) == Result::TOO_SOON);   // 179
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-06-29")) == Result::OK);         // 180
    }
 
    {   // another year-crossing boundary
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2023-12-15")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2024-06-11")) == Result::TOO_SOON);   // 179
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2024-06-12")) == Result::OK);         // 180
    }
 
    {   // a later calendar year can still be too soon
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-12-31")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2026-01-01")) == Result::TOO_SOON);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2026-03-15")) == Result::TOO_SOON);
        assert(acc.size() == 1);
    }
 
    {   // a rejected donation must NOT become the new "most recent"
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-03-01")) == Result::TOO_SOON);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);   // 180 after the first ACCEPTED one
        assert(acc.size() == 2);
        assert(acc.balanceHours() == 8.0);
        assert(DateUtil::sameDay(acc.at(1)->date(), Date{2025, 6, 30}));
    }
 
    {   // compares against the most recent accepted donation, not the first
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-07-01")) == Result::OK);          // 181 after the first
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-12-27")) == Result::TOO_SOON);    // 179 after the latest (360 after first)
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-12-28")) == Result::OK);          // exactly 180 after the latest
        assert(acc.size() == 3);
        assert(acc.balanceHours() == 12.0);
    }
 
    {   // spec step 3: SAME_DAY checks ALL accepted donations, not only the latest.
        // (Presents out-of-order dates on purpose; delete this block if you consider it out of scope.)
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-07-01")) == Result::OK);
        //assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::SAME_DAY);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-07-01")) == Result::SAME_DAY);
        assert(acc.size() == 2);
        assert(acc.balanceHours() == 8.0);
    }
 
    {   // hours only move on accepted donations
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.balanceHours() == 4.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-02-30")) == Result::BAD_DATE);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::SAME_DAY);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-02-01")) == Result::TOO_SOON);
        assert(acc.add(BloodDonation("999999", 30, 150.0, "2025-09-01")) == Result::BAD_ID);
        assert(acc.balanceHours() == 4.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
        assert(acc.balanceHours() == 8.0);
        assert(acc.balanceHours() == 4.0 * acc.size());
    }
 
    // ====================================================================
    // VacationAccount -- dynamic array growth (20 donations, exactly 180 days apart)
    // ====================================================================
    {
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2000-01-01")) == Result::OK);
        assert(acc.size() == 1 && acc.balanceHours() == 4.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2000-06-29")) == Result::OK);
        assert(acc.size() == 2 && acc.balanceHours() == 8.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2000-12-26")) == Result::OK);
        assert(acc.size() == 3 && acc.balanceHours() == 12.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2001-06-24")) == Result::OK);
        assert(acc.size() == 4 && acc.balanceHours() == 16.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2001-12-21")) == Result::OK);
        assert(acc.size() == 5 && acc.balanceHours() == 20.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2002-06-19")) == Result::OK);
        assert(acc.size() == 6 && acc.balanceHours() == 24.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2002-12-16")) == Result::OK);
        assert(acc.size() == 7 && acc.balanceHours() == 28.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2003-06-14")) == Result::OK);
        assert(acc.size() == 8 && acc.balanceHours() == 32.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2003-12-11")) == Result::OK);
        assert(acc.size() == 9 && acc.balanceHours() == 36.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2004-06-08")) == Result::OK);
        assert(acc.size() == 10 && acc.balanceHours() == 40.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2004-12-05")) == Result::OK);
        assert(acc.size() == 11 && acc.balanceHours() == 44.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2005-06-03")) == Result::OK);
        assert(acc.size() == 12 && acc.balanceHours() == 48.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2005-11-30")) == Result::OK);
        assert(acc.size() == 13 && acc.balanceHours() == 52.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2006-05-29")) == Result::OK);
        assert(acc.size() == 14 && acc.balanceHours() == 56.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2006-11-25")) == Result::OK);
        assert(acc.size() == 15 && acc.balanceHours() == 60.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2007-05-24")) == Result::OK);
        assert(acc.size() == 16 && acc.balanceHours() == 64.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2007-11-20")) == Result::OK);
        assert(acc.size() == 17 && acc.balanceHours() == 68.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2008-05-18")) == Result::OK);
        assert(acc.size() == 18 && acc.balanceHours() == 72.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2008-11-14")) == Result::OK);
        assert(acc.size() == 19 && acc.balanceHours() == 76.0);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2009-05-13")) == Result::OK);
        assert(acc.size() == 20 && acc.balanceHours() == 80.0);
        assert(acc.at(0) != nullptr && DateUtil::sameDay(acc.at(0)->date(), Date{2000, 1, 1}));
        assert(acc.at(1) != nullptr && DateUtil::sameDay(acc.at(1)->date(), Date{2000, 6, 29}));
        assert(acc.at(2) != nullptr && DateUtil::sameDay(acc.at(2)->date(), Date{2000, 12, 26}));
        assert(acc.at(3) != nullptr && DateUtil::sameDay(acc.at(3)->date(), Date{2001, 6, 24}));
        assert(acc.at(4) != nullptr && DateUtil::sameDay(acc.at(4)->date(), Date{2001, 12, 21}));
        assert(acc.at(5) != nullptr && DateUtil::sameDay(acc.at(5)->date(), Date{2002, 6, 19}));
        assert(acc.at(6) != nullptr && DateUtil::sameDay(acc.at(6)->date(), Date{2002, 12, 16}));
        assert(acc.at(7) != nullptr && DateUtil::sameDay(acc.at(7)->date(), Date{2003, 6, 14}));
        assert(acc.at(8) != nullptr && DateUtil::sameDay(acc.at(8)->date(), Date{2003, 12, 11}));
        assert(acc.at(9) != nullptr && DateUtil::sameDay(acc.at(9)->date(), Date{2004, 6, 8}));
        assert(acc.at(10) != nullptr && DateUtil::sameDay(acc.at(10)->date(), Date{2004, 12, 5}));
        assert(acc.at(11) != nullptr && DateUtil::sameDay(acc.at(11)->date(), Date{2005, 6, 3}));
        assert(acc.at(12) != nullptr && DateUtil::sameDay(acc.at(12)->date(), Date{2005, 11, 30}));
        assert(acc.at(13) != nullptr && DateUtil::sameDay(acc.at(13)->date(), Date{2006, 5, 29}));
        assert(acc.at(14) != nullptr && DateUtil::sameDay(acc.at(14)->date(), Date{2006, 11, 25}));
        assert(acc.at(15) != nullptr && DateUtil::sameDay(acc.at(15)->date(), Date{2007, 5, 24}));
        assert(acc.at(16) != nullptr && DateUtil::sameDay(acc.at(16)->date(), Date{2007, 11, 20}));
        assert(acc.at(17) != nullptr && DateUtil::sameDay(acc.at(17)->date(), Date{2008, 5, 18}));
        assert(acc.at(18) != nullptr && DateUtil::sameDay(acc.at(18)->date(), Date{2008, 11, 14}));
        assert(acc.at(19) != nullptr && DateUtil::sameDay(acc.at(19)->date(), Date{2009, 5, 13}));
        assert(acc.at(20) == nullptr);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2009-11-08")) == Result::TOO_SOON);   // 179 after the last
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2009-05-13")) == Result::SAME_DAY);
        assert(acc.size() == 20);
        assert(acc.balanceHours() == 80.0);
    }
 
    // ====================================================================
    // Rule of Three -- copy constructor
    // ====================================================================
    {   // deep copy, independent afterwards (donations use distinct ages/weights on purpose)
        VacationAccount orig("123456");
        assert(orig.add(BloodDonation("123456", 25, 120.5, "2025-01-01")) == Result::OK);
        assert(orig.add(BloodDonation("123456", 40, 199.0, "2025-06-30")) == Result::OK);
        assert(orig.add(BloodDonation("123456", 65, 280.0, "2025-12-27")) == Result::OK);
        VacationAccount copy(orig);
        assert(copy.id() == "123456");
        assert(copy.size() == 3);
        assert(copy.balanceHours() == 12.0);
    assert(copy.at(0) != nullptr && orig.at(0) != nullptr);
    assert(copy.at(0) != orig.at(0));   // different objects => deep copy
    assert(copy.at(0)->id() == orig.at(0)->id());
    assert(copy.at(0)->age() == orig.at(0)->age());
    assert(copy.at(0)->weight() == orig.at(0)->weight());
    assert(DateUtil::sameDay(copy.at(0)->date(), orig.at(0)->date()));
    assert(copy.at(1) != nullptr && orig.at(1) != nullptr);
    assert(copy.at(1) != orig.at(1));   // different objects => deep copy
    assert(copy.at(1)->id() == orig.at(1)->id());
    assert(copy.at(1)->age() == orig.at(1)->age());
    assert(copy.at(1)->weight() == orig.at(1)->weight());
    assert(DateUtil::sameDay(copy.at(1)->date(), orig.at(1)->date()));
    assert(copy.at(2) != nullptr && orig.at(2) != nullptr);
    assert(copy.at(2) != orig.at(2));   // different objects => deep copy
    assert(copy.at(2)->id() == orig.at(2)->id());
    assert(copy.at(2)->age() == orig.at(2)->age());
    assert(copy.at(2)->weight() == orig.at(2)->weight());
    assert(DateUtil::sameDay(copy.at(2)->date(), orig.at(2)->date()));
        assert(copy.at(3) == nullptr);
        // growing the copy does not touch the original...
        assert(copy.add(BloodDonation("123456", 30, 150.0, "2026-06-25")) == Result::OK);   // exactly 180 after 2025-12-27
        assert(copy.size() == 4);
        assert(copy.balanceHours() == 16.0);
        assert(orig.size() == 3);
        assert(orig.balanceHours() == 12.0);
        assert(orig.at(3) == nullptr);
        // ...and growing the original does not touch the copy
        assert(orig.add(BloodDonation("123456", 30, 150.0, "2026-06-26")) == Result::OK);   // 181 after 2025-12-27
        assert(orig.size() == 4);
        assert(copy.size() == 4);
        assert(copy.at(3)->date().d == 25);
        assert(orig.at(3)->date().d == 26);
    }
    {   // the copy must outlive the original (a shallow copy would dangle / double-free here)
        VacationAccount* heapOrig = new VacationAccount("123456");
        assert(heapOrig->add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(heapOrig->add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
        VacationAccount copy(*heapOrig);
        delete heapOrig;
        assert(copy.size() == 2);
        assert(copy.at(0)->date().y == 2025 && copy.at(0)->date().m == 1 && copy.at(0)->date().d == 1);
        assert(copy.at(1)->date().y == 2025 && copy.at(1)->date().m == 6 && copy.at(1)->date().d == 30);
        assert(copy.at(1)->id() == "123456");
        assert(copy.add(BloodDonation("123456", 30, 150.0, "2025-12-27")) == Result::OK);
        assert(copy.size() == 3);
    }
 
    {   // copy of an EMPTY account must be fully usable
        VacationAccount empty("123456");
        VacationAccount copy(empty);
        assert(copy.id() == "123456");
        assert(copy.size() == 0);
        assert(copy.balanceHours() == 0.0);
        assert(copy.at(0) == nullptr);
        assert(copy.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(copy.add(BloodDonation("123456", 30, 150.0, "2025-01-02")) == Result::TOO_SOON);
        assert(copy.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
        assert(copy.size() == 2);
        assert(empty.size() == 0);
    }
 
    {   // a copy keeps enforcing the rules based on the copied history
        VacationAccount orig("123456");
        assert(orig.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        VacationAccount copy(orig);
        assert(copy.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::SAME_DAY);
        assert(copy.add(BloodDonation("123456", 30, 150.0, "2025-06-29")) == Result::TOO_SOON);
        assert(copy.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
        assert(copy.add(BloodDonation("654321", 30, 150.0, "2025-09-01")) == Result::BAD_ID);   // copy keeps its own ID
    }
 
    {   // copy made and destroyed in an inner scope (what pass-by-value does); original must survive
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
        {
            VacationAccount byValue(acc);
            assert(byValue.size() == 2);
            assert(byValue.balanceHours() == 8.0);
        }
        {
            VacationAccount byValueAgain(acc);
            assert(byValueAgain.size() == 2);
        }
        assert(acc.size() == 2);
        assert(acc.balanceHours() == 8.0);
        assert(acc.at(1) != nullptr);
        assert(acc.at(1)->date().m == 6);
    }
 
    // ====================================================================
    // Rule of Three -- copy assignment
    // ====================================================================
    {   // non-empty = non-empty (different IDs and sizes)
        VacationAccount a("111111");
        assert(a.add(BloodDonation("111111", 25, 120.5, "2025-01-01")) == Result::OK);
        assert(a.add(BloodDonation("111111", 40, 199.0, "2025-06-30")) == Result::OK);
        assert(a.add(BloodDonation("111111", 65, 280.0, "2025-12-27")) == Result::OK);
        VacationAccount b("222222");
        assert(b.add(BloodDonation("222222", 30, 150.0, "2024-03-01")) == Result::OK);
        b = a;
        assert(b.id() == "111111");          // assignment copies the whole account
        assert(b.size() == 3);
        assert(b.balanceHours() == 12.0);
    assert(b.at(0) != nullptr && a.at(0) != nullptr);
    assert(b.at(0) != a.at(0));   // different objects => deep copy
    assert(b.at(0)->id() == a.at(0)->id());
    assert(b.at(0)->age() == a.at(0)->age());
    assert(b.at(0)->weight() == a.at(0)->weight());
    assert(DateUtil::sameDay(b.at(0)->date(), a.at(0)->date()));
    assert(b.at(1) != nullptr && a.at(1) != nullptr);
    assert(b.at(1) != a.at(1));   // different objects => deep copy
    assert(b.at(1)->id() == a.at(1)->id());
    assert(b.at(1)->age() == a.at(1)->age());
    assert(b.at(1)->weight() == a.at(1)->weight());
    assert(DateUtil::sameDay(b.at(1)->date(), a.at(1)->date()));
    assert(b.at(2) != nullptr && a.at(2) != nullptr);
    assert(b.at(2) != a.at(2));   // different objects => deep copy
    assert(b.at(2)->id() == a.at(2)->id());
    assert(b.at(2)->age() == a.at(2)->age());
    assert(b.at(2)->weight() == a.at(2)->weight());
    assert(DateUtil::sameDay(b.at(2)->date(), a.at(2)->date()));
        assert(b.add(BloodDonation("111111", 30, 150.0, "2026-06-25")) == Result::OK);
        assert(b.size() == 4);
        assert(a.size() == 3);               // a unaffected
        assert(a.balanceHours() == 12.0);
        assert(b.add(BloodDonation("222222", 30, 150.0, "2024-03-01")) == Result::BAD_ID);   // old ID/history are gone
    }
    {   // smaller assigned over larger (destination had more donations)
        VacationAccount big("123456");
    assert(big.add(BloodDonation("123456", 30, 150.0, "2020-01-01")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2020-06-29")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2020-12-26")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2021-06-24")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2021-12-21")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2022-06-19")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2022-12-16")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2023-06-14")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2023-12-11")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2024-06-08")) == Result::OK);
        VacationAccount small("123456");
        assert(small.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        big = small;
        assert(big.size() == 1);
        assert(big.balanceHours() == 4.0);
        assert(big.at(0) != nullptr && big.at(0)->date().y == 2025);
        assert(big.at(1) == nullptr);
        assert(big.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
        assert(big.size() == 2);
        assert(small.size() == 1);
    }
    {   // larger assigned over smaller
        VacationAccount small("123456");
        assert(small.add(BloodDonation("123456", 30, 150.0, "2020-01-01")) == Result::OK);
        VacationAccount big("123456");
    assert(big.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2025-12-27")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2026-06-25")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2026-12-22")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2027-06-20")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2027-12-17")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2028-06-14")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2028-12-11")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2029-06-09")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2029-12-06")) == Result::OK);
    assert(big.add(BloodDonation("123456", 30, 150.0, "2030-06-04")) == Result::OK);
        small = big;
        assert(small.size() == 12);
        assert(small.balanceHours() == 48.0);
    assert(small.at(0) != nullptr && big.at(0) != nullptr);
    assert(small.at(0) != big.at(0));   // different objects => deep copy
    assert(small.at(0)->id() == big.at(0)->id());
    assert(small.at(0)->age() == big.at(0)->age());
    assert(small.at(0)->weight() == big.at(0)->weight());
    assert(DateUtil::sameDay(small.at(0)->date(), big.at(0)->date()));
    assert(small.at(5) != nullptr && big.at(5) != nullptr);
    assert(small.at(5) != big.at(5));   // different objects => deep copy
    assert(small.at(5)->id() == big.at(5)->id());
    assert(small.at(5)->age() == big.at(5)->age());
    assert(small.at(5)->weight() == big.at(5)->weight());
    assert(DateUtil::sameDay(small.at(5)->date(), big.at(5)->date()));
    assert(small.at(11) != nullptr && big.at(11) != nullptr);
    assert(small.at(11) != big.at(11));   // different objects => deep copy
    assert(small.at(11)->id() == big.at(11)->id());
    assert(small.at(11)->age() == big.at(11)->age());
    assert(small.at(11)->weight() == big.at(11)->weight());
    assert(DateUtil::sameDay(small.at(11)->date(), big.at(11)->date()));
    }
    {   // empty assigned over non-empty: destination must become empty and stay usable
        VacationAccount full("123456");
        assert(full.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(full.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
        VacationAccount empty("123456");
        full = empty;
        assert(full.size() == 0);
        assert(full.balanceHours() == 0.0);
        assert(full.at(0) == nullptr);
        assert(full.add(BloodDonation("123456", 30, 150.0, "2025-01-02")) == Result::OK);   // old history was wiped
        assert(full.size() == 1);
    }
 
    {   // non-empty assigned over empty
        VacationAccount dest("123456");
        VacationAccount src("123456");
        assert(src.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        dest = src;
        assert(dest.size() == 1);
        assert(dest.balanceHours() == 4.0);
        assert(dest.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::SAME_DAY);
    }
 
    {   // empty assigned over empty
        VacationAccount e1("123456");
        VacationAccount e2("123456");
        e1 = e2;
        assert(e1.size() == 0);
        assert(e1.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(e1.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
    }
 
    {   // self-assignment must be a harmless no-op
        VacationAccount acc("123456");
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
        const BloodDonation* before = acc.at(0);
        VacationAccount& alias = acc;   // alias avoids compiler self-assign warnings
        acc = alias;
        assert(acc.size() == 2);
        assert(acc.balanceHours() == 8.0);
        assert(acc.at(0) == before);
        assert(acc.at(0)->date().m == 1 && acc.at(1)->date().m == 6);
        assert(acc.add(BloodDonation("123456", 30, 150.0, "2025-12-27")) == Result::OK);
    }
 
    {   // chained assignment (operator= must return *this)
        VacationAccount a("123456");
        assert(a.add(BloodDonation("123456", 30, 150.0, "2025-01-01")) == Result::OK);
        VacationAccount b("222222");
        VacationAccount c("333333");
        assert(c.add(BloodDonation("333333", 30, 150.0, "2020-01-01")) == Result::OK);
        assert(c.add(BloodDonation("333333", 30, 150.0, "2020-07-01")) == Result::OK);
        c = b = a;
        assert(b.size() == 1 && c.size() == 1);
        assert(b.id() == "123456" && c.id() == "123456");
        assert(b.at(0) != a.at(0) && c.at(0) != a.at(0) && c.at(0) != b.at(0));
        assert(b.add(BloodDonation("123456", 30, 150.0, "2025-06-30")) == Result::OK);
        assert(a.size() == 1 && c.size() == 1 && b.size() == 2);
    }
 
    // ====================================================================
    // Rule of Three -- copy/assign/destroy a few times in a row
    // ====================================================================
    {
        VacationAccount base("123456");
    assert(base.add(BloodDonation("123456", 30, 150.0, "2010-01-01")) == Result::OK);
    assert(base.add(BloodDonation("123456", 30, 150.0, "2010-06-30")) == Result::OK);
    assert(base.add(BloodDonation("123456", 30, 150.0, "2010-12-27")) == Result::OK);
    assert(base.add(BloodDonation("123456", 30, 150.0, "2011-06-25")) == Result::OK);
    assert(base.add(BloodDonation("123456", 30, 150.0, "2011-12-22")) == Result::OK);
    assert(base.add(BloodDonation("123456", 30, 150.0, "2012-06-19")) == Result::OK);
    assert(base.add(BloodDonation("123456", 30, 150.0, "2012-12-16")) == Result::OK);
        {   // round 1
            VacationAccount c1(base);
            VacationAccount c2("123456");
            c2 = c1;
            VacationAccount c3(c2);
            assert(c3.size() == 7);
            assert(c3.balanceHours() == 28.0);
            assert(c3.at(6) != base.at(6));
        }
        {   // round 2
            VacationAccount c1(base);
            VacationAccount c2("123456");
            c2 = c1;
            VacationAccount c3(c2);
            assert(c3.size() == 7);
            assert(c3.balanceHours() == 28.0);
            assert(c3.at(6) != base.at(6));
        }
        {   // round 3
            VacationAccount c1(base);
            VacationAccount c2("123456");
            c2 = c1;
            VacationAccount c3(c2);
            assert(c3.size() == 7);
            assert(c3.balanceHours() == 28.0);
            assert(c3.at(6) != base.at(6));
        }
        assert(base.size() == 7);
        assert(base.balanceHours() == 28.0);
    }
    std::cout << "All Cases Passed" << std::endl;
    return 0;
}
