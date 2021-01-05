
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 13:05:32 by fthemis           #+#    #+#              #
#    Updated: 2020/11/04 13:05:33 by fthemis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strrev_bonus.c\
		ft_atoil_bonus.c ft_itoa_x_bonus.c ft_isspace_bonus.c ft_ltoa_bonus.c ft_ltoa_x_bonus.c\
		ft_atof_bonus.c ft_lstindex_bonus.c ft_strcmp_bonus.c

SRC_OBJECTS = $(patsubst %.c,%.o,$(SRC))
BNS_OBJECTS = $(patsubst %.c,%.o,$(BNS))

HEADERS = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_OBJECTS)
	ar rc $(NAME) $(SRC_OBJECTS)

%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@


clean:
	rm -rf $(SRC_OBJECTS) $(BNS_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

bonus: $(SRC_OBJECTS) $(BNS_OBJECTS)
	ar rc $(NAME) $(SRC_OBJECTS) $(BNS_OBJECTS)
