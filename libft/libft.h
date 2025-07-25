/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:36:45 by trupham           #+#    #+#             */
/*   Updated: 2025/07/17 19:28:21 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/* ft_isany.c */
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

/* ft_string.c */
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);

/* ft_memory.c */
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t n, size_t size);

/* ft_num.c */
int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);
char				*ft_itoa(int n);

/* ft_split.c */
char				**ft_split(char const *s, char c);
int					ft_count_word(const char *s, char c);
void				free_split(char **arr);

/* ft_others.c */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/* ft_write.c */
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/* linked list functions */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new_node);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* get next line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

int					has_nl(const char *str);
char				*gnl_strjoin(char *s1, char *s2);
char				*get_next_line(int fd);

/* ft_printf.c */
int					ft_printf(const char *str, ...);
int					ft_putchar(int c);
int					ft_putstr(const char *str);
int					ft_putuint(unsigned int n);
int					ft_putint(int n);
int					ft_puthex(unsigned long n, char c);
int					ft_putptr(void *ptr);
int					ft_ulen(unsigned int n);
int					ft_ilen(int n);

/* sort functions in ft_sort.c*/
bool				is_sorted(int *arr, int size);
void				quicksort(int *arr, int low, int high);
void				bubblesort(int *arr, int size);

/* math functions in ft_math.c */
int					ft_sqrt(int num);
int					ft_min(int num1, int num2);
int					ft_max(int num1, int num2);
#endif
