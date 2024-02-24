# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 14:47:42 by afrasch           #+#    #+#              #
#    Updated: 2021/12/21 21:24:30 by afrasch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CHECKER		:= checker

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g

SRCS		:= main.c \
			cdl_lst.c \
			init_stack.c \
			input_check.c \
			op_push.c \
			op_swap.c \
			op_rotation.c \
			op_rev_rotation.c \
			sort_three_or_two.c \
			sort_five.c \
			create_chunks.c \
			push_chunks.c \
			exec_moves_calculator.c \
			moves_calculation.c \
			longest_chain.c \
			find_nums.c \
			find_place.c \
			rotates.c \
			exit_free.c \

SRCS_CHECKER	:= checker.c \
				cdl_lst.c \
				init_stack.c \
				input_check.c \
				op_push.c \
				op_swap.c \
				op_rotation.c \
				op_rev_rotation.c \
				sort_three_or_two.c \
				sort_five.c \
				create_chunks.c \
				push_chunks.c \
				exec_moves_calculator.c \
				moves_calculation.c \
				longest_chain.c \
				find_nums.c \
				find_place.c \
				rotates.c \
				exit_free.c \

LDLIBS		:= -lft

LIBDIRS		:= $(wildcard libs/*)
LDLIBS		:= $(addprefix -L./, $(LIBDIRS)) $(LDLIBS)
INCLUDES	:= -I./include/ $(addprefix -I./, $(addsuffix /include, $(LIBDIRS)))

SDIR		:= src
ODIR		:= obj
OBJS		:= $(addprefix $(ODIR)/, $(SRCS:.c=.o))

OBJS_CHECK	:= $(addprefix $(ODIR)/, $(SRCS_CHECKER:.c=.o))

# COLORS
LB   		= \033[0;36m
B			= \033[0;34m
Y  			= \033[0;33m
G		    = \033[0;32m
R 			= \033[0;31m
X		    = \033[m

# **************************************************************************** #
#	SYSTEM SPECIFIC SETTINGS							   					   #
# **************************************************************************** #

UNAME_S		:= $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	CFLAGS += -D LINUX -Wno-unused-result
endif

# **************************************************************************** #
#	FUNCTIONS									   							   #
# **************************************************************************** #

define MAKE_LIBS
	for DIR in $(LIBDIRS); do \
		$(MAKE) -C $$DIR $(1) --silent; \
	done
endef

# **************************************************************************** #
#	RULES																	   #
# **************************************************************************** #

.PHONY: all $(NAME) $(CHECKER) header prep clean fclean re bonus debug release libs

all: $(NAME) $(CHECKER)

$(CHECKER): libs checker_header prep $(OBJS_CHECK)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(OBJS_CHECK) $(LDLIBS)
	@printf "$(G)======= $(CHECKER)$(X)\n"

$(NAME): libs header prep $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
	@printf "$(G)======= $(NAME)$(X)\n"

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "%-57b %b" "$(B)compile $(LB)$@" "$(G)[✓]$(X)\n"

header:
	@printf "###############################################\n"
	@printf "$(Y)####### $(shell echo "$(NAME)" | tr '[:lower:]' '[:upper:]')$(X)\n"

checker_header:
	@printf "###############################################\n"
	@printf "$(Y)####### $(shell echo "$(CHECKER)" | tr '[:lower:]' '[:upper:]')$(X)\n"

prep:
	@mkdir -p $(ODIR)

clean: libs header
	@$(RM) -r $(ODIR)
	@$(RM) -r *.dSYM $(SDIR)/*.dSYM $(SDIR)/$(NAME)
	@printf "%-50b %b" "$(R)clean" "$(G)[✓]$(X)\n"

fclean: libs header clean
	@$(RM) $(NAME)
	@printf "%-50b %b" "$(R)fclean" "$(G)[✓]$(X)\n"

re: fclean all

bonus: $(CHECKER)

debug: CFLAGS += -O0 -DDEBUG -g
debug: all

release: fclean
release: CFLAGS	+= -O2 -DNDEBUG
release: all clean

libs:
ifeq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), clean fclean re debug release))
	@$(call MAKE_LIBS,$(MAKECMDGOALS))
else
	@$(call MAKE_LIBS,all)
endif
