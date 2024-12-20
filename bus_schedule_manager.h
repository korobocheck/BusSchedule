#ifndef BUS_SCHEDULE_MANAGER_H
#define BUS_SCHEDULE_MANAGER_H

#include "bus_schedule.h"

class BusScheduleManager {
public:
    BusScheduleManager();
    ~BusScheduleManager();

    BusScheduleManager(const BusScheduleManager& other);  // Copy constructor
    BusScheduleManager& operator=(const BusScheduleManager& other);  // Assignment operator

    void AddSchedule();
    void UpdateSchedule(int index) const;
    void DeleteSchedule(int index);
    void DisplaySchedules() const;
    bool CompareSchedules(int index1, int index2) const;

    bool IsFirstScheduleEarlier(int index1, int index2) const;
private:
    BusSchedule** schedules_;
    int size_;
    int capacity_;

    void Resize();
    void CopyFrom(const BusScheduleManager& other);  // Helper function for copy constructor and assignment
    void Clear();  // Helper function to clear resources
};

#endif // BUS_SCHEDULE_MANAGER_H
