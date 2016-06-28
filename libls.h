/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:06:57 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 04:54:21 by pbourdon         ###   ########.fr       */
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

struct node
{
	char		*name;
	char		*path;
	int			data;
	struct node *p_next;
	struct node *p_prev;
};

typedef struct dlist
{
	size_t length;
	struct node *p_tail;
	struct node *p_head;
}				Dlist;

Dlist	*dlist_new(void);
void	dlist_delete(Dlist **p_list);
void	dlist_display(Dlist *p_list);
void	ft_init_struct(t_arg *arg);
int		ft_handle_option(t_arg *arg, int argc, char **argv, int option);
void	ft_find_options(t_arg *arg, char *command);
int		ft_ls(t_arg *arg, char *path, int id);
int		registre(t_arg *arg, char *path, int recursive);
int		ft_check_folder(char *path);
Dlist	*dlist_new(void);
Dlist	*ft_add_data(Dlist *list, char *name, char *path);
int		ft_display_list(Dlist *p_list, int l);
void	ft_display(t_arg *arg, Dlist *p_list);
int		ft_display_r(t_arg *arg, Dlist *p_list,  int l);
int		ft_display_all(char *path, char *name);
int		ft_display_link_count(char *path);
void	ft_display_rights(char *path);
int		ft_display_ownership(char *path);
int		ft_display_link(char *path);
int		ft_make_time(char *path, int index, int index2);
int		ft_display_size(char *path);
void	dlist_delete(Dlist **p_list);
int		registre2(char *path, t_arg *arg);


void	ft_putstr(char *str);
void	ft_putchar(char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int nbr);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		s(const char *s1);
int		e(const char *s1);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
char	*ft_strjoin_special(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
#endif
