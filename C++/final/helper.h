#pragma once
#include <bitset>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <fstream>

#include <filesystem>
using namespace std;
namespace helper
{

    bool file_is_empty(string file)
    {
        ifstream pFile(file);
        return pFile.peek() == std::ifstream::traits_type::eof();
    }
    short str_to_int(string str)
    {
        return stoi(str);
    }
    int coun_word(string file)
    {
        ifstream fin(file); //opening text file
        int word = 0;       //will not count first word so initial value is 1
        char ch;
        fin.seekg(0, ios::beg); //bring position of file pointer to begining of file

        while (fin)
        {
            fin.get(ch);
            if (ch == ' ' || ch == '\n')
                word++;
        }
        return word;
    }
    int coun_char(string file, char character)
    {
        ifstream fin(file); //opening text file
        int word = 0;       //will not count first word so initial value is 1
        char ch;
        fin.seekg(0, ios::beg); //bring position of file pointer to begining of file

        while (fin)
        {
            fin.get(ch);
            if (ch == character)
            {
                word++;
            }
        }
        return word;
    }
    string input(string a)
    {
        cout << a;
        getline(cin, a);
        return a;
    }
    string input()
    {
        string a;
        getline(cin, a);
        return a;
    }
    char inputc(string A)
    {
        char B;
        cout<<A;
        cin.get(B);
        cin.clear();
        cin.ignore(256, '\n');
        return B;
    }
    char inputc()
    {
        return cin.get();
    }
    void printl(int a)
    {
        cout << a << endl;
    }
    void printl(string a, string b = "\n")
    {
        cout << a << b;
    }
    void printCLR(string A, string B = "\n")
    {
        system("cls");
        cout << A << B;
    }
    void printl(string a, string b, string c, string d)
    {
        cout << a << b << c << d;
    }
    void printl(char a)
    {
        cout << a << endl;
    }
    void exit_program(string A)
    {
        printCLR(A);
        exit(0);
    }
    string printfile(string file, short number)
    {
        fstream files(file, ios::in | ios::out);
        string line;
        string retval;
        short num = 1;
        while (getline(files, line))
        {
            if (num == number)
            {
                retval = line;
            }
        }
        return retval;
    }
    auto trim(string input)
    {

        for (short i = 0; i < input.length(); i++)
        {
            if (input[i] == ' ')
            {
                input[i] = '\0';
            }
        }
        return input;
    }

    bool file_check(string file)
    {
        fstream ifile;
        ifile.open(file);
        if (ifile)
        {
            ifile.close();
            return true;
        }
        return false;
    }
    string strreplace(string orgString, const string search, const string replace)
    {
        for (size_t pos = 0;; pos += replace.length())
        {
            pos = orgString.find(search, pos);
            if (pos == string::npos)
                break;
            orgString.erase(pos, search.length());
            orgString.insert(pos, replace);
        }
        return orgString;
    }
    bool search_wordL(string file, string text)
    {
        ifstream infile(file);
        string line;
        if (infile)
        {
            while (getline(infile, line))
            {
                if (line == text)
                {
                    infile.close();
                    return true;
                }
            }
        }
        return false;
    }
    void file_app_fix(string file,string txt ,string exists)
    {
        fstream files(file,ios::in|ios::out);
        vector <string> data;
        string line;
        data.reserve(10);
        data.push_back(txt);
        while (getline(files,line))
        {
            data.push_back(line);
            if (line == txt){
                printl(exists);
                files.close();
                return;
            }
        }
        files.close();
        sort(data.begin(),data.end());
        ofstream indexs(file);
        ostream_iterator<string> output_iterator(indexs, "\n");
        copy(data.begin(), data.end(), output_iterator);
        indexs.close();
    }
    void file_app_fix(string file,string txt)
    {
        fstream files(file,ios::in|ios::out);
        vector <string> data;
        string line;
        data.reserve(10);
        data.push_back(txt);
        while (getline(files,line))
        {
            data.push_back(line);

        }
        files.close();
        sort(data.begin(),data.end());
        ofstream indexs(file);
        ostream_iterator<string> output_iterator(indexs, "\n");
        copy(data.begin(), data.end(), output_iterator);
        indexs.close();
    }
    string search_word_bynumber(short num, string file)
    {
        fstream ifile;
        ifile.open(file);
        string line, retval;

        if (ifile)
        {
            short i = 1;
            while (getline(ifile, line))
            {
                retval = line;
                if (i == num)
                {
                    break;
                }
                i++;
            }
        }
        return retval;
    }
    void file_app(string file, string text)
    {
        fstream indexs(file, ios::in | ios::out | ios::app);
        indexs << text << endl;
        indexs.close();
    }

