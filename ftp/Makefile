# Make variables (CC, etc...)
CC			:= gcc
CFLAGS		 = -Wall -I $(DIR_INC)

DIR_INC 	:= $(wildcard include) 
DIR_SRC 	:= $(wildcard src)
DIR_OBJ 	:= $(wildcard obj)
DIR_EXE		:= $(wildcard bin)

SRC 		 = $(wildcard $(DIR_SRC)/*.c)
OBJ 		 = $(patsubst %.c, $(DIR_OBJ)/%.o, $(notdir $(SRC)))
TARGET 		 = main.exe
EXE			:= $(wildcard $(DIR_EXE)/$(TARGET))
#EXE			:= $(DIR_EXE)/$(TARGET)

# ===========================================================================
# Rules shared between targets and prerequisites

#$(EXE): $(OBJ)
$(DIR_EXE)/$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	$(CC) -c $< -o $@ $(CFLAGS) 

PHONY += clean
clean: 
	@rm -f $(EXE) $(OBJ)

.PHONY: PHONY
