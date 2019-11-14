make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 libftprintf.a test-printf/test-main.c
i=$1+1
awk "NR == $i" result.log | cut -d ':' -f 1
printf "Original : ["
./a.out $1
./a.out $1 > /dev/null
printf "] - $?"
printf "\nYours    : ["
./a.out $1 u
./a.out $1 u > /dev/null
printf "] - $?"
printf "\n"
