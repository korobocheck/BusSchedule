# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./src/include

# Directories
SRCDIR = src/cpp
INCDIR = src/include
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/bus_schedule.cpp $(SRCDIR)/bus_schedule_manager.cpp

# Object files
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Output executable
EXEC = $(BINDIR)/bus_schedule_app

# Default target
all: $(EXEC)

# Rule to compile the executable
$(EXEC): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object and binary files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Phony targets to prevent conflicts with filenames
.PHONY: all clean
