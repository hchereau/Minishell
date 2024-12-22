NAME := minishell

### LIBFT #####################################################################

PATH_LIBFT := libft/

LIBFT := $(PATH_LIBFT)libft.a

### SRCS ######################################################################

PATH_SRCS += srcs/
PATH_SRCS += srcs/user_interface/
PATH_SRCS += srcs/history
PATH_SRCS += srcs/syntax_analysis
PATH_SRCS += srcs/syntax_analysis/lexing
PATH_SRCS += srcs/syntax_analysis/parsing
PATH_SRCS += srcs/environment

SRCS += main.c
SRCS += exit_shell_routine.c

# scrs/user_interface

SRCS += signals.c
SRCS += prompt.c

# srcs/history

SRCS += add_history.c

# srcs/syntax_analysis

# srcs/environment

SRCS += env_builtin.c

vpath %.c $(PATH_SRCS)

### TETS SRCS ################################################################

TESTS_NAME := features_tests

TESTS_SRCS_DIR += ./tests
TESTS_SRCS_DIR += ./tests/feature_syntax_analysis
TESTS_SRCS_DIR += ./tests/feature_syntax_analysis/lexing/BDD
TESTS_SRCS_DIR += ./tests/feature_syntax_analysis/lexing/unit_tests
TESTS_SRCS_DIR += ./tests/feature_syntax_analysis/parsing/BDD
TESTS_SRCS_DIR += ./tests/feature_syntax_analysis/parsing/unit_tests
TESTS_SRCS_DIR += ./tests/environment

TESTS_SRCS += tests_main.c

# lexing

TESTS_SRCS += lexing_bdd.c
TESTS_SRCS += lexing_bdd_empty_string.c

# parsing

# environment

TESTS_SRCS += env_builtin.test.c

# Unity

UNITY_SRCS := Unity/src/unity.c

vpath %.c $(TESTS_SRCS_DIR)

### OBJS ######################################################################

PATH_OBJS := objs/

OBJS := $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

### TESTS_OBJS ################################################################

PATH_TESTS_OBJS := objs/tests/

TESTS_OBJS := $(patsubst %.c, $(PATH_TESTS_OBJS)%.o, $(TESTS_SRCS))


### HEADERS ###################################################################

PATH_INCLUDES := includes/
PATH_INCLUDES_LIBFT := $(PATH_LIBFT)includes/
PATH_INCLUDES_TESTS := includes/
PATH_INCLUDES_UNITY := ./Unity/src

HEADERS += $(PATH_INCLUDES)minishell.h
HEADERS += $(PATH_INCLUDES)history.h
HEADERS += $(PATH_INCLUDES)user_interface.h
HEADERS += $(PATH_INCLUDES)environment.h

### COMPILATION ################################################################

CC := cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifeq ($(sanitize), true)
	CFLAGS += -fsanitize=address,undefined -g3
endif

ifeq ($(d), 1)
	CFLAGS += -g3
endif

ifeq ($(d), 2)
	CC = clang
	CFLAGS = -Weverything
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

$(TESTS_OBJS): $(PATH_TESTS_OBJS)%.o: %.c $(HEADERS)
	@mkdir -p $(PATH_TESTS_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES_TESTS) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT) -I $(PATH_INCLUDES_UNITY)


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
	@$(RM) $(TESTS_NAME)
	@$(MAKE) -sC $(PATH_LIBFT) fclean
	@echo "$(GREEN)$(NAME) Fully Cleaned ! $(WHITE)"

re: fclean all

install_hooks:
	.scripts/install_hooks.sh

norminette: $(SRCS) $(HEADERS)
	norminette $^

tests: $(LIBFT) $(TESTS_OBJS) $(filter-out $(PATH_OBJS)main.o, $(OBJS)) $(UNITY_SRCS)
	@echo "$(BLUE)Features tests...$(WHITE)"
	@$(CC) $(CFLAGS) $(RL_FLAG) -I $(PATH_INCLUDES_TESTS) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_UNITY) -I $(PATH_INCLUDES_LIBFT) $^ -o $(TESTS_NAME) -L$(PATH_LIBFT) -lft -DTEST_MODE $(RL_FLAG)
	./features_tests
	@echo "$(GREEN)Features tests passed !$(WHITE)"

#$(CC) $(CFLAGS) $(RL_FLAG) -I $(PATH_INCLUDES_TESTS) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_UNITY) -I $(PATH_INCLUDES_LIBFT) -o $(TESTS_NAME) $^ -DTEST_MODE

environment_tests:
	@echo "$(BLUE)Environment tests...$(WHITE)"
	@./e2e/launch_environment_tests.test.sh
	@echo "$(GREEN)Environment tests passed !$(WHITE)"

.PHONY: all clean fclean re cppcheck clang_analyzer norminette tests
