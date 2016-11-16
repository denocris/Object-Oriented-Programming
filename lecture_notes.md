# C++

to commpile: clang++ main.cc (try also g++, it will work!)

it produce a.out: run it with ./a.out and the echo $?

Let print it on the screen. We need to import #include <iostream>

strong typing (variable can change type, python) and static typing (one varible can only have one type, C, C++)



int: 4 byte
unsigned int: 

double: 8 byte (64 bit floating point - 16 decimal digits)

float: 4 byte (6 decimal digits)

long double: 80 bit


If I declare variable inside {} (thing about for loops, if or while...), their will live just inside!


int a = 3;
int b = a++

the result is: a=4, b=3 (assignement first than increment)

int a = 3;
int b = ++a;

the result is: a=4, b=4 (assignement later than the increment)


clang++ -std=c++11 (in order to compile for C++ 11)



Compile with header

clang++ -std=c++11 -c main_read_vect2D.cc
clang++ -std=c++11 -c vect2D.cc
clang++ -std=c++11 vect2D.o main_read_vect2D.o
