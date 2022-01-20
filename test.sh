
#-----------------------------# 1 2 3

ARG="1 2 3";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="1 3 2";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

#-----------------------------# 2 1 3

ARG="2 1 3";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="2 3 1";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

#-----------------------------# 3 1 2

ARG="3 1 2";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="3 2 1"; 
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

#---------------------------# 1 2 3 4

ARG="1 2 3 4";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="1 2 4 3";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="1 3 2 4";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="1 3 4 2";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="1 4 2 3";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="1 4 3 2";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

#---------------------------# 2 1 3 4

ARG="2 1 3 4";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="2 1 4 3";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="2 3 1 4";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="2 3 4 1";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="2 4 1 3";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="2 4 3 1";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"


#---------------------------# 3 1 2 4

ARG="3 1 2 4";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="3 1 4 2";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="3 2 1 4";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="3 2 4 1";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="3 4 1 2";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="3 4 2 1";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

#---------------------------# 4 1 2 3


ARG="4 1 2 3";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="4 1 3 2";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="4 2 1 3";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="4 2 3 1";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="4 3 1 2";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"

ARG="4 3 2 1";
printf "commands    : "
./push_swap $ARG | wc -l | awk '{ print $1}'
printf "checker_Mac : "
./push_swap $ARG | ./checker_Mac $ARG
printf "checker_My  : "
./push_swap $ARG | ./checker $ARG
printf "\n"
