# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 15:46:15 by tshimoda          #+#    #+#              #
#    Updated: 2022/02/07 16:10:52 by tshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= test_jour1

AR= ar rc
RM= rm -rf

CC= gcc
CFLAGS= -Wall -Werror -Wextra -c -g
MFLAGS= -Lminilibx_opengl -lmlx -framework OpenGL -framework Appkit

SDIR= sources
ODIR= objects

SRCS=	main.c

OBJS= $(SRCS:.c=.o)

SFIX= $(addprefix $(SDIR)/, $(SRCS))
OFIX= $(addprefix $(ODIR)/, $(OBJS)) 

VPATH= $(SDIR)

$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(ODIR) $(OFIX)
#	$(MAKE) -C ./libft
#	$(MAKE) -C ./minilibx_macos
#	$(CC) $(OFIX) $(MFLAGS) -lft -L./libft -o $(NAME)
	$(CC) $(OFIX) $(MFLAGS) -o $(NAME)
	@echo "\033[1;32m 下田、徳太郎のTEST_MINILIBX\033[0;39m"

all:	$(NAME)

$(ODIR):
		mkdir -p $(ODIR)

#bonus: all

clean:
#	$(MAKE) clean -C ./libft
	$(RM) $(NAME) $(ODIR)

fclean: clean
#	$(MAKE) fclean -C ./libft
	@echo "\033[1;34m make fclean done!\033[0;39m"
	
re:	clean all

.PHONY: all clean flcean re