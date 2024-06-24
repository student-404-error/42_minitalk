SRCS		=	ft_printf.c		\
			ft_printf_utils.c	\
			ft_print_hex.c		\
			ft_print_ptr.c		\
			ft_print_unsigned.c

NAME		=	libftprintf.a

INCLUDES	=	../../include
LIBFTNAME	=	libft.a
LIBFT_PATH	=	../libft

CC		=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDES)

OBJS		=	$(SRCS:.c=.o)

#======================RULES=======================#

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

all		:	$(NAME)

$(LIBFTNAME)	:
			@make -C $(LIBFT_PATH)
			@cp $(LIBFT_PATH)/$(LIBFTNAME) ./
			@mv $(LIBFTNAME) $(NAME)

$(NAME)		:	$(LIBFTNAME) $(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean		:
			@rm -f $(OBJS)
			@cd $(LIBFT_PATH) && make clean

fclean		:	clean
			@rm -f $(NAME)
			@cd $(LIBFT_PATH) && make fclean

re		:	fclean	\
			all

.PHONY		:	all	\
			clean	\
			fclean	\
			re
