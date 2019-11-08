# 42-tests
To test 42 exercises

# Usage of libft test
Copy test-libft.c in libft repo and run "make bonus" then "gcc -Wall -Wextra -Werror libft.a test-libft.c && ./a.out".
Check outputs manually. Cat the "testput..." files to check use of fd in ft_put... functions.

# Usage of gnl test
Kind of broken at the moment.
Copy test-gnl.c in gnl repo and run "gcc -D BUFFER_SIZE=10 -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c test-gnl.c && ./a.out".
Check outputs manually. Change BUFFER_SIZE. Set to 32 for tests with lines of length BUFFER_SIZE / +1 / -1.

Add flag "g" after "./a.out" to test the big files in the repo.
Add flag "l" after "./a.out" to test big lines.
Add flag "0" after "./a.out" to test standard input.

To test bonus, do the same with test-gnl-multiplefd.c and "gcc -D BUFFER_SIZE=10 -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c test-gnl-multiplefd.c && ./a.out".

# Usage of printf test
Copy test-printf/ directory in your printf repo. From root of your repo, run "sh test-printf/test-printf.sh".
To test only one category, run for instance "sh test-printf/test-printf.sh H".
To see one test, its original output and your output, run for example "sh test-printf/show.sh 563". (it works with the last test-print.sh run)
