# ANSI COLOR CODE
RED		:=	\033[31m
GREEN		:=	\033[32m
YELLOW		:=	\033[33m
BLUE		:=	\033[34m
MAGENTA		:=	\033[35m
CYAN		:=	\033[36m
WHITE		:=	\033[37m
RESET		:=	\033[0m

NAME		=	minitalk
CLIENT		=	client
SERVER		=	server

INCLUDES	=	./include

#SRC_DIR		=	./
#SRCS		=	$(wildcard $(SRC_DIR)/*.c)
SRCS		=	./client.c
SRV_SRCS	=	./server.c
#BONUS_DIR	=	./src/bonus
#BONUS_SRCS	=	$(wildcard $(BONUS_DIR)/*.c)

LIBFTNAME	=	libftprintf.a
LIBFT_PATH	=	./src/ft_printf

CC		=	cc
CFLAGS		=	-Wall -Werror -Wextra -g -I$(INCLUDES)

CLI_OBJS		=	$(SRCS:.c=.o)
SRV_OBJS		=	$(SRV_SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

#======================RULES=======================#

all		:	$(NAME)

$(NAME)		:	$(CLI_OBJS) $(SRV_OBJS)
			@echo "$(GREEN)==========================$(RESET)"
			@echo "$(GREEN) Building $(MAGENTA)Client$(GREEN)...$(RESET)"
			@make -C $(LIBFT_PATH)
			@$(CC) $(CFLAGS) $(CLI_OBJS) $(LIBFT_PATH)/$(LIBFTNAME) -o $(CLIENT)
			@echo "$(GREEN) Building $(MAGENTA)Server$(GREEN)...$(RESET)"
			@$(CC) $(CFLAGS) $(SRV_OBJS) $(LIBFT_PATH)/$(LIBFTNAME) -o $(SERVER)
			@echo "$(GREEN) Build complete!$(RESET)"
			@echo "$(GREEN)==========================$(RESET)"

bonus		:	$(B_OBJS)
			@echo "$(GREEN)==========================$(RESET)"
			@echo "$(GREEN) Building $(BLUE)checker$(GREEN)...$(RESET)"
			@make -C $(LIBFT_PATH)
			@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT_PATH)/$(LIBFTNAME) -o checker
			@echo "$(GREEN) Build complete!$(RESET)"
			@echo "$(GREEN)==========================$(RESET)"

clean		:
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"
			@echo "$(RED)Cleaning up...$(RESET)"
			@rm -f $(CLI_OBJS) $(SRV_OBJS)
			@cd $(LIBFT_PATH) && make clean
			@echo "$(RED)Cleaning complete!$(RESET)"
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"

fclean		:	clean
			@echo "$(RED)===========$(CYAN)fclean$(RED)===========$(RESET)"
			@echo "$(RED)Deleting .a files...$(RESET)"
			@rm -f $(CLIENT) $(SERVER)
			@cd $(LIBFT_PATH) && make fclean
			@echo "$(RED)Delete complete!$(RESET)"
			@echo "$(RED)===========$(CYAN)fclean$(RED)===========$(RESET)"

re		:	fclean	\
			all

.PHONY		:	all	\
			clean	\
			fclean	\
			bonus	\
			re
