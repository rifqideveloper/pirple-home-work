import os
def AskFilename():
    A = ('A) Read the file')
    B = ('B) Delete the file and start over')
    C = ('C) Append the file')
    D = ('D) Replace a single line')
    usersinput = input('please enter file name: ')
    if os.path.exists(usersinput) and os.path.isfile(usersinput):
        print('',A,'\n',B,'\n',C,'\n',D)
        answer = usersinput
        file = input('what you want to do with the file: ')
        if file == A or file.lower() == 'Read the file' or file.lower() == 'read' or file.lower() == 'a':
            file_read = open(answer, 'r')
            fr = file_read.read()
            print(fr)
            file_read.close()
        elif file == B or file.lower() == 'Delete the file and start over' or file.lower() == 'Delete' or file.lower() == 'b':
            os.remove(answer)
            print('file has been Deleted')
            AskFilename()
        elif file == C or file.lower() == 'Append the file' or file.lower() == 'Append' or file.lower() == 'c':
            fa = open(answer,'a')
            Append_file = input('please enter a word:\n')
            fa.write(Append_file)
            fa.close()
            print('file has been Append')
        elif file == D or file.lower() == 'Replace a single line' or file.lower() == 'Replace' or file.lower() == 'd':
            line_counter = 1
            line_array = []
            with open(answer, "r") as file:
                for line in file:
                    print(line_counter, " ", line)
                    line_counter += 1
                    line_array.append(line)
            line_num = input('\nEnter the line number you wish to replace:\n')
            line_num = int(line_num)
            if line_num <= len(line_array):
                txt = input('Enter the new line:\n')
                line_array[line_num - 1] = txt
                paragraph = ("\n").join(line_array)
                writeToFile(answer, paragraph)
                print('\nFile content replaced!')
            else:
                print('Sorry, invalid line number :(')

    else:
        filenotfound()
def writeToFile(file_path, content):
    file = open(file_path, "w")
    file.write(content)
    file.close()

def filenotfound():
        make_file = str(input('You want to create a new file(yes/no): '))
        if make_file.lower() == 'yes' or make_file.lower() == 'y':
            create_file = str(input('what a name of new file: '))
            fh = open(create_file,'w')
            new_file = str(input('please enter a word:\n'))
            fh.write(new_file)
            fh.close()
            print('new file has been created','(',create_file,')')
        elif make_file.lower() == 'no' or make_file.lower() == 'n':
            print('do you whan to exists(e)')
            print('do you want to try searching for the file again(s)')
            goback = input('your answer: ')
            if goback.lower() == 'e'or goback.lower() == 'exists' or goback.lower() == 'exist':
                print('====exist program====')
            elif goback.lower() == 's' or goback.lower() == 'searching' or goback.lower() == 'search':
                AskFilename()
        else:
            print('your answer is wrong please enter right answer :(')
            filenotfound()

AskFilename()
