# hanoi of Tower

###### C implementation of the Hanoi Tower challenge.
####
#### Createde By

##### Alexandre Jastrow da Cruz
#

Objective: solve the tower of hanoi challenge using only the C language and stacks created by the student.

[pdf with description of the challenge](https://github.com/alexandrejastrow/hanoiTower/blob/master/ED_Trab2.pdf)
#
#### Image demonstration
![image demonstration](https://github.com/alexandrejastrow/hanoiTower/blob/master/img/Tower_of_Hanoi.jpeg)


# Compilation method in gcc.

gcc -Wall -pedantic -o main main.c stack.c tower.c

# execution: 

./main 30

#### 30 = number of discs

## using the command:

./main 10 -v

#### initial configurations, all movements made between stacks and the final settings.

#
# results on my computer:

 Number of disks     Real time
 3                   0m 0.000s
 4                   0m 0.000s
 5                   0m 0.000s
 6                   0m 0.000s
 7                   0m 0.000s
 8                   0m 0.000s
 9                   0m 0.000s
 10                  0m 0.000s
 11                  0m 0.000s
 12                  0m 0.000s
 13                  0m 0.000s
 14                  0m 0.001s
 15                  0m 0.003s
 16                  0m 0.005s
 17                  0m 0.011s
 18                  0m 0.023s
 19                  0m 0.054s
 20                  0m 0.096s
 21                  0m 0.188s
 22                  0m 0.405s
 23                  0m 0.803s
 24                  0m 1.560s
 25                  0m 3.015s
 26                  0m 6.289s
 27                  0m 12.456s
 28                  0m 23.978s
 29                  0m 47.589s
 30                  1m 39.030s
 31                  3m 19.978s
 32                  6m 37.111s
 33                  13m 16.998s
