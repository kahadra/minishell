#--------------------------------- VARIABLES ---------------------------------#

# Executable / Library (Can be changed).

FT				= libft.a
NAME			= minishell

# Color codes (Can be changed).

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Libraries (Can be changed).

LFT_DIR			= libft

# Project (Can be changed).

SRCS_DIR		= src
OBJS_DIR		= obj

# Location of all header files used in the project to avoid
# writing the full path upon include (Can be changed).

INCS_DIR		:= include
INCS_DIR		+= libft
INCS_DIR		+= $(HOME)/.brew/opt/readline/include
#INCS_DIR		+= /opt/homebrew/opt/readline/include

# All the subdirectories used in the project
# to organise source files (Can be changed).

OBJS_SUBDIRS	:= core
OBJS_SUBDIRS	+= shell
OBJS_SUBDIRS	+= lexer
OBJS_SUBDIRS	+= parser
OBJS_SUBDIRS	+= executor
OBJS_SUBDIRS	+= queue
OBJS_SUBDIRS	+= builtins
OBJS_SUBDIRS	+= process
OBJS_SUBDIRS	+= utils
OBJS_SUBDIRS	+= debug

#------------------------------------ FILES -----------------------------------#

# Every libraries needed to compile the project (Can be changed).

LFT				= $(LFT_DIR)/$(FT)

# Used header at each compilation to check file integrity (Can be changed).

INCS			:= include/ft_core.h
INCS			+= include/ft_enums.h
INCS			+= include/ft_shell.h
INCS			+= include/ft_lexer.h
INCS			+= include/ft_parser.h
INCS			+= include/ft_executor.h
INCS			+= include/ft_structs.h
INCS			+= include/ft_queue.h
INCS			+= include/ft_builtins.h
INCS			+= include/ft_process.h
INCS			+= include/ft_utils.h
INCS			+= include/ft_debug.h

# Source files (Can be changed)

SRCS_MANDA		:= core/main.c
SRCS_MANDA		+= shell/ft_shell.c
SRCS_MANDA		+= shell/ft_shell_setup.c
SRCS_MANDA		+= shell/ft_shell_readline.c
SRCS_MANDA		+= shell/ft_shell_lex.c
SRCS_MANDA		+= shell/ft_shell_parse.c
SRCS_MANDA		+= shell/ft_shell_execute.c
SRCS_MANDA		+= shell/ft_shell_utils.c
SRCS_MANDA		+= lexer/ft_lexer.c
SRCS_MANDA		+= lexer/ft_lexer_env.c
SRCS_MANDA		+= lexer/ft_lexer_env_util.c
SRCS_MANDA		+= lexer/ft_lexer_make_expr.c
SRCS_MANDA		+= lexer/ft_lexer_make_expr_utils.c
SRCS_MANDA		+= lexer/ft_lexer_set_index.c
SRCS_MANDA		+= lexer/ft_lexer_setup.c
SRCS_MANDA		+= lexer/ft_lexer_syntax.c
SRCS_MANDA		+= lexer/ft_lexer_utils.c
SRCS_MANDA		+= parser/ft_parser.c
SRCS_MANDA		+= parser/ft_parser_routine.c
SRCS_MANDA		+= parser/ft_parser_setup.c
SRCS_MANDA		+= parser/ft_parser_utils.c
SRCS_MANDA		+= parser/ft_parser_utils2.c
SRCS_MANDA		+= parser/ft_parser_utils3.c
SRCS_MANDA		+= parser/ft_parser_utils4.c
SRCS_MANDA		+= executor/ft_executor.c
SRCS_MANDA		+= executor/ft_executor_setup.c
SRCS_MANDA		+= executor/ft_executor_heredoc.c
SRCS_MANDA		+= executor/ft_executor_routine.c
SRCS_MANDA		+= executor/ft_executor_utils.c
SRCS_MANDA		+= queue/ft_queue_0.c
SRCS_MANDA		+= queue/ft_queue_1.c
SRCS_MANDA		+= queue/ft_queue_2.c
SRCS_MANDA		+= builtins/ft_builtins.c
SRCS_MANDA		+= builtins/ft_builtins_single.c
SRCS_MANDA		+= builtins/ft_builtins_utils.c
SRCS_MANDA		+= builtins/ft_echo.c
SRCS_MANDA		+= builtins/ft_cd.c
SRCS_MANDA		+= builtins/ft_pwd.c
SRCS_MANDA		+= builtins/ft_export.c
SRCS_MANDA		+= builtins/ft_unset.c
SRCS_MANDA		+= builtins/ft_env.c
SRCS_MANDA		+= builtins/ft_exit.c
SRCS_MANDA		+= process/ft_process.c
SRCS_MANDA		+= process/ft_process_exec.c
SRCS_MANDA		+= process/ft_process_redir.c
SRCS_MANDA		+= utils/ft_dup.c
SRCS_MANDA		+= utils/ft_dup2.c
SRCS_MANDA		+= utils/ft_execve.c
SRCS_MANDA		+= utils/ft_open.c
SRCS_MANDA		+= utils/ft_unlink.c
SRCS_MANDA		+= utils/ft_wait.c
SRCS_MANDA		+= utils/ft_signal.c
SRCS_MANDA		+= utils/ft_termios.c
SRCS_MANDA		+= utils/ft_utils_0.c
SRCS_MANDA		+= utils/ft_utils_1.c
SRCS_MANDA		+= utils/ft_utils_2.c
SRCS_MANDA		+= utils/ft_utils_3.c
SRCS_MANDA		+= debug/ft_debug.c

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job (Can't be changed).

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS_MANDA	= $(addprefix $(D_OBJS), $(OBJS_MANDA))
C_OBJS_BONUS	= $(addprefix $(D_OBJS), $(OBJS_BONUS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

ifeq ($(BONUS_FLAG),1)
	C_OBJS		= $(C_OBJS_BONUS)
else
	C_OBJS		= $(C_OBJS_MANDA)
endif

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled (Can't be changed).

CC				= cc
OBJS_MANDA		= $(SRCS_MANDA:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

# Linked libraries at compile time (Can be changed).

LIBS			:= -L$(LFT_DIR) -lft
LIBS			+= -L$(HOME)/.brew/opt/readline/lib -lreadline
#LIBS			+= -L/opt/homebrew/opt/readline/lib -lreadline

# Compilation flags (Can be changed).

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule
# to prompt some informations (Can't be changed).

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies
# to compile our project (Can't be canged).

all: $(OBJS_DIR) $(C_SUBDIRS) $(NAME)

bonus:
	@make BONUS_FLAG=1

$(NAME): $(LFT) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Libraries installion using their own Makefile (Can be changed).

$(LFT):
	@make -sC $(LFT_DIR) -j

# Rules used to create folders if they aren't already existing (Can be changed).

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Deleting all .o files. (Can't be changed).

clean:
	@make -sC $(LFT_DIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) -r $(OBJS_DIR)

# Deleting all executables and libraries after cleaning up
# all .o files (Can't be changed).

fclean: clean
	@make -sC $(LFT_DIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

# Re-build libs (Can't be changed).

re-libs: $(OBJS_DIR) $(C_SUBDIRS) $(C_OBJS)
	@make -sC $(LFT_DIR) re
	@echo "$(YELLOW)      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Re-compile everything (Can't be changed).

re:
	@make fclean
	@make all

# Avoid unexpected behaviour when regular files
# get the same name as the following variables (Can be changed).

.PHONY: all clean fclean re bonus
