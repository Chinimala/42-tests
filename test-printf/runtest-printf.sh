GREEN='\033[0;32m'
DARK_BLUE='\e[1;34m'
RED='\x1B[31m'
BLUE='\e[96m'
NC='\033[0m'
i=0
success=0
error=0

# $1 = text, $2 = test number
test()
{
	printf "$1" >> test-printf/result.log
	test-printf/test.out $2 > test-printf/original_output
	echo $? >> test-printf/original_output
	sh test-printf/timeout.sh 1 test-printf/test.out $2 user > test-printf/user_output 2> /dev/null
	ret=$(echo $?)
	echo $ret >> test-printf/user_output
	if diff "test-printf/original_output" "test-printf/user_output" >> /dev/null
	then
		if [ $error -eq 1 ]
		then
			printf "\n"
		fi
    	printf "${GREEN}OK ${NC}"
    	printf "${GREEN}OK ${NC}\n" >> test-printf/result.log
		((success++))
		error=0
	else
    	printf "\n${RED}$1"
		if [ $ret -eq 142 ] #timeout
		then
			printf "${RED}TIMEOUT${NC}"
			printf "${RED}TIMEOUT${NC}\n" >> test-printf/result.log
		else
			printf "${RED}FAILED${NC}"
			printf "${RED}FAILED${NC}\n" >> test-printf/result.log
		fi
		error=1
	fi
	((i++))
}

rm test-printf/result.log
make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 test-printf/test-main.c libftprintf.a -o test-printf/test.out
printf "\n${BLUE}[B - Tests with minimum field width]${NC}\n"
test "$i - (\"%%*c\", -1000, 'a') : ${NC}" $i 
test "$i - (\"%%*s\", -1000, \"\") : ${NC}" $i 
test "$i - (\"%%1%%\") : ${NC}" $i 
test "$i - (\"%%2%%\") : ${NC}" $i 
test "$i - (\"%%10%%\") : ${NC}" $i 
test "$i - (\"%%1c\", '1') : ${NC}" $i 
test "$i - (\"%%2c\", '1') : ${NC}" $i 
test "$i - (\"%%10c\", '1') : ${NC}" $i 
test "$i - (\"%%1s\", \"\") : ${NC}" $i 
test "$i - (\"%%5s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%6s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%1i\", 0) : ${NC}" $i 
test "$i - (\"%%2i\", 0) : ${NC}" $i 
test "$i - (\"%%10i\", 0) : ${NC}" $i 
test "$i - (\"%%1i\", -1) : ${NC}" $i 
test "$i - (\"%%2i\", -1) : ${NC}" $i 
test "$i - (\"%%3i\", -1) : ${NC}" $i 
test "$i - (\"%%9i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%1d\", 0) : ${NC}" $i 
test "$i - (\"%%2d\", 0) : ${NC}" $i 
test "$i - (\"%%10d\", 0) : ${NC}" $i 
test "$i - (\"%%1d\", -1) : ${NC}" $i 
test "$i - (\"%%2d\", -1) : ${NC}" $i 
test "$i - (\"%%3d\", -1) : ${NC}" $i 
test "$i - (\"%%9d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%1u\", 0) : ${NC}" $i 
test "$i - (\"%%2u\", 0) : ${NC}" $i 
test "$i - (\"%%10u\", 0) : ${NC}" $i 
test "$i - (\"%%1u\", -1) : ${NC}" $i 
test "$i - (\"%%2u\", -1) : ${NC}" $i 
test "$i - (\"%%3u\", -1) : ${NC}" $i 
test "$i - (\"%%9u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%1x\", 0) : ${NC}" $i 
test "$i - (\"%%2x\", 0) : ${NC}" $i 
test "$i - (\"%%10x\", 0) : ${NC}" $i 
test "$i - (\"%%1x\", -1) : ${NC}" $i 
test "$i - (\"%%2x\", -1) : ${NC}" $i 
test "$i - (\"%%3x\", -1) : ${NC}" $i 
test "$i - (\"%%9x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%1X\", 0) : ${NC}" $i 
test "$i - (\"%%2X\", 0) : ${NC}" $i 
test "$i - (\"%%10X\", 0) : ${NC}" $i 
test "$i - (\"%%1X\", -1) : ${NC}" $i 
test "$i - (\"%%2X\", -1) : ${NC}" $i 
test "$i - (\"%%3X\", -1) : ${NC}" $i 
test "$i - (\"%%9X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%1p\", (void*)42) : ${NC}" $i 
test "$i - (\"%%5p\", (void*)42) : ${NC}" $i 
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"
