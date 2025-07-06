# Makefile for Minimal Qt Window Project
# Qt5-based GUI application

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
INCLUDES = $(shell pkg-config --cflags Qt5Widgets Qt5Core)
LIBS = $(shell pkg-config --libs Qt5Widgets Qt5Core)

# Project files
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = qt_window

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LIBS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Run the application
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Clean everything including the executable
distclean: clean
	rm -f $(TARGET)

# Install dependencies (for Ubuntu/Debian)
install-deps:
	sudo apt-get update
	sudo apt-get install -y build-essential qt5-default pkg-config

# Install dependencies (for Raspberry Pi OS)
install-deps-rpi:
	sudo apt-get update
	sudo apt-get install -y build-essential qt5-default pkg-config

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)

# Release build
release: CXXFLAGS += -DNDEBUG
release: $(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all          - Build the application (default)"
	@echo "  run          - Build and run the application"
	@echo "  clean        - Remove object files"
	@echo "  distclean    - Remove all build artifacts"
	@echo "  debug        - Build with debug symbols"
	@echo "  release      - Build optimized release version"
	@echo "  install-deps - Install dependencies (Ubuntu/Debian)"
	@echo "  install-deps-rpi - Install dependencies (Raspberry Pi OS)"
	@echo "  help         - Show this help message"

# Phony targets
.PHONY: all run clean distclean debug release install-deps install-deps-rpi help 