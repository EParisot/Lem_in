/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:01:25 by eparisot          #+#    #+#             */
/*   Updated: 2018/01/23 23:18:19 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *s);
size_t				ft_strlen_w(const wchar_t *s);
size_t				ft_wcharlen(const wchar_t c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s, const char *to_find);
char				*ft_strnstr(const char *s, const char *to_find, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_atoi(const char *s);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_sqrt(int n);
int					ft_pw(int a, int b);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_strrev(char *s);
char				*ft_itoa(int n);
void				ft_foreach(int *tab, int len, void(*f)(int));
int					ft_putchar(char c);
int					ft_putchar_w(wchar_t wc);
void				ft_putstr(const char *s, int *p_ret);
void				ft_putstr_w(const wchar_t *s, int *p_ret);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(long n, int *p_ret);
void				ft_putnbr_int(int n, int *p_ret);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_hex(int n, int *p_ret);
void				ft_putnbr_hex_up(int n, int *p_ret);
void				ft_putnbr_hex_l(uintmax_t n, int *p_ret);
void				ft_putnbr_hex_up_l(uintmax_t n, int *p_ret);
void				ft_putnbr_oct(int n, int *p_ret);
void				ft_putnbr_oct_l(uintmax_t n, int *p_ret);
void				ft_putnbr_hex_p(uintmax_t n, int *p_ret);
void				ft_putnbr_unsigned(unsigned int n, int *p_ret);
void				ft_putnbr_unsigned_l(uintmax_t n, int *p_ret);
int					ft_countdigits(long long n);
int					ft_countdigits_hex(unsigned long n);
int					ft_countdigits_oct(unsigned long n);
int					ft_countdigits_u(unsigned long n);

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **als, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstsort(t_list *lst);
size_t				ft_lstcount(t_list *lst);

void				ft_strswap(char *s1, char *s2);
size_t				ft_tablen(char **tab);

#endif
