using System;

namespace csaff
{
    class Program
    {
        static void Main(string[] args)
        {
            Cars tesla = new Cars("tesla","model X",2019,2000,50);
            tesla.Drive();
            tesla.Stop();
            tesla.Print();
            Cars Ferrari = new Cars("Ferrari", "458 Italia", 2018, 2000, 100);
            Ferrari.Repair();
            Ferrari.Drive();
            Ferrari.Stop();
            Ferrari.Print();
            Cars BMW = new Cars("BMW", "i8", 2015, 2000, 10);
            BMW.Drive();
            BMW.Stop();
            BMW.Print();
        }
    }
    public class Vehicle
    {
        public static string Make = "", Model = "";
        public static int Year = 0, Weight = 0, TripsSinceMaintenance = 0;
        public static bool NeedsMaintenance = false;
        public void Repair()
        {
            NeedsMaintenance = false; 
            TripsSinceMaintenance = 0;
        }
        public bool Needrepair()
        {
            return TripsSinceMaintenance >= 100;
        }
    }
    public class Cars : Vehicle
    {
        public static bool isDriving = false;
        public Cars(string make, string model, int year, int weight, int tripsSinceMaintenance)
        {
            Make = make;
            Model = model;
            Year = year;
            Weight = weight;
            TripsSinceMaintenance = tripsSinceMaintenance;
            NeedsMaintenance = Needrepair();
        }
        public void Drive()
        {
            switch (NeedsMaintenance)
            {
                case false:
                    isDriving = true;
                    TripsSinceMaintenance++;
                    if (Needrepair()) Stop();
                    break;
                default:
                    break;
            }
        }
        public void Stop() { isDriving = false; }
        public void Print()
        {
            Console.Write("make   = {0}\nmodel = {1}\nyear = {2}\nweaigt = {3}\nTripsSinceMaintenance = {4}\nNeedsMaintenance = {5}\n\n", 
                            Make, Model, Year, Weight, TripsSinceMaintenance, NeedsMaintenance);

        }

    }
}
