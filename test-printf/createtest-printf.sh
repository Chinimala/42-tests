# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    createtest-printf.sh                             .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/25 11:48:54 by aalleman     #+#   ##    ##    #+#        #
#    Updated: 2019/10/28 11:00:26 by jgambard    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

size=`wc -l < test-printf/test-printf.c | bc`
let size=$size-2
head -n 34 test-printf/testbase-printf.sh > test-printf/runtest-printf.sh
sed -n "37,$size p" test-printf/test-printf.c | grep -e fct -e "\[" | tr -d '\t' | sed 's/%/%%/g' | sed 's/"/\\"/g' | sed 's/fct/test "$i - /' | sed 's/;/ : ${NC}" $i /' | sed 's/\/\/ \[/printf "\\n\\n${BLUE}\[/g' | sed 's/\]/\]${NC}\\n" \&\& error=0/g' >> test-printf/runtest-printf.sh
