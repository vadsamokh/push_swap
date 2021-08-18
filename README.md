# push_swap

**A project of School 21.**

In this project i had to make a program, that allows to sort a stack of numbers by using the following operations only:

>sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
>is only one or no elements).
>
>sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
>is only one or no elements).
>
>ss : sa and sb at the same time.
>
>pa : push a - take the first element at the top of b and put it at the top of a. Do
>nothing if b is empty.
>
>pb : push b - take the first element at the top of a and put it at the top of b. Do
>nothing if a is empty.
>
>ra : rotate a - shift up all elements of stack a by 1. The first element becomes
>the last one.
>
>rb : rotate b - shift up all elements of stack b by 1. The first element becomes
>the last one.
>
>rr : ra and rb at the same time.
>
>rra : reverse rotate a - shift down all elements of stack a by 1. The last element
>becomes the first one.

This project was inspired by [VBrazhnik's algorithm](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm).

Installation:

```
$ git clone https://github.com/vadsamokh/push_swap && cd push_swap && make
```

Launch:

```
$ ./push_swap number1 number2 number3 ...
```
