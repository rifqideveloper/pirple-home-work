
def playingboard(rows, columns):
    if type(rows) != int or type(columns) != int:
        return False
    if rows <= 1 or columns <= 1:
        return False

    endchars = ''
    for row in range(rows):
        if row % 2 == 0:
            for column in range(0, columns):
                if column % 2 == 0:
                    if column != columns - 1:
                        print(' ', end=endchars)
                    else:
                        print(' ')
                else:
                    print('|', end=endchars)

            #print(' | | ')
        else:
            for column in range(0, columns):
                endChar = ""
                if column == columns - 1:
                    endChar = "\n"
                print("-", end=endChar)
    print('')
    return True

def playingBoardCreated(rows, columns):
    if (playingboard(rows, columns)):
        print('this is your playing board.')
    else:
        print('Eror No playing board for you.')


playingBoardCreated(5,5)
