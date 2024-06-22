# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 01:15:47 by yerbs             #+#    #+#              #
#    Updated: 2024/06/21 16:10:05 by yerbs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/main.c \
		srcs/get_map_size.c \
		srcs/alloc_map.c \
		srcs/init.c \
		srcs/print_map.c \
		srcs/fd_manager.c \
		srcs/check_map.c \
		srcs/check_map_utils.c \
		srcs/free.c \
		srcs/fill.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_printf/srcs/ft_printf.c \
		ft_printf/srcs/ft_printchar.c \
		ft_printf/srcs/ft_printnbr.c \
		ft_printf/srcs/ft_printpointer.c \
		ft_printf/srcs/ft_printhex.c \
		ft_printf/srcs/ft_printpercent.c \
		ft_printf/srcs/ft_printunsignednbr.c \
		ft_printf/srcs/ft_uitoa.c \
		
OBJDIR = .obj/

OBJS = ${SRC:%.c=${OBJDIR}%.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra 
RM = rm -rf

NAME = so_long

all: ps ${NAME}

${OBJDIR}%.o: %.c
	@mkdir -p ${@D}
	@printf "\r${GREEN}Compilation of $(CYAN)so_long${RESET}..."
	@${CC} ${CFLAGS} -c $< -o $@
	${call progress_bar}


define color_progress
$(if $(shell test $(1) -gt 66 && echo true),$(GREEN),$(if $(shell test $(1) -gt 33 && echo true),$(YELLOW),$(RED)))
endef

define progress_bar
@$(eval COMPILED=$(shell echo $$(($(COMPILED)+1))))
@$(eval PROGRESS_PERCENT=$(shell echo $$((($(COMPILED) * 100) / $(TOTAL)))))
@printf "$(CYAN)❘"
@for number in $$(seq 1 $(COMPILED)); do printf "$(call color_progress,$(PROGRESS_PERCENT))█"; done
@for number in $$(seq 1 $$(($(TOTAL) - $(COMPILED)))); do printf "$(GRAY)•"; done
@printf "$(CYAN)❘ $(COMPILED)/$(TOTAL)$(END) ✔️\r"
endef

TOTAL := ${words ${SRC}}
COMPILED := 0

${NAME}: ${OBJS}
	@echo "\n$(CYAN)${NAME}$(RESET) $(GREEN)has been created $(RESET)✔️\n"
	@make --no-print-directory -C ./libft
	@mv ./libft/libft.a .
	@${CC} ${CFLAGS} ${OBJS} libft.a -o so_long

clean:
	@make --no-print-directory clean -C ./libft
	@echo "$(RED)Deleting $(CYAN)${NAME} $(YELLOW)objs$(RESET) ✔️"
	@${RM} ${OBJDIR}

ps:
	@printf "${PINK} --- SO_LONG ---\n"

fclean: clean
	@${RM} libft.a
	@${RM} ${NAME} 
	@${RM} a.out

re: fclean all

.PHONY: all clean fclean re

# ==================== COLOR ==================== #

RED 	:= \033[1;31m
GREEN 	:= \033[1;32m
YELLOW 	:= \033[1;33m
PINK	:= \033[4;35m
CYAN 	:= \033[1;36m
RESET 	:= \033[0m
END 	:= \033[0m
