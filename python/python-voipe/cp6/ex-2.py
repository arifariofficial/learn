""" 
In the second exercise the idea is to try out parameters between functions. Create a program which has the main function and a subfunction "poweroftwo". The main function prompts the user for a number "Give a number: " and then this number is sent to the subfunction as a parameter. The subfunction calculates the n:th power of 2 of the number (if given 3, 2*2*2; if 5, 2*2*2*2*2 and so on, 2**[number]) and prints it out with the message "The result was [result]". When working correctly, the program prints:

>>> 
Give a number: 5
The result is 32
>>> 
Or possibly

>>> 
Give a number: 8
The result is 256
>>> 
Also remember to add this main function call to the main level:

if __name__ == "__main__":
    main()

"""


def main():
    number = int(input("Give a number: "))
    print("The result is", poweroftwo(number))


def poweroftwo(n):
    return 2**n


if __name__ == "__main__":
    main()
