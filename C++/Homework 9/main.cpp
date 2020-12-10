#include <iostream>
#include <string.h>
using namespace std;
string fullname;
const char str1 = ':',
           str2 = '-';

const string title = "TITLE:",
             artist = "ARTIST:";

void display(const string a, const string b)
{
    cout << title << a << endl
         << artist << b << endl
         << endl;
}

void test1(const char a)
{
    string ARTIST,
        TITLE;
    short i = 0;
    while (i < fullname.length())
    {
        if (fullname[i] != a)
        {
            ARTIST = ARTIST + fullname[i];
        }
        else
        {
            break;
        }
        i++;
    }
    while (i < fullname.length())
    {
        i++;
        if (fullname[i] != a)
        {
            TITLE = TITLE + fullname[i];
        }
        else
        {
            break;
        }
    }
    if (ARTIST[0] == ' ')
    {
        ARTIST[0] = '\0';
    }
    if (TITLE[0] == ' ')
    {
        TITLE[0] = '\0';
    }
    display(TITLE, ARTIST);
}
void test2(const char a)
{
    string ARTIST,
        TITLE;
    short i = 0;
    while (i < fullname.length())
    {
        if (fullname[i] != a)
        {
            TITLE = TITLE + fullname[i];
        }
        else
        {
            break;
        }
        i++;
    }
    while (i < fullname.length())
    {
        i++;
        if (fullname[i] != a)
        {
            ARTIST = ARTIST + fullname[i];
        }
        else
        {
            break;
        }
    }
    if (ARTIST[0] == ' ')
    {
        ARTIST[0] = '\0';
    }
    if (TITLE[0] == ' ')
    {
        TITLE[0] = '\0';
    }
    display(TITLE, ARTIST);
}
void test3()
{
    string ARTIST,
        TITLE;
    short i = 0;
    while (i < fullname.length())
    {
        if (fullname[i] == 'b' && fullname[i + 1] == 'y' &&
            fullname[i - 1] == ' ' && fullname[i + 2] == ' ')
        {
            break;
        }
        else
        {
            TITLE = TITLE + fullname[i];
        }
        i++;
    }
    i = i + 2;
    while (i < fullname.length())
    {
        if (fullname[i] == 'b' && fullname[i + 1] == 'y' &&
            fullname[i - 1] == ' ' && fullname[i + 2] == ' ')
        {
            break;
        }
        else
        {
            ARTIST = ARTIST + fullname[i];
        }
        i++;
    }
    if (ARTIST[0] == ' ')
    {
        ARTIST[0] = '\0';
    }
    if (TITLE[0] == ' ')
    {
        TITLE[0] = '\0';
    }
    display(TITLE, ARTIST);
}

void check()
{

    for (int i = 0; i < fullname.length(); i++)
    {
        if (fullname[i] == str1)
        {
            test1(str1);
            return;
        }
        else if (fullname[i] == str2)
        {
            test2(str2);
            return;
        }
    }
    for (int x = 0; x < fullname.length(); x++)
    {
        if (fullname[x] == 'b' && fullname[x + 1] == 'y' &&
            fullname[x - 1] == ' ' && fullname[x + 2] == ' ')
        {
            test3();
            return;
        }
    }
}

void input()
{
    cout << "Enter a track or \'Q\' to quit." << endl;
    getline(cin, fullname);
    if (fullname == "q")
    {
        exit(0);
    }
    else if (fullname.length() < 5)
    {
        printf("please enter a track with more than five characters.");
    }
    else if (fullname.length() > 5)
    {
        check();
    }
}
int main(int argc, char const *argv[])
{
    while (true)
    {
        input();
    }

    return 0;
}
