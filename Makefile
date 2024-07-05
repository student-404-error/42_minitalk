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
B_CLI		=	client_bonus
B_SRV		=	server_bonus
INCLUDES	=	./include

SRCS		=	./client.c
SRV_SRCS	=	./server.c
CLI_BNS		=	./client_bonus.c
SRV_BNS		=	./server_bonus.c

LIBFTNAME	=	libftprintf.a
LIBFT_PATH	=	./src/ft_printf

CC		=	cc
CFLAGS		=	-Wall -Werror -Wextra -g -I$(INCLUDES)

CLI_OBJS		=	$(SRCS:.c=.o)
SRV_OBJS		=	$(SRV_SRCS:.c=.o)
CLI_BNS_OBJS	=	$(CLI_BNS:.c=.o)
SRV_BNS_OBJS	=	$(SRV_BNS:.c=.o)
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

bonus		:	$(CLI_BNS_OBJS) $(SRV_BNS_OBJS)
			@echo "$(GREEN)==========================$(RESET)"
			@echo "$(GREEN) Building $(BLUE)bonus$(GREEN)...$(RESET)"
			@make -C $(LIBFT_PATH)
			@$(CC) $(CFLAGS) $(CLI_BNS_OBJS) $(LIBFT_PATH)/$(LIBFTNAME) -o $(B_CLI)
			@echo "$(GREEN) Building $(MAGENTA)Server$(GREEN)...$(RESET)"
			@$(CC) $(CFLAGS) $(SRV_BNS_OBJS) $(LIBFT_PATH)/$(LIBFTNAME) -o $(B_SRV)
			@echo "$(GREEN) Build complete!$(RESET)"
			@echo "$(GREEN) Build complete!$(RESET)"
			@echo "$(GREEN)==========================$(RESET)"

clean		:
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"
			@echo "$(RED)Cleaning up...$(RESET)"
			@rm -f $(CLI_OBJS) $(SRV_OBJS) $(CLI_BNS_OBJS) $(SRV_BNS_OBJS)
			@cd $(LIBFT_PATH) && make clean
			@echo "$(RED)Cleaning complete!$(RESET)"
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"

fclean		:	clean
			@echo "$(RED)===========$(CYAN)fclean$(RED)===========$(RESET)"
			@echo "$(RED)Deleting .a files...$(RESET)"
			@rm -f $(CLIENT) $(SERVER) $(B_CLI) $(B_SRV)
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
