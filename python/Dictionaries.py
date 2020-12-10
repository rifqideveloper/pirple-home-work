myfavoritesong = {"song": "Got to Be There",
                   "Artist": "Michael Jackson",
                   "YearReleased": "1972",
                   "Genre": "pop",
                   "label": "Motown Records",
                   "producer": "Hal Davis and Willie Hutch",
                   "DurationInSeconds": "2145",
                   }


def favoritesong():
    for key in myfavoritesong:
        print(key, ':',myfavoritesong[key])

def guess_song():
    key = input('guess what name of the key:')
    value = input('guess what name of the value:')
    if key and value:
        key = key.lower()
        value = value.lower()
        if key in myfavoritesong and myfavoritesong[key].lower() == value:
            print('your guoss is right')
            favoritesong()
            return True
        else:
            print('your guoss is wrong')
            wrong = input('you whan to try again(y/n): ')
            if wrong.lower() == 'y':
                guess_song()
            elif wrong.lower() == 'n':
                print('see you again')
            else:
                print('your typing is error')
                print('see you again')
    return False
guess_song()





