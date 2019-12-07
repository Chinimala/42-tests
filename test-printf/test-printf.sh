BLUE='\e[96m'
sh test-printf/createtest-printf.sh $1
sh test-printf/runtest-printf.sh
printf "\n\n${BLUE}Cat result.log to see all tests. Run \"sh test-printf/show.sh 8\" to see the 8th test, your and the original's output. Run \"sh test-printf/test-printf.sh B\" to run only category B.\n"
