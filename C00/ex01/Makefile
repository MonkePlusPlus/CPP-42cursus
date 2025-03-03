
SRC_DIR = ./src/

BUILD_DIR = ./build/

INCLUDES = ./includes/

# ALL FILES
FILES = PhoneBook.cpp
FILES += Contact.cpp
# END FILES

SRC_FILES = $(addprefix $(SRC_DIR), $(FILES))

OBJ_FILES = $(patsubst $(SRC_DIR)%.cpp, $(BUILD_DIR)%.o, $(SRC_FILES))

DEP_FILES = $(patsubst $(SRC_DIR)%.cpp, $(BUILD_DIR)%.d, $(SRC_FILES))

NAME		:= phonebook
CXX			:= c++
CXXFLAGS	:=  -gdwarf-4 -Wall -Wextra -Werror -I $(INCLUDES) -MMD -MP -std=c++98

MKDIR	:= mkdir -p
RM_RF	:= rm -rf
ECHO	:= echo

BLUE	:= \e[34m
BROWN	:= \e[33m
GREEN	:= \e[32m
RED		:= \e[31m
NC		:= \e[0m

$(BUILD_DIR)%.o : $(SRC_DIR)%.cpp
	@$(MKDIR) $(dir $@)
	@$(ECHO) "$(BLUE)[CMP] Compiling $<...$(NC)"
	@$(CXX) -c $(CXXFLAGS) $< -o $@

# This is to add the .d files as dependencies for linking
-include $(DEP_FILES)

re : clean all 

$(NAME) : $(OBJ_FILES)
	@$(ECHO) "$(BROWN)[BLD] Building executable...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)
	@$(ECHO) "$(GREEN)[BLD] Executable built successfully.$(NC)"

all : $(NAME)

clean : 
	@$(ECHO) "$(BROWN)[CLN] Cleaning object and dependency files...$(NC)"
	@$(RM_RF) $(DEP_FILES) $(BUILD_DIR)
	@$(ECHO) "$(GREEN)[CLN] Clean complete.$(NC)"

fclean : 
	@$(ECHO) "$(BROWN)[CLN] Cleaning object, dependency files, and executable...$(NC)"
	@$(RM_RF) $(BUILD_DIR) $(NAME)
	@$(ECHO) "$(GREEN)[CLN] Clean complete.$(NC)"

.DEFAULT_GOAL := all
.PHONY: all clean fclean re