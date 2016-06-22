/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:06:57 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/22 19:40:12 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H
# define LIBLS_H

# include "stdlib.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <grp.h>

typedef struct	s_yolo
{
	int		*read;
	int		uid;
	int		option_a;
	int		option_rr;
	int		option_l;
	int		option_t;
	int		option_r;
}				t_arg;

typedef struct node
{
	char		*name;
	char		*path;
	struct node *p_next;
	struct node *p_prev;
}				t_arg2;

typedef struct dlist
{
	size_t length;
	struct node *p_tail;
	struct node *p_head;
}				Dlist;

Dlist	*dlist_new(void);
void	dlist_delete(Dlist **p_list);
Dlist	*dlist_insert(Dlist *p_list, char *name, char *path, int position);
Dlist	*dlist_append(Dlist *p_list, char *name, char *path);
Dlist	*dlist_prepend(Dlist *p_list, char *name, char *path);
void	dlist_display(Dlist *p_list);
void	ft_init_struct(t_arg *arg);
void	ft_init_struct2(t_arg2 *arg2);
int		ft_handle_option(t_arg *arg, int argc, char **argv, int option);
void	ft_find_options(t_arg *arg, char *command);
int		ft_ls(t_arg *arg, t_arg2 *arg2, char *path, int id);
int		registre(t_arg *arg, t_arg2 *arg2, char *path, int recursive);
int		ft_check_folder(char *path);
t_arg2	*ft_add_data(char *name, t_arg2 *arg2, char *path);
void	ft_display_list(t_arg2 *arg2);

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int nbr);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
char	*ft_strjoin_special(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
#endif
