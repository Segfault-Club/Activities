#!/bin/bash
# ATTENTION! THIS FILE MUST NOT BE ALTERED
# ALTERING THIS WILL DISCLASSIFY YOU FROM THE COMPETITION
# WHEN SUBBMITING YOUR SOLUTION, RUN THIS IN THE FOLLOWING WAY:
# 	b2sum ./test.sh && ./test.sh
# you may have to install b2sum, this script is made for unix-compatible shells

# ./main returns EXIT_SUCCESS if you pass, EXIT_FAILURE otherwise
if ./exploit | ./main; then
	b2sum ./main # Making sure the binary was not altered
else
	echo You did not pass!
fi
