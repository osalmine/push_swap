# push_swap
Because swap_push isn’t as natural

> This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

This is the first algorithms branch project I did at Hive Helsinki.

Grade:

[![osalmine's Push_swap Score](https://badge42.vercel.app/api/v2/cl2gijtz7003009mofz5pnp5t/project/1778078)](https://github.com/JaeSeoKim/badge42)

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

After compiling you have two executables: `checker` and `push_swap`.

Run `./checker -h` to see the usage.

A handy script to use:

```
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```

where it suffles numbers from 1 to 50 into a random order.

**SEE [SUBJECT](push_swap.en.pdf) FOR MORE DETAILS**

### Bonuses

These bonuses are for the checker program:

* `-v` flag: toggle visualizer. Works with other flags, but only with up to 80 numbers as the schools iMac's screen couldn't fit more lines.
* `-n` flag: see the number of moves. Works with other flags.
* `-h` flag: help.

## How it works

I made two algorithms for the project. One for 5 numbers and less in the stack and one for everything else. The subject was strict with the number of moves allowed for five numbers, so I made a separate algorith for that.

I utilize a modified version of insert sort:

1. Put all except the smallest, biggest and the last remaining number to B stack, and sort the three numbers on the A stack.
2. Calculate the least number of moves to get some number from the B stack to the A stack in to the right position. A right position for a number is a place where the numbers on top of it are smaller and the numbers below it are bigger. This way eventually all numbers are sorted.
  * The algorithm calculates the number of moves to rotate the A stack so the number inspected can be placed from the B stack (e.g. is it better to ra or rra and how many times)
  * It also calculates the same for B stack.
  * It takes into account that it can combine commands (ra + rb = rr , rra + rrb = rrr). This way ra, ra, ra, rrb, rrb, rrb costs 6 moves but ra, ra, ra, ra, rb, rb, rb, rb costs 4 moves as the commands can be combined (rr, rr, rr, rr).
3. Rotate the stacks accordingly and put the number to A stack.
4. Repeat until B stack is empty
5. Either use ra or rra to get the A stack's largest number to the bottom, depending on where that number is.
6. At this point push_swap has placed all the commands into a linked list. Now it will go through that list and combine the commands that it can and print out the list.

If checker program is used, it will take in the commands and depending on the options used, it will execute the commands on the stacks and output OK or KO after the commands have finished.

**My program passes the evaluations benchmarks as follows:**

- With 5 numbers it solves the stack in 10 or less moves every time (minimum required is in 12)
- With 100 numbers it solves the stack in under 700 moves every time (to get full points, it has to go under 700)
- With 500 numbers, it solves the stack in under 5500 moves except around 5-10 times in 1000 tries (to get full points, it has to go under 5500, but mine was close enough to get full points)
