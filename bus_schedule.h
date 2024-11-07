#ifndef BUS_SCHEDULE_H
#define BUS_SCHEDULE_H

#include <iostream>

class BusSchedule {
public:
    BusSchedule();
    BusSchedule(const char* destination,
                const char* bus_number,
                const char* departure_time);
    BusSchedule(const BusSchedule& other);

    BusSchedule& operator=(const BusSchedule& other);

    ~BusSchedule();
    friend bool AreSchedulesEqual(const BusSchedule& lhs, const BusSchedule& rhs);

    void InputDestination(char* field) const;
    void InputBusNumber(char* field) const;
    void InputDepartureTime(char* field) const;
    void AddSchedule();
    void UpdateSchedule();
    void DeleteSchedule();
    void Display() const;

    bool operator==(const BusSchedule& other) const;
    bool operator!=(const BusSchedule& other) const;
    bool operator<(const BusSchedule& other) const;
private:
    char* destination_;
    char* bus_number_;
    char* departure_time_;

    void CopyFrom(const BusSchedule& other);
    void FreeMemory();

    friend std::istream& operator>>(std::istream& in, BusSchedule& bus);
    friend bool AreSchedulesEqual(const BusSchedule& lhs, const BusSchedule& rhs);
};

#endif // BUS_SCHEDULE_H