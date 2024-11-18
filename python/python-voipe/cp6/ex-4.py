""" 
The last exercise in this chapter extends the previous exercise, but it is also possible to make it completely independently. Modify the function tester so that, besides testing if the length of the given string is more than ten characters, it also tests if there is the character "X" (capital X) in the given string. If the string is longer than 10 characters and it has X in it, the tester subfunction returns a value True to the main function, otherwise False.

If the subfunction returns True to the main function, the program prints "X spotted!". As earlier, if the user inputs "quit", the program terminates. When working correctly, the program prints something like this:

>>> 
Write something (quit ends): Hello
Too short
Write something (quit ends): Ok a bit longer then?
Ok a bit longer then?
Write something (quit ends): Is Xavier here?
Is Xavier here?
X spotted!
Write something (quit ends): OMG
Too short
Write something (quit ends): quit
>>> 

"""


def main():
    while True:
        user_input = input("Write something (quit ends): ").strip()
        if user_input == "quit":
            break
        if len(user_input) < 10:
            print("Too short")
        else:
            print(user_input)
            if tester(user_input):
                print("X spotted!")


def tester(user_input):
    return "X" in user_input


if __name__ == "__main__":
    main()
