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
printf "\n${BLUE}[P - Tests with #]${NC}\n"
test "$i - (\"%%#x\", 42) : ${NC}" $i 
test "$i - (\"%%#10x\", 42) : ${NC}" $i 
test "$i - (\"%%#-10x\", 42) : ${NC}" $i 
test "$i - (\"%%#010x\", 42) : ${NC}" $i 
test "$i - (\"%%#10.4x\", 42) : ${NC}" $i 
test "$i - (\"%%#10x\", 0) : ${NC}" $i 
test "$i - (\"%%#10.0x\", 0) : ${NC}" $i 
test "$i - (\"%%#X\", 42) : ${NC}" $i 
test "$i - (\"%%#10X\", 42) : ${NC}" $i 
test "$i - (\"%%#-10X\", 42) : ${NC}" $i 
test "$i - (\"%%#010X\", 42) : ${NC}" $i 
test "$i - (\"%%#10.4X\", 42) : ${NC}" $i 
test "$i - (\"%%#10X\", 0) : ${NC}" $i 
test "$i - (\"%%#10.0X\", 0) : ${NC}" $i 
test "$i - (\"%%#f\", 42.0) : ${NC}" $i 
test "$i - (\"%%#.0f\", 42.0) : ${NC}" $i 
test "$i - (\"%%#.0f\", -42.0) : ${NC}" $i 
test "$i - (\"%%#.0f\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#5.0f\", 42.0) : ${NC}" $i 
test "$i - (\"%%#-5.0f\", -42.0) : ${NC}" $i 
test "$i - (\"%%#-5.0f\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#05.0f\", 42.0) : ${NC}" $i 
test "$i - (\"%%#05.0f\", -42.0) : ${NC}" $i 
test "$i - (\"%%#05.0f\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#e\", 42.0) : ${NC}" $i 
test "$i - (\"%%#.0e\", 42.0) : ${NC}" $i 
test "$i - (\"%%#.0e\", -42.0) : ${NC}" $i 
test "$i - (\"%%#.0e\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#10.0e\", 42.0) : ${NC}" $i 
test "$i - (\"%%#-10.0e\", -42.0) : ${NC}" $i 
test "$i - (\"%%#-10.0e\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#010.0e\", 42.0) : ${NC}" $i 
test "$i - (\"%%#010.0e\", -42.0) : ${NC}" $i 
test "$i - (\"%%#010.0e\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#g\", 42.0) : ${NC}" $i 
test "$i - (\"%%g\", 42.0) : ${NC}" $i 
test "$i - (\"%%#.0g\", 42.0) : ${NC}" $i 
test "$i - (\"%%#.0g\", -42.0) : ${NC}" $i 
test "$i - (\"%%#.0g\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#10.0g\", 42.0) : ${NC}" $i 
test "$i - (\"%%#-10.0g\", -42.0) : ${NC}" $i 
test "$i - (\"%%#-10.0g\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#010.0g\", 42.0) : ${NC}" $i 
test "$i - (\"%%#010.0g\", -42.0) : ${NC}" $i 
test "$i - (\"%%#010.0g\", 0.0) : ${NC}" $i ;
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"
