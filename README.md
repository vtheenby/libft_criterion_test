# libft_criterion_test
tests for libft (criterion required)
clone next to your libft folder, with libft.a compiled
like this:


|-libft
|
|-libft_criterion_test
|
|-you, typing the command below


compile with 'gcc libft_criterion_test/test_libft_criterion.c -Llibft -lft -lcriterion

PART 1:
currently it tests:
strlen
strchr
strrchr
strncmp
atoi
isalpha
isdigit
isalnum
isascii
isprint
toupper
tolower
strnstr

todo:
memset
bzero
memcpy
memccpy
memmove
memchr
memcmp
strlcpy
strlcat
calloc
strdup

PART 2:
todo:
substr
strjoin
strtrim
split
itoa
strmapi
putchar_fd
putstr_fd
putendl_fd
putnbr_fd

BONUS:
lstnew
lstadd_front
lstsize
lstlast
lstadd_back
lstdelone
lstclear
lstiter
lstmap