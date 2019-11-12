# libft_criterion_test
please also write your own tests aswell <3 (or, at least in the future)
tests for libft (criterion required) (look up snaipe criterion github, remember to add the .brew/include and .brew/lib dirs to search path)

to use:
  -copy test_libft_criterion.c into your project folder
  -add the following rule to your makefile
    test: test_libft_criterion.c
	  @echo 'creating criterion test'
	  @gcc -o test test_libft_criterion.c -lcriterion -lft
	  @echo 'done!'
  -type make test after using your usual rules to compile the library
  
hab enjoy with this test
