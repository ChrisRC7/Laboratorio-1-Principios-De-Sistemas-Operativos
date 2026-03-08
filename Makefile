CXX = g++
CXXFLAGS = -std=c++20 -O3
TARGET = factorial
SRC= factorial.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)