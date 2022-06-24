# My-mastermind
Compile with:  gcc demo.c -o mind -g -Wall -Wextra -Werror -O0 -g3 -fsanitize=address --pedantic

then you can test like:
./mind -c code -t attempts
./mind -t attempts -c code
./mind                          
in this case secret code will be generated randomly, and attempts equal to 10
./mind -t attempts
in this case secret code will be generated randomly
./mind -c code 
in this case attempts equal to 10 
