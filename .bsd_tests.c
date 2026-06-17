#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>
#include <string.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define COLOR_RESET "\x1b[0m"

static void	check_strlcpy(const char *name, const char *initial,
	const char *src, size_t size)
{
	char	ft_buf[32];
	char	bsd_buf[32];
	size_t	ft_result;
	size_t	bsd_result;
	int		result;

	memset(ft_buf, 'X', sizeof(ft_buf));
	memset(bsd_buf, 'X', sizeof(bsd_buf));
	strcpy(ft_buf, initial);
	strcpy(bsd_buf, initial);
	ft_result = ft_strlcpy(ft_buf, src, size);
	bsd_result = strlcpy(bsd_buf, src, size);
	result = ft_result == bsd_result
		&& memcmp(ft_buf, bsd_buf, sizeof(ft_buf)) == 0;
	printf("%s - Result: %s, %zu, Expected: %s, %zu - %s\n",
		name, ft_buf, ft_result, bsd_buf, bsd_result,
		result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

static void	check_strlcat(const char *name, const char *initial,
	const char *src, size_t size)
{
	char	ft_buf[32];
	char	bsd_buf[32];
	size_t	ft_result;
	size_t	bsd_result;
	int		result;

	memset(ft_buf, 'X', sizeof(ft_buf));
	memset(bsd_buf, 'X', sizeof(bsd_buf));
	strcpy(ft_buf, initial);
	strcpy(bsd_buf, initial);
	ft_result = ft_strlcat(ft_buf, src, size);
	bsd_result = strlcat(bsd_buf, src, size);
	result = ft_result == bsd_result
		&& memcmp(ft_buf, bsd_buf, sizeof(ft_buf)) == 0;
	printf("%s - Result: %s, %zu, Expected: %s, %zu - %s\n",
		name, ft_buf, ft_result, bsd_buf, bsd_result,
		result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

static void	test_ft_strlcpy_bsd(void)
{
	check_strlcpy("ft_strlcpy(Hello, World, 10)", "Hello", "World", 10);
	check_strlcpy("ft_strlcpy(Hello, World, 4)", "Hello", "World", 4);
	check_strlcpy("ft_strlcpy(Hello, , 10)", "Hello", "", 10);
	check_strlcpy("ft_strlcpy(Hello, World, 0)", "Hello", "World", 0);
	check_strlcpy("ft_strlcpy(Hello, World, 6)", "Hello", "World", 6);
}

static void	test_ft_strlcat_bsd(void)
{
	check_strlcat("ft_strlcat(Hello,  World, 15)", "Hello", " World", 15);
	check_strlcat("ft_strlcat(Hello,  World, 8)", "Hello", " World", 8);
	check_strlcat("ft_strlcat(Hello, , 10)", "Hello", "", 10);
	check_strlcat("ft_strlcat(, Hello World, 15)", "", "Hello World", 15);
	check_strlcat("ft_strlcat(Hello,  World, 3)", "Hello", " World", 3);
	check_strlcat("ft_strlcat(Hello,  World, 0)", "Hello", " World", 0);
	check_strlcat("ft_strlcat(Hello, !, 7)", "Hello", "!", 7);
}

int	main(void)
{
	printf(BLUE "bsd_string_tests\n" COLOR_RESET);
	test_ft_strlcpy_bsd();
	test_ft_strlcat_bsd();
	return (0);
}
