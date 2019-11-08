/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_libft_criterion.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lboertie <lboertie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 12:53:18 by lboertie       #+#    #+#                */
/*   Updated: 2019/11/08 14:04:35 by lboertie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <limits.h>
#include <string.h>

Test(isx, isalpha) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isalpha(c), ft_isalpha(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isalpha(c), ft_isalpha(c));
		c++;
	}
}

Test(isx, isalnum) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isalnum(c), ft_isalnum(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isalnum(c), ft_isalnum(c));
		c++;
	}
}

Test(isx, isascii) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isascii(c), ft_isascii(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isascii(c), ft_isalpha(c));
		c++;
	}
}

Test(isx, isdigit) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isdigit(c), ft_isdigit(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isdigit(c), ft_isdigit(c));
		c++;
	}
}

Test(isx, isprint) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isprint(c), ft_isprint(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isprint(c), ft_isprint(c));
		c++;
	}
}

Test(tox, tolower) {
	int c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(tolower(c), ft_tolower(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, tolower(c), ft_tolower(c));
		c++;
	}
}

Test(tox, toupper) {
	int c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(toupper(c), ft_toupper(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, toupper(c), ft_toupper(c));
		c++;
	}
}

Test(str, strlen_regular_input) {
	char *str = "0123456";
	cr_expect_eq(strlen(str), ft_strlen(str), \
	"value passed: [%s]\nlibc: %zu\nlibft: %zu", str, strlen(str), ft_strlen(str));
	str = "";
	cr_expect_eq(strlen(str), ft_strlen(str), \
	"value passed: [%s]\nlibc: %zu\nlibft: %zu", str, strlen(str), ft_strlen(str));
	cr_expect_eq(strlen(str), ft_strlen(str), \
	"value passed: [%s]\nlibc: %zu\nlibft: %zu", str, strlen(str), ft_strlen(str));
}

Test(str, strlen_null_input, .signal = SIGSEGV) {
	cr_expect(ft_strlen(NULL), "strlen does not segfault with input NULL");
}

Test(str, strncmp) {
	char *str = "0123456789";
	char *str1 = "01234567";
	cr_expect_eq(strncmp(str, str, 10), ft_strncmp(str, str, 10), \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str, str, strncmp(str, str, 10), ft_strncmp(str, str, 10));
	cr_expect_lt(ft_strncmp(str1, str, 10), 0, \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str1, str, strncmp(str1, str, 10), ft_strncmp(str1, str, 10));
	str = "01234567";
	str1 = "0123456789";
	cr_expect_gt(ft_strncmp(str1, str, 10), 0, \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str1, str, strncmp(str1, str, 10), ft_strncmp(str1, str, 10));
	cr_expect_eq(strncmp(str, str, 0), ft_strncmp(str, str, 0), \
	"values passed: [%s|%s|0]\nlibc: %d\nlibft: %d", str, str, strncmp(str, str, 0), ft_strncmp(str, str, 0));
	cr_expect_eq(strncmp(NULL, NULL, 0), ft_strncmp(NULL, NULL, 0), \
	"values passed: [NULL|NULL|0]\nlibc: %d\nlibft: %d", strncmp(NULL, NULL, 0), ft_strncmp(NULL, NULL, 0));
}

Test(str, strncmp_null, .signal = SIGSEGV) {
	ft_strncmp(NULL, "str", 4);
}

Test(convert, atoi) {
	char *str = "";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-0";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "+0";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "   +.";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-+";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-123 3";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-2147483648";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-922337203685477590000999";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "922337203685999999999";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
}

Test(convert, atoi_null, .signal = SIGSEGV) {
	cr_expect(ft_atoi(NULL), "ft_atoi does not segfault with input NULL");
}

Test(convert, itoa) {
	int n = 0;
	cr_expect_str_eq("0", ft_itoa(n), \
	"value passed: [%d]\nlibft: %s", n, ft_itoa(n));
	n = MIN_INT;
	cr_expect_str_eq("-2147483648", ft_itoa(n), \
	"value passed: [%d]\nlibft: %s", n, ft_itoa(n));
	n = INT_MAX;
	cr_expect_str_eq("2147483647", ft_itoa(n), \
	"value passed: [%d]\nlibft: %s", n, ft_itoa(n));
	n = -45390001;
	cr_expect_str_eq("-45390001", ft_itoa(n), \
	"value passed: [%d]\nlibft: %s", n, ft_itoa(n));
	n = 45390001;
	cr_expect_str_eq("45390001", ft_itoa(n), \
	"value passed: [%d]\nlibft: %s", n, ft_itoa(n));
	n = 1000;
	cr_expect_str_eq("1000", ft_itoa(n), \
	"value passed: [%d]\nlibft: %s", n, ft_itoa(n));
}

Test(str, strchr) {
	char *str = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char c = 'x';
	cr_expect_str_eq(strchr(str, c), ft_strchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strchr(str, c), ft_strchr(str, c));
	c = '\0';
	cr_expect_str_eq(strchr(str, c), ft_strchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strchr(str, c), ft_strchr(str, c));
	c = '1';
	cr_expect_null(ft_strchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strchr(str, c), ft_strchr(str, c));
}

Test(str, strchr_null, .signal = SIGSEGV) {
	char *str = NULL;
	char c = 'x';
	cr_expect_str_eq(ft_strchr(str, c), \
	"ft_strchr does not segfault with input NULL");
}

Test(str, strrchr) {
	char *str = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char c = 'x';
	cr_expect_str_eq(strrchr(str, c), ft_strrchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strrchr(str, c), ft_strrchr(str, c));
	c = '\0';
	cr_expect_str_eq(strrchr(str, c), ft_strrchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strrchr(str, c), ft_strrchr(str, c));
	c = '1';
	cr_expect_null(ft_strrchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strrchr(str, c), ft_strrchr(str, c));
}

Test(str, strrchr_null, .signal = SIGSEGV) {
	char *str = NULL;
	char c = 'x';
	cr_expect_str_eq(ft_strrchr(str, c), \
	"ft_strrchr does not segfault with input NULL");
}

Test(str, strnstr) {
	char *str = "we're about to go searching in this hecking string\0DONOTSEARCHHERE";
	char *str1 = "this";
	cr_expect_str_eq(strnstr(str, str1, strlen(str)), strnstr(str, str1, strlen(str)), \
	"values passed: [%s|%s|%lu]\nlibc: %s\nlibft: %s", str, str1, strlen(str), strnstr(str, str1, strlen(str)), ft_strnstr(str, str1, strlen(str)));
	cr_expect_null(ft_strnstr(str, str1, 20), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, str1, 20, strnstr(str, str1, 20), ft_strnstr(str, str1, 20));
	cr_expect_null(ft_strnstr(str, str1, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, str1, 0, strnstr(str, str1, 0), ft_strnstr(str, str1, 0));
	str1 = "DONOT";
	cr_expect_null(ft_strnstr(str, str1, 65), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, str1, 65, strnstr(str, str1, 65), ft_strnstr(str, str1, 65));
}

Test(str, strnstr_null, .signal = SIGSEGV) {
	char *str = NULL;
	ft_strnstr(str, str, 20);
}

Test(str, strlcpy) {
	char *str = malloc(sizeof(char) * 10 + 1);
	char *str1 = malloc(sizeof(char) * 10 + 1);
	size_t ret = 0;
	size_t ret1 = 0;
	ret = strlcpy(str, "0123456789", 10);
	ret1 = ft_strlcpy(str1, "0123456789", 10);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, "0123456789", 10, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, "0123456789", 10, ret, ret1);
	ret = strlcpy(str, "0123456789", 0);
	ret1 = ft_strlcpy(str1, "0123456789", 0);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, "0123456789", 0, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, "0123456789", 10, ret, ret1);
	ret = strlcpy(str, "0123456789", 20);
	ret1 = ft_strlcpy(str1, "0123456789", 20);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, "0123456789", 20, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, "0123456789", 10, ret, ret1);
	free(str);
	free(str1);
}

Test(str, strlcpy_null, .signal = SIGSEGV) {
	ft_strlcpy(NULL, NULL, 6);
}

Test(str, strlcat) {
	char *str = strdup("start");
	char *str1 = strdup("start");
	char *app = "append";
	size_t ret = 0;
	size_t ret1 = 0;
	ret = strlcat(str, app, 11);
	ret1 = ft_strlcat(str1, app, 11);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, app, 11, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, app, 11, ret, ret1);
	ret = strlcat(str, app, 0);
	ret1 = ft_strlcat(str1, app, 0);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, app, 0, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, app, 0, ret, ret1);
	free(str);
	free(str1);
}

Test(str, strlcat_null, .signal = SIGSEGV) {
	ft_strlcat(NULL, NULL, 0);
}

Test(mem, memcmp) {
	char *str = "0123456789";
	char *str1 = "01234567";
	cr_expect_eq(memcmp(str, str, 10), ft_memcmp(str, str, 10), \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str, str, memcmp(str, str, 10), ft_memcmp(str, str, 10));
	cr_expect_lt(ft_memcmp(str1, str, 10), 0, \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str1, str, memcmp(str1, str, 10), ft_memcmp(str1, str, 10));
	str = "01234567";
	str1 = "0123456789";
	cr_expect_gt(ft_memcmp(str1, str, 10), 0, \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str1, str, memcmp(str1, str, 10), ft_memcmp(str1, str, 10));
	cr_expect_eq(memcmp(str, str, 0), ft_memcmp(str, str, 0), \
	"values passed: [%s|%s|0]\nlibc: %d\nlibft: %d", str, str, memcmp(str, str, 0), ft_memcmp(str, str, 0));
	cr_expect_eq(memcmp(NULL, NULL, 0), ft_memcmp(NULL, NULL, 0), \
	"values passed: [NULL|NULL|0]\nlibc: %d\nlibft: %d", memcmp(NULL, NULL, 0), ft_memcmp(NULL, NULL, 0));
}

Test(mem, memcmp_null, .signal = SIGSEGV) {
	ft_memcmp(NULL, "str", 4);
}

Test(mem, memchr) {
	char *mem = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char c = 'x';
	cr_expect_str_eq(memchr(mem, c, 26), ft_memchr(mem, c, 26), \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", mem, c, 26, memchr(mem, c, 26), ft_memchr(mem, c, 26));
	cr_expect_null(ft_memchr(mem, c, 0), \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", mem, c, 0, memchr(mem, c, 0), ft_memchr(mem, c, 0));
	c = '\0';
	cr_expect_null(ft_memchr(mem, c, 26), \
	"values passed: [%s|(null)|%d]\nlibc: %s\nlibft: %s", mem, 26, memchr(mem, c, 26), ft_memchr(mem, c, 26));
	c = '1';
	cr_expect_null(ft_memchr(mem, c, 26), \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", mem, c, 26, memchr(mem, c, 26), ft_memchr(mem, c, 26));
}

Test(mem, memchr_null, .signal = SIGSEGV) {
	char *mem = NULL;
	char c = 'x';
	cr_expect_null(memchr(mem, c, 26), \
	"ft_memchr does not segfault with input NULL");
}

Test(mem, memmove) {
	char *ret = strdup("this_is_the_memory_area");
	char *ret1 = strdup(ret);
	char *edit = strdup("copythis");
	cr_expect_str_eq(memmove(ret, edit, 23), ft_memmove(ret1, edit, 23), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret, edit, 23, memmove(ret, edit, 23), ft_memmove(ret1, edit, 23));
	cr_expect_str_eq(memmove(ret, ret + 5, 15), ft_memmove(ret1, ret1 + 5, 15), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret1, ret1 + 5, 15, memmove(ret, ret + 5, 15), ft_memmove(ret1, ret1 + 5, 15));
	cr_expect_str_eq(memmove(ret + 5, ret, 15), ft_memmove(ret1 + 5, ret1, 15), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret1 + 5, ret1, 15, memmove(ret + 5, ret, 15), ft_memmove(ret1 + 5, ret1, 15));
	cr_expect_str_eq(memmove(edit, NULL, 0), ft_memmove(edit, NULL, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", edit, NULL, 0, memmove(edit, NULL, 0), ft_memmove(edit, NULL, 0));
	cr_expect_null(ft_memmove(NULL, edit, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", edit, NULL, 0, memmove(edit, NULL, 0), ft_memmove(edit, NULL, 0));
	free(ret);
	free(ret1);
	free(edit);
}

Test(mem, memmove_null, .signal = SIGSEGV) {
	char *str = strdup("string");
	ft_memmove(str, NULL, 6);
}

Test(mem, memset) {
	char *str = malloc(10);
	char *str1 = malloc(10);
	char c = 'd';
	int len = 8;
	char *ret = memset(str, c, len);
	char *ret1 = ft_memset(str, c, len);
	cr_expect_str_eq(memset(str, c, len), ft_memset(str, c, len), \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", str, c, len, ret, ret1);
	len = 0;
	c = 'a';
	ret = memset(str, c, len);
	ret1 = ft_memset(str, c, len);
	cr_expect_str_eq(ret, ret1, \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", str, c, len, ret, ret1);
	ret = memset(NULL, c, len);
	ret1 = ft_memset(NULL, c, len);
	cr_expect_null(ret1, \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", str, c, len, ret, ret1);
	len = 10;
	c = '\0';
	ret = memset(str, c, len);
	ret1 = ft_memset(str, c, len);
	cr_expect_str_eq(ret, ret1, \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", str, c, len, ret, ret1);
	free(str);
	free(str1);
}

Test(mem, memset_null, .signal = SIGSEGV) {
	ft_memset(NULL, 'c', 9);
}

Test(mem, bzero) {
	char str[20] = "epicstring";
	char str1[20] = "epicstring";
	int i = 0;
	int j = 0;
	int len = 5;
	bzero(str, (0));
	ft_bzero(str1, (0));
	cr_assert_str_eq(str, str1, \
	"values passed: [%s|%d]:\nlibc: %s\nlibft: %s", str, 0, str, str1);
	ft_bzero(NULL, 0);
	bzero(str, len);
	ft_bzero(str1, len);
	while (str[i] == '\0')
		i++;
	cr_assert_eq(i, len, \
	"did not set the right amount to 0");
}

Test(mem, bzero_null, .signal = SIGSEGV) {
	ft_bzero(NULL, 7);
}

Test(mem, memcpy) {
	char *ret = strdup("this_is_the_memory_area");
	char *ret1 = strdup(ret);
	char *edit = strdup("copythis");
	cr_expect_str_eq(memcpy(ret, edit, 23), ft_memcpy(ret1, edit, 23), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret, edit, 23, memcpy(ret, edit, 23), ft_memcpy(ret1, edit, 23));
	cr_expect_str_eq(memcpy(ret, ret + 5, 15), ft_memcpy(ret1, ret1 + 5, 15), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret1, ret1 + 5, 15, memcpy(ret, ret + 5, 15), ft_memcpy(ret1, ret1 + 5, 15));
	cr_expect_str_eq(memcpy(ret + 5, ret, 15), ft_memcpy(ret1 + 5, ret1, 15), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret1 + 5, ret1, 15, memcpy(ret + 5, ret, 15), ft_memcpy(ret1 + 5, ret1, 15));
	cr_expect_str_eq(memcpy(edit, NULL, 0), ft_memcpy(edit, NULL, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", edit, NULL, 0, memcpy(edit, NULL, 0), ft_memcpy(edit, NULL, 0));
	cr_expect_null(ft_memcpy(NULL, edit, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", edit, NULL, 0, memcpy(edit, NULL, 0), ft_memcpy(edit, NULL, 0));
	free(ret);
	free(ret1);
	free(edit);
}

Test(mem, memcpy_null, .signal = SIGSEGV) {
	char *str = strdup("string");
	ft_memcpy(str, NULL, 6);
}

Test(mem, memccpy) {
	char dst[21] = "0123456789abcdefghij";
	char dst1[21] = "0123456789abcdefghij";
	char src[21] = "abcdefghij0123456789";
	char *ret = ft_memccpy(dst1, src, 'A', 4);
	char *ret1 = memccpy(dst, src, 'A', 4);
	cr_expect_null(ret, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'A', 4, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'A', 4, dst, dst1);
	ret = ft_memccpy(dst1, src, 'f', 5);
	ret1 = memccpy(dst, src, 'f', 5);
	cr_expect_null(ret, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'f', 5, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'f', 5, dst, dst1);
	ret = ft_memccpy(dst1, src, 'f', 8);
	ret1 = memccpy(dst, src, 'f', 8);
	cr_expect_str_eq(ret, ret1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'f', 8, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'f', 8, dst, dst1);
	ret = ft_memccpy(NULL, src, 'f', 0);
	ret1 = memccpy(NULL, src, 'f', 0);
	cr_expect_null(ret, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", NULL, src, 'f', 0, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", NULL, src, 'f', 0, dst, dst1);
	ret = ft_memccpy(src, NULL, 'f', 0);
	ret1 = memccpy(src, NULL, 'f', 0);
	cr_expect_null(ret, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", src, NULL, 'f', 0, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", src, NULL, 'f', 0, dst, dst1);
}

Test(mem, memccpy_null_src, .signal = SIGSEGV) {
	char str[40] = "very cool";
	ft_memccpy(NULL, str, 'a', 6);

}

Test(mem, memccpy_null_dst, .signal = SIGSEGV) {
	char str[40] = "very cool";
	ft_memccpy(str, NULL, 'a', 6);

}

Test(alloc, calloc) {
	char *str = ft_calloc(5, 5);
	char *str1 = calloc(5, 5);
	int cool = 1;
	int i = 0;
	while (i > 25)
	{
		if (str[i] != 0)
			cool = 0;
		i++;
	}
	cr_expect(cool, \
	"values passed: [%d|%d]\n libc: %s\n libft: %s", 5, 5, str, str1);
	cr_expect_str_eq(str1, str, \
	"values passed: [%d|%d]\n libc: %s\n libft: %s", 5, 5, str, str1);
	free(str);
	free(str1);
}

Test(alloc, strdup) {
	char *dup = "duplicate this";
	char *dup1 = "";
	char *str1 = ft_strdup(dup);
	char *str2 = strdup(dup);
	cr_assert_str_eq(str1, str2, \
	"value passed: [%s]\nlibc: %s\nlibft: %s", dup, str1, str2);
	free(str1);
	free(str2);
	str1 = ft_strdup(dup1);
	str2 = strdup(dup1);
	cr_assert_str_eq(str1, str2, \
	"value passed: [%s]\nlibc: %s\nlibft: %s", dup1, str1, str2);
	free(str1);
	free(str2);
}

Test(alloc, strdup_null, .signal = SIGSEGV) {
	char *str = ft_strdup(NULL);
}