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
printf "\n\n${BLUE}[A - Tests without options]${NC}\n" && error=0
test "$i - (\"\") : ${NC}" $i 
test "$i - (\"1\") : ${NC}" $i 
test "$i - (\"%%%%\") : ${NC}" $i 
test "$i - (\"%%%%%%%%\") : ${NC}" $i 
test "$i - (\"%%%%%%%%%%%%\") : ${NC}" $i 
test "$i - (\"%%c\", '1') : ${NC}" $i 
test "$i - (\"%%c\", -207) : ${NC}" $i 
test "$i - (\"%%c\", 256 + 48) : ${NC}" $i 
test "$i - (\"%%c%%%%\", '3') : ${NC}" $i 
test "$i - (\"0%%c\", 0) : ${NC}" $i 
test "$i - (\"%%c\", -129) : ${NC}" $i 
test "$i - (\"%%c\", 128) : ${NC}" $i 
test "$i - (\"%%c\", '\0') : ${NC}" $i 
test "$i - (\"%%s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%s%%%%\", \"Hello3\") : ${NC}" $i 
test "$i - (\"%%s\", \"\") : ${NC}" $i 
test "$i - (\"%%s\", \"1\") : ${NC}" $i 
test "$i - (\"%%i\", 0) : ${NC}" $i 
test "$i - (\"%%i\", -1) : ${NC}" $i 
test "$i - (\"%%i\", -42) : ${NC}" $i 
test "$i - (\"%%i\", 1) : ${NC}" $i 
test "$i - (\"%%i\", 42) : ${NC}" $i 
test "$i - (\"%%i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%i\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%i\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%i\", 1000) : ${NC}" $i 
test "$i - (\"%%i\", -1000) : ${NC}" $i 
test "$i - (\"%%d\", 0) : ${NC}" $i 
test "$i - (\"%%d\", -1) : ${NC}" $i 
test "$i - (\"%%d\", -42) : ${NC}" $i 
test "$i - (\"%%d\", 1) : ${NC}" $i 
test "$i - (\"%%d\", 42) : ${NC}" $i 
test "$i - (\"%%d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%d\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%d\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%d\", 1000) : ${NC}" $i 
test "$i - (\"%%d\", -1000) : ${NC}" $i 
test "$i - (\"%%u\", 0) : ${NC}" $i 
test "$i - (\"%%u\", -1) : ${NC}" $i 
test "$i - (\"%%u\", 1) : ${NC}" $i 
test "$i - (\"%%u\", 42) : ${NC}" $i 
test "$i - (\"%%u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%u\", UINT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%u\", 1000) : ${NC}" $i 
test "$i - (\"%%x\", 0) : ${NC}" $i 
test "$i - (\"%%x\", -1) : ${NC}" $i 
test "$i - (\"%%x\", -42) : ${NC}" $i 
test "$i - (\"%%x\", 1) : ${NC}" $i 
test "$i - (\"%%x\", 42) : ${NC}" $i 
test "$i - (\"%%x\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%x\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%x\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%x\", 1000) : ${NC}" $i 
test "$i - (\"%%x\", -1000) : ${NC}" $i 
test "$i - (\"%%X\", 0) : ${NC}" $i 
test "$i - (\"%%X\", -1) : ${NC}" $i 
test "$i - (\"%%X\", -42) : ${NC}" $i 
test "$i - (\"%%X\", 1) : ${NC}" $i 
test "$i - (\"%%X\", 42) : ${NC}" $i 
test "$i - (\"%%X\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%X\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%X\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%X\", 1000) : ${NC}" $i 
test "$i - (\"%%X\", -1000) : ${NC}" $i 
test "$i - (\"%%p\", (void*)1) : ${NC}" $i 
test "$i - (\"%%p\", (void*)-1) : ${NC}" $i 
test "$i - (\"%%p\", (void*)42) : ${NC}" $i 
test "$i - (\"%%p\", (void*)1000) : ${NC}" $i 
test "$i - (\"%%p\", (void*)ULONG_MAX) : ${NC}" $i 
test "$i - (\"%%p\", (void*)ULONG_MAX + 1) : ${NC}" $i 
printf "\n\n${BLUE}[B - Tests with minimum field width]${NC}\n" && error=0
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
printf "\n\n${BLUE}[C - Tests with flag -]${NC}\n" && error=0
test "$i - (\"%%-1%%\") : ${NC}" $i 
test "$i - (\"%%-2%%\") : ${NC}" $i 
test "$i - (\"%%-10%%\") : ${NC}" $i 
test "$i - (\"%%-1c\", '1') : ${NC}" $i 
test "$i - (\"%%-2c\", '1') : ${NC}" $i 
test "$i - (\"%%-10c\", '1') : ${NC}" $i 
test "$i - (\"%%-1s\", \"\") : ${NC}" $i 
test "$i - (\"%%-5s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-6s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-1i\", 0) : ${NC}" $i 
test "$i - (\"%%-2i\", 0) : ${NC}" $i 
test "$i - (\"%%-10i\", 0) : ${NC}" $i 
test "$i - (\"%%-1i\", -1) : ${NC}" $i 
test "$i - (\"%%-2i\", -1) : ${NC}" $i 
test "$i - (\"%%-3i\", -1) : ${NC}" $i 
test "$i - (\"%%-9i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-1d\", 0) : ${NC}" $i 
test "$i - (\"%%-2d\", 0) : ${NC}" $i 
test "$i - (\"%%-10d\", 0) : ${NC}" $i 
test "$i - (\"%%-1d\", -1) : ${NC}" $i 
test "$i - (\"%%-2d\", -1) : ${NC}" $i 
test "$i - (\"%%-3d\", -1) : ${NC}" $i 
test "$i - (\"%%-9d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-1u\", 0) : ${NC}" $i 
test "$i - (\"%%-2u\", 0) : ${NC}" $i 
test "$i - (\"%%-10u\", 0) : ${NC}" $i 
test "$i - (\"%%-1u\", -1) : ${NC}" $i 
test "$i - (\"%%-2u\", -1) : ${NC}" $i 
test "$i - (\"%%-3u\", -1) : ${NC}" $i 
test "$i - (\"%%-9u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-1x\", 0) : ${NC}" $i 
test "$i - (\"%%-2x\", 0) : ${NC}" $i 
test "$i - (\"%%-10x\", 0) : ${NC}" $i 
test "$i - (\"%%-1x\", -1) : ${NC}" $i 
test "$i - (\"%%-2x\", -1) : ${NC}" $i 
test "$i - (\"%%-3x\", -1) : ${NC}" $i 
test "$i - (\"%%-9x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-1X\", 0) : ${NC}" $i 
test "$i - (\"%%-2X\", 0) : ${NC}" $i 
test "$i - (\"%%-10X\", 0) : ${NC}" $i 
test "$i - (\"%%-1X\", -1) : ${NC}" $i 
test "$i - (\"%%-2X\", -1) : ${NC}" $i 
test "$i - (\"%%-3X\", -1) : ${NC}" $i 
test "$i - (\"%%-9X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-1p\", (void*)42) : ${NC}" $i 
test "$i - (\"%%-5p\", (void*)42) : ${NC}" $i 
printf "\n\n${BLUE}[D - Tests with flag 0]${NC}\n" && error=0
test "$i - (\"%%01i\", 0) : ${NC}" $i 
test "$i - (\"%%02i\", 0) : ${NC}" $i 
test "$i - (\"%%010i\", 0) : ${NC}" $i 
test "$i - (\"%%01i\", -1) : ${NC}" $i 
test "$i - (\"%%02i\", -1) : ${NC}" $i 
test "$i - (\"%%03i\", -1) : ${NC}" $i 
test "$i - (\"%%09i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%01d\", 0) : ${NC}" $i 
test "$i - (\"%%02d\", 0) : ${NC}" $i 
test "$i - (\"%%010d\", 0) : ${NC}" $i 
test "$i - (\"%%01d\", -1) : ${NC}" $i 
test "$i - (\"%%02d\", -1) : ${NC}" $i 
test "$i - (\"%%03d\", -1) : ${NC}" $i 
test "$i - (\"%%09d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%01u\", 0) : ${NC}" $i 
test "$i - (\"%%02u\", 0) : ${NC}" $i 
test "$i - (\"%%010u\", 0) : ${NC}" $i 
test "$i - (\"%%01u\", -1) : ${NC}" $i 
test "$i - (\"%%02u\", -1) : ${NC}" $i 
test "$i - (\"%%03u\", -1) : ${NC}" $i 
test "$i - (\"%%09u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%01x\", 0) : ${NC}" $i 
test "$i - (\"%%02x\", 0) : ${NC}" $i 
test "$i - (\"%%010x\", 0) : ${NC}" $i 
test "$i - (\"%%01x\", -1) : ${NC}" $i 
test "$i - (\"%%02x\", -1) : ${NC}" $i 
test "$i - (\"%%03x\", -1) : ${NC}" $i 
test "$i - (\"%%09x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%01X\", 0) : ${NC}" $i 
test "$i - (\"%%02X\", 0) : ${NC}" $i 
test "$i - (\"%%010X\", 0) : ${NC}" $i 
test "$i - (\"%%01X\", -1) : ${NC}" $i 
test "$i - (\"%%02X\", -1) : ${NC}" $i 
test "$i - (\"%%03X\", -1) : ${NC}" $i 
test "$i - (\"%%09X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%0-10d\", 42) : ${NC}" $i 
test "$i - (\"%%-010d\", 42) : ${NC}" $i 
printf "\n\n${BLUE}[E - Tests with .]${NC}\n" && error=0
test "$i - (\"%%.0%%\") : ${NC}" $i 
test "$i - (\"%%.0%%\") : ${NC}" $i 
test "$i - (\"%%.1%%\") : ${NC}" $i 
test "$i - (\"%%.2%%\") : ${NC}" $i 
test "$i - (\"%%.10%%\") : ${NC}" $i 
test "$i - (\"%%.0s\", \"\") : ${NC}" $i 
test "$i - (\"%%.1s\", \"\") : ${NC}" $i 
test "$i - (\"%%.3s\", \"\") : ${NC}" $i 
test "$i - (\"%%.0s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.1s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.2s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.5s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.6s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.7s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%.s\", 42) : ${NC}" $i 
test "$i - (\"%%.0d\", 0) : ${NC}" $i 
test "$i - (\"%%.1d\", 0) : ${NC}" $i 
test "$i - (\"%%.2d\", 0) : ${NC}" $i 
test "$i - (\"%%.0d\", 5) : ${NC}" $i 
test "$i - (\"%%.1d\", 5) : ${NC}" $i 
test "$i - (\"%%.2d\", 5) : ${NC}" $i 
test "$i - (\"%%.0d\", 42) : ${NC}" $i 
test "$i - (\"%%.1d\", 42) : ${NC}" $i 
test "$i - (\"%%.2d\", 42) : ${NC}" $i 
test "$i - (\"%%.3d\", 42) : ${NC}" $i 
test "$i - (\"%%.10d\", 42) : ${NC}" $i 
test "$i - (\"%%.6d\", 100) : ${NC}" $i 
test "$i - (\"%%.0d\", -1) : ${NC}" $i 
test "$i - (\"%%.1d\", -1) : ${NC}" $i 
test "$i - (\"%%.2d\", -1) : ${NC}" $i 
test "$i - (\"%%.3d\", -1) : ${NC}" $i 
test "$i - (\"%%.0d\", -42) : ${NC}" $i 
test "$i - (\"%%.1d\", -42) : ${NC}" $i 
test "$i - (\"%%.3d\", -42) : ${NC}" $i 
test "$i - (\"%%.4d\", -42) : ${NC}" $i 
test "$i - (\"%%.20d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%.20d\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%.20d\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%.20d\", INT_MIN - 1) : ${NC}" $i 
test "$i - (\"%%.0i\", 0) : ${NC}" $i 
test "$i - (\"%%.1i\", 0) : ${NC}" $i 
test "$i - (\"%%.2i\", 0) : ${NC}" $i 
test "$i - (\"%%.0i\", 5) : ${NC}" $i 
test "$i - (\"%%.1i\", 5) : ${NC}" $i 
test "$i - (\"%%.2i\", 5) : ${NC}" $i 
test "$i - (\"%%.0i\", 42) : ${NC}" $i 
test "$i - (\"%%.1i\", 42) : ${NC}" $i 
test "$i - (\"%%.2i\", 42) : ${NC}" $i 
test "$i - (\"%%.3i\", 42) : ${NC}" $i 
test "$i - (\"%%.10i\", 42) : ${NC}" $i 
test "$i - (\"%%.6i\", 100) : ${NC}" $i 
test "$i - (\"%%.0i\", -1) : ${NC}" $i 
test "$i - (\"%%.1i\", -1) : ${NC}" $i 
test "$i - (\"%%.2i\", -1) : ${NC}" $i 
test "$i - (\"%%.3i\", -1) : ${NC}" $i 
test "$i - (\"%%.0i\", -42) : ${NC}" $i 
test "$i - (\"%%.1i\", -42) : ${NC}" $i 
test "$i - (\"%%.3i\", -42) : ${NC}" $i 
test "$i - (\"%%.4i\", -42) : ${NC}" $i 
test "$i - (\"%%.20i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%.20i\", INT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%.20i\", INT_MIN) : ${NC}" $i 
test "$i - (\"%%.20i\", INT_MIN - 1) : ${NC}" $i 
test "$i - (\"%%.0u\", 0) : ${NC}" $i 
test "$i - (\"%%.1u\", 0) : ${NC}" $i 
test "$i - (\"%%.2u\", 0) : ${NC}" $i 
test "$i - (\"%%.0u\", 5) : ${NC}" $i 
test "$i - (\"%%.1u\", 5) : ${NC}" $i 
test "$i - (\"%%.2u\", 5) : ${NC}" $i 
test "$i - (\"%%.0u\", 42) : ${NC}" $i 
test "$i - (\"%%.1u\", 42) : ${NC}" $i 
test "$i - (\"%%.2u\", 42) : ${NC}" $i 
test "$i - (\"%%.3u\", 42) : ${NC}" $i 
test "$i - (\"%%.10u\", 42) : ${NC}" $i 
test "$i - (\"%%.6u\", 100) : ${NC}" $i 
test "$i - (\"%%.0u\", -1) : ${NC}" $i 
test "$i - (\"%%.1u\", -1) : ${NC}" $i 
test "$i - (\"%%.2u\", -1) : ${NC}" $i 
test "$i - (\"%%.3u\", -1) : ${NC}" $i 
test "$i - (\"%%.0u\", -42) : ${NC}" $i 
test "$i - (\"%%.1u\", -42) : ${NC}" $i 
test "$i - (\"%%.3u\", -42) : ${NC}" $i 
test "$i - (\"%%.4u\", -42) : ${NC}" $i 
test "$i - (\"%%.20u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%.20u\", UINT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%.0x\", 0) : ${NC}" $i 
test "$i - (\"%%.1x\", 0) : ${NC}" $i 
test "$i - (\"%%.2x\", 0) : ${NC}" $i 
test "$i - (\"%%.0x\", 5) : ${NC}" $i 
test "$i - (\"%%.1x\", 5) : ${NC}" $i 
test "$i - (\"%%.2x\", 5) : ${NC}" $i 
test "$i - (\"%%.0x\", 42) : ${NC}" $i 
test "$i - (\"%%.1x\", 42) : ${NC}" $i 
test "$i - (\"%%.2x\", 42) : ${NC}" $i 
test "$i - (\"%%.3x\", 42) : ${NC}" $i 
test "$i - (\"%%.10x\", 42) : ${NC}" $i 
test "$i - (\"%%.6x\", 100) : ${NC}" $i 
test "$i - (\"%%.0x\", -1) : ${NC}" $i 
test "$i - (\"%%.1x\", -1) : ${NC}" $i 
test "$i - (\"%%.2x\", -1) : ${NC}" $i 
test "$i - (\"%%.3x\", -1) : ${NC}" $i 
test "$i - (\"%%.0x\", -42) : ${NC}" $i 
test "$i - (\"%%.1x\", -42) : ${NC}" $i 
test "$i - (\"%%.3x\", -42) : ${NC}" $i 
test "$i - (\"%%.4x\", -42) : ${NC}" $i 
test "$i - (\"%%.20x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%.20x\", UINT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%.0X\", 0) : ${NC}" $i 
test "$i - (\"%%.1X\", 0) : ${NC}" $i 
test "$i - (\"%%.2X\", 0) : ${NC}" $i 
test "$i - (\"%%.0X\", 5) : ${NC}" $i 
test "$i - (\"%%.1X\", 5) : ${NC}" $i 
test "$i - (\"%%.2X\", 5) : ${NC}" $i 
test "$i - (\"%%.0X\", 42) : ${NC}" $i 
test "$i - (\"%%.1X\", 42) : ${NC}" $i 
test "$i - (\"%%.2X\", 42) : ${NC}" $i 
test "$i - (\"%%.3X\", 42) : ${NC}" $i 
test "$i - (\"%%.10X\", 42) : ${NC}" $i 
test "$i - (\"%%.6X\", 100) : ${NC}" $i 
test "$i - (\"%%.0X\", -1) : ${NC}" $i 
test "$i - (\"%%.1X\", -1) : ${NC}" $i 
test "$i - (\"%%.2X\", -1) : ${NC}" $i 
test "$i - (\"%%.3X\", -1) : ${NC}" $i 
test "$i - (\"%%.0X\", -42) : ${NC}" $i 
test "$i - (\"%%.1X\", -42) : ${NC}" $i 
test "$i - (\"%%.3X\", -42) : ${NC}" $i 
test "$i - (\"%%.4X\", -42) : ${NC}" $i 
test "$i - (\"%%.20X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%.20X\", UINT_MAX + 1) : ${NC}" $i 
printf "\n\n${BLUE}[F - Tests with minimum field width and .]${NC}\n" && error=0
test "$i - (\"%%1.0%%\") : ${NC}" $i 
test "$i - (\"%%1.1%%\") : ${NC}" $i 
test "$i - (\"%%1.2%%\") : ${NC}" $i 
test "$i - (\"%%1.10%%\") : ${NC}" $i 
test "$i - (\"%%2.0%%\") : ${NC}" $i 
test "$i - (\"%%2.1%%\") : ${NC}" $i 
test "$i - (\"%%2.2%%\") : ${NC}" $i 
test "$i - (\"%%2.10%%\") : ${NC}" $i 
test "$i - (\"%%10.0%%\") : ${NC}" $i 
test "$i - (\"%%10.1%%\") : ${NC}" $i 
test "$i - (\"%%10.2%%\") : ${NC}" $i 
test "$i - (\"%%10.10%%\") : ${NC}" $i 
test "$i - (\"%%1.0s\", \"\") : ${NC}" $i 
test "$i - (\"%%1.1s\", \"\") : ${NC}" $i 
test "$i - (\"%%1.2s\", \"\") : ${NC}" $i 
test "$i - (\"%%1.10s\", \"\") : ${NC}" $i 
test "$i - (\"%%5.0s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%5.1s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%5.2s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%5.10s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%6.0s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%6.1s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%6.2s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%6.10s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%1.0i\", 0) : ${NC}" $i 
test "$i - (\"%%1.1i\", 0) : ${NC}" $i 
test "$i - (\"%%1.2i\", 0) : ${NC}" $i 
test "$i - (\"%%1.10i\", 0) : ${NC}" $i 
test "$i - (\"%%2.0i\", 0) : ${NC}" $i 
test "$i - (\"%%2.1i\", 0) : ${NC}" $i 
test "$i - (\"%%2.2i\", 0) : ${NC}" $i 
test "$i - (\"%%2.10i\", 0) : ${NC}" $i 
test "$i - (\"%%10.0i\", 0) : ${NC}" $i 
test "$i - (\"%%10.1i\", 0) : ${NC}" $i 
test "$i - (\"%%10.2i\", 0) : ${NC}" $i 
test "$i - (\"%%10.10i\", 0) : ${NC}" $i 
test "$i - (\"%%1.0i\", -1) : ${NC}" $i 
test "$i - (\"%%1.1i\", -1) : ${NC}" $i 
test "$i - (\"%%1.2i\", -1) : ${NC}" $i 
test "$i - (\"%%1.10i\", -1) : ${NC}" $i 
test "$i - (\"%%2.0i\", -1) : ${NC}" $i 
test "$i - (\"%%2.1i\", -1) : ${NC}" $i 
test "$i - (\"%%2.2i\", -1) : ${NC}" $i 
test "$i - (\"%%2.10i\", -1) : ${NC}" $i 
test "$i - (\"%%3.0i\", -1) : ${NC}" $i 
test "$i - (\"%%3.1i\", -1) : ${NC}" $i 
test "$i - (\"%%3.2i\", -1) : ${NC}" $i 
test "$i - (\"%%3.10i\", -1) : ${NC}" $i 
test "$i - (\"%%9.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%1.0d\", 0) : ${NC}" $i 
test "$i - (\"%%1.1d\", 0) : ${NC}" $i 
test "$i - (\"%%1.2d\", 0) : ${NC}" $i 
test "$i - (\"%%1.10d\", 0) : ${NC}" $i 
test "$i - (\"%%2.0d\", 0) : ${NC}" $i 
test "$i - (\"%%2.1d\", 0) : ${NC}" $i 
test "$i - (\"%%2.2d\", 0) : ${NC}" $i 
test "$i - (\"%%2.10d\", 0) : ${NC}" $i 
test "$i - (\"%%10.0d\", 0) : ${NC}" $i 
test "$i - (\"%%10.1d\", 0) : ${NC}" $i 
test "$i - (\"%%10.2d\", 0) : ${NC}" $i 
test "$i - (\"%%10.10d\", 0) : ${NC}" $i 
test "$i - (\"%%1.0d\", -1) : ${NC}" $i 
test "$i - (\"%%1.1d\", -1) : ${NC}" $i 
test "$i - (\"%%1.2d\", -1) : ${NC}" $i 
test "$i - (\"%%1.10d\", -1) : ${NC}" $i 
test "$i - (\"%%2.0d\", -1) : ${NC}" $i 
test "$i - (\"%%2.1d\", -1) : ${NC}" $i 
test "$i - (\"%%2.2d\", -1) : ${NC}" $i 
test "$i - (\"%%2.10d\", -1) : ${NC}" $i 
test "$i - (\"%%3.0d\", -1) : ${NC}" $i 
test "$i - (\"%%3.1d\", -1) : ${NC}" $i 
test "$i - (\"%%3.2d\", -1) : ${NC}" $i 
test "$i - (\"%%3.10d\", -1) : ${NC}" $i 
test "$i - (\"%%9.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%1.0u\", 0) : ${NC}" $i 
test "$i - (\"%%1.1u\", 0) : ${NC}" $i 
test "$i - (\"%%1.2u\", 0) : ${NC}" $i 
test "$i - (\"%%1.10u\", 0) : ${NC}" $i 
test "$i - (\"%%2.0u\", 0) : ${NC}" $i 
test "$i - (\"%%2.1u\", 0) : ${NC}" $i 
test "$i - (\"%%2.2u\", 0) : ${NC}" $i 
test "$i - (\"%%2.10u\", 0) : ${NC}" $i 
test "$i - (\"%%10.0u\", 0) : ${NC}" $i 
test "$i - (\"%%10.1u\", 0) : ${NC}" $i 
test "$i - (\"%%10.2u\", 0) : ${NC}" $i 
test "$i - (\"%%10.10u\", 0) : ${NC}" $i 
test "$i - (\"%%1.0u\", -1) : ${NC}" $i 
test "$i - (\"%%1.1u\", -1) : ${NC}" $i 
test "$i - (\"%%1.2u\", -1) : ${NC}" $i 
test "$i - (\"%%1.10u\", -1) : ${NC}" $i 
test "$i - (\"%%2.0u\", -1) : ${NC}" $i 
test "$i - (\"%%2.1u\", -1) : ${NC}" $i 
test "$i - (\"%%2.2u\", -1) : ${NC}" $i 
test "$i - (\"%%2.10u\", -1) : ${NC}" $i 
test "$i - (\"%%3.0u\", -1) : ${NC}" $i 
test "$i - (\"%%3.1u\", -1) : ${NC}" $i 
test "$i - (\"%%3.2u\", -1) : ${NC}" $i 
test "$i - (\"%%3.10u\", -1) : ${NC}" $i 
test "$i - (\"%%9.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%1.0x\", 0) : ${NC}" $i 
test "$i - (\"%%1.1x\", 0) : ${NC}" $i 
test "$i - (\"%%1.2x\", 0) : ${NC}" $i 
test "$i - (\"%%1.10x\", 0) : ${NC}" $i 
test "$i - (\"%%2.0x\", 0) : ${NC}" $i 
test "$i - (\"%%2.1x\", 0) : ${NC}" $i 
test "$i - (\"%%2.2x\", 0) : ${NC}" $i 
test "$i - (\"%%2.10x\", 0) : ${NC}" $i 
test "$i - (\"%%10.0x\", 0) : ${NC}" $i 
test "$i - (\"%%10.1x\", 0) : ${NC}" $i 
test "$i - (\"%%10.2x\", 0) : ${NC}" $i 
test "$i - (\"%%10.10x\", 0) : ${NC}" $i 
test "$i - (\"%%1.0x\", -1) : ${NC}" $i 
test "$i - (\"%%1.1x\", -1) : ${NC}" $i 
test "$i - (\"%%1.2x\", -1) : ${NC}" $i 
test "$i - (\"%%1.10x\", -1) : ${NC}" $i 
test "$i - (\"%%2.0x\", -1) : ${NC}" $i 
test "$i - (\"%%2.1x\", -1) : ${NC}" $i 
test "$i - (\"%%2.2x\", -1) : ${NC}" $i 
test "$i - (\"%%2.10x\", -1) : ${NC}" $i 
test "$i - (\"%%3.0x\", -1) : ${NC}" $i 
test "$i - (\"%%3.1x\", -1) : ${NC}" $i 
test "$i - (\"%%3.2x\", -1) : ${NC}" $i 
test "$i - (\"%%3.10x\", -1) : ${NC}" $i 
test "$i - (\"%%9.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%1.0X\", 0) : ${NC}" $i 
test "$i - (\"%%1.1X\", 0) : ${NC}" $i 
test "$i - (\"%%1.2X\", 0) : ${NC}" $i 
test "$i - (\"%%1.10X\", 0) : ${NC}" $i 
test "$i - (\"%%2.0X\", 0) : ${NC}" $i 
test "$i - (\"%%2.1X\", 0) : ${NC}" $i 
test "$i - (\"%%2.2X\", 0) : ${NC}" $i 
test "$i - (\"%%2.10X\", 0) : ${NC}" $i 
test "$i - (\"%%10.0X\", 0) : ${NC}" $i 
test "$i - (\"%%10.1X\", 0) : ${NC}" $i 
test "$i - (\"%%10.2X\", 0) : ${NC}" $i 
test "$i - (\"%%10.10X\", 0) : ${NC}" $i 
test "$i - (\"%%1.0X\", -1) : ${NC}" $i 
test "$i - (\"%%1.1X\", -1) : ${NC}" $i 
test "$i - (\"%%1.2X\", -1) : ${NC}" $i 
test "$i - (\"%%1.10X\", -1) : ${NC}" $i 
test "$i - (\"%%2.0X\", -1) : ${NC}" $i 
test "$i - (\"%%2.1X\", -1) : ${NC}" $i 
test "$i - (\"%%2.2X\", -1) : ${NC}" $i 
test "$i - (\"%%2.10X\", -1) : ${NC}" $i 
test "$i - (\"%%3.0X\", -1) : ${NC}" $i 
test "$i - (\"%%3.1X\", -1) : ${NC}" $i 
test "$i - (\"%%3.2X\", -1) : ${NC}" $i 
test "$i - (\"%%3.10X\", -1) : ${NC}" $i 
test "$i - (\"%%9.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%9.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%10.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%11.10X\", UINT_MAX) : ${NC}" $i 
printf "\n\n${BLUE}[G - Tests with minimum field width, flag - and .]${NC}\n" && error=0
test "$i - (\"%%-1.0%%\") : ${NC}" $i 
test "$i - (\"%%-1.1%%\") : ${NC}" $i 
test "$i - (\"%%-1.2%%\") : ${NC}" $i 
test "$i - (\"%%-1.10%%\") : ${NC}" $i 
test "$i - (\"%%-2.0%%\") : ${NC}" $i 
test "$i - (\"%%-2.1%%\") : ${NC}" $i 
test "$i - (\"%%-2.2%%\") : ${NC}" $i 
test "$i - (\"%%-2.10%%\") : ${NC}" $i 
test "$i - (\"%%-10.0%%\") : ${NC}" $i 
test "$i - (\"%%-10.1%%\") : ${NC}" $i 
test "$i - (\"%%-10.2%%\") : ${NC}" $i 
test "$i - (\"%%-10.10%%\") : ${NC}" $i 
test "$i - (\"%%-1.0s\", \"\") : ${NC}" $i 
test "$i - (\"%%-1.1s\", \"\") : ${NC}" $i 
test "$i - (\"%%-1.2s\", \"\") : ${NC}" $i 
test "$i - (\"%%-1.10s\", \"\") : ${NC}" $i 
test "$i - (\"%%-5.0s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-5.1s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-5.2s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-5.10s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-6.0s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-6.1s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-6.2s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-6.10s\", \"Hello\") : ${NC}" $i 
test "$i - (\"%%-1.0i\", 0) : ${NC}" $i 
test "$i - (\"%%-1.1i\", 0) : ${NC}" $i 
test "$i - (\"%%-1.2i\", 0) : ${NC}" $i 
test "$i - (\"%%-1.10i\", 0) : ${NC}" $i 
test "$i - (\"%%-2.0i\", 0) : ${NC}" $i 
test "$i - (\"%%-2.1i\", 0) : ${NC}" $i 
test "$i - (\"%%-2.2i\", 0) : ${NC}" $i 
test "$i - (\"%%-2.10i\", 0) : ${NC}" $i 
test "$i - (\"%%-10.0i\", 0) : ${NC}" $i 
test "$i - (\"%%-10.1i\", 0) : ${NC}" $i 
test "$i - (\"%%-10.2i\", 0) : ${NC}" $i 
test "$i - (\"%%-10.10i\", 0) : ${NC}" $i 
test "$i - (\"%%-1.0i\", -1) : ${NC}" $i 
test "$i - (\"%%-1.1i\", -1) : ${NC}" $i 
test "$i - (\"%%-1.2i\", -1) : ${NC}" $i 
test "$i - (\"%%-1.10i\", -1) : ${NC}" $i 
test "$i - (\"%%-2.0i\", -1) : ${NC}" $i 
test "$i - (\"%%-2.1i\", -1) : ${NC}" $i 
test "$i - (\"%%-2.2i\", -1) : ${NC}" $i 
test "$i - (\"%%-2.10i\", -1) : ${NC}" $i 
test "$i - (\"%%-3.0i\", -1) : ${NC}" $i 
test "$i - (\"%%-3.1i\", -1) : ${NC}" $i 
test "$i - (\"%%-3.2i\", -1) : ${NC}" $i 
test "$i - (\"%%-3.10i\", -1) : ${NC}" $i 
test "$i - (\"%%-9.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-1.0d\", 0) : ${NC}" $i 
test "$i - (\"%%-1.1d\", 0) : ${NC}" $i 
test "$i - (\"%%-1.2d\", 0) : ${NC}" $i 
test "$i - (\"%%-1.10d\", 0) : ${NC}" $i 
test "$i - (\"%%-2.0d\", 0) : ${NC}" $i 
test "$i - (\"%%-2.1d\", 0) : ${NC}" $i 
test "$i - (\"%%-2.2d\", 0) : ${NC}" $i 
test "$i - (\"%%-2.10d\", 0) : ${NC}" $i 
test "$i - (\"%%-10.0d\", 0) : ${NC}" $i 
test "$i - (\"%%-10.1d\", 0) : ${NC}" $i 
test "$i - (\"%%-10.2d\", 0) : ${NC}" $i 
test "$i - (\"%%-10.10d\", 0) : ${NC}" $i 
test "$i - (\"%%-1.0d\", -1) : ${NC}" $i 
test "$i - (\"%%-1.1d\", -1) : ${NC}" $i 
test "$i - (\"%%-1.2d\", -1) : ${NC}" $i 
test "$i - (\"%%-1.10d\", -1) : ${NC}" $i 
test "$i - (\"%%-2.0d\", -1) : ${NC}" $i 
test "$i - (\"%%-2.1d\", -1) : ${NC}" $i 
test "$i - (\"%%-2.2d\", -1) : ${NC}" $i 
test "$i - (\"%%-2.10d\", -1) : ${NC}" $i 
test "$i - (\"%%-3.0d\", -1) : ${NC}" $i 
test "$i - (\"%%-3.1d\", -1) : ${NC}" $i 
test "$i - (\"%%-3.2d\", -1) : ${NC}" $i 
test "$i - (\"%%-3.10d\", -1) : ${NC}" $i 
test "$i - (\"%%-9.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%-1.0u\", 0) : ${NC}" $i 
test "$i - (\"%%-1.1u\", 0) : ${NC}" $i 
test "$i - (\"%%-1.2u\", 0) : ${NC}" $i 
test "$i - (\"%%-1.10u\", 0) : ${NC}" $i 
test "$i - (\"%%-2.0u\", 0) : ${NC}" $i 
test "$i - (\"%%-2.1u\", 0) : ${NC}" $i 
test "$i - (\"%%-2.2u\", 0) : ${NC}" $i 
test "$i - (\"%%-2.10u\", 0) : ${NC}" $i 
test "$i - (\"%%-10.0u\", 0) : ${NC}" $i 
test "$i - (\"%%-10.1u\", 0) : ${NC}" $i 
test "$i - (\"%%-10.2u\", 0) : ${NC}" $i 
test "$i - (\"%%-10.10u\", 0) : ${NC}" $i 
test "$i - (\"%%-1.0u\", -1) : ${NC}" $i 
test "$i - (\"%%-1.1u\", -1) : ${NC}" $i 
test "$i - (\"%%-1.2u\", -1) : ${NC}" $i 
test "$i - (\"%%-1.10u\", -1) : ${NC}" $i 
test "$i - (\"%%-2.0u\", -1) : ${NC}" $i 
test "$i - (\"%%-2.1u\", -1) : ${NC}" $i 
test "$i - (\"%%-2.2u\", -1) : ${NC}" $i 
test "$i - (\"%%-2.10u\", -1) : ${NC}" $i 
test "$i - (\"%%-3.0u\", -1) : ${NC}" $i 
test "$i - (\"%%-3.1u\", -1) : ${NC}" $i 
test "$i - (\"%%-3.2u\", -1) : ${NC}" $i 
test "$i - (\"%%-3.10u\", -1) : ${NC}" $i 
test "$i - (\"%%-9.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-1.0x\", 0) : ${NC}" $i 
test "$i - (\"%%-1.1x\", 0) : ${NC}" $i 
test "$i - (\"%%-1.2x\", 0) : ${NC}" $i 
test "$i - (\"%%-1.10x\", 0) : ${NC}" $i 
test "$i - (\"%%-2.0x\", 0) : ${NC}" $i 
test "$i - (\"%%-2.1x\", 0) : ${NC}" $i 
test "$i - (\"%%-2.2x\", 0) : ${NC}" $i 
test "$i - (\"%%-2.10x\", 0) : ${NC}" $i 
test "$i - (\"%%-10.0x\", 0) : ${NC}" $i 
test "$i - (\"%%-10.1x\", 0) : ${NC}" $i 
test "$i - (\"%%-10.2x\", 0) : ${NC}" $i 
test "$i - (\"%%-10.10x\", 0) : ${NC}" $i 
test "$i - (\"%%-1.0x\", -1) : ${NC}" $i 
test "$i - (\"%%-1.1x\", -1) : ${NC}" $i 
test "$i - (\"%%-1.2x\", -1) : ${NC}" $i 
test "$i - (\"%%-1.10x\", -1) : ${NC}" $i 
test "$i - (\"%%-2.0x\", -1) : ${NC}" $i 
test "$i - (\"%%-2.1x\", -1) : ${NC}" $i 
test "$i - (\"%%-2.2x\", -1) : ${NC}" $i 
test "$i - (\"%%-2.10x\", -1) : ${NC}" $i 
test "$i - (\"%%-3.0x\", -1) : ${NC}" $i 
test "$i - (\"%%-3.1x\", -1) : ${NC}" $i 
test "$i - (\"%%-3.2x\", -1) : ${NC}" $i 
test "$i - (\"%%-3.10x\", -1) : ${NC}" $i 
test "$i - (\"%%-9.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-1.0X\", 0) : ${NC}" $i 
test "$i - (\"%%-1.1X\", 0) : ${NC}" $i 
test "$i - (\"%%-1.2X\", 0) : ${NC}" $i 
test "$i - (\"%%-1.10X\", 0) : ${NC}" $i 
test "$i - (\"%%-2.0X\", 0) : ${NC}" $i 
test "$i - (\"%%-2.1X\", 0) : ${NC}" $i 
test "$i - (\"%%-2.2X\", 0) : ${NC}" $i 
test "$i - (\"%%-2.10X\", 0) : ${NC}" $i 
test "$i - (\"%%-10.0X\", 0) : ${NC}" $i 
test "$i - (\"%%-10.1X\", 0) : ${NC}" $i 
test "$i - (\"%%-10.2X\", 0) : ${NC}" $i 
test "$i - (\"%%-10.10X\", 0) : ${NC}" $i 
test "$i - (\"%%-1.0X\", -1) : ${NC}" $i 
test "$i - (\"%%-1.1X\", -1) : ${NC}" $i 
test "$i - (\"%%-1.2X\", -1) : ${NC}" $i 
test "$i - (\"%%-1.10X\", -1) : ${NC}" $i 
test "$i - (\"%%-2.0X\", -1) : ${NC}" $i 
test "$i - (\"%%-2.1X\", -1) : ${NC}" $i 
test "$i - (\"%%-2.2X\", -1) : ${NC}" $i 
test "$i - (\"%%-2.10X\", -1) : ${NC}" $i 
test "$i - (\"%%-3.0X\", -1) : ${NC}" $i 
test "$i - (\"%%-3.1X\", -1) : ${NC}" $i 
test "$i - (\"%%-3.2X\", -1) : ${NC}" $i 
test "$i - (\"%%-3.10X\", -1) : ${NC}" $i 
test "$i - (\"%%-9.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-9.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-10.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%-11.10X\", UINT_MAX) : ${NC}" $i 
printf "\n\n${BLUE}[H - Tests with minimum field width, flag 0 and .]${NC}\n" && error=0
test "$i - (\"%%01.0i\", 0) : ${NC}" $i 
test "$i - (\"%%01.1i\", 0) : ${NC}" $i 
test "$i - (\"%%01.2i\", 0) : ${NC}" $i 
test "$i - (\"%%01.10i\", 0) : ${NC}" $i 
test "$i - (\"%%02.0i\", 0) : ${NC}" $i 
test "$i - (\"%%02.1i\", 0) : ${NC}" $i 
test "$i - (\"%%02.2i\", 0) : ${NC}" $i 
test "$i - (\"%%02.10i\", 0) : ${NC}" $i 
test "$i - (\"%%010.0i\", 0) : ${NC}" $i 
test "$i - (\"%%010.1i\", 0) : ${NC}" $i 
test "$i - (\"%%010.2i\", 0) : ${NC}" $i 
test "$i - (\"%%010.10i\", 0) : ${NC}" $i 
test "$i - (\"%%01.0i\", -1) : ${NC}" $i 
test "$i - (\"%%01.1i\", -1) : ${NC}" $i 
test "$i - (\"%%01.2i\", -1) : ${NC}" $i 
test "$i - (\"%%01.10i\", -1) : ${NC}" $i 
test "$i - (\"%%02.0i\", -1) : ${NC}" $i 
test "$i - (\"%%02.1i\", -1) : ${NC}" $i 
test "$i - (\"%%02.2i\", -1) : ${NC}" $i 
test "$i - (\"%%02.10i\", -1) : ${NC}" $i 
test "$i - (\"%%03.0i\", -1) : ${NC}" $i 
test "$i - (\"%%03.1i\", -1) : ${NC}" $i 
test "$i - (\"%%03.2i\", -1) : ${NC}" $i 
test "$i - (\"%%03.10i\", -1) : ${NC}" $i 
test "$i - (\"%%09.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%01.0d\", 0) : ${NC}" $i 
test "$i - (\"%%01.1d\", 0) : ${NC}" $i 
test "$i - (\"%%01.2d\", 0) : ${NC}" $i 
test "$i - (\"%%01.10d\", 0) : ${NC}" $i 
test "$i - (\"%%02.0d\", 0) : ${NC}" $i 
test "$i - (\"%%02.1d\", 0) : ${NC}" $i 
test "$i - (\"%%02.2d\", 0) : ${NC}" $i 
test "$i - (\"%%02.10d\", 0) : ${NC}" $i 
test "$i - (\"%%010.0d\", 0) : ${NC}" $i 
test "$i - (\"%%010.1d\", 0) : ${NC}" $i 
test "$i - (\"%%010.2d\", 0) : ${NC}" $i 
test "$i - (\"%%010.10d\", 0) : ${NC}" $i 
test "$i - (\"%%01.0d\", -1) : ${NC}" $i 
test "$i - (\"%%01.1d\", -1) : ${NC}" $i 
test "$i - (\"%%01.2d\", -1) : ${NC}" $i 
test "$i - (\"%%01.10d\", -1) : ${NC}" $i 
test "$i - (\"%%02.0d\", -1) : ${NC}" $i 
test "$i - (\"%%02.1d\", -1) : ${NC}" $i 
test "$i - (\"%%02.2d\", -1) : ${NC}" $i 
test "$i - (\"%%02.10d\", -1) : ${NC}" $i 
test "$i - (\"%%03.0d\", -1) : ${NC}" $i 
test "$i - (\"%%03.1d\", -1) : ${NC}" $i 
test "$i - (\"%%03.2d\", -1) : ${NC}" $i 
test "$i - (\"%%03.10d\", -1) : ${NC}" $i 
test "$i - (\"%%09.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%01.0u\", 0) : ${NC}" $i 
test "$i - (\"%%01.1u\", 0) : ${NC}" $i 
test "$i - (\"%%01.2u\", 0) : ${NC}" $i 
test "$i - (\"%%01.10u\", 0) : ${NC}" $i 
test "$i - (\"%%02.0u\", 0) : ${NC}" $i 
test "$i - (\"%%02.1u\", 0) : ${NC}" $i 
test "$i - (\"%%02.2u\", 0) : ${NC}" $i 
test "$i - (\"%%02.10u\", 0) : ${NC}" $i 
test "$i - (\"%%010.0u\", 0) : ${NC}" $i 
test "$i - (\"%%010.1u\", 0) : ${NC}" $i 
test "$i - (\"%%010.2u\", 0) : ${NC}" $i 
test "$i - (\"%%010.10u\", 0) : ${NC}" $i 
test "$i - (\"%%01.0u\", -1) : ${NC}" $i 
test "$i - (\"%%01.1u\", -1) : ${NC}" $i 
test "$i - (\"%%01.2u\", -1) : ${NC}" $i 
test "$i - (\"%%01.10u\", -1) : ${NC}" $i 
test "$i - (\"%%02.0u\", -1) : ${NC}" $i 
test "$i - (\"%%02.1u\", -1) : ${NC}" $i 
test "$i - (\"%%02.2u\", -1) : ${NC}" $i 
test "$i - (\"%%02.10u\", -1) : ${NC}" $i 
test "$i - (\"%%03.0u\", -1) : ${NC}" $i 
test "$i - (\"%%03.1u\", -1) : ${NC}" $i 
test "$i - (\"%%03.2u\", -1) : ${NC}" $i 
test "$i - (\"%%03.10u\", -1) : ${NC}" $i 
test "$i - (\"%%09.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%01.0x\", 0) : ${NC}" $i 
test "$i - (\"%%01.1x\", 0) : ${NC}" $i 
test "$i - (\"%%01.2x\", 0) : ${NC}" $i 
test "$i - (\"%%01.10x\", 0) : ${NC}" $i 
test "$i - (\"%%02.0x\", 0) : ${NC}" $i 
test "$i - (\"%%02.1x\", 0) : ${NC}" $i 
test "$i - (\"%%02.2x\", 0) : ${NC}" $i 
test "$i - (\"%%02.10x\", 0) : ${NC}" $i 
test "$i - (\"%%010.0x\", 0) : ${NC}" $i 
test "$i - (\"%%010.1x\", 0) : ${NC}" $i 
test "$i - (\"%%010.2x\", 0) : ${NC}" $i 
test "$i - (\"%%010.10x\", 0) : ${NC}" $i 
test "$i - (\"%%01.0x\", -1) : ${NC}" $i 
test "$i - (\"%%01.1x\", -1) : ${NC}" $i 
test "$i - (\"%%01.2x\", -1) : ${NC}" $i 
test "$i - (\"%%01.10x\", -1) : ${NC}" $i 
test "$i - (\"%%02.0x\", -1) : ${NC}" $i 
test "$i - (\"%%02.1x\", -1) : ${NC}" $i 
test "$i - (\"%%02.2x\", -1) : ${NC}" $i 
test "$i - (\"%%02.10x\", -1) : ${NC}" $i 
test "$i - (\"%%03.0x\", -1) : ${NC}" $i 
test "$i - (\"%%03.1x\", -1) : ${NC}" $i 
test "$i - (\"%%03.2x\", -1) : ${NC}" $i 
test "$i - (\"%%03.10x\", -1) : ${NC}" $i 
test "$i - (\"%%09.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%01.0X\", 0) : ${NC}" $i 
test "$i - (\"%%01.1X\", 0) : ${NC}" $i 
test "$i - (\"%%01.2X\", 0) : ${NC}" $i 
test "$i - (\"%%01.10X\", 0) : ${NC}" $i 
test "$i - (\"%%02.0X\", 0) : ${NC}" $i 
test "$i - (\"%%02.1X\", 0) : ${NC}" $i 
test "$i - (\"%%02.2X\", 0) : ${NC}" $i 
test "$i - (\"%%02.10X\", 0) : ${NC}" $i 
test "$i - (\"%%010.0X\", 0) : ${NC}" $i 
test "$i - (\"%%010.1X\", 0) : ${NC}" $i 
test "$i - (\"%%010.2X\", 0) : ${NC}" $i 
test "$i - (\"%%010.10X\", 0) : ${NC}" $i 
test "$i - (\"%%01.0X\", -1) : ${NC}" $i 
test "$i - (\"%%01.1X\", -1) : ${NC}" $i 
test "$i - (\"%%01.2X\", -1) : ${NC}" $i 
test "$i - (\"%%01.10X\", -1) : ${NC}" $i 
test "$i - (\"%%02.0X\", -1) : ${NC}" $i 
test "$i - (\"%%02.1X\", -1) : ${NC}" $i 
test "$i - (\"%%02.2X\", -1) : ${NC}" $i 
test "$i - (\"%%02.10X\", -1) : ${NC}" $i 
test "$i - (\"%%03.0X\", -1) : ${NC}" $i 
test "$i - (\"%%03.1X\", -1) : ${NC}" $i 
test "$i - (\"%%03.2X\", -1) : ${NC}" $i 
test "$i - (\"%%03.10X\", -1) : ${NC}" $i 
test "$i - (\"%%09.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%09.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010.10X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.0X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.1X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.2X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011.10X\", UINT_MAX) : ${NC}" $i 
printf "\n\n${BLUE}[I - Tests with *]${NC}\n" && error=0
test "$i - (\"%%*d\", 0, 42) : ${NC}" $i 
test "$i - (\"%%*d\", 0, 0) : ${NC}" $i 
test "$i - (\"%%*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%*d\", -10, 42) : ${NC}" $i 
test "$i - (\"%%0*d\", -10, 42) : ${NC}" $i 
test "$i - (\"%%0*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%0*d\", 10, -42) : ${NC}" $i 
test "$i - (\"%%0*d\", 0, 42) : ${NC}" $i 
test "$i - (\"%%0*d\", 10, 0) : ${NC}" $i 
test "$i - (\"%%0*d\", -10, 0) : ${NC}" $i 
test "$i - (\"%%*d\", 010, 42) : ${NC}" $i 
test "$i - (\"%%*s\", 10, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*s\", -10, \"Hello\") : ${NC}" $i 
test "$i - (\"%%-*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%-*d\", -10, 42) : ${NC}" $i 
test "$i - (\"%%-*d\", -10, -42) : ${NC}" $i 
test "$i - (\"%%.*d\", 0, 42) : ${NC}" $i 
test "$i - (\"%%.*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%.*d\", -10, 42) : ${NC}" $i 
test "$i - (\"%%.*d\", 0, 0) : ${NC}" $i 
test "$i - (\"%%.*d\", 10, 0) : ${NC}" $i 
test "$i - (\"%%.*d\", -10, 0) : ${NC}" $i 
test "$i - (\"%%.*d\", -0, 0) : ${NC}" $i 
test "$i - (\"%%.*d\", -0, 42) : ${NC}" $i 
test "$i - (\"%%.*d\", -0, -42) : ${NC}" $i 
test "$i - (\"%%.*s\", -3, \"Hello\") : ${NC}" $i 
test "$i - (\"%%10.*d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%*.10d\", 10, 42) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, 0, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, 0, 42) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, 0, -42) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, 5, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", 0, -5, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", 5, 0, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", -5, 0, 0) : ${NC}" $i 
test "$i - (\"%%*.*d\", 5, 5, 0) : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, 5, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 0, -5, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 5, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", -5, 0, \"Hello\") : ${NC}" $i 
test "$i - (\"%%*.*s\", 5, 5, \"Hello\") : ${NC}" $i 
printf "\n\n${BLUE}[J - Tests with n]${NC}\n" && error=0
test "$i - (\"%%n\", NULL) : ${NC}" $i 
test "$i - (\"size = %%d\", t2) : ${NC}" $i 
test "$i - (\"size = %%d\", t2) : ${NC}" $i 
test "$i - (\"size = %%d\", t2) : ${NC}" $i 
test "$i - (\"size = %%d\", t2) : ${NC}" $i 
test "$i - (\"size = %%d\", t2) : ${NC}" $i 
test "$i - (\"size = %%d ; size = %%d\", t2, t2bis) : ${NC}" $i 
printf "\n\n${BLUE}[K - Tests with f]${NC}\n" && error=0
test "$i - (\"%%f\", 0) : ${NC}" $i 
test "$i - (\"%%.f\", 42.0) : ${NC}" $i 
test "$i - (\"%%.1f\", 42.0) : ${NC}" $i 
test "$i - (\"%%.f\", 42.1) : ${NC}" $i 
test "$i - (\"%%f\", 42.0) : ${NC}" $i 
test "$i - (\"%%f\", 42.1) : ${NC}" $i 
test "$i - (\"%%f\", 42.101) : ${NC}" $i 
test "$i - (\"%%f\", 42.002) : ${NC}" $i 
test "$i - (\"%%12f\", 42.0) : ${NC}" $i 
test "$i - (\"%%1f\", 42.0) : ${NC}" $i 
test "$i - (\"%%12f\", 42.101) : ${NC}" $i 
test "$i - (\"%%-12f\", 42.101) : ${NC}" $i 
test "$i - (\"%%012f\", 42.101) : ${NC}" $i 
test "$i - (\"%%0-12f\", 42.101) : ${NC}" $i 
test "$i - (\"%%.2f\", 42.101) : ${NC}" $i 
test "$i - (\"%%.0f\", 42.101) : ${NC}" $i 
test "$i - (\"%%.0f\", 42.101) : ${NC}" $i 
test "$i - (\"%%.8f\", 42.121) : ${NC}" $i 
test "$i - (\"%%.8f\", 1234567890123456.1) : ${NC}" $i 
test "$i - (\"%%.8f\", 12345678901234567.1) : ${NC}" $i 
test "$i - (\"%%.8f\", 123456789012345678.1) : ${NC}" $i 
test "$i - (\"%%.8f\", INT_MAX - 40 + 0.1) : ${NC}" $i 
test "$i - (\"%%.70f\", 42.10115645159842215121541215412126) : ${NC}" $i 
test "$i - (\"%%.120f\", 42.12356489797986111100001235648979798611110000123564897912356489797986111100001235648979798611110000123564897979861111000012356489797986111100001235648979798611110000119999999999999999999999999999999999999999999999999999999999999999999) : ${NC}" $i 
test "$i - (\"%%040.8f\", 1234567890123456.1) : ${NC}" $i 
test "$i - (\"%%-40.8f\", 12345678901234567.1) : ${NC}" $i 
test "$i - (\"%%0-40.8f\", 123456789012345678.1) : ${NC}" $i 
test "$i - (\"%%.8f\", INT_MAX - 40 + 0.1) : ${NC}" $i 
test "$i - (\"%%.70f\", 42.10115645159842215121541215412126) : ${NC}" $i 
test "$i - (\"%%.3f\", 9.9997) : ${NC}" $i 
test "$i - (\"%%07.3f\", 9.9997) : ${NC}" $i 
test "$i - (\"%%f\", -42.0) : ${NC}" $i 
test "$i - (\"%%f\", -42.1) : ${NC}" $i 
test "$i - (\"%%f\", -42.101) : ${NC}" $i 
test "$i - (\"%%f\", -42.002) : ${NC}" $i 
test "$i - (\"%%12f\", -42.0) : ${NC}" $i 
test "$i - (\"%%1f\", -42.0) : ${NC}" $i 
test "$i - (\"%%12f\", -42.101) : ${NC}" $i 
test "$i - (\"%%-12f\", -42.101) : ${NC}" $i 
test "$i - (\"%%012f\", -42.101) : ${NC}" $i 
test "$i - (\"%%0-12f\", -42.101) : ${NC}" $i 
test "$i - (\"%%.2f\", -42.101) : ${NC}" $i 
test "$i - (\"%%.0f\", -42.101) : ${NC}" $i 
test "$i - (\"%%.0f\", -42.101) : ${NC}" $i 
test "$i - (\"%%.8f\", -42.121) : ${NC}" $i 
test "$i - (\"%%.8f\", -1234567890123456.1) : ${NC}" $i 
test "$i - (\"%%.8f\", -12345678901234567.1) : ${NC}" $i 
test "$i - (\"%%.8f\", -123456789012345678.1) : ${NC}" $i 
test "$i - (\"%%.70f\", -42.10115645159842215121541215412126) : ${NC}" $i 
test "$i - (\"%%040.8f\", -1234567890123456.1) : ${NC}" $i 
test "$i - (\"%%-40.8f\", -12345678901234567.1) : ${NC}" $i 
test "$i - (\"%%0-40.8f\", -123456789012345678.1) : ${NC}" $i 
test "$i - (\"%%.70f\", -42.10115645159842215121541215412126) : ${NC}" $i 
test "$i - (\"%%.3f\", -9.9997) : ${NC}" $i 
test "$i - (\"%%07.3f\", -9.9997) : ${NC}" $i 
test "$i - (\"%%f\", 0.1) : ${NC}" $i 
test "$i - (\"%%f\", 0.2) : ${NC}" $i 
test "$i - (\"%%f\", 0.01) : ${NC}" $i 
test "$i - (\"%%f\", -0.1) : ${NC}" $i 
test "$i - (\"%%f\", -0.2) : ${NC}" $i 
test "$i - (\"%%f\", -0.01) : ${NC}" $i 
test "$i - (\"%%f\", 0.0000000056) : ${NC}" $i 
test "$i - (\"%%010f\", 0.01) : ${NC}" $i 
test "$i - (\"%%-10f\", 0.01) : ${NC}" $i 
test "$i - (\"%%-10f\", 0.42) : ${NC}" $i 
test "$i - (\"%%f\", 0.0101010101010101) : ${NC}" $i 
test "$i - (\"%%.f\", 0.1) : ${NC}" $i 
test "$i - (\"%%.0f\", 0.1) : ${NC}" $i 
test "$i - (\"%%.1f\", 0.2) : ${NC}" $i 
test "$i - (\"%%.1f\", 0.01) : ${NC}" $i 
test "$i - (\"%%.0f\", -0.1) : ${NC}" $i 
test "$i - (\"%%.12f\", 0.0000000056) : ${NC}" $i 
test "$i - (\"%%.20f\", 0.0101010101010101) : ${NC}" $i 
test "$i - (\"%%.0f\", 2.51) : ${NC}" $i 
test "$i - (\"%%.0f\", 1.5) : ${NC}" $i 
test "$i - (\"%%.0f\", 4.5) : ${NC}" $i 
test "$i - (\"%%.0f\", -2.5) : ${NC}" $i 
test "$i - (\"%%.0f\", -3.5) : ${NC}" $i 
test "$i - (\"%%.0f\", 2.5) : ${NC}" $i 
test "$i - (\"%%.0f\", 3.5) : ${NC}" $i 
test "$i - (\"%%.0f\", 2.45) : ${NC}" $i 
test "$i - (\"%%.0f\", 2.35) : ${NC}" $i 
test "$i - (\"%%.0f\", -2.35) : ${NC}" $i 
test "$i - (\"%%.0f\", 3.451) : ${NC}" $i 
printf "\n\n${BLUE}[L - Tests with e]${NC}\n" && error=0
test "$i - (\"%%.4e\", 150.129) : ${NC}" $i 
test "$i - (\"%%e\", 0.0) : ${NC}" $i 
test "$i - (\"%%e\", 42.0) : ${NC}" $i 
test "$i - (\"%%e\", 42.1) : ${NC}" $i 
test "$i - (\"%%e\", 42.101) : ${NC}" $i 
test "$i - (\"%%e\", 42.002) : ${NC}" $i 
test "$i - (\"%%12e\", 42.0) : ${NC}" $i 
test "$i - (\"%%1e\", 42.0) : ${NC}" $i 
test "$i - (\"%%12e\", 42.101) : ${NC}" $i 
test "$i - (\"%%-12e\", 42.101) : ${NC}" $i 
test "$i - (\"%%012e\", 42.101) : ${NC}" $i 
test "$i - (\"%%0-12e\", 42.101) : ${NC}" $i 
test "$i - (\"%%.2e\", 42.101) : ${NC}" $i 
test "$i - (\"%%.0e\", 42.101) : ${NC}" $i 
test "$i - (\"%%.0e\", 42.101) : ${NC}" $i 
test "$i - (\"%%.8e\", 42.121) : ${NC}" $i 
test "$i - (\"%%.8e\", 1234567890123456.1) : ${NC}" $i 
test "$i - (\"%%.8e\", 12345678901234567.1) : ${NC}" $i 
test "$i - (\"%%.8e\", 123456789012345678.1) : ${NC}" $i 
test "$i - (\"%%.8e\", INT_MAX - 40 + 0.1) : ${NC}" $i 
test "$i - (\"%%.70e\", 42.10115645159842215121541215412126) : ${NC}" $i 
test "$i - (\"%%040.8e\", 1234567890123456.1) : ${NC}" $i 
test "$i - (\"%%-40.8e\", 12345678901234567.1) : ${NC}" $i 
test "$i - (\"%%0-40.8e\", 123456789012345678.1) : ${NC}" $i 
test "$i - (\"%%.8e\", INT_MAX - 40 + 0.1) : ${NC}" $i 
test "$i - (\"%%.70e\", 42.10115645159842215121541215412126) : ${NC}" $i 
test "$i - (\"%%.3e\", 9.9997) : ${NC}" $i 
test "$i - (\"%%07.3e\", 9.9997) : ${NC}" $i 
test "$i - (\"%%e\", -42.0) : ${NC}" $i 
test "$i - (\"%%e\", -42.1) : ${NC}" $i 
test "$i - (\"%%e\", -42.101) : ${NC}" $i 
test "$i - (\"%%e\", -42.002) : ${NC}" $i 
test "$i - (\"%%12e\", -42.0) : ${NC}" $i 
test "$i - (\"%%1e\", -42.0) : ${NC}" $i 
test "$i - (\"%%12e\", -42.101) : ${NC}" $i 
test "$i - (\"%%-12e\", -42.101) : ${NC}" $i 
test "$i - (\"%%012e\", -42.101) : ${NC}" $i 
test "$i - (\"%%0-12e\", -42.101) : ${NC}" $i 
test "$i - (\"%%.2e\", -42.101) : ${NC}" $i 
test "$i - (\"%%.0e\", -42.101) : ${NC}" $i 
test "$i - (\"%%.0e\", -42.101) : ${NC}" $i 
test "$i - (\"%%.8e\", -42.121) : ${NC}" $i 
test "$i - (\"%%.8e\", -1234567890123456.1) : ${NC}" $i 
test "$i - (\"%%.8e\", -12345678901234567.1) : ${NC}" $i 
test "$i - (\"%%.8e\", -123456789012345678.1) : ${NC}" $i 
test "$i - (\"%%.70e\", -42.10115645159842215121541215412126) : ${NC}" $i 
test "$i - (\"%%040.8e\", -1234567890123456.1) : ${NC}" $i 
test "$i - (\"%%-40.8e\", -12345678901234567.1) : ${NC}" $i 
test "$i - (\"%%0-40.8e\", -123456789012345678.1) : ${NC}" $i 
test "$i - (\"%%.70e\", -42.10115645159842215121541215412126) : ${NC}" $i 
test "$i - (\"%%.3e\", -9.9997) : ${NC}" $i 
test "$i - (\"%%07.3e\", -9.9997) : ${NC}" $i 
test "$i - (\"%%e\", 0.1) : ${NC}" $i 
test "$i - (\"%%e\", 0.2) : ${NC}" $i 
test "$i - (\"%%e\", 0.01) : ${NC}" $i 
test "$i - (\"%%e\", -0.1) : ${NC}" $i 
test "$i - (\"%%e\", -0.2) : ${NC}" $i 
test "$i - (\"%%e\", -0.01) : ${NC}" $i 
test "$i - (\"%%e\", 0.0000000056) : ${NC}" $i 
test "$i - (\"%%010e\", 0.01) : ${NC}" $i 
test "$i - (\"%%-10e\", 0.01) : ${NC}" $i 
test "$i - (\"%%-10e\", 0.42) : ${NC}" $i 
test "$i - (\"%%e\", 0.0101010101010101) : ${NC}" $i 
test "$i - (\"%%.e\", 0.1) : ${NC}" $i 
test "$i - (\"%%.0e\", 0.1) : ${NC}" $i 
test "$i - (\"%%.1e\", 0.2) : ${NC}" $i 
test "$i - (\"%%.1e\", 0.01) : ${NC}" $i 
test "$i - (\"%%.0e\", -0.1) : ${NC}" $i 
test "$i - (\"%%.12e\", 0.0000000056) : ${NC}" $i 
printf "\n\n${BLUE}[M - Tests with g]${NC}\n" && error=0
test "$i - (\"%%g\", 0.0) : ${NC}" $i 
test "$i - (\"%%g\", 42.0) : ${NC}" $i 
test "$i - (\"%%g\", 1.0) : ${NC}" $i 
test "$i - (\"%%g\", 100.0) : ${NC}" $i 
test "$i - (\"%%g\", 0.1) : ${NC}" $i 
test "$i - (\"%%g\", 0.1001000001) : ${NC}" $i 
test "$i - (\"%%g\", 0.0101010101) : ${NC}" $i 
test "$i - (\"%%g\", 0.42) : ${NC}" $i 
test "$i - (\"%%g\", 42.1) : ${NC}" $i 
test "$i - (\"%%g\", 0.01) : ${NC}" $i 
test "$i - (\"%%g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%g\", -42.0) : ${NC}" $i 
test "$i - (\"%%g\", -1.0) : ${NC}" $i 
test "$i - (\"%%g\", -100.0) : ${NC}" $i 
test "$i - (\"%%g\", -0.1) : ${NC}" $i 
test "$i - (\"%%g\", -0.42) : ${NC}" $i 
test "$i - (\"%%g\", -42.1) : ${NC}" $i 
test "$i - (\"%%g\", -0.01) : ${NC}" $i 
test "$i - (\"%%g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%.g\", 0.0) : ${NC}" $i 
test "$i - (\"%%.g\", 42.0) : ${NC}" $i 
test "$i - (\"%%.g\", 1.0) : ${NC}" $i 
test "$i - (\"%%.g\", 100.0) : ${NC}" $i 
test "$i - (\"%%.g\", 0.1) : ${NC}" $i 
test "$i - (\"%%.g\", 0.42) : ${NC}" $i 
test "$i - (\"%%.g\", 42.1) : ${NC}" $i 
test "$i - (\"%%.g\", 0.01) : ${NC}" $i 
test "$i - (\"%%.g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%.g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%.g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%.g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%.g\", -42.0) : ${NC}" $i 
test "$i - (\"%%.g\", -1.0) : ${NC}" $i 
test "$i - (\"%%.g\", -100.0) : ${NC}" $i 
test "$i - (\"%%.g\", -0.1) : ${NC}" $i 
test "$i - (\"%%.g\", -0.42) : ${NC}" $i 
test "$i - (\"%%.g\", -42.1) : ${NC}" $i 
test "$i - (\"%%.g\", -0.01) : ${NC}" $i 
test "$i - (\"%%.g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%.g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%.g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%.g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%.0g\", 0.0) : ${NC}" $i 
test "$i - (\"%%.0g\", 42.0) : ${NC}" $i 
test "$i - (\"%%.0g\", 1.0) : ${NC}" $i 
test "$i - (\"%%.0g\", 100.0) : ${NC}" $i 
test "$i - (\"%%.0g\", 0.1) : ${NC}" $i 
test "$i - (\"%%.0g\", 0.42) : ${NC}" $i 
test "$i - (\"%%.0g\", 42.1) : ${NC}" $i 
test "$i - (\"%%.0g\", 0.01) : ${NC}" $i 
test "$i - (\"%%.0g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%.0g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%.0g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%.0g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%.0g\", -42.0) : ${NC}" $i 
test "$i - (\"%%.0g\", -1.0) : ${NC}" $i 
test "$i - (\"%%.0g\", -100.0) : ${NC}" $i 
test "$i - (\"%%.0g\", -0.1) : ${NC}" $i 
test "$i - (\"%%.0g\", -0.42) : ${NC}" $i 
test "$i - (\"%%.0g\", -42.1) : ${NC}" $i 
test "$i - (\"%%.0g\", -0.01) : ${NC}" $i 
test "$i - (\"%%.0g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%.0g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%.0g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%.0g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%.1g\", 0.0) : ${NC}" $i 
test "$i - (\"%%.1g\", 42.0) : ${NC}" $i 
test "$i - (\"%%.1g\", 1.0) : ${NC}" $i 
test "$i - (\"%%.1g\", 100.0) : ${NC}" $i 
test "$i - (\"%%.1g\", 0.1) : ${NC}" $i 
test "$i - (\"%%.1g\", 0.42) : ${NC}" $i 
test "$i - (\"%%.1g\", 42.1) : ${NC}" $i 
test "$i - (\"%%.1g\", 0.01) : ${NC}" $i 
test "$i - (\"%%.1g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%.1g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%.1g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%.1g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%.1g\", -42.0) : ${NC}" $i 
test "$i - (\"%%.1g\", -1.0) : ${NC}" $i 
test "$i - (\"%%.1g\", -100.0) : ${NC}" $i 
test "$i - (\"%%.1g\", -0.1) : ${NC}" $i 
test "$i - (\"%%.1g\", -0.42) : ${NC}" $i 
test "$i - (\"%%.1g\", -42.1) : ${NC}" $i 
test "$i - (\"%%.1g\", -0.01) : ${NC}" $i 
test "$i - (\"%%.1g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%.1g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%.1g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%.1g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%.2g\", 0.0) : ${NC}" $i 
test "$i - (\"%%.2g\", 42.0) : ${NC}" $i 
test "$i - (\"%%.2g\", 1.0) : ${NC}" $i 
test "$i - (\"%%.2g\", 100.0) : ${NC}" $i 
test "$i - (\"%%.2g\", 0.1) : ${NC}" $i 
test "$i - (\"%%.2g\", 0.42) : ${NC}" $i 
test "$i - (\"%%.2g\", 42.1) : ${NC}" $i 
test "$i - (\"%%.2g\", 0.01) : ${NC}" $i 
test "$i - (\"%%.2g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%.2g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%.2g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%.2g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%.2g\", -42.0) : ${NC}" $i 
test "$i - (\"%%.2g\", -1.0) : ${NC}" $i 
test "$i - (\"%%.2g\", -100.0) : ${NC}" $i 
test "$i - (\"%%.2g\", -0.1) : ${NC}" $i 
test "$i - (\"%%.2g\", -0.42) : ${NC}" $i 
test "$i - (\"%%.2g\", -42.1) : ${NC}" $i 
test "$i - (\"%%.2g\", -0.01) : ${NC}" $i 
test "$i - (\"%%.2g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%.2g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%.2g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%.2g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%.2g\", 56789.0) : ${NC}" $i 
test "$i - (\"%%.2g\", 56789.1) : ${NC}" $i 
test "$i - (\"%%.2g\", 56789.12) : ${NC}" $i 
test "$i - (\"%%.g\", 56789.12) : ${NC}" $i 
test "$i - (\"%%.g\", 54789.12) : ${NC}" $i 
test "$i - (\"%%.g\", -54789.12) : ${NC}" $i 
test "$i - (\"%%20.g\", -54789.12) : ${NC}" $i 
test "$i - (\"%%020.g\", -54789.12) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.0) : ${NC}" $i 
test "$i - (\"%%.3g\", 42.0) : ${NC}" $i 
test "$i - (\"%%.3g\", 1.0) : ${NC}" $i 
test "$i - (\"%%.3g\", 100.0) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.1) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.42) : ${NC}" $i 
test "$i - (\"%%.3g\", 42.1) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.01) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%.3g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%.3g\", -42.0) : ${NC}" $i 
test "$i - (\"%%.3g\", -1.0) : ${NC}" $i 
test "$i - (\"%%.3g\", -100.0) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.1) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.42) : ${NC}" $i 
test "$i - (\"%%.3g\", -42.1) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.01) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%.3g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.0) : ${NC}" $i 
test "$i - (\"%%.3g\", 42.0) : ${NC}" $i 
test "$i - (\"%%.3g\", 1.0) : ${NC}" $i 
test "$i - (\"%%.3g\", 100.0) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.1) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.42) : ${NC}" $i 
test "$i - (\"%%.3g\", 42.1) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.01) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%.3g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%.3g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%.3g\", -42.0) : ${NC}" $i 
test "$i - (\"%%.3g\", -1.0) : ${NC}" $i 
test "$i - (\"%%.3g\", -100.0) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.1) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.42) : ${NC}" $i 
test "$i - (\"%%.3g\", -42.1) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.01) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%.3g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%.3g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%.5g\", 0.0) : ${NC}" $i 
test "$i - (\"%%.5g\", 42.0) : ${NC}" $i 
test "$i - (\"%%.5g\", 1.0) : ${NC}" $i 
test "$i - (\"%%.5g\", 100.0) : ${NC}" $i 
test "$i - (\"%%.5g\", 0.1) : ${NC}" $i 
test "$i - (\"%%.5g\", 0.42) : ${NC}" $i 
test "$i - (\"%%.5g\", 42.1) : ${NC}" $i 
test "$i - (\"%%.5g\", 0.01) : ${NC}" $i 
test "$i - (\"%%.5g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%.5g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%.5g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%.5g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%.5g\", -42.0) : ${NC}" $i 
test "$i - (\"%%.5g\", -1.0) : ${NC}" $i 
test "$i - (\"%%.5g\", -100.0) : ${NC}" $i 
test "$i - (\"%%.5g\", -0.1) : ${NC}" $i 
test "$i - (\"%%.5g\", -0.42) : ${NC}" $i 
test "$i - (\"%%.5g\", -42.1) : ${NC}" $i 
test "$i - (\"%%.5g\", -0.01) : ${NC}" $i 
test "$i - (\"%%.5g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%.5g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%.5g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%.5g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%g\", DBL_MAX) : ${NC}" $i 
test "$i - (\"%%g\", DBL_MAX + 1) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", 42.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", 1.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", 100.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.1) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.42) : ${NC}" $i 
test "$i - (\"%%010.3g\", 42.1) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.01) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%010.3g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", -42.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", -1.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", -100.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.1) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.42) : ${NC}" $i 
test "$i - (\"%%010.3g\", -42.1) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.01) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%010.3g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", 42.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", 1.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", 100.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.1) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.42) : ${NC}" $i 
test "$i - (\"%%010.3g\", 42.1) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.01) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%010.3g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%010.3g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", -42.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", -1.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", -100.0) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.1) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.42) : ${NC}" $i 
test "$i - (\"%%010.3g\", -42.1) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.01) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%010.3g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%010.3g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%010.6g\", 100000000.0) : ${NC}" $i 
test "$i - (\"%%020.9g\", 1000420000.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 42.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 1.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 100.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.1) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.42) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 42.1) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.01) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%-10.3g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -42.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -1.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -100.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.1) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.42) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -42.1) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.01) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%-10.3g\", INT_MIN - 1.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 42.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 1.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 100.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.1) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.42) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 42.1) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.01) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.0101) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%-10.3g\", 0.000423) : ${NC}" $i 
test "$i - (\"%%-10.3g\", INT_MAX + 1.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -42.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -1.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -100.0) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.1) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.42) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -42.1) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.01) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.0101) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%-10.3g\", -0.000423) : ${NC}" $i 
test "$i - (\"%%-10.3g\", INT_MIN - 1.0) : ${NC}" $i 
printf "\n\n${BLUE}[N - Tests with length modifiers]${NC}\n" && error=0
test "$i - (\"%%c\", 0b01000001) : ${NC}" $i 
test "$i - (\"%%hhi\", CHAR_MAX) : ${NC}" $i 
test "$i - (\"%%hhi\", CHAR_MAX + 1) : ${NC}" $i 
test "$i - (\"%%hhi\", CHAR_MIN) : ${NC}" $i 
test "$i - (\"%%hhi\", CHAR_MIN - 1) : ${NC}" $i 
test "$i - (\"%%hhu\", UCHAR_MAX) : ${NC}" $i 
test "$i - (\"%%hhu\", UCHAR_MAX + 1) : ${NC}" $i 
test "$i - (\"%%hhx\", UCHAR_MAX) : ${NC}" $i 
test "$i - (\"%%hhx\", UCHAR_MAX + 1) : ${NC}" $i 
test "$i - (\"%%hi\", SHRT_MAX) : ${NC}" $i 
test "$i - (\"%%hi\", SHRT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%hi\", SHRT_MIN) : ${NC}" $i 
test "$i - (\"%%hi\", SHRT_MIN - 1) : ${NC}" $i 
test "$i - (\"%%hu\", USHRT_MAX) : ${NC}" $i 
test "$i - (\"%%hu\", USHRT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%hx\", USHRT_MAX) : ${NC}" $i 
test "$i - (\"%%hx\", USHRT_MAX + 1) : ${NC}" $i 
test "$i - (\"%%li\", LONG_MAX) : ${NC}" $i 
test "$i - (\"%%li\", LONG_MAX + 1) : ${NC}" $i 
test "$i - (\"%%li\", LONG_MIN) : ${NC}" $i 
test "$i - (\"%%li\", LONG_MIN - 1) : ${NC}" $i 
test "$i - (\"%%lu\", ULONG_MAX) : ${NC}" $i 
test "$i - (\"%%lu\", ULONG_MAX + 1) : ${NC}" $i 
test "$i - (\"%%lx\", ULONG_MAX) : ${NC}" $i 
test "$i - (\"%%lx\", ULONG_MAX + 1) : ${NC}" $i 
test "$i - (\"%%lli\", LLONG_MAX) : ${NC}" $i 
test "$i - (\"%%lli\", LLONG_MAX + 1) : ${NC}" $i 
test "$i - (\"%%lli\", LLONG_MIN) : ${NC}" $i 
test "$i - (\"%%lli\", LLONG_MIN - 1) : ${NC}" $i 
test "$i - (\"%%llu\", ULLONG_MAX) : ${NC}" $i 
test "$i - (\"%%llu\", ULLONG_MAX + 1) : ${NC}" $i 
test "$i - (\"%%llx\", ULLONG_MAX) : ${NC}" $i 
test "$i - (\"%%llx\", ULLONG_MAX + 1) : ${NC}" $i 
test "$i - (\"size = %%d\", t4) : ${NC}" $i 
test "$i - (\"%%lc \", 128519) : ${NC}" $i 
test "$i - (\"%%lc \", 0x80000) : ${NC}" $i 
test "$i - (\"%%lc \", 176) : ${NC}" $i 
test "$i - (\"%%lc \", 35211) : ${NC}" $i 
test "$i - (\"%%lc \", 0x7E) : ${NC}" $i 
test "$i - (\"%%lc \", 0x7F) : ${NC}" $i 
test "$i - (\"%%lc \", 0x80) : ${NC}" $i 
test "$i - (\"%%lc \", 0x7FF) : ${NC}" $i 
test "$i - (\"%%lc \", 0x800) : ${NC}" $i 
test "$i - (\"%%lc \", 0xFFFF) : ${NC}" $i 
test "$i - (\"%%lc \", 0x80000) : ${NC}" $i 
test "$i - (\"%%lc %%lc \", 0x13143, 0x13144) : ${NC}" $i 
test "$i - (\"%%lc \", 256 + 48) : ${NC}" $i 
test "$i - (\"%%6lc \", 176) : ${NC}" $i 
test "$i - (\"%%6lc \", 35211) : ${NC}" $i 
test "$i - (\"%%6lc \", 128519) : ${NC}" $i 
test "$i - (\"%%-6lc \", 176) : ${NC}" $i 
test "$i - (\"%%-6lc \", 35211) : ${NC}" $i 
test "$i - (\"%%-6lc \", 128519) : ${NC}" $i 
test "$i - (\"%%.0ls \", t) : ${NC}" $i 
test "$i - (\"%%.1ls \", t) : ${NC}" $i 
test "$i - (\"%%.2ls \", t) : ${NC}" $i 
test "$i - (\"%%.3ls \", t) : ${NC}" $i 
test "$i - (\"%%.4ls \", t) : ${NC}" $i 
test "$i - (\"%%.5ls \", t) : ${NC}" $i 
test "$i - (\"%%.6ls \", t) : ${NC}" $i 
test "$i - (\"%%.7ls \", t) : ${NC}" $i 
test "$i - (\"%%15.0ls \", t) : ${NC}" $i 
test "$i - (\"%%15.1ls \", t) : ${NC}" $i 
test "$i - (\"%%15.2ls \", t) : ${NC}" $i 
test "$i - (\"%%15.3ls \", t) : ${NC}" $i 
test "$i - (\"%%15.4ls \", t) : ${NC}" $i 
test "$i - (\"%%15.5ls \", t) : ${NC}" $i 
test "$i - (\"%%15.6ls \", t) : ${NC}" $i 
test "$i - (\"%%15.7ls \", t) : ${NC}" $i 
test "$i - (\"%%-15.0ls \", t) : ${NC}" $i 
test "$i - (\"%%-15.1ls \", t) : ${NC}" $i 
test "$i - (\"%%-15.2ls \", t) : ${NC}" $i 
test "$i - (\"%%-15.3ls \", t) : ${NC}" $i 
test "$i - (\"%%-15.4ls \", t) : ${NC}" $i 
test "$i - (\"%%-15.5ls \", t) : ${NC}" $i 
test "$i - (\"%%-15.6ls \", t) : ${NC}" $i 
test "$i - (\"%%-15.7ls \", t) : ${NC}" $i 
test "$i - (\"%%ls \", t) : ${NC}" $i 
test "$i - (\"%%-ls \", t) : ${NC}" $i 
test "$i - (\"%%15ls \", t) : ${NC}" $i 
printf "\n\n${BLUE}[P - Tests with #]${NC}\n" && error=0
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
test "$i - (\"%%#.0g\", 42.0) : ${NC}" $i 
test "$i - (\"%%#.0g\", -42.0) : ${NC}" $i 
test "$i - (\"%%#.0g\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#10.0g\", 42.0) : ${NC}" $i 
test "$i - (\"%%#-10.0g\", -42.0) : ${NC}" $i 
test "$i - (\"%%#-10.0g\", 0.0) : ${NC}" $i ;
test "$i - (\"%%#010.0g\", 42.0) : ${NC}" $i 
test "$i - (\"%%#010.0g\", -42.0) : ${NC}" $i 
test "$i - (\"%%#010.0g\", 0.0) : ${NC}" $i ;
printf "\n\n${BLUE}[R - Tests with plus flag]${NC}\n" && error=0
test "$i - (\"%%+i\", 42) : ${NC}" $i 
test "$i - (\"%%+i\", -42) : ${NC}" $i 
test "$i - (\"%%0 10i\", 42) : ${NC}" $i 
test "$i - (\"%%0 10i\", -42) : ${NC}" $i 
test "$i - (\"%%+5i\", 42) : ${NC}" $i 
test "$i - (\"%%+3i\", 42) : ${NC}" $i 
test "$i - (\"%%+.1i\", 0) : ${NC}" $i 
test "$i - (\"%%+.0i\", 0) : ${NC}" $i 
test "$i - (\"%%+f\", 42.0) : ${NC}" $i 
test "$i - (\"%%+f\", -42.0) : ${NC}" $i 
test "$i - (\"%%+10f\", 42.0) : ${NC}" $i 
test "$i - (\"%%+f\", 0.0) : ${NC}" $i 
test "$i - (\"%%-+10f\", 0.0) : ${NC}" $i 
test "$i - (\"%%+15f\", 0.0) : ${NC}" $i 
test "$i - (\"%%+e\", 42.0) : ${NC}" $i 
test "$i - (\"%%+e\", -42.0) : ${NC}" $i 
test "$i - (\"%%+10e\", 42.0) : ${NC}" $i 
test "$i - (\"%%+e\", 0.0) : ${NC}" $i 
test "$i - (\"%%-+10e\", 0.0) : ${NC}" $i 
test "$i - (\"%%-+10e\", 42.0) : ${NC}" $i 
test "$i - (\"%%-+10e\", -42.0) : ${NC}" $i 
test "$i - (\"%%+23e\", 100000.0) : ${NC}" $i 
test "$i - (\"%%-+23e\", 100000.0) : ${NC}" $i 
test "$i - (\"%%+g\", 0.00001) : ${NC}" $i 
test "$i - (\"%%+g\", 0.000042) : ${NC}" $i 
test "$i - (\"%%+g\", -0.000042) : ${NC}" $i 
test "$i - (\"%%+10g\", 0.000042) : ${NC}" $i 
test "$i - (\"%%-+10g\", 0.000042) : ${NC}" $i 
test "$i - (\"%%+10g\", -0.000042) : ${NC}" $i 
test "$i - (\"%%-+10g\", -0.000042) : ${NC}" $i 
test "$i - (\"%%+7g\", 0.000042) : ${NC}" $i 
test "$i - (\"%%-+7g\", 0.000042) : ${NC}" $i 
test "$i - (\"%%+.2g\", 121.42) : ${NC}" $i 
test "$i - (\"%%0 10.2g\", 121.42) : ${NC}" $i 
test "$i - (\"%%+g\", 0.0001) : ${NC}" $i 
test "$i - (\"%%+g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%+g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%+10g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%-+10g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%+10g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%-+10g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%+7g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%-+7g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%-+7g\", 42.0) : ${NC}" $i 
test "$i - (\"%%#-+7.2g\", 42.0) : ${NC}" $i 
printf "\n\n${BLUE}[Q - Tests with space flag]${NC}\n" && error=0
test "$i - (\"%% i\", 42) : ${NC}" $i 
test "$i - (\"%% i\", -42) : ${NC}" $i 
test "$i - (\"%%0 10i\", 42) : ${NC}" $i 
test "$i - (\"%%0 10i\", -42) : ${NC}" $i 
test "$i - (\"%% 5i\", 42) : ${NC}" $i 
test "$i - (\"%% 3i\", 42) : ${NC}" $i 
test "$i - (\"%% .1i\", 0) : ${NC}" $i 
test "$i - (\"%% .0i\", 0) : ${NC}" $i 
test "$i - (\"%% f\", 42.0) : ${NC}" $i 
test "$i - (\"%% f\", -42.0) : ${NC}" $i 
test "$i - (\"%% 10f\", 42.0) : ${NC}" $i 
test "$i - (\"%% f\", 0.0) : ${NC}" $i 
test "$i - (\"%%- 10f\", 0.0) : ${NC}" $i 
test "$i - (\"%% 15f\", 0.0) : ${NC}" $i 
test "$i - (\"%% e\", 42.0) : ${NC}" $i 
test "$i - (\"%% e\", -42.0) : ${NC}" $i 
test "$i - (\"%% 10e\", 42.0) : ${NC}" $i 
test "$i - (\"%% e\", 0.0) : ${NC}" $i 
test "$i - (\"%%- 10e\", 0.0) : ${NC}" $i 
test "$i - (\"%%- 10e\", 42.0) : ${NC}" $i 
test "$i - (\"%%- 10e\", -42.0) : ${NC}" $i 
test "$i - (\"%% 23e\", 100000.0) : ${NC}" $i 
test "$i - (\"%%- 23e\", 100000.0) : ${NC}" $i 
test "$i - (\"%% g\", 0.00001) : ${NC}" $i 
test "$i - (\"%% g\", 0.000042) : ${NC}" $i 
test "$i - (\"%% g\", -0.000042) : ${NC}" $i 
test "$i - (\"%% 10g\", 0.000042) : ${NC}" $i 
test "$i - (\"%%- 10g\", 0.000042) : ${NC}" $i 
test "$i - (\"%% 10g\", -0.000042) : ${NC}" $i 
test "$i - (\"%%- 10g\", -0.000042) : ${NC}" $i 
test "$i - (\"%% 7g\", 0.000042) : ${NC}" $i 
test "$i - (\"%%- 7g\", 0.000042) : ${NC}" $i 
test "$i - (\"%% .2g\", 121.42) : ${NC}" $i 
test "$i - (\"%%0 10.2g\", 121.42) : ${NC}" $i 
test "$i - (\"%% g\", 0.0001) : ${NC}" $i 
test "$i - (\"%% g\", 0.00042) : ${NC}" $i 
test "$i - (\"%% g\", -0.00042) : ${NC}" $i 
test "$i - (\"%% 10g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%- 10g\", 0.00042) : ${NC}" $i 
test "$i - (\"%% 10g\", -0.00042) : ${NC}" $i 
test "$i - (\"%%- 10g\", -0.00042) : ${NC}" $i 
test "$i - (\"%% 7g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%- 7g\", 0.00042) : ${NC}" $i 
test "$i - (\"%%- 7g\", 42.0) : ${NC}" $i 
test "$i - (\"%%#- 7.2g\", 42.0) : ${NC}" $i 
printf "\n\n${BLUE}[S - Tests with ' flag]${NC}\n" && error=0
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
printf "\n\n${BLUE}[T - Tests with infinity and nan]${NC}\n" && error=0
test "$i - (\"%%-10g\", 0.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%010g\", 0.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%10g\", 0.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%-10e\", 0.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%010e\", 0.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%10e\", 0.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%-10f\", 0.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%010f\", 0.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%10f\", 0.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%-10g\", -1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%010g\", -1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%10g\", -1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%-10e\", -1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%010e\", -1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%10e\", -1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%-10f\", -1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%010f\", -1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%10f\", -1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%-10g\", 1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%010g\", 1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%10g\", 1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%-10e\", 1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%010e\", 1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%10e\", 1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%-10f\", 1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%010f\", 1.0 / 0.0) : ${NC}" $i 
test "$i - (\"%%10f\", 1.0 / 0.0) : ${NC}" $i 
printf "\n\n${BLUE}[U - Tests with o (our bonus !)]${NC}\n" && error=0
test "$i - (\"%%o\", 042) : ${NC}" $i 
test "$i - (\"%%o\", 0) : ${NC}" $i 
test "$i - (\"%%o\", 8) : ${NC}" $i 
test "$i - (\"%%10o\", 042) : ${NC}" $i 
test "$i - (\"%%.2o\", 456789) : ${NC}" $i 
test "$i - (\"%%-10.3o\", 456789) : ${NC}" $i 
test "$i - (\"%%#-10o\", 042) : ${NC}" $i 
test "$i - (\"%%#010o\", 042) : ${NC}" $i 
test "$i - (\"%%'o\", 123456789) : ${NC}" $i 
test "$i - (\"%%#1.o\", 0) : ${NC}" $i 
test "$i - (\"%%#o\", 0) : ${NC}" $i 
test "$i - (\"|%%#01o| |%%#0.10o| |%%#010o| |%%#0-10o| |%%#0+10o| |%%#0+10.o| |%%#0-10.o|\n\", 0, 0, 0, 0, 0, 0, 0) : ${NC}" $i 
test "$i - (\"|%%#01.o| |%%02.o| |%%-03.o| |%%1.o| |%%2.o| |%%-.1o| |%%-.2o|\n\", 0, 0, 0, 0, 0, 0, 0) : ${NC}" $i 
test "$i - (\"|%%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.8o| : %%%%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.8o\n\", nbr) : ${NC}" $i 
test "$i - (\"|%%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.6o| : %%%%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.6o\n\", nbr) : ${NC}" $i 
test "$i - (\"|%%+- #0 - 0 + -0# - + - 0-+ - #+- 7o| : %%%%+- #0 - 0 + -0# - + - 0-+ - #+- 7o\n\", nbr) : ${NC}" $i 
printf "\n\n${BLUE}[Z - MIX (good test for leaks)]${NC}\n" && error=0
test "$i - (\"012%%c3456%%s789%%%%012%%i3456%%x789%%u012%%p456789%%e012%%f3456789%%g0123456789%%o01%%lc3456%%ls789%%n012%%c3456%%s789%%%%012%%i3456%%x789%%u012%%p456789%%e012%%f3456789%%g0123456789%%o01%%lc3456%%ls789%%n\", 'A', \"TEST\", 42, 0x42, 42, (void*)42, 4.2, -4.2, 4.101, 042, 35211, y, &z, 'A', \"TEST\", -21, -0x21, 0, (void*)0x101, 4.2, -4.2, 4.101, 042, 35211, y, &z) : ${NC}" $i 
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"
