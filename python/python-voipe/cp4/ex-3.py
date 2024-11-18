""" 
The third progam tests a for-iteration. In this program, build a calculator, which asks the user for a number, and calculates the sum of all positive numbers from 0 to the usergiven input. If the user gives the number 4, the program calculates the sum 0+1+2+3, if 7, the calculation is 0+1+2+3+4+5+6. Finally, the program produces an answer with the printout "The sum was:" and an answer.

When working correctly, the program prints something like this:

>>> 
Give a number: 3
The sum was: 3
>>> 

Give a number: 5
The sum was: 10
>>> 
Keep in mind, that with the for in range-approach, there is always a variable which knows the current round number. Also, in this exercise it is allowed to assume that the user does not give faulty inputs such as letters or empty lines.

"""

num = int(input("Give a number: "))
sum = 0

for i in range(0, num):
    sum += i

print(f"The sum was: {sum}")
