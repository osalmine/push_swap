# push_swap
Hive - push_swap, because swap_push isn’t as natural

This is the first algorithms branch project I did at Hive Helsinki.

> This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.


## Usage

After cloning the repo and going to it's folder, you can use these make commands:
* To compile:
  * `make`
* To clean .o files:
  * `make clean`
* To clean everything:
  * `make fclean`
* To fclean and compile:
  * `make re`

After compiling you have two executables, checker and push_swap.

**SEE SUBJECT FOR MORE DETAILS**

```
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```

-v flag for checker is visualizer
