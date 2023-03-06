import random
a = random.randint(1, 9)
while True:
    n = input("Enter a number or 'exit': ")
    if n == str(a):
        break
    elif n == "exit":
        print("Program ending.")
        break
    elif n > str(a):
        print("Your number is bigger than random number")
    else:
        print("Your number is less than random number")