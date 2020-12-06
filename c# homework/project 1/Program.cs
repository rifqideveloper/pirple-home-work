using System.Threading;
namespace csaff
{
    class Program
    {
        static void Main(string[] args)
        {
            Elevators A = new Elevators(-1, 9);
            A.Go(5);//go to floor 5
            A.Up(7);//call elevator from floor 7
            Elevators B = new Elevators(0, 10);
            B.Go(10);//go to floor 10
            B.Down(3);//call elevator from floor 3
            B.Emergensi();// emergensi botton
            B.reset();// reset boton

        }

    }
    class Elevators
    {
        //up = true , down = false
        public bool up_down = true, door_open = false, emergensi = false;
        public int[] min_max = { 0, 1 };
        public int floor = 0;
        public Elevators(int min, int max)
        {
            min_max[0] = min;
            min_max[1] = max;
        }
        public void Go(int to)
        {
            if (!emergensi)
            {
                if (floor == to || to! < min_max[0] || to! > min_max[1])
                { /*Elevators not move */ }
                else if (floor < to)
                {
                    System.Console.WriteLine("go from {0} to {1}", floor, to);
                    while (floor != to)
                    {
                        floor++;
                        Thread.Sleep(1000);
                        print();
                    }
                }

                else
                    System.Console.WriteLine("go from {0} to {1}", floor, to);
                while (floor != to) floor--; Thread.Sleep(1000); print();
            }

        }
        public void Up(int from)
        {

            if (from == floor)
            {
                Open();
            }
            else
            {
                if (!emergensi)
                {
                    while (from != floor)
                    {
                        floor++;
                        Thread.Sleep(1000);
                        print();
                    }
                    Open();
                }

            }

        }
        public void Down(int from)
        {
            if (from == floor)
            {
                Open();
            }
            else
            {
                if (!emergensi)
                {
                    while (from != floor)
                    {
                        floor--;
                        Thread.Sleep(1000);
                        print();
                    }
                    Open();
                }


            }
        }
        public void Open()
        {
            door_open = true;
            System.Console.WriteLine("Open doors");
            if (!emergensi)
                Thread.Sleep(3000);
            door_open = false;
            System.Console.WriteLine("close doors");
        }
        public void Emergensi()
        {
            emergensi = true;
            System.Console.WriteLine("Emergensi");
            Open();

        }
        public void reset()
        {
            emergensi = false;
            System.Console.WriteLine("reset");
        }
        void print()
        {
            System.Console.WriteLine("floor : {0}", floor);
        }
    }
}
