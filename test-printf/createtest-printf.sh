# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    createtest-printf.sh                             .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/25 11:48:54 by aalleman     #+#   ##    ##    #+#        #
#    Updated: 2019/12/07 17:18:51 by aalleman    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

size=`wc -l < test-printf/test-printf.c | bc`
let size=$size-3
endofmain=31
head -n 48 test-printf/testbase-printf.sh > test-printf/runtest-printf.sh
if [ $# -ge 1 ]
then
	sed -n "1,$endofmain p" test-printf/test-printf.c > test-printf/test-main.c
	sed -n "/\[$1 /,/\[[A-Z]/p" test-printf/test-printf.c >> test-printf/test-main.c
	echo "return (0);\n}" >> test-printf/test-main.c
	grep "\["$1 test-printf/test-main.c | tr -d '\t' | sed 's/\/\/ \[/printf "\\n${BLUE}\[/g' | sed 's/\]\./\]${NC}\\n"/' >> test-printf/runtest-printf.sh
	sed -n "/\[$1/,/\[[A-Z]/p" test-printf/test-main.c | grep "return" | tr -d '\t' | sed 's/%/%%/g' | sed 's/"/\\"/g' | sed 's/return(ac == 2 ? printf(.*) : ft_printf/test "$i - /' | sed 's/);/ : ${NC}" $i /' >> test-printf/runtest-printf.sh
else
	cat test-printf/test-printf.c > test-printf/test-main.c
	sed -n "$endofmain,$size p" test-printf/test-printf.c | grep -e "return" -e "\[[A-Z] " | tr -d '\t' | sed 's/%/%%/g' | sed 's/"/\\"/g' | sed 's/return(ac == 2 ? printf(.*) : ft_printf/test "$i - /' | sed 's/);/ : ${NC}" $i /' | sed 's/\/\/ \[/printf "\\n\\n${BLUE}\[/g' | sed 's/\]\./\]${NC}\\n" \&\& error=0/g' >> test-printf/runtest-printf.sh
fi

echo 'printf "\\n\\n${DARK_BLUE}Result [$success/$i]${NC}"' >> test-printf/runtest-printf.sh
