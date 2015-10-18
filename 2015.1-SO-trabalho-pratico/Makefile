CC = g++
RM = /bin/rm -f
PROG = bin
MKDIR_P = mkdir -p
OBJ_DIR := obj/
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -g -Wall
LD_FLAGS := 



.PHONY: directories
all: directories $(PROG)
directories: ${OBJ_DIR}

${OBJ_DIR}:
	${MKDIR_P} ${OBJ_DIR}

$(PROG): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(PROG)

main.o: $(OBJ_FILES)
	$(CC) $(LD_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	$(RM) $(PROG) $(OBJ_FILES)
