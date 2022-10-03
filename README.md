# Push_Swap

Sort a random list of integers on two stacks, with a limited set of instructions, using the lowest possible number of actions.

## The Project

Create the programs `push_swap`.

This program takes a list of integers as input from command line argument,
and calculates the instructions to sort these integers
and displays those instructions on stdout or, in case of an error,
`Error\n` on stderr.

I have 2 stacks named **a** and **b**.

At the beginning:
-  The stack **a** contains a random amount of numbers that cannot be duplicated.
-  The stack **b** is empty.

Using the combinations of instructions listed below,
my goal is that stack **b** is empty and all numbers must be in stack **a**,
sorted in ascending order.

- `sa` : swap a - swap the first 2 elements at the top of stack a.
  Do nothing if there is only one or no elements).
- `sb` : swap b - swap the first 2 elements at the top of stack b.
  Do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Donothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1.
  The first element becomes the last one.
- `rb` : rotate b - shift up all elements of stack b by 1.
The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1.
  The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1.
  The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

[This page](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
illustrates what each instructions do.

### misc
- I can use `read`, `write`, `malloc`, `free`, and `exit`,
  and other normal libc functions are forbidden.
- In no way can it quit abruptly.
  (segmentation fault, bus error, double free, etc).
- All heap allocated memory space must be properly freed when necessary.
  No leaks will be tolerated.
- Global variables are forbidden.
- All code must conform to the [42 Norm](https://github.com/42School/norminette).

## Usage

Clone this repository and run `make`, and make the executable file `push_swap`.

This program is used as follows :
```bash
./push_swap 1 2 3 4 5 6
```

In case of large numbers (say 500),
[this repository](https://github.com/nafuka11/push_swap_tester)
is useful.

## Approach

This is what this whole program does in the sorting process.

![](images/push_swap.gif)
credit goes to [Ilya Kashnitskiy](https://github.com/elijahkash/push_swap_gui) for this gif

This program is something like the combination of quicksort and mergesort.
The whole algorithm consists of two main stages:
1. Pushing numbers from a to b.
     - During this stage, this algorithm sort the number raughly in descending order.
2. Pushing them back to a.
     - During this stage, sort numbers in exactly ascending order.

## Author

[Twitter](https://twitter.com/t76_1205)

## Licence

[MIT](./LICENSE)