import random
from getpass import getpass
from threading import Thread

from hangword import word_list


def main():
    def welcome():
        print('=' * 12, 'python in easy', '=' * 12)
        print('-' * 15, 'HANGMAN', '-' * 16, '\ndibuiat oleh/made by: Rifqi Nugraha\n')

    def check(w):
        guess_wrong = []
        word_completion = ["_"] * len(w)
        if w.isalpha() != True:
            print("you only can put alphabet")
            friend()
        tries = 6
        print("Hangman start")
        display(tries)
        print('guess word below')

        def add_letter():
            for i in word_completion:
                print(i, ' ', end="")
            print()

        add_letter()
        while True:
            if '_' not in word_completion:
                print("You guessed it!")
                print("""
               ___________
               |         |
               hurry     |
               \\O/       |
                |        |
                |        |
               / \\       |
              __________/|\\""")
                print("I picked", w)
                print("player 2 win the game")
                break
            guess = input('please enter your guess here:').upper()
            if guess in w:
                index = 0
                for i in w:
                    if i == guess.upper():
                        word_completion[index] = guess
                    index += 1
                display(tries)
                add_letter()
            elif guess not in w:
                tries -= 1
                if guess in guess_wrong:
                    print("You already guessed", guess, ' try another guess')
                    display(tries)
                    add_letter()
                else:
                    print(guess, "is not in player 1 word")
                    guess_wrong.append(guess)
                    display(tries)
                    add_letter()
            if tries == 0:
                print("player 2 can\'t guess the word")
                print('player 1 word is', w)
                print("player 1 win the game")
                break

    def friend():
        word = getpass("enter word here:").upper()
        check(word)

    def AI():
        word = random.choice(word_list)
        check(word)

    def game_play():
        print('with whom you play:')
        print(' (1)multyplayer with friend\n', '(2)multiplayer with AI(Robot)\n')
        inputs = int(input('your answer: '))
        if inputs == 1:
            friend()
        elif inputs == 2:
            AI()
        else:
            print("your answer is wrong")
            game_play()

    def display(stage=0):
        stages = [
            # stage0
            """
               ___________
               |  DEAD   |
               O         |
              /|\\        |
               |         |
              / \\        |
                         |
              __________/|\\""",
            # stage1
            """
         ___________
         |         |
         O         |
        /|\\        |
         |         |
        /          |
                   |
        __________/|\\""",
            # stage2
            """
         ___________
         |         |
         O         |
        /|\\        |
         |         |
                   |
                   |
        __________/|\\""",
            # stage3
            """
         ___________
         |         |
         O         |
        /|\\        |
                   |
                   |
                   |
        __________/|\\""",
            # stage4
            """
               ___________
               |         |
               O         |
              /|         |
                         |
                         |
                         |
              __________/|\\""",
            # stage5
            """
               ___________
               |         |
               O         |
              /          |
                         |
                         |
                         |
              __________/|\\""",
            # stage6
            """
               ___________
               |         |
               O         |
                         |
                         |
                         |
                         |
              __________/|\\"""

        ]
        print(stages[stage])

    t1 = Thread(target=welcome)
    t2 = Thread(target=display)
    t3 = Thread(target=game_play)
    t1.start()
    t1.join()
    t2.start()
    t3.start()
    t2.join()
    t3.join()


if __name__ == "__main__":
    main()
