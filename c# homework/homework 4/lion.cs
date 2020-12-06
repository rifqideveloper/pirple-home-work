using System;

namespace ConsoleApp2
{
    
    class Program
    {
        static void Main(string[] args)
        {
            //this file is about animal lion   
            double HeightIncentimeter = 105.0;
            uint WeightInKilos = 250;
            ushort NumberOfTeeth = 30;
            int NumberOfLegs = 4;
            byte TailLength = 170;
            ulong MaxTeritoriInkm2 = 400;
            //extra information
            string[] discrition = new string[10];
            discrition[0] = "\tDomain   : Eukartoya";
            discrition[1] = "\tKingdom  : Animalia";
            discrition[2] = "\tPhylum   : Chordata";
            discrition[3] = "\tClass    : Mammalia";
            discrition[4] = "\torder    : Carnivora";
            discrition[5] = "\tsuborder : Feliformia";
            discrition[6] = "\tFamily   : Felidae";
            discrition[7] = "\tSubfamily: Pantherinae";
            discrition[8] = "\tGenus    : Panthera";
            discrition[9] = "\tSpecies  : P. leo";
            Console.WriteLine("------------LION------------");
            Console.WriteLine("\tHeight          :" + HeightIncentimeter);
            Console.WriteLine("\tWeight          :" + WeightInKilos);
            Console.WriteLine("\tNumberOfTeeth   :" + NumberOfTeeth);
            Console.WriteLine("\tNumberOfLegs    :" + NumberOfLegs);
            Console.WriteLine("\tTailLength      :" + TailLength);
            Console.WriteLine("\tMaxTeritoriInkm2:" + MaxTeritoriInkm2);
            Console.WriteLine("descrition:");
            for (short i = 0;i < 10; i++)
            {
                Console.WriteLine(discrition[i]);
            }
        }
    }
}
