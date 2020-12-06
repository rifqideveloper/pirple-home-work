namespace csaff
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            the difference between object and procedural is
            objects can be inherited,
            We can create multiple objects which have the same properties 
            making the code smaller if the programmer uses many objects. 
            procedural is simpler to use than object, easy to understand, 
            reduces repetition of the same code.
            */
            int[] arr = { 1, 2, 3, 4 };
            string[] str = { "hello", "world" };
            //object example
            println.arr(arr);
            println.arr(str);
            //example procedure
            println_array(arr);
            println_array(str);
        }
        //procedure code
        public static void println_array(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
                System.Console.WriteLine(arr[i]);
        }
        public static void println_array(string[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
                System.Console.WriteLine(arr[i]);
        }
        //objectc with inheritance
        class print
        {
            public void print_int(int x)
            {
                System.Console.Write(x);
            }
            public void print_String(string x)
            {
                System.Console.Write(x);
            }
            public static void println_int(int x)
            {
                System.Console.WriteLine(x);
            }
            public static void println_String(string x)
            {
                System.Console.WriteLine(x);
            }
        }
        class println : print// <- the print class inherits to the println class
        {
            public static void arr(int[] arr)//<- print int array
            {
                for (int i = 0; i < arr.Length; i++)
                    println_int(arr[i]);
            }
            public static void arr(string[] arr)//<- print String array
            {
                for (int i = 0; i < arr.Length; i++)
                    println_String(arr[i]);
            }
        }
    }


}
