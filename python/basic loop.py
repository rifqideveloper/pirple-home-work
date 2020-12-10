nomber = 0

while(nomber<=99):
    nomber = nomber + 1
    if nomber % 3 == 0 and nomber % 5 == 0:
        print('FizzBuzz')
    elif nomber % 3 == 0:
        print('Fizz')
    elif nomber % 5 == 0:
        print('Buzz')
    elif nomber > 1:
        for i in range(2, nomber):
            if (nomber % i) == 0:
                print('prime')
    else:
        print(nomber)

print(nomber)