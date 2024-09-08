#include "bus_schedule_manager.h"
#include <iostream>
#include <limits>

void DisplayMenu() {
    std::cout << "\n\n\n";
    std::cout << "Bus Schedule Management System\n";
    std::cout << "1. Add new schedule\n";
    std::cout << "2. View schedules\n";
    std::cout << "3. Update schedule\n";
    std::cout << "4. Delete schedule\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    BusScheduleManager manager;
    int choice;
    int index;
    int scheduleCount = 0;

    while (true) {
        DisplayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
            case 1:
                manager.AddSchedule();
                scheduleCount++;
                break;
            case 2:
                manager.DisplaySchedules();
                break;
            case 3:
                {
                    if (scheduleCount == 0) {
                        std::cout << "No schedules available to update.\n";
                        break;
                    }
                    manager.DisplaySchedules();  // Show current schedules
                    std::cout << "Enter index of the schedule to update (0 to " << (scheduleCount - 1) << "): ";
                    std::cin >> index;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

                    if (index >= 0 && index < scheduleCount) {
                        manager.UpdateSchedule(index);
                    } else {
                        std::cout << "Invalid index! Please try again.\n";
                    }
                }
                break;
            case 4:
                {
                    if (scheduleCount == 0) {
                        std::cout << "No schedules available to delete.\n";
                        break;
                    }
                    manager.DisplaySchedules();  // Show current schedules
                    std::cout << "Enter index of the schedule to delete (0 to " << (scheduleCount - 1) << "): ";
                    std::cin >> index;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer

                    if (index >= 0 && index < scheduleCount) {
                        manager.DeleteSchedule(index);
                        scheduleCount--;
                    } else {
                        std::cout << "Invalid index! Please try again.\n";
                    }
                }
                break;
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }
}
