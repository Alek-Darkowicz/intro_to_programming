#include <iostream>
#include <string>

enum class Time_of_day{ Morning, Day, Evening, Night};
struct time_ {
    int hour;
    int minute;
    int second;
    //constructor
    time_(int a, int b, int c) {
        hour = a;
        minute = b;
        second = c;
    }
    //member functions
    auto to_string() const -> std::string {
        std::string output; 
        if (hour < 10) {
            output = "0";
        }
        output = output + std::to_string(hour) + ":";
        if (minute < 10) {
            output = output + "0";
        }
        output = output + std::to_string(minute) + ":";
        if (second < 10) {
            output = output + "0";
        }
        output = output + std::to_string(second);
        return output;
    }
    auto next_hour() -> void {
        hour = hour + 1;
        if (hour >= 24) {
            hour = (hour % 24);
        }
        std::cout << time_::to_string();
        return;
    }
    auto next_minute() -> void {
        minute = minute + 1;
        if (minute >= 60) {
            hour = hour + ((minute - (minute % 60)) / 60);
            minute = (minute % 60);
            if (hour >= 24) {
                hour = (hour % 24);
            }
        }
        std::cout << time_::to_string();
        return;
    }
    auto next_second() -> void {
        second = second + 1;
        if (second >= 60) {
            minute = minute + ((second - (second % 60)) / 60);
            second = (second % 60);
            if (minute >= 60) {
                hour = hour + ((minute - (minute % 60)) / 60);
                minute = (minute % 60);
                if (hour >= 24) {
                    hour = (hour % 24);
                }
            }
        }
        std::cout << time_::to_string();
        return;
    }
    auto time_of_day() const -> Time_of_day {
        if ((hour >= 6) and (hour < 12)) {
            return Time_of_day::Morning;
        }
        else if ((hour >= 12) and (hour < 18)) {
            return Time_of_day::Day;
        }
        else if ((hour >= 0) and (hour < 6)) {
            return Time_of_day::Night;
        }
        else {
            return Time_of_day::Evening;
        }
    }
    auto to_string(Time_of_day const a) -> std::string {
        if (a == Time_of_day::Morning) {
            return "Morning";
        }
        else if (a == Time_of_day::Night) {
            return "Night";
        }
        else if (a == Time_of_day::Day) {
            return "Day";
        }
        else {
            return "Evening";
        }
    }
    auto operator+ (time_ const& a) const -> time_ {
        int h = hour;
        int m = minute;
        int s = second;
        h = h + a.hour;
        m = m + a.minute;
        s = s + a.second;
        if (s >= 60) {
            m = m + ((s - (s % 60)) / 60);
            s = (s % 60);
        }
        if (m >= 60) {
            h = h + ((m - (m % 60)) / 60);
            m = (m % 60);
        }
        if (h >= 24) {
            h = (h % 24);
        }
        return time_(h, m, s);
    }
    auto operator- (time_ const& a) const -> time_ {
        int h = hour;
        int m = minute;
        int s = second;
        h = h - a.hour;
        m = m - a.minute;
        s = s - a.second;
        if (s < 0) {
            m = m + ((s - (s % 60)) / 60) - 1;
            s = (60 + (s % 60));
        }
        if (m < 0) {
            h = h + ((m - (m % 60)) / 60) - 1;
            m = (60 + (m % 60));
        }
        if (h < 0) {
            h = (24 + (h % 24));
        }
        return time_(h, m, s);
    }
    auto operator< (time_ const& a) const -> bool {
        int h = hour;
        int m = minute;
        int s = second;
        if (h < a.hour) {
            return true;
        }
        else if (h == a.hour) {
            if (m < a.minute) {
                return true;
            }
            else if (m == a.minute) {
                if (s < a.second) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else{
            return false;
        }
    }
    auto operator> (time_ const& a) const -> bool {
        int h = hour;
        int m = minute;
        int s = second;
        if (h > a.hour) {
            return true;
        }
        else if (h == a.hour) {
            if (m > a.minute) {
                return true;
            }
            else if (m == a.minute) {
                if (s > a.second) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else{
            return false;
        }
    }
    auto operator== (time_ const& a) const -> bool {
        int h = hour;
        int m = minute;
        int s = second;
        if (h == a.hour) {
            if (m == a.minute) {
                if (s == a.second) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else{
            return false;
        }
    }
    auto operator!= (time_ const& a) const -> bool {
        int h = hour;
        int m = minute;
        int s = second;
        if (h == a.hour) {
            if (m == a.minute) {
                if (s == a.second) {
                    return false;
                }
                else {
                    return true;
                }
            }
            else {
                return true;
            }
        }
        else{
            return true;
        }
    }
    auto count_seconds() const -> uint64_t {
        return (((hour*60 + minute)*60) + second);
    }
    auto count_minutes() const -> uint64_t {
        return (((((hour*60 + minute)*60) + second) - ((((hour*60 + minute)*60) + second) % 60)) / 60);
    }
    auto time_to_midnight() const -> time_ {
        time_ Midnight(24, 0, 0);
        time_ Current(hour, minute, second);
        return (Midnight - Current);
    }
};
