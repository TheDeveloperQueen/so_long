/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:40:12 by rivasque          #+#    #+#             */
/*   Updated: 2023/11/04 10:30:09 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *dest, int c, size_t count);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t count);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t count);
int		ft_memcmp(const void *buffer1, const void *buffer2, size_t count);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strdup(char *str);
void	*ft_calloc(size_t number, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memmove(void *dest, const void *src, size_t count);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		ft_line_length(int fd);
char	*get_next_line(int fd);
int		ft_line_count(char **file);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long n);
int		ft_printf(const char *str, ...);

#endif