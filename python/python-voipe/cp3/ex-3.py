"""
The third exercise is to create a conditional structure which prints a line depending on the given selection. The program asks a number between 1 and 3, and based on the number prints the following: 1 prints "You selected one.", 2 prints "You selected two." and 3 prints "You selected three.", like this:

Select a number (1-3): 1
You selected one.

"""

num = int(input("Select a number (1-3): "))

if num == 1:
    print("You slected one.")
elif num == 2:
    print("You slected two.")
elif num == 3:
    print("You slected three.")