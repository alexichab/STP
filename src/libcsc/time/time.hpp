#pragma once

#include <iostream>

namespace csctime {

class TimeSpan;

class Time {
  private:
    unsigned long long seconds_;

  public:
    constexpr explicit Time(long long s) : seconds_(s) {}
    unsigned long long getSeconds() const { return seconds_; }
    bool operator<(const Time &rhs) const {
        return seconds_ < rhs.getSeconds();
    }
    bool operator<=(const Time &rhs) const { return !(rhs < *this); }
    bool operator>(const Time &rhs) const { return rhs < *this; }
    bool operator>=(const Time &rhs) const { return !(*this < rhs); }
    bool operator==(const Time &rhs) const {
        return !(*this < rhs) || (rhs < *this);
    }

    bool operator!=(const Time &rhs) const {
        return *this < rhs || rhs < *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Time &t) {
        long long days = t.getSeconds() / (24 * 3600);
        long long remaining_seconds = t.getSeconds() % (24 * 3600);
        long long hours = remaining_seconds / 3600;
        remaining_seconds %= 3600;
        long long minutes = remaining_seconds / 60;
        remaining_seconds %= 60;
        os << days << "d " << hours << "h " << minutes << "m "
           << remaining_seconds << "s";
        return os;
    }
};

class TimeSpan {
  private:
    unsigned long long seconds_;

  public:
    constexpr explicit TimeSpan(long long s) : seconds_(s) {}

    unsigned long long getSeconds() const { return seconds_; }

    TimeSpan operator+(const TimeSpan &other) const {
        return TimeSpan(seconds_ + other.getSeconds());
    }

    TimeSpan operator-(const TimeSpan &other) const {
        return TimeSpan(seconds_ - other.getSeconds());
    }

    bool operator<(const TimeSpan &rhs) const {
        return seconds_ < rhs.getSeconds();
    }

    bool operator<=(const TimeSpan &rhs) const { return !(rhs < *this); }
    bool operator>(const TimeSpan &rhs) const { return rhs < *this; }
    bool operator>=(const TimeSpan &rhs) const { return !(*this < rhs); }
    bool operator==(const TimeSpan &rhs) const {
        return !(*this < rhs) || (rhs < *this);
    }
    bool operator!=(const TimeSpan &rhs) const {
        return *this < rhs || rhs < *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const TimeSpan &ts) {
        long long days = ts.getSeconds() / (24 * 3600);
        long long remaining_seconds = ts.getSeconds() % (24 * 3600);
        long long hours = remaining_seconds / 3600;
        remaining_seconds %= 3600;
        long long minutes = remaining_seconds / 60;
        remaining_seconds %= 60;
        os << days << "d " << hours << "h " << minutes << "m "
           << remaining_seconds << "s";
        return os;
    }
};

// Overloaded operators
inline Time operator+(const Time &lhs, const TimeSpan &rhs) {
    return Time(lhs.getSeconds() + rhs.getSeconds());
}

inline Time operator-(const Time &lhs, const TimeSpan &rhs) {
    return Time(lhs.getSeconds() - rhs.getSeconds());
}

inline TimeSpan operator-(const Time &lhs, const Time &rhs) {
    return TimeSpan(lhs.getSeconds() - rhs.getSeconds());
}

// User-defined literals
namespace literals {
inline TimeSpan operator""_d(unsigned long long days) {
    return TimeSpan(days * 24 * 3600);
}

inline TimeSpan operator""_h(unsigned long long hours) {
    return TimeSpan(hours * 3600);
}

inline TimeSpan operator""_m(unsigned long long minutes) {
    return TimeSpan(minutes * 60);
}

inline TimeSpan operator""_s(unsigned long long seconds) {
    return TimeSpan(seconds);
}

} // namespace literals

} // namespace csctime
