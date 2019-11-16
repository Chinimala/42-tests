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
	printf "$1" >> result.log
	./a.out $2 > original_output
	echo $? >> original_output
	./a.out $2 user > user_output
	echo $? >> user_output
	if diff "original_output" "user_output" >> /dev/null
	then
		if [ $error -eq 1 ]
		then
			printf "\n"
		fi
    	printf "${GREEN}OK ${NC}"
    	printf "${GREEN}OK ${NC}\n" >> result.log
		((success++))
		error=0
	else
    	printf "\n${RED}$1"
		printf "${RED}FAILED${NC}"
		printf "${RED}FAILED${NC}\n" >> result.log
		error=1
	fi
	((i++))
}

rm result.log
make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 test-printf/test-main.c libftprintf.a
printf "\n${BLUE}[S - Tests with ' flag]${NC}\n"
test "$i - (\"%%'i\", 10000) : ${NC}" $i 
test "$i - (\"%%'i\", 0) : ${NC}" $i 
test "$i - (\"%%'i\", 999) : ${NC}" $i 
test "$i - (\"%%'i\", 1000) : ${NC}" $i 
test "$i - (\"%%'i\", 789456) : ${NC}" $i 
test "$i - (\"%%'i\", 1000000) : ${NC}" $i 
test "$i - (\"%%'i\", 999000000) : ${NC}" $i 
test "$i - (\"%%'i\", -10000) : ${NC}" $i 
test "$i - (\"%%'i\", -999) : ${NC}" $i 
test "$i - (\"%%'i\", -1000) : ${NC}" $i 
test "$i - (\"%%'i\", -789456) : ${NC}" $i 
test "$i - (\"%%'u\", 10000) : ${NC}" $i 
test "$i - (\"%%'u\", 0) : ${NC}" $i 
test "$i - (\"%%'u\", 999) : ${NC}" $i 
test "$i - (\"%%'u\", 1000) : ${NC}" $i 
test "$i - (\"%%'u\", 789456) : ${NC}" $i 
test "$i - (\"%%'u\", 1000000) : ${NC}" $i 
test "$i - (\"%%'u\", 999000000) : ${NC}" $i 
test "$i - (\"%%'u\", -10000) : ${NC}" $i 
test "$i - (\"%%'u\", -999) : ${NC}" $i 
test "$i - (\"%%'u\", -1000) : ${NC}" $i 
test "$i - (\"%%'u\", -789456) : ${NC}" $i 
test "$i - (\"%%'f\", 10000.0) : ${NC}" $i 
test "$i - (\"%%'f\", 0.0) : ${NC}" $i 
test "$i - (\"%%'f\", 999.0) : ${NC}" $i 
test "$i - (\"%%'f\", 1000.0) : ${NC}" $i 
test "$i - (\"%%'f\", 789456.0) : ${NC}" $i 
test "$i - (\"%%'f\", 1000000.0) : ${NC}" $i 
test "$i - (\"%%'f\", 999000000.0) : ${NC}" $i 
test "$i - (\"%%'f\", -10000.0) : ${NC}" $i 
test "$i - (\"%%'f\", -999.0) : ${NC}" $i 
test "$i - (\"%%'f\", -1000.0) : ${NC}" $i 
test "$i - (\"%%'f\", -789456.0) : ${NC}" $i 
test "$i - (\"%%'g\", 10000.0) : ${NC}" $i 
test "$i - (\"%%'g\", 0.0) : ${NC}" $i 
test "$i - (\"%%'g\", 999.0) : ${NC}" $i 
test "$i - (\"%%'g\", 1000.0) : ${NC}" $i 
test "$i - (\"%%'g\", 789456.0) : ${NC}" $i 
test "$i - (\"%%'.10g\", 1000000.0) : ${NC}" $i 
test "$i - (\"%%'.15g\", 999000000.0) : ${NC}" $i 
test "$i - (\"%%'g\", -10000.0) : ${NC}" $i 
test "$i - (\"%%'g\", -999.0) : ${NC}" $i 
test "$i - (\"%%'g\", -1000.0) : ${NC}" $i 
test "$i - (\"%%'g\", -789456.0) : ${NC}" $i 
test "$i - (\"%%'g\", 10000.0) : ${NC}" $i 
test "$i - (\"%%'f\", 0.42) : ${NC}" $i 
test "$i - (\"%%'f\", 0.0001) : ${NC}" $i 
test "$i - (\"%%'g\", 0.42) : ${NC}" $i 
test "$i - (\"%%'g\", 0.001) : ${NC}" $i 
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"
