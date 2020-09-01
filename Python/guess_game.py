

from random import randint


print("please enter your name:- ")
name = input()

print("Hi " + str(name) + " please guess a number between 0 and 20 ")

secret_number = randint(0, 20)
print("debug-- secret number is :- " + str(secret_number))

for guess_counter in range(5 , 0 , -1):
    print("geuss_counter " + str(guess_counter))
    print("take a guess :- ")
    number = int(input())

    if (number < secret_number) and (guess_counter > 1):
        print("Try a higher number! ")

    elif (number > secret_number) and (guess_counter > 1):
        print("Try a lower number! ")

    else:
        # you geussed the right number'
        break


if number == secret_number:
    print(str(name) + " you guessed the right number \n")

else:
    print(str(name) + " you failed try again later! \n")







