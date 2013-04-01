CXXFLAGS = -std=c++11
LIBS = -lSDL2

CXX = g++

TARGET = Salmon

SRC_DIR = src
OBJ_DIR = build

SOURCES = \
main.cpp\
event/keyboard.cpp\
event/mouse.cpp\
event/resize.cpp


SRCS = $(foreach src,$(SOURCES),$(SRC_DIR)/$(src))
OBJS = $(subst .cpp,.o,\
$(foreach obj,$(SRCS),\
$(subst $(SRC_DIR),$(OBJ_DIR),$(obj))))

$(TARGET): $(OBJS)
	@$(CXX) $(LIBS) $(OBJS) -o $(TARGET)
	@echo "CXX $<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "CXX $<"

clean:
	@rm -rf $(OBJS) $(TARGET)
	@echo "Clean done"
