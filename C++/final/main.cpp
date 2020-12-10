#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#include <sstream>
#include <filesystem>
#include "helper.h"
using namespace std;
class List_base
{
private:
    const string common_use[7] = {
        "\nYour choice: ",
        "index.txt",
        "Invalid choice. Please try again.",
        "Unrecognized format. Please try again.",
        "No text entered. Please try again.",
        "Invalid playlist number. Please try again.",
        "Select ",
    };

protected:
    const string *choice = &common_use[0],
                 *index = &common_use[1],
                 *invalid = &common_use[2],
                 *format_error = &common_use[3],
                 *NO_text = &common_use[4],
                 *invalid_num = &common_use[5],
                 *Select = &common_use[6];
    char input;
    void deletplaylist(short file_num, string file, string playlist_del)
    {
        string line_;
        vector<string> temp;
        short X = 0;
        fstream indexs(file, ios::in | ios::out);
        while (getline(indexs, line_))
        {
            X++;
            if (X != file_num)
            {
                temp.push_back(line_);
            }
        }
        indexs.close();
        ofstream files(file);
        ostream_iterator<string> output_iterator(files, "\n");
        copy(temp.begin(), temp.end(), output_iterator);
        helper::printCLR(playlist_del);
    }
    void extra_(string file, string extra)
    {
        ifstream ifile(file);
        if (ifile)
        {
            short i = 1;
            cout << *Select << extra << endl;
            while (getline(ifile, file))
            {
                cout << i << "-" << file << endl;
                i++;
            }
            ifile.close();
            return;
        }
    }
    void _menu_(string file, string menu, string extra)
    {
        cout << menu;
        extra_(file, extra);
        input = helper::inputc(*choice);
    }
};
class Playlist : List_base
{
private:
    string menu = "\' Menu:\n",
           play = "Playlist \'",
           play_choice = "\na. Add track(s) to playlist\nd. Delete this playlist\nx. Exit to main menu\n\n",
           track_choice = "d. Delete this track\nx. Exit to playlist menu\n",
           track = "Track\'",
           add = "Enter a title and artist, or 'x' to exit\n",
           track_exists = "That track already exists. Please try again.",
           track_Select = "Track #\n",
           track_del = "Track deleted.\n",
           Exit_ = "Exit to playlist menu",
           exit_to_menu = "Exit to main menu\n",
           invalid_num = "Invalid track number. Please try again.";
    void track_MENU(string &file, short num, string &playin)
    {
        if (!helper::file_check(file))
        {
            helper::printCLR(invalid_num);
            return;
        }
        else
        {
            system("cls");
            string track__ = helper::search_word_bynumber(num, file);
            cout << track << track__ << "\'" << endl
                 << endl
                 << play << playin << menu << endl
                 << track_choice;
            char input3;
            while (input3 != 'x')
            {
                input3 = helper::inputc(*choice);
                switch (input3)
                {
                case 'd':
                    deletplaylist(num, file, track__);
                    helper::printCLR(track_del + Exit_);
                    return;
                    break;
                default:
                    helper::printCLR(*invalid);
                    break;
                }
            }
            helper::printCLR(Exit_);
        }

        //testing
    }

    void check_track()
    {
    }
    void make_track(string &file)
    {
        string input2;
        //testing
        while (input2 != "x")
        {
            input2 = helper::input(add);
            if (!helper::format_check(input2))
            {
                helper::printl(*format_error);
                system("cls");
            }
            else
            {
                input2 = helper::string_format(input2);
                helper::file_app_fix(file, input2, track_exists);
            }
        }
    }
    void in_out(short file_num, string file, string play, string &play_file)
    {
        switch (input)
        {
        case '0':
            helper::printCLR(invalid_num);
            break;
        case '1' ... '9':
            track_MENU(play_file, input - 48, play);
            break;
        case 'a':
            make_track(play_file);
            system("cls");
            break;
        case 'd':
            deletplaylist(file_num, file, play);
            exit_to_menu = exit_to_menu + "Playlist Deleted.";
            input = 'x';
            break;
        case '\n':
            helper::printCLR(*NO_text);
            break;
        default:
            helper::printCLR(*invalid);
            break;
        }
    }

public:
    Playlist(short file_num);
};

Playlist::Playlist(short file_num)
{
    system("cls");
    string playlist_ = helper::search_word_bynumber(file_num, *index);
    string playlist_file = playlist_ + ".playlist";
    while (input != 'x')
    {
        cout << play << playlist_ << menu << play_choice;
        extra_(playlist_file, track_Select);
        input = helper::inputc(*choice);
        in_out(file_num, *index, playlist_, playlist_file);
    }
    helper::printCLR(exit_to_menu);
}

class ListIndex : List_base
{
private:
    const string MENU = "Main Menu\n\nc. Create a playlist\nx. Exit program\n\n",
                 exit_message = "Farewell",
                 play = "Playlist #",
                 new_playlist = "Please enter a name for your new playlist\n",
                 already_exists = "Sorry. That Playlist already exists. Please try again.\n";
    void make_file()
    {
        string input2 = helper::trim(helper::input(new_playlist));
        if (!helper::file_check(*index) || helper::file_is_empty(*index))
        {
            helper::file_app(*index, input2);
            system("cls");
        }
        else
        {
            system("cls");
            helper::file_app_fix(*index, input2, already_exists);
        }
    }
    void in_out()
    {

        switch (input)
        {
        case '0' ... '9':
            Playlist(input - 48);
            break;
        case 'c':
            make_file();
            break;
        case 'x':
            helper::exit_program(exit_message);
            break;
        case '\n':
            helper::printCLR(*NO_text);
            break;
        default:
            helper::printCLR(*invalid);
            break;
        }
    }

public:
    ListIndex();
};

ListIndex::ListIndex()
{
    system("cls");
    while (input != 'x')
    {
        _menu_(*index, MENU, play);
        in_out();
    }
    helper::printCLR(exit_message);
}

int main()
{
    ListIndex();
    return 0;
}
