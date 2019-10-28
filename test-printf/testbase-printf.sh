GREEN='\033[0;32m'
RED='\x1B[31m'
BLUE='\e[96m'
NC='\033[0m'
i=0
error=0

# $1 = text, $2 = test number
test()
{
	printf "$1" >> result.log
	./a.out $2 > original_output
	./a.out $2 user > user_output
	if diff "original_output" "user_output" >>/dev/null
	then
		if [ $error -eq 1 ]
		then
			printf "\n"
		fi
    	printf "${GREEN}OK ${NC}"
    	printf "${GREEN}OK ${NC}\n" >> result.log
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
gcc -Wall -Wextra -Werror test-printf/test-printf.c libftprintf.a
