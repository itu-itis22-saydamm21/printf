#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_putcharacter_len(char c, int *len);
void	ft_string(char *args, int *len);
void	ft_pointer(size_t pointer, int *len);
void	ft_number(int num, int *len);
void	ft_unsigned_int(unsigned int u, int *len);
void	ft_hexadecimal(unsigned int hex, int *len, char x_or_X);

#endif
