# Bus Schedules

**Bus Schedules** is a command-line interface (CLI) program that allows users to manage bus schedules using dynamic memory allocation. This system supports basic CRUD operations and validates input fields like the bus number.

## Features:
- **Add, View, Update, and Delete** bus schedules.
- **Bus number validation** (must start with a digit, allows alphanumeric).
- **Dynamic memory allocation** (manages schedules without using STL containers like vectors).
- Developed with **Google C++ Style Guide** and **C++ Core Guidelines** in mind.

## Project Structure:
Bus_Schedules/ ├── src/ │ ├── cpp/ # C++ source files │ └── include/ # Header files ├── obj/ # Compiled object files ├── bin/ # Compiled binary files ├── Makefile # Build script for the project └── README.md # Project documentation

## Prerequisites:
- **C++17** or later.
- **Make** utility for building the project.

## Build Instructions:
1. Clone the repository to your local machine: ```bash git clone https://github.com/your-repo/Bus_Schedules.git cd Bus_Schedules ```

2. Build the project: ```bash make ```

3. Run the program: ```bash ./bin/bus_schedule_manager ```

## Usage Example:
```bash Bus Schedule Management System 1. Add new schedule 2. View schedule 3. Update schedule 4. Delete schedule 5. Exit Enter your choice: 1 Enter Bus Number: 123A Enter Destination: Central Station Schedule added successfully! ```

## Makefile Targets:
- `make` : Compile the project.
- `make clean` : Remove object files and binaries.

## Code Style:
The project follows the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) and the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).

## License:
This project is licensed under the MIT License.
