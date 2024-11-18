""" 
In the third program, we take a look into the classification of file contents. In the same directory with the source code is a file "strings.txt", which has random strings in several lines. The lines can be divided into two groups: those which only have letters (a-z, A-Z) and numbers (0-9), and those which also have random special characters (?,&,@, $ ...).

Create a program which reads all of the lines from the file and tests the lines. If the line has only letters and/or numbers, the program prints "[line] was ok.". If the line has special characters, the program should print "[line] was invalid.". When the program works, it prints out something like this:

>>> 
5345m345ö34l was ok.
no2no123non4 was ok.
noq234n5ioqw#% was invalid.
%#""SGMSGSER was invalid.
doghdp5234 was ok.
sg,dermoepm was invalid.
43453-frgsd was invalid.
hsth())) was invalid.
bmepm35wae was ok.
vmopaem2234+0+ was invalid.
gsdm12313 was ok.
bbrbwb55be3"?"#? was invalid.
"?"#%#"!%#"&"?%%"?#?#"?" was invalid.
retrte#%#?% was invalid.
abcdefghijklmnopqrstuvxy was ok.
>>> 
It is advisable to read the lines one at a time, test them with the isalmun() string test and go on from there. Also remember that the strings may also end in a line break (\n), which is allowed, but fails the .isalnum() test if not sliced away.

"""

with open("strings.txt", "r") as file:
    for line in file:
        line = line.rstrip()
        if line.isalnum():
            print(f"{line} was ok.")
        else:
            print(f"{line} was invalid.")