    bool is_number(const std::string &s)
    {
        string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it))
            ++it;
        return !s.empty() && it == s.end();
    }
    int count_line(string file)
    {
        int count = 0;
        string line;
        /* Creating input filestream */
        ifstream files(file);
        while (getline(files, line))
        {
            count++;
        }
        files.close();
        return count;
    }
    void printV(std::vector<int> const &input)
    {
        for (int i = 0; i < input.size(); i++)
        {
            std::cout << input.at(i) << ' ';
        }
    }
    void printV(std::vector<string> const &input)
    {
        for (int i = 0; i < input.size(); i++)
        {
            std::cout << input.at(i) << ' ';
        }
    }
    string file_format(string A, char B1, char B2)
    {
        string retval = A;
        for (short i = 0; i < A.length(); i++)
        {
            if (A[i] == B1 || A[i] == B2)
            {
                retval[i] = '\0';
            }
        }
        return retval;
    }
    string file_format(string A, char B1, char B2, short num)
    {
        string retval = A;
        for (short i = 0; i < num; i++)
        {
            if (A[i] == B1 || A[i] == B2)
            {
                retval[i] = '\0';
            }
        }
        return retval;
    }
    bool format_check(string &A)
    {

        for (short i = 0; i < A.length(); i++)
        {
            if (A[i] == ':')
            {
                return true;
            }
            else if (A[i] == '-')
            {
                return true;
            }
        }
        for (short i = 0; i < A.length(); i++)
        {
            if (A[i] == ' ' && A[i + 1] == 'a' && A[i + 2] == 'n' && A[i + 3] == 'd')
            {
                return true;
            }
        }

        return false;
    }
    bool not_same(string input2, string file)
    {
        string line;
        ifstream files(file);
        while (getline(files,line))
        {
            string name,track;
            short i = 0;
            while (line[i] != ':')
            {
                name = name + line[i];
                i++;
            }
            i++;
            while (i < line.length())
            {
                track = track + line[i];
                i++;
            }
            track = trim(track);
            input2 = trim(input2);
            short X = 0;
            while (true)
            {
                if (input2[X] == ':')
                {
                    input2[X] = '\0';
                    break;
                }
                input2[X] = '\0';
                X++;
               
            }
            
            if(trim(track).compare(trim(input2)) == 0)
            {
                files.close();
                return true;
            }
            
        
        }
        files.close();
        return false;
    }
    string string_format(string a)
    {
        string ARTIST,TITLE,fullname;
        const char str1 = ':',str2 = '-';
        for (short i = 0; i < a.length(); i++)
        {
            if (a[i] == str1)
            {
                 fullname = a;
                 break;  
            }else if (a[i] == str2)
            {
                short X = 0;
                while (true)
                {
                    if (a[X] == str2){a[X] = '\0';break;}
                    ARTIST = ARTIST + a[X];
                    X++;
                }
                while (X < a.length())
                {
                    TITLE = TITLE + a[X];
                    X++;
                }
                if (ARTIST[0] == ' ')
                {
                    ARTIST[0] = '\0';
                }
                if (TITLE[0] == ' ')
                {
                    TITLE[0] = '\0';
                }
                fullname = TITLE +str1+ ARTIST;
                break;
                
            }else if (a[i] == 'b'&&a[i+1] == 'y')
            {
                for (short i = 0; i < a.length(); i++)
                {
                    if(a[i] == 'b'&&a[i+1] == 'y'){
                        a[i] = '\0';
                        a[i+1] = '\0';
                        break;
                    }
                    TITLE = TITLE + a[i];
                    a[i] = '\0';
                }
                if (ARTIST[0] == ' ')
                {
                    ARTIST[0] = '\0';
                }
                if (TITLE[0] == ' ')
                {
                    TITLE[0] = '\0';
                }
                fullname = a +str1+ TITLE;
                break;
            }
            
        }
        return fullname;

    }    
} // namespace helper