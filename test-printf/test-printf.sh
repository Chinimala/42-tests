BLUE='\e[96m'
sh test-printf/createtest-printf.sh $1
sh test-printf/runtest-printf.sh
printf "\n\n${BLUE}See result.log for all tests. Run \"sh test-printf/show.sh 8\" to see the 8th test.\n"
rm user_output
rm original_output
