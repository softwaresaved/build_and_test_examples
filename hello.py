try:
    mode=int(input("Give me a number! "))
    print("That number was: "),  mode, "\n"
except ValueError:
    print("That was string without a numeral\n")
except NameError:
    print("That was neither a numeral or a string\n")
#except SyntaxError:
    #print("Syntax Error:  Possibly an incorrectly formatted string\n")