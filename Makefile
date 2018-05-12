# Application name
APP := main

# Directory Locations
SRC_DIR := src
OBJ_DIR := ./.obj

# File Lists
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

# Compiler options
LDFLAGS  := $(LDFLAGS) `pkg-config --libs opencv`
CXXFLAGS := $(CXXFLAGS) --std=c++11 -Wall -Wextra -Wpedantic


.PHONY: all
all: $(APP) | $(OBJ_DIR)

$(APP): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(APP)
	$(RM) -rf $(OBJ_DIR)