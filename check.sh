ARG="`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`"
# ARG="`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`"

./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

#bash check.sh