make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 libftprintf.a test-printf/test-main.c -o test-printf/test.out
i=$1+1
awk "NR == $i" test-printf/result.log | cut -d ':' -f 1
printf "Original : ["
test-printf/test.out $1
printf "] - $?"
printf "\nYours    : ["
sh test-printf/timeout.sh 1 test-printf/test.out $1 user 2> /dev/null
ret=$(echo $?)
if [ $ret -eq 142 ]
then
	printf "TIMEOUT"
fi
printf "] - $ret"
printf "\n"
