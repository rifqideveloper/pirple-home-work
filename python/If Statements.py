#test score
chemistry = 10
math = 7
english = 9

def tests():
    if chemistry >= 7 and math >= 7 and english >= 7:
        print(True)
    elif chemistry <= 7 and math <= 7 and english <= 7:
        print(False)
    else:
        print(False)
    return

tests()