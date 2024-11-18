""" 
The second exercise tries to elaborates on the first task. The idea is to create an iteration where the user is able to define when the loop ends by testing the input which the user gave.

Create a program which, for every loop, prompts the user for input, and then prints it on the screen. If the user inputs the string "quit", the program prints "Bye bye!" and shuts down. When the program is working correctly it should print out something like this:

>>> 
Write something: What?
What?
Write something: Fight the power.
Fight the power.
Write something: quit
Bye bye!
>>> 
It is probably a good idea to implement the entire program within one "while True" code block, and define the ending criteria so that the program uses a selection criteria and break command.

"""

while True:
    user_input = input("Write something: ")
    if user_input != "quit":
        print(user_input)
    else:
        print("Bye bye!")
        break
