make all
gcc -Wall -Wextra -Werror libftprintf.a test-printf/test-printf.c
i=$1+1
awk "NR == $i" result.log | cut -d ':' -f 1
printf "Original : ["
./a.out $1 | tr '\n' '$' | cat
printf "]\nYours : ["
./a.out $1 u | tr '\n' '$' | cat
printf "]\n"
