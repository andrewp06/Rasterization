# Compiler
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -g -I/opt/homebrew/include

# Executable name
TARGET = Main

# Source files
SOURCES = Main.cpp 2DVector.cpp 3DVector.cpp ProjectionMath.cpp Triangle.cpp Window.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Libraries
LIBS = -L/opt/homebrew/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

# Default rule
all: $(TARGET)

# Link objects into the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

# Compile source files into objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
