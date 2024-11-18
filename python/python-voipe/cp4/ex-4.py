""" The last exercise in this chapter continues with the exercise from the last chapter, the calculator. In this exercise, expand the existing code by implementing the following new features: (A) Calculator does not automatically quit when the result is given, allowing user to do new calculations. The user has to select "6" in the menu to exit the program. (B) The calculator shows the selected numbers in the main menu by printing "Current numbers:" and the user-given input. By selecting "5" in the calculator menu, the user can change the given numbers. When implemented correctly, the program prints out following:

Calculator
Give the first number: 100
Give the second number: 25
(1) +
(2) -
(3) *
(4) /
(5) Change numbers
(6) Quit
Current numbers: 100 25
Please select something (1-6): 5
Give the first number: 10
Give the second number: 30

(1) +
(2) -
(3) *
(4) /
(5) Change numbers
(6) Quit
Current numbers: 10 30
Please select something (1-6): 1
The result is: 40

(1) +
(2) -
(3) *
(4) /
(5) Change numbers
(6) Quit
Current numbers: 10 30
Please select something (1-6): 6
Thank you!
>>> 
Again, implement the program within one large while True-segment, which is terminated with break if the user selects the option "6".

"""

print("Calculator")

first_number = int(input("Give the first number: "))
second_number = int(input("Give the second number: "))
result = None  # Initialize result with None

while True:
    print("(1) +")
    print("(2) -")
    print("(3) *")
    print("(4) /")
    print("(5) Change numbers")
    print("(6) Quit")
    print("Current numbers:", first_number, second_number)
    selection = int(input("Please select something (1-6): "))

    if selection == 1:
        result = first_number + second_number
    elif selection == 2:
        result = first_number - second_number
    elif selection == 3:
        result = first_number * second_number
    elif selection == 4:
        if second_number == 0:
            continue
        result = first_number / second_number
    elif selection == 5:
        first_number = int(input("Give the first number: "))
        second_number = int(input("Give the second number: "))
        continue
    elif selection == 6:
        print("Thank you!")
        break
    else:
        print("Invalid selection.")
        continue

    print("The result is: ", result)
