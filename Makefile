NAME := minishell

### LIBFT #####################################################################

PATH_LIBFT := libft/

LIBFT := $(PATH_LIBFT)libft.a

### SRCS ######################################################################

PATH_SRCS += srcs/
PATH_SRCS += srcs/history

SRCS += main.c
SRCS += exit_shell_routine.c
SRCS += prompt.c

## HISTORY ##

SRCS += add_history.c

vpath %.c $(PATH_SRCS)

### OBJS ######################################################################

PATH_OBJS := objs/

OBJS := $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

### HEADERS ###################################################################

PATH_INCLUDES := includes/
PATH_INCLUDES_LIBFT := $(PATH_LIBFT)includes/

HEADERS += $(PATH_INCLUDES)minishell.h

### COMPILATION ################################################################

CC := cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifeq ($(sanitize), true)
	CFLAGS += -fsanitize=address,undefined -g3
endif

### RL_FLAG ####################################################################

RL_FLAG := -lreadline

### COLORS #####################################################################

GREEN := \033[0;32m
BLUE := \033[0;34m
WHITE := \033[0;37m

### LINT #######################################################################

CLANG_ANALYZE_OPTIONS = --analyze \
						-Weverything \
						-Wno-unknown-warning-option \
						-Werror \
						-ferror-limit=0 \
						-Xanalyzer -analyzer-output=text \
						-Xanalyzer -analyzer-config \
						-Xanalyzer aggressive-binary-operation-simplification=true \
						-Xanalyzer -analyzer-config \
						-Xanalyzer unroll-loops=true

CPPCHECK_OPTIONS =  --enable=all \
					--inconclusive \
					--error-exitcode=1 \
					--suppress=missingIncludeSystem \
					--suppress=variableScope

### RULES ######################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(WHITE)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT) $(RL_FLAG)
	@echo "$(GREEN)$(NAME) Compiled !$(WHITE)"

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADERS)
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT)

$(LIBFT):
	@echo "$(BLUE)Compiling $(LIBFT) ...$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT)
	@echo "$(GREEN)$(LIBFT) Compiled ! $(WHITE)"

clean:
	@echo "$(BLUE)Cleaning $(NAME) ...$(WHITE)"
	@$(RM) -r $(PATH_OBJS)
	@$(MAKE) -sC $(PATH_LIBFT) clean
	@echo "$(GREEN)$(NAME) Cleaned ! $(WHITE)"

fclean: clean
	@echo "$(BLUE)Full Cleaning $(NAME) ...$(WHITE)"
	@$(RM) $(NAME)
	@$(MAKE) -sC $(PATH_LIBFT) fclean
	@echo "$(GREEN)$(NAME) Fully Cleaned ! $(WHITE)"

re: fclean all

install_hooks:
	.scripts/install_hooks.sh

norminette: $(SRCS) $(HEADERS)
	norminette $^

environment_tests:
	@echo "$(BLUE)Environment tests...$(WHITE)"
	@./e2e/Launch_shell/launch_shell.test.sh
	@echo "$(GREEN)Environment tests passed !$(WHITE)"

.PHONY: all clean fclean re cppcheck clang_analyzer norminette
