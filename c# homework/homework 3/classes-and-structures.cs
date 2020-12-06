using System;

namespace ConsoleApp2
{
    //class support inheritance
    class test
    {
        protected static string testing = "hello";
    }
    class test1 : test //<- will work
    {
        
        public static void test_(string text)
        {
            Console.WriteLine(testing + " " + text);
        }

    }
    //struct not support inheritance
    public struct test2 //:test //<- will not work
    {
        static string testing = "hello";
        public static void test_(string text)
        {
            Console.WriteLine(testing + " " + text);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            test1.test_("class");
            test2.test_("struct");
        }
    }
}
