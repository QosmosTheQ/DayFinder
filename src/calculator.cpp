#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <string>


std::string determineZodiacSign(int day, int month) {
    std::string zodiacSign;

    if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) {
        zodiacSign = "Aquarius";
    } else if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) {
        zodiacSign = "Pisces";
    } else if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) {
        zodiacSign = "Aries";
    } else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {
        zodiacSign = "Taurus";
    } else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) {
        zodiacSign = "Gemini";
    } else if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) {
        zodiacSign = "Cancer";
    } else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {
        zodiacSign = "Leo";
    } else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {
        zodiacSign = "Virgo";
    } else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {
        zodiacSign = "Libra";
    } else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {
        zodiacSign = "Scorpio";
    } else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {
        zodiacSign = "Sagittarius";
    } else {
        zodiacSign = "Capricorn";
    }

    return zodiacSign;
}

std::string determineChineseZodiac(int year) {
    std::string chineseZodiac;

    switch ((year - 1900) % 12) {
    case 0: chineseZodiac = "Monkey"; break;
    case 1: chineseZodiac = "Rooster"; break;
    case 2: chineseZodiac = "Dog"; break;
    case 3: chineseZodiac = "Pig"; break;
    case 4: chineseZodiac = "Rat"; break;
    case 5: chineseZodiac = "Ox"; break;
    case 6: chineseZodiac = "Tiger"; break;
    case 7: chineseZodiac = "Rabbit"; break;
    case 8: chineseZodiac = "Dragon"; break;
    case 9: chineseZodiac = "Snake"; break;
    case 10: chineseZodiac = "Horse"; break;
    case 11: chineseZodiac = "Sheep"; break;
    }

    return chineseZodiac;
}


struct TimeElapsed {
    int years;
    int months;
    int days;
};

TimeElapsed calculateTimeElapsed(const std::chrono::system_clock::time_point& start, const std::chrono::system_clock::time_point& end) {
    TimeElapsed elapsed;

    std::chrono::duration<double> diff = end - start;
    double totalDays = diff.count() / (60 * 60 * 24);
    elapsed.years = totalDays / 365;
    elapsed.months = (totalDays - (elapsed.years * 365)) / 30;
    elapsed.days = totalDays - (elapsed.years * 365) - (elapsed.months * 30);

    return elapsed;
}

std::string getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int century = year / 100;
    int yearOfCentury = year % 100;

    int dayOfWeek = (day + 13 * (month + 1) / 5 + yearOfCentury + yearOfCentury / 4 + century / 4 - 2 * century) % 7;

    switch (dayOfWeek) {
    case 0:
        return "Saturday";
    case 1:
        return "Sunday";
    case 2:
        return "Monday";
    case 3:
        return "Tuesday";
    case 4:
        return "Wednesday";
    case 5:
        return "Thursday";
    case 6:
        return "Friday";
    default:
        return "Invalid";
    }
}

int calculate() {
    std::cout << "Enter the date (day month year, For example: 10 06 2000): ";
    std::string date;
    std::getline(std::cin, date);

    std::stringstream ss(date);
    int day, month, year;
    ss >> day >> month >> year;

    // Get the current date and time
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Convert the target date to a time_point
    std::tm target_tm = {};
    target_tm.tm_mday = day;
    target_tm.tm_mon = month - 1;
    target_tm.tm_year = year - 1900;
    std::time_t target_time = std::mktime(&target_tm);
    std::chrono::system_clock::time_point target = std::chrono::system_clock::from_time_t(target_time);

    // Calculate the time elapsed
    TimeElapsed elapsed = calculateTimeElapsed(target, now);

    // Print the entered date and the current date
    std::cout << "Entered Date: " << std::setfill('0') << std::setw(2) << day << "." << std::setfill('0') << std::setw(2) << month << "." << year << std::endl;
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current Date: " << std::put_time(std::localtime(&now_time), "%d.%m.%Y") << std::endl;

    // Print the time elapsed
    auto duration = std::chrono::duration_cast<std::chrono::hours>(now - target);
    int hours = duration.count() % 24;
    int days = duration.count() / 24;
    std::cout << " " << std::endl;
    std::cout << "Time Elapsed: " << days << " days, " << hours << " hours." << std::endl;
    std::cout << "Time Elapsed (in year month day): " << elapsed.years << " years, " << elapsed.months << " months, " << elapsed.days << " days." << std::endl;
    std::cout << " " << std::endl;

    // Determine the zodiac sign
    std::string zodiacSign = determineZodiacSign(day, month);
    std::cout << "Zodiac Sign: " << zodiacSign << std::endl;

    // Determine the corresponding Chinese zodiac animal
    std::string chineseZodiac = determineChineseZodiac(year);
    std::cout << "Chinese Zodiac Sign: " << chineseZodiac << std::endl;


    // Determine the day of the week
    std::string dayOfWeek = getDayOfWeek(day, month, year);
    std::cout << "Day of the Week: " << dayOfWeek << std::endl;

    return 0;
}
