/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_libft_criterion.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lboertie <lboertie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 12:53:18 by lboertie       #+#    #+#                */
/*   Updated: 2019/11/06 22:11:28 by lboertie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <limits.h>
#include <string.h>

Test(isx, isalpha) {
	int	c;

	c = 0;
	while (c <= 130)
	{
		cr_expect_eq(isalpha(c), ft_isalpha(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isalpha(c), ft_isalpha(c));
		c++;
	}
}

Test(isx, isalnum) {
	int	c;

	c = 0;
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