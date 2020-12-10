def main():
    print('========connect 4 game========')

    def board(boards):
        for row in boards:
            print(row)

    def player_1(users):
        # player1
        caracter1 = 'X'
        if users == users and boards[-1][users - 1] != 'X' and boards[-1][users - 1] != 'O':
            boards[-1][users - 1] = caracter1
            board(boards)
        elif users == users and boards[-2][users - 1] != 'X' and boards[-2][users - 1] != 'O':
            boards[-2][users - 1] = caracter1
            board(boards)
        elif users == users and boards[-3][users - 1] != 'X' and boards[-3][users - 1] != 'O':
            boards[-3][users - 1] = caracter1
            board(boards)
        elif users == users and boards[-4][users - 1] != 'X' and boards[-4][users - 1] != 'O':
            boards[-4][users - 1] = caracter1
            board(boards)
        elif users == users and boards[-5][users - 1] != 'X' and boards[-5][users - 1] != 'O':
            boards[-5][users - 1] = caracter1
            board(boards)
        elif users == users and boards[-6][users - 1] != 'X' and boards[-6][users - 1] != 'O':
            boards[-6][users - 1] = caracter1
            board(boards)
        else:
            print('this lines is full')

    def player_2(users):
        # player2
        caracter2 = 'O'
        if users == users and boards[-1][users - 1] != 'X' and boards[-1][users - 1] != 'O':
            boards[-1][users - 1] = caracter2
            board(boards)
        elif users == users and boards[-2][users - 1] != 'X' and boards[-2][users - 1] != 'O':
            boards[-2][users - 1] = caracter2
            board(boards)
        elif users == users and boards[-3][users - 1] != 'X' and boards[-3][users - 1] != 'O':
            boards[-3][users - 1] = caracter2
            board(boards)
        elif users == users and boards[-4][users - 1] != 'X' and boards[-4][users - 1] != 'O':
            boards[-4][users - 1] = caracter2
            board(boards)
        elif users == users and boards[-5][users - 1] != 'X' and boards[-5][users - 1] != 'O':
            boards[-5][users - 1] = caracter2
            board(boards)
        elif users == users and boards[-6][users - 1] != 'X' and boards[-6][users - 1] != 'O':
            boards[-6][users - 1] = caracter2
            board(boards)
        else:
            print('this lines is full')

    def winner(wins):
        if wins == 'X':
            print('winner is player1')
            restart()
        else:
            print('winner is player2')
            restart()

    def restart():
        reset = input('play again ?(y/n) : ')
        try:
            if reset.lower() == 'y':
                main()
            elif reset.lower() == 'n':
                exit()
            elif reset.isdigit():
                raise ValueError
            else:
                print("wrong choice please enter again")
                restart()
        except ValueError:
            print("please enter y or n ,not number")
            restart()

    def check_winner(win):
        # horizontal win
        if boards[5][0] == win and boards[5][1] == win and boards[5][2] == win and boards[5][3] == win or boards[5][
            1] == win and boards[5][2] == win and boards[5][3] == win and boards[5][4] == win or boards[5][2] == win and \
                boards[5][3] == win and boards[5][4] == win and boards[5][5] == win:
            winner(win)
        elif boards[4][0] == win and boards[4][1] == win and boards[4][2] == win and boards[4][3] == win or boards[4][
            1] == win and boards[4][2] == win and boards[4][3] == win and boards[4][4] == win or boards[4][2] == win and \
                boards[4][3] == win and boards[4][4] == win and boards[4][5] == win:
            winner(win)
        elif boards[3][0] == win and boards[3][1] == win and boards[3][2] == win and boards[3][3] == win or boards[3][
            1] == win and boards[3][2] == win and boards[3][3] == win and boards[3][4] == win or boards[3][2] == win and \
                boards[3][3] == win and boards[3][4] == win and boards[3][5] == win:
            winner(win)
        elif boards[2][0] == win and boards[2][1] == win and boards[2][2] == win and boards[2][3] == win or boards[2][
            1] == win and boards[2][2] == win and boards[2][3] == win and boards[2][4] == win or boards[2][2] == win and \
                boards[2][3] == win and boards[2][4] == win and boards[2][5] == win:
            winner(win)
        elif boards[1][0] == win and boards[1][1] == win and boards[1][2] == win and boards[1][3] == win or boards[1][
            1] == win and boards[1][2] == win and boards[1][3] == win and boards[1][4] == win or boards[1][2] == win and \
                boards[1][3] == win and boards[1][4] == win and boards[1][5] == win:
            winner(win)
        elif boards[0][0] == win and boards[0][1] == win and boards[0][2] == win and boards[0][3] == win or boards[0][
            1] == win and boards[0][2] == win and boards[0][3] == win and boards[0][4] == win or boards[0][2] == win and \
                boards[0][3] == win and boards[0][4] == win and boards[0][5] == win:
            winner(win)
        # vertical win
        elif boards[-1][0] == win and boards[-2][0] == win and boards[-3][0] == win and boards[-4][0] == win or\
                boards[-2][0] == win and boards[-3][0] == win and boards[-4][0] == win and boards[-5][0] == win or\
                boards[-3][0] == win and boards[-4][0] == win and boards[-5][0] == win and boards[-6][0] == win:
            winner(win)
        elif boards[-1][1] == win and boards[-2][1] == win and boards[-3][1] == win and boards[-4][1] == win or\
                boards[-2][1] == win and boards[-3][1] == win and boards[-4][1] == win and boards[-5][1] == win or\
                boards[-3][1] == win and boards[-4][1] == win and boards[-5][1] == win and boards[-6][1] == win:
            winner(win)
        elif boards[-1][2] == win and boards[-2][2] == win and boards[-3][2] == win and boards[-4][2] == win or\
                boards[-2][2] == win and boards[-3][2] == win and boards[-4][2] == win and boards[-5][2] == win or\
                boards[-3][2] == win and boards[-4][2] == win and boards[-5][2] == win and boards[-6][2] == win:
            winner(win)
        elif boards[-1][3] == win and boards[-2][3] == win and boards[-3][3] == win and boards[-4][3] == win or\
                boards[-2][3] == win and boards[-3][3] == win and boards[-4][3] == win and boards[-5][3] == win or\
                boards[-3][3] == win and boards[-4][3] == win and boards[-5][3] == win and boards[-6][3] == win:
            winner(win)
        elif boards[-1][4] == win and boards[-2][4] == win and boards[-3][4] == win and boards[-4][4] == win or\
                boards[-2][4] == win and boards[-3][4] == win and boards[-4][4] == win and boards[-5][4] == win or\
                boards[-3][4] == win and boards[-4][4] == win and boards[-5][4] == win and boards[-6][4] == win:
            winner(win)
        elif boards[-1][5] == win and boards[-2][5] == win and boards[-3][5] == win and boards[-4][5] == win or\
                boards[-2][5] == win and boards[-3][5] == win and boards[-4][5] == win and boards[-5][5] == win or\
                boards[-3][5] == win and boards[-4][5] == win and boards[-5][5] == win and boards[-6][5] == win:
            winner(win)
        #diagonal win
        elif boards[-1][0] == win and boards[-2][1] == win and boards[-3][2] == win and boards[-4][3] == win or\
                boards[-2][0] == win and boards[-3][1] == win and boards[-4][2] == win and boards[-5][3] == win or\
                boards[-3][0] == win and boards[-4][1] == win and boards[-5][2] == win and boards[-6][3] == win or\
                boards[-1][1] == win and boards[-2][2] == win and boards[-3][3] == win and boards[-4][4] == win or\
                boards[-1][2] == win and boards[-2][3] == win and boards[-3][4] == win and boards[-4][5] == win or\
                boards[-2][1] == win and boards[-3][2] == win and boards[-4][3] == win and boards[-5][4] == win or\
                boards[-2][2] == win and boards[-3][3] == win and boards[-4][4] == win and boards[-5][5] == win or\
                boards[-3][1] == win and boards[-4][2] == win and boards[-5][3] == win and boards[-6][4] == win or\
                boards[-3][2] == win and boards[-4][3] == win and boards[-5][4] == win and boards[-6][5] == win:
            winner(win)
        elif boards[-1][5] == win and boards[-2][4] == win and boards[-3][3] == win and boards[-4][2] == win or\
                boards[-2][5] == win and boards[-3][4] == win and boards[-4][3] == win and boards[-5][2] == win or\
                boards[-3][5] == win and boards[-4][4] == win and boards[-5][3] == win and boards[-6][2] == win or\
                boards[-1][4] == win and boards[-2][3] == win and boards[-3][2] == win and boards[-4][1] == win or\
                boards[-1][3] == win and boards[-2][2] == win and boards[-3][1] == win and boards[-4][0] == win or\
                boards[-2][4] == win and boards[-3][3] == win and boards[-4][2] == win and boards[-5][1] == win or\
                boards[-2][3] == win and boards[-3][2] == win and boards[-4][1] == win and boards[-5][0] == win or\
                boards[-3][4] == win and boards[-4][3] == win and boards[-5][2] == win and boards[-6][1] == win or\
                boards[-3][3] == win and boards[-4][2] == win and boards[-5][1] == win and boards[-6][0] == win:
            winner(win)


    def player_input():
        while True:
            try:
                board(boards)
                input_ = input('player 1(X): ')
                if input_.isalpha():
                    raise ValueError
                elif int(input_) <= 0 or int(input_) > 6:
                    raise IndexError
                player_1(int(input_))
                check_winner('X')
                board(boards)
                input_2 = input('player 2(O): ')
                if input_2.isalpha():
                    raise ValueError
                elif int(input_2) <= 0 or int(input_2) > 6:
                    raise IndexError
                player_2(int(input_2))
                check_winner('O')
            except ValueError as e:
                print("please enter number")
                continue
            except IndexError:
                print('wrong number')
                continue
    boards = [['1', '2', '3', '4', '5', '6'],#0
              [' ', ' ', ' ', ' ', ' ', ' '],#1
              [' ', ' ', ' ', ' ', ' ', ' '],#2
              [' ', ' ', ' ', ' ', ' ', ' '],#3
              [' ', ' ', ' ', ' ', ' ', ' '],#4
              [' ', ' ', ' ', ' ', ' ', ' ']]#5

    player_input()
main()

