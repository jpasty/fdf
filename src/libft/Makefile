# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 23:59:53 by cmeowth           #+#    #+#              #
#    Updated: 2020/03/11 23:03:23 by cshinoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

GCC			= /usr/bin/clang
WOPT		= -Wall -Wextra -Werror
OOPT		= -O2
IOPT		= -I $(INCDIR)

AR			= /usr/bin/ar -rc
RM			= /bin/rm -rf
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p

INCDIR		= ./includes
SRCDIR		= ./src
OBJDIR		= ./objects

SRCNAME		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
             	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
             	   ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
             	   ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memdel.c \
             	   ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
             	   ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
             	   ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
             	   ft_strdel.c ft_strdup.c ft_strequ.c ft_strnew.c ft_strnstr.c \
             	   ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
             	   ft_tolower.c ft_toupper.c ft_striter.c ft_striteri.c ft_strjoin.c \
             	   ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
             	   ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_swap.c ft_min.c ft_error.c ft_gnl.c

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))

CLEAR       = "\033[K"
EOC			= "\033[0;0m"
GREEN		= "\033[0;32m"
CR			= "\r"$(CLEAR)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)
	-@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-@$(MKDIR) $(OBJDIR)
	$(GCC) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	$(NORMINETTE) $(INCDIR) $(SRC)

.PHONY: all clean fclean re norm
