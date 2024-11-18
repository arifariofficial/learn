""" 
The third exercise tests out the default values of parameters. Create a program which has a main function and a subfunction called tester. The main function prompts user for an input "Write something (quit ends): " and sends this input to the subfunction as a parameter.

Define the subfunction tester so that it has one parameter called "givenstring", which has the default value "Too short". If the user input is less than 10 characters, the program uses the default value and if 10 or more, it prints the usergiven input. If the user inputs "quit", the program is terminated. When working correctly, the program will print out something like this:

>>> 
Write something (quit ends): what?
Too short
Write something (quit ends): What do you mean?
What do you mean?
Write something (quit ends): Ok thats it
Ok thats it
Write something (quit ends): I am out of here
I am out of here
Write something (quit ends): quit
>>> 
The easiest way of testing the length of a string is by using the function len().

"""


def main():
    while True:
        user_input = input("Write something (quit ends): ")
        if user_input == "quit":
            break
        tester(user_input)


def tester(user_input="Too short"):
    if len(user_input) >= 10:
        print(user_input)
    else:
        print("Too short")


if __name__ == "__main__":
    main()
