make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 libftprintf.a test-printf/test-main.c
i=$1+1
awk "NR == $i" result.log | cut -d ':' -f 1
printf "Original : ["
./a.out $1
printf "] - $?"
printf "\nYours    : ["
./a.out $1 u
printf "] - $?"
printf "\n"
