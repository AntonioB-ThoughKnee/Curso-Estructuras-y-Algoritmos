# C++ Compiler
XC=g++

#default library name
libname=mylib

# Directories
OBJ_DIR=build
BIN_DIR=bin
SRC_DIR=src
INC_DIR=include
LIB_DIR=lib
TEST_DIR=test
TESTOUTPUT_DIR=testOutput

# Compilation flags
INCLUDES= -I include -I src -I lib
FLAGS= $(strip -g $(INCLUDES)) #-std=c++11 -Wall -Wextra 

# Get list of all .cpp files in SRC_DIR
SOURCE_FILES=$(wildcard $(SRC_DIR)/*.cpp)
# For each element in SOURCE_FILES that looks like '$(SRC_DIR)/%.cpp' transform to '$(OBJ_DIR)/%.o'
OBJECT_FILES=$(SOURCE_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Get list of all .so files in LIB_DIR
DYNAMIC_LIBRARIES=$(wildcard $(LIB_DIR)/*.so)
# Get list of all .a files in LIB_DIR
STATIC_LIBRARIES=$(wildcard $(LIB_DIR)/*.a)


$(BIN_DIR)/program.exe: $(OBJECT_FILES)
	mkdir -p $(@D)
	$(XC) $(OBJECT_FILES) $(DYNAMIC_LIBRARIES) $(STATIC_LIBRARIES) -o $(BIN_DIR)/program.exe
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(XC) $(FLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(TESTOUTPUT_DIR)
test: $(TESTOUTPUT_DIR)/tester.exe 
	$(TESTOUTPUT_DIR)/tester.exe
	rm -r $(TESTOUTPUT_DIR)
$(TESTOUTPUT_DIR)/tester.exe :	
	mkdir -p $(TESTOUTPUT_DIR)
	g++ -I $(INC_DIR) -I $(LIB_DIR) -I $(SRC_DIR) SRC2/*.cpp $(TEST_DIR)/*.cpp -o $(TESTOUTPUT_DIR)/tester.exe
static: $(OBJECT_FILES)
	mkdir -p $(BIN_DIR)
	ar rcs $(BIN_DIR)/$(libname).a $(OBJECT_FILES)
dynamic: $(OBJECT_FILES)
	mkdir -p $(BIN_DIR)
	g++ -shared -fPIC $(OBJECT_FILES) -o $(BIN_DIR)/$(libname).so 





