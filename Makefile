CXX = g++

CXXFLAGS = -std=c++17 -g -Wall

LIB_SOURCES = student_database.cpp
LIB_OBJECTS = $(LIB_SOURCES:.cpp=.o)

APP_SOURCE = main.cpp
TEST_SOURCE = tests.cpp

GTEST_LIBS = -lgtest -lgtest_main -lpthread

APP_TARGET = app
TEST_TARGET = test

all: $(APP_TARGET)

$(APP_TARGET): $(APP_SOURCE) $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(APP_TARGET) $(APP_SOURCE) $(LIB_OBJECTS)

$(TEST_TARGET): $(TEST_SOURCE) $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SOURCE) $(LIB_OBJECTS) $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(APP_TARGET) $(TEST_TARGET)

.PHONY: all clean