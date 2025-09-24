CXX = g++

BASE_CXXFLAGS = -std=c++17 -g -Wall

COVERAGE_FLAGS = --coverage

LIB_SOURCES = student_database.cpp
LIB_OBJECTS = $(LIB_SOURCES:.cpp=.o)
APP_SOURCE = main.cpp
TEST_SOURCE = tests.cpp
APP_TARGET = app
TEST_TARGET = test

COVERAGE_DIR = coverage_report

GTEST_LIBS = -lgtest -lgtest_main -lpthread

all: $(APP_TARGET)

$(APP_TARGET): $(APP_SOURCE) $(LIB_OBJECTS)
	$(CXX) $(BASE_CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_SOURCE) $(LIB_OBJECTS)
	$(CXX) $(BASE_CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) $(BASE_CXXFLAGS) -c $< -o $@

coverage:
	mkdir -p $(COVERAGE_DIR)
	
	cd $(COVERAGE_DIR) && $(CXX) $(BASE_CXXFLAGS) $(COVERAGE_FLAGS) -O0 \
		-o $(TEST_TARGET)_coverage \
		../$(TEST_SOURCE) ../$(LIB_SOURCES) $(GTEST_LIBS)
	
	./$(COVERAGE_DIR)/$(TEST_TARGET)_coverage

	gcovr --gcov-executable gcov-13 --root . \
		--lcov -o coverage_report/coverage.lcov \
		--filter "student_database.cpp"
	
	gcovr --gcov-executable gcov-13 --root . \
		--html-details -o coverage_report/index.html \
		--filter "student_database.cpp" --print-summary


clean:
	rm -f *.o $(APP_TARGET) $(TEST_TARGET)
	# Удаляем папку с отчетами о покрытии и все ее содержимое
	rm -rf $(COVERAGE_DIR)