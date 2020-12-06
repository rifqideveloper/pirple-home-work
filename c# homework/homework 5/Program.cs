using System;

namespace csaff
{
    class Program
    {
        static void Main(string[] args)
        {
            const string fizz = "fizz", buzz = "buzz";
            for (short i = 1; i < 100; i++)
                if (i % 3 == 0)
                    Console.WriteLine(fizz);
                else if (i % 5 == 0)
                    Console.WriteLine(buzz);
                else
                    Console.WriteLine(i);

        }
    }
}
