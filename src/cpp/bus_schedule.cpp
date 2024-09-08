#include "bus_schedule.h"
#include <cstring>
#include <limits>

// Constructor
BusSchedule::BusSchedule()
    : destination_(new char[1]{'\0'}),
      bus_number_(new char[1]{'\0'}),
      departure_time_(new char[1]{'\0'}) {}

// Parameterized Constructor
BusSchedule::BusSchedule(const char* destination,
                         const char* bus_number,
                         const char* departure_time) {
    destination_ = new char[strlen(destination) + 1];
    strcpy(destination_, destination);

    bus_number_ = new char[strlen(bus_number) + 1];
    strcpy(bus_number_, bus_number);

    departure_time_ = new char[strlen(departure_time) + 1];
    strcpy(departure_time_, departure_time);
}

// Copy Constructor
BusSchedule::BusSchedule(const BusSchedule& other) {
    CopyFrom(other);
}

// Copy Assignment Operator
BusSchedule& BusSchedule::operator=(const BusSchedule& other) {
    if (this != &other) {
        FreeMemory();
        CopyFrom(other);
    }
    return *this;
}

// Destructor
BusSchedule::~BusSchedule() {
    FreeMemory();
}

// Input validation for destination
void BusSchedule::InputDestination(char* field) const {
    char input[256];
    while (true) {
        std::cout << "Enter Destination (no numbers allowed): ";
        std::cin.getline(input, 256);

        bool valid = true;
        for (size_t i = 0; i < strlen(input); ++i) {
            if (isdigit(input[i])) {
                std::cout << "Error: Destination cannot contain numbers!\n";
                valid = false;
                break;
            }
        }

        if (strlen(input) > 0 && valid) {
            strcpy(field, input);
            break;
        } else {
            std::cout << "Error: Destination cannot be empty!\n";
        }
    }
}

// Input validation for bus number
void BusSchedule::InputBusNumber(char* field) const {
    char input[256];
    while (true) {
        std::cout << "Enter Bus Number (must start with a digit, can be alphanumeric): ";
        std::cin.getline(input, 256);

        if (strlen(input) == 0 || !isdigit(input[0])) {
            std::cout << "Error: Bus Number must start with a digit and cannot be empty!\n";
            continue;
        }

        bool has_digit = false;
        for (size_t i = 0; i < strlen(input); ++i) {
            if (isdigit(input[i])) {
                has_digit = true;
                break;
            }
        }

        if (has_digit) {
            strcpy(field, input);
            break;
        } else {
            std::cout << "Error: Bus Number must contain at least one digit!\n";
        }
    }
}

// Input validation for departure time
void BusSchedule::InputDepartureTime(char* field) const {
    char input[256];
    while (true) {
        std::cout << "Enter Departure Time (HH:MM, 24-hour format): ";
        std::cin.getline(input, 256);

        if (strlen(input) == 5 && input[2] == ':') {
            int hours = atoi(std::string(input, 2).c_str());
            int minutes = atoi(std::string(input + 3, 2).c_str());

            if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60) {
                strcpy(field, input);
                break;
            }
        }
        std::cout << "Error: Invalid time format!\n";
    }
}

// Method to add a new schedule
void BusSchedule::AddSchedule() {
    InputDestination(destination_);
    InputBusNumber(bus_number_);
    InputDepartureTime(departure_time_);
    std::cout << "New schedule added successfully!\n";
}

// Method to update an existing schedule
void BusSchedule::UpdateSchedule() {
    InputDestination(destination_);
    InputBusNumber(bus_number_);
    InputDepartureTime(departure_time_);
    std::cout << "Schedule updated successfully!\n";
}

// Method to delete a schedule
void BusSchedule::DeleteSchedule() {
    destination_[0] = '\0';
    bus_number_[0] = '\0';
    departure_time_[0] = '\0';
    std::cout << "Schedule deleted successfully!\n";
}

// Method to display the schedule
void BusSchedule::Display() const {
    if (strlen(destination_) > 0 && strlen(bus_number_) > 0 && strlen(departure_time_) > 0) {
        std::cout << "Destination: " << destination_
                  << ", Bus Number: " << bus_number_
                  << ", Departure Time: " << departure_time_ << std::endl;
    } else {
        std::cout << "No schedule available.\n";
    }
}

// Helper function to copy data from another BusSchedule
void BusSchedule::CopyFrom(const BusSchedule& other) {
    destination_ = new char[strlen(other.destination_) + 1];
    strcpy(destination_, other.destination_);

    bus_number_ = new char[strlen(other.bus_number_) + 1];
    strcpy(bus_number_, other.bus_number_);

    departure_time_ = new char[strlen(other.departure_time_) + 1];
    strcpy(departure_time_, other.departure_time_);
}

// Helper function to free allocated memory
void BusSchedule::FreeMemory() {
    delete[] destination_;
    delete[] bus_number_;
    delete[] departure_time_;
}

// Overload input operator for schedule input
std::istream& operator>>(std::istream& in, BusSchedule& bus) {
    bus.AddSchedule();
    return in;
}