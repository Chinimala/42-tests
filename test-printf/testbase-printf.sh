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
