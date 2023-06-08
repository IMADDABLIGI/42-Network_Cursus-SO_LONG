/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:49 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/18 18:55:50 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

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
	void	*coin;
	void	*door;
	int		move;
	int		p_i;
	int		p_j;
	int		e_i;
	int		e_j;
	int		f_i;
	int		f_j;
	int		height;
	int		width;
	int		tall;
}	t_data;

void	ft_write_error(int f, t_data *data);
void	ft_write_error1(char *buff, char *line, int fd);
void	ft_write_error2(char **maze, int i, t_data *data);
void	ft_end(t_data *data);
void	ft_cheek_a(t_data *data);
void	ft_cheek_map(t_data *data);
void	ft_cheek_ber(char *str);
void	ft_fill_map(t_data *data, char *str);
int		ft_find_path(t_data *data, int i, int j);
void	ft_cheek_path(t_data *data);
void	ft_cheek_edge(t_data *data);
char	*ft_map(char *str);
void	ft_putnbr_fd(int n);
void	ft_free_split(t_data *data);
void	ft_free_maze(t_data *data);
void	ft_get_maze(t_data *data);
void	ft_norme1(t_data *data);
void	ft_norme2(t_data *data);
void	ft_norme3(t_data *data);
void	ft_norme4(t_data *data);
int		ft_destroy(t_data *data);
void	ft_textures(t_data *data);
void	ft_find_exit(t_data *data);
void	ft_find_player(t_data *data);
int		ft_cheek_coins(t_data *data);
void	ft_width_height(t_data *data);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c, t_data *data);
void	ft_push(int keycode, t_data *data);
void	push_images(t_data *data, char key, int x, int y);
int		ft_event(int keycode, t_data *data);
void	*ft_calloc(size_t count, size_t size);

#endif