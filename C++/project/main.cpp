#include <iostream>
#include <thread>
#include <string>
#include <bitset>
using namespace std;
string d1 = "    1       2       3       4      ",
       d2 = "   ___     ___     ___     ___     ",
       d3 = " x|   |x x|   |x x|   |x x|   |x   ",
       d4 = "  |   |   |   |   |   |   |   |    ",
       d5 = "   ---     ---     ---     ---     ",
       d6 = "    ?       ?       ?       ?      ";
short positionMask = 0b0001;

short rotateLeft(short value, short amount)
{
    //four bit rotate left

    const short OVERFLOW = 0b10000;
    while (amount > 0)
    {
        value = value << 1;
        if (((value & OVERFLOW) == OVERFLOW))
        {
            value = value & 0b1111; //remove overflow bit
            value = value | 0b0001; //set the rightmost bit
        }
        amount--;
    }
    return value;
}
void display1()
{
    cout << d1 << endl
         << d2 << endl
         << d3 << endl;
};
void display2()
{
    cout << d4 << endl
         << d5 << endl
         << d6 << endl;
};

const char upPiston = ' ',
           chamber = ' ',
           downPiston = 'T';
void cylinder1()
{
    char inValvesOpen = 0b1000,
         outValvesOpen = 0b0010,
         pistonUp = 0b0100,
         cylinderFire = 0b0001,
         stateLabel = 'C',
         inValve = 'x',
         outValve = 'x';
    if (positionMask == cylinderFire)
    {
        d3[3] = '*';
        d3[4] = downPiston;
        d3[5] = '*';
        d4[4] = chamber;
        inValve = 'x';
        outValve = 'x';
        stateLabel = 'p';
    }
    else if (positionMask == outValvesOpen)
    {
        d3[3] = upPiston;
        d3[4] = downPiston;
        d3[5] = upPiston;
        d4[4] = chamber;
        inValve = 'x';
        outValve = 'o';
        stateLabel = 'I';
    }
    else if (positionMask == pistonUp)
    {
        d3[3] = chamber;
        d3[4] = chamber;
        d3[5] = chamber;
        d4[4] = downPiston;
        inValve = 'x';
        outValve = 'x';
        stateLabel = 'C';
    }
    else if (positionMask == inValvesOpen)
    {
        d3[3] = chamber;
        d3[4] = chamber;
        d3[5] = chamber;
        d4[4] = downPiston;
        inValve = 'o';
        outValve = 'x';
        stateLabel = 'E';
    }

    d3[7] = inValve;
    d3[1] = outValve;
    d6[4] = stateLabel;
};
void cylinder2()
{
    char inValvesOpen = 0b0001,
         outValvesOpen = 0b1000,
         pistonUp = 0b0010,
         cylinderFire = 0b0100,
         stateLabel = 'C',
         inValve = 'x',
         outValve = 'x';
    if (positionMask == cylinderFire)
    {
        d3[11] = '*';
        d3[12] = downPiston;
        d3[13] = '*';
        d4[12] = chamber;
        inValve = 'x';
        outValve = 'x';
        stateLabel = 'p';
    }
    else if (positionMask == outValvesOpen)
    {
        d3[11] = upPiston;
        d3[12] = downPiston;
        d3[13] = upPiston;
        d4[12] = chamber;
        inValve = 'x';
        outValve = 'o';
        stateLabel = 'I';
    }
    else if (positionMask == pistonUp)
    {
        d3[11] = chamber;
        d3[12] = chamber;
        d3[13] = chamber;
        d4[12] = downPiston;
        inValve = 'x';
        outValve = 'x';
        stateLabel = 'C';
    }
    else if (positionMask == inValvesOpen)
    {
        d3[11] = chamber;
        d3[12] = chamber;
        d3[13] = chamber;
        d4[12] = downPiston;
        inValve = 'o';
        outValve = 'x';
        stateLabel = 'E';
    }
    d3[15] = inValve;
    d3[9] = outValve;
    d6[12] = stateLabel;
};
void cylinder3()
{
    char inValvesOpen = 0b0100,
         outValvesOpen = 0b0001,
         pistonUp = 0b1000,
         cylinderFire = 0b0010,
         stateLabel = 'C',
         inValve = 'x',
         outValve = 'x';
    if (positionMask == cylinderFire)
    {
        d3[19] = '*';
        d3[20] = downPiston;
        d3[21] = '*';
        d4[20] = chamber;
        inValve = 'x';
        outValve = 'x';
        stateLabel = 'p';
    }
    else if (positionMask == outValvesOpen)
    {
        d3[19] = upPiston;
        d3[20] = downPiston;
        d3[21] = upPiston;
        d4[20] = chamber;
        inValve = 'x';
        outValve = 'o';
        stateLabel = 'I';
    }
    else if (positionMask == pistonUp)
    {
        d3[19] = chamber;
        d3[20] = chamber;
        d3[21] = chamber;
        d4[20] = downPiston;
        inValve = 'x';
        outValve = 'x';
        stateLabel = 'C';
    }
    else if (positionMask == inValvesOpen)
    {
        d3[19] = chamber;
        d3[20] = chamber;
        d3[21] = chamber;
        d4[20] = downPiston;
        inValve = 'o';
        outValve = 'x';
        stateLabel = 'E';
    }
    d3[23] = inValve;
    d3[17] = outValve;
    d6[20] = stateLabel;
};
void cylinder4()
{
    char inValvesOpen = 0b0010,
         outValvesOpen = 0b0100,
         pistonUp = 0b0001,
         cylinderFire = 0b1000,
         stateLabel = 'C',
         inValve = 'x',
         outValve = 'x';
    if (positionMask == cylinderFire)
    {
        d3[27] = '*';
        d3[28] = downPiston;
        d3[29] = '*';
        d4[28] = chamber;
        inValve = 'x';
        outValve = 'x';
        stateLabel = 'p';
    }
    else if (positionMask == outValvesOpen)
    {
        d3[27] = upPiston;
        d3[28] = downPiston;
        d3[29] = upPiston;
        d4[28] = chamber;
        inValve = 'x';
        outValve = 'o';
        stateLabel = 'I';
    }
    else if (positionMask == pistonUp)
    {
        d3[27] = chamber;
        d3[28] = chamber;
        d3[29] = chamber;
        d4[28] = downPiston;
        inValve = 'x';
        outValve = 'x';
        stateLabel = 'C';
    }
    else if (positionMask == inValvesOpen)
    {
        d3[27] = chamber;
        d3[28] = chamber;
        d3[29] = chamber;
        d4[28] = downPiston;
        inValve = 'o';
        outValve = 'x';
        stateLabel = 'E';
    }
    d3[31] = inValve;
    d3[25] = outValve;
    d6[28] = stateLabel;
}
int main()
{

    auto rotate = [] {
        positionMask = rotateLeft(positionMask, 1);
    };

    for (unsigned char i = 0; i < 5; i++)
    {

        thread t1(cylinder1);
        t1.detach();
        thread t2(cylinder2);
        t2.detach();
        thread t3(cylinder3);
        t3.detach();
        thread t4(cylinder4);
        t4.detach();
        thread t5(display1);
        t5.join();
        thread t6(display2);
        t6.join();
        thread t7(rotate);
        t7.join();
    }

    return 0;
}
