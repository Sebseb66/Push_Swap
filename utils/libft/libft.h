/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfroidev <sfroidev@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:38:27 by sfroidev          #+#    #+#             */
/*   Updated: 2023/09/25 15:38:02 by sfroidev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

# define BUFFER_SIZE	1
# define MAX_FD			1025

void			*ft_bzero(void *s, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memset(void *str1, int val, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *str, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);

int				ft_memcmp(const void *str1, const void *str2, size_t len);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *str1, const char *str2, size_t lestrlen);
int				ft_atoi(const char *nptr);

size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dest, const char *src, size_t size);

char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strnstr(const char *str, const char *sub_str, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *str, unsigned int start, size_t len);
char			*ft_strjoin(char const *str1, char const *str2);
char			*ft_strtrim(char const *str, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);

char			*ft_read_line(int fd, char *str);
char			*ft_check_line(char *str);
char			*ft_clean_line(char *str, size_t i);
char			*get_next_line(int fd);
char			*ft_str_dup(char *str, size_t c);
size_t			ft_str_len(char *s);
char			*ft_check(char *str, int c);
char			*ft_str_join(char *s1, char *s2);

int				ft_string(char *str);
int				ft_putchar_printf(char a);
int				ft_printf(const char *str, ...);
int				ft_type_di(int a);
int				ft_type_p(unsigned long a, int cont);
int				ft_type_u(unsigned int a);
int				ft_type_x(unsigned int a, char c);

#endif
