# libft_criterion_test
please also write your own tests aswell <3 (or, at least in the future)
tests for libft (criterion required) (look up snaipe criterion github, remember to add the .brew/include and .brew/lib dirs to search path)
clone next to your libft folder, with libft.a compiled (it won't compile if you don't have the functions, but technically you can comment them out)
like this:


|-libft
|
|-libft_criterion_test
|
|-you, typing the command below


compile with 'gcc libft_criterion_test/test_libft_criterion.c -Llibft -lft -lcriterion
currently it tests:

PART 1:

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
all to be done
lstnew
lstadd_front
lstsize
lstlast
lstadd_back
lstdelone
lstclear
lstiter
lstmap
