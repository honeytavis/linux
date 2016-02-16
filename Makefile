# Make variables (CC, etc...)
CC			:= gcc
CFLAGS		 = -Wall -I $(DIR_INC)

EXE			:= main.exe
DIR_SRC 	:= $(wildcard src)
DIR_OBJ 	:= $(wildcard bin)
DIR_INC 	:= $(wildcard include) 
SRC 		 = $(wildcard $(DIR_SRC)/*.c)
OBJ 		 = $(patsubst %.c, $(DIR_OBJ)/%.o, $(notdir $(SRC)))

# ===========================================================================
# Rules shared between targets and prerequisites

$(EXE): $(OBJ)
	$(CC) $^ -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	$(CC) -c $< -o $@ $(CFLAGS) 

PHONY += clean
clean: 
	@rm -f $(EXE) $(OBJ)

.PHONY: PHONY
