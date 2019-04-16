CXX = g++
CXXFLAGS = -std=c++0x -g

LINKFLAGS = -lgtest

LIB_CLEAN = -Llibs -lshapes-clean
LIB_BUGS = -Llibs -lshapes-bugs

TEST_DIR = test

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

PROGRAM_TEST = testShapes
PROGRAM_TEST_CLEAN = $(PROGRAM_TEST)-clean
PROGRAM_TEST_BUGS = $(PROGRAM_TEST)-bugs

.PHONY: all
all: $(PROGRAM_TEST_CLEAN) $(PROGRAM_TEST_BUGS) memcheck docs static style

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o $(TEST_SRC)/*.o \
	$(PROGRAM_TEST_CLEAN) $(PROGRAM_TEST_BUGS) $(MEMCHECK_RESULTS) \
	doxygen/html doxygen/doxygen.log obj bin \
	*.bak

$(PROGRAM_TEST_CLEAN): $(TEST_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST)-clean $(INCLUDE) \
	$(TEST_DIR)/*.cpp $(LINKFLAGS) $(LIB_CLEAN)

$(PROGRAM_TEST_BUGS): $(TEST_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST)-bugs $(INCLUDE) \
	$(TEST_DIR)/*.cpp $(LINKFLAGS) $(LIB_BUGS)


test-clean: $(PROGRAM_TEST_CLEAN)
	$(PROGRAM_TEST_CLEAN)

test-bugs: $(PROGRAM_TEST_BUGS)
	$(PROGRAM_TEST_BUGS)

memcheck: $(PROGRAM_TEST_CLEAN)
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM_TEST_CLEAN)

static: ${SRC_DIR} ${TEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${TEST_DIR} ${SRC_INCLUDE} --suppress=missingInclude

style: ${TEST_DIR} ${SRC_INCLUDE}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${TEST_DIR}/*

docs: ${SRC_INCLUDE}
	doxygen doxygen/doxyfile
