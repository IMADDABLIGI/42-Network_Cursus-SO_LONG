/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:49 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/19 12:15:50 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct t_dat
{
	char	*av;
	char	**map;
	char	**maze;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*space;
	void	*player;
	void	*player_l;
	void	*enemy;
	void	*enemy_2;
	void	*coin;
	void	*door;
	char	*stm;
	char	key;
	char	dey;
	int		move;
	int		p_i;
	int		p_j;
	int		e_i;
	int		e_j;
	int		f_i;
	int		f_j;
	int		en_i;
	int		en_j;
	int		m_i;
	int		m_j;
	int		height;
	int		width;
	int		tall;
}	t_data;

void	ft_enemy(t_data *data);
int		ft_count_bonus(t_data *data);
void	ft_write_error_bonus(int f, t_data *data);
void	ft_write_error1_bonus(char *buff, char *line, int fd);
void	ft_write_error2_bonus(char **maze, int i, t_data *data);
void	ft_end_bonus(t_data *data);
int		ft_move_enemy(t_data *data);
char	*ft_itoa(int n);
void	ft_cheek_a_bonus(t_data *data);
void	ft_cheek_map_bonus(t_data *data);
void	ft_cheek_ber_bonus(char *str);
void	ft_fill_map_bonus(t_data *data, char *str);
int		ft_find_path_bonus(t_data *data, int i, int j);
void	ft_cheek_path_bonus(t_data *data);
void	ft_cheek_edge_bonus(t_data *data);
char	*ft_map_bonus(char *str);
void	ft_error_textures_b(t_data *data);
void	ft_putnbr_fd_bonus(int n);
void	ft_free_split_bonus(t_data *data);
void	ft_free_maze_bonus(t_data *data);
void	ft_get_maze_bonus(t_data *data);
void	ft_norme1_bonus(t_data *data);
void	ft_norme2_bonus(t_data *data);
void	ft_norme3_bonus(t_data *data);
void	ft_norme4_bonus(t_data *data);
int		ft_destroy_bonus(t_data *data);
void	ft_textures_bonus(t_data *data);
void	ft_find_exit_bonus(t_data *data);
void	ft_find_player_bonus(t_data *data);
int		ft_cheek_coins_bonus(t_data *data);
void	ft_width_height_bonus(t_data *data);
void	*ft_memcpy_bonus(void *dst, const void *src, size_t n);
char	**ft_split_bonus(char const *s, char c, t_data *data);
void	ft_push_bonus(int keycode, t_data *data);
void	push_images_bonus(t_data *data, int x, int y);
int		ft_event_bonus(int keycode, t_data *data);
void	*ft_calloc_bonus(size_t count, size_t size);

#endif