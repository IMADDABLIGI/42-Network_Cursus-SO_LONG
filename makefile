# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 10:07:02 by idabligi          #+#    #+#              #
#    Updated: 2023/02/19 12:19:32 by idabligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME2 = so_long_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

MAN = mandatory/
HEADER = mandatory/header.h

BNS = bonus/
HEADER_B = bonus/header_bonus.h

FLS = mandatory/ft_split  mandatory/main  mandatory/ft_get_map  mandatory/ft_images  mandatory/ft_width_height\
	mandatory/ft_push  mandatory/ft_write_error  mandatory/ft_find_player  mandatory/ft_cheek_coins  mandatory/ft_norme\
	mandatory/ft_write_error1  mandatory/ft_end  mandatory/ft_fill_map  mandatory/ft_cheek_path  mandatory/ft_find_path\
	mandatory/ft_event  mandatory/ft_cheek_map  mandatory/ft_putnbr  mandatory/ft_write_error2  mandatory/ft_get_maze  mandatory/ft_cheek_edge\
	
FLS_B = bonus/ft_split_bonus  bonus/main_bonus  bonus/ft_get_map_bonus  bonus/ft_images_bonus  bonus/ft_width_height_bonus bonus/ft_itoa\
	bonus/ft_push_bonus  bonus/ft_write_error_bonus  bonus/ft_find_player_bonus  bonus/ft_cheek_coins_bonus  bonus/ft_norme_bonus bonus/ft_count_bonus\
	bonus/ft_event_bonus  bonus/ft_cheek_map_bonus  bonus/ft_putnbr_bonus  bonus/ft_write_error2_bonus  bonus/ft_get_maze_bonus  bonus/ft_cheek_edge_bonus\
	bonus/ft_write_error1_bonus  bonus/ft_end_bonus  bonus/ft_fill_map_bonus  bonus/ft_cheek_path_bonus  bonus/ft_find_path_bonus bonus/ft_move_enemy_bonus\

FO = $(FLS:=.o)

FO_B = $(FLS_B:=.o)

all : $(NAME)

$(NAME) : $(FO) $(HEADER)
	$(CC) $(FO) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MAN)%.o : $(MAN)%.c $(HEADER)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

bonus : $(NAME2)

$(NAME2) : $(FO_B) $(HEADER_B)
	$(CC) $(FO_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME2)

$(BNS)%.o : $(BNS)%.c $(HEADER_B)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(FO) $(FO_B)

fclean : clean
	$(RM) $(NAME) $(NAME2)
	
re : fclean all

.PHONY : all clean fclean re