namespace csaff
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Object[] time = timeAdder(59, "seconds", 1, "seconds");
            System.Console.WriteLine("{0} {1}", time[0], time[1]);
            //
            System.Object[] time1 = timeAdder(60, "seconds", 1, "minutes");
            System.Console.WriteLine("{0} {1}", time1[0], time1[1]);
            //
            System.Object[] time2 = timeAdder(60, "seconds", 1439, "minutes");
            System.Console.WriteLine("{0} {1}", time2[0], time2[1]);
            //
            System.Object[] time3 = timeAdder(86400, "seconds", 2, "days");
            System.Console.WriteLine("{0} {1}", time3[0], time3[1]);
            //
            System.Object[] time4 = timeAdder(5, "hour", 5, "minutes");
            System.Console.WriteLine("{0} {1}", time4[0], time4[1]);
        }
        static System.Object[] timeAdder(int value1, string label1, int value2, string label2)
        {
            string[] label = { "seconds", "minutes", "hours", "days", "second",
                                "minute", "hour", "day" };
            System.Object[] retval = new System.Object[] { 0, "" };
            if (errorcheck(ref label, ref label1, ref label2, ref value1, ref value2))
            {
                return new System.Object[] { false, false };
            }
            else if (labelc(ref label1, ref label))
            {
                if (labelc(ref label2, ref label, 3))
                {//if label2 is day
                    day_plus(ref retval, ref label, value2, second_to_day(ref value1));
                }
                else if (labelc(ref label2, ref label, 2))
                {//if label2 is hour
                    hour_to(ref retval, ref label, value2, second_to_hour(ref value1));
                }
                else if (labelc(ref label2, ref label, 1))
                {//if label2 is menute
                    menute_to(ref retval, ref label, value2, second_to_menute(ref value1));
                }
                else
                {//if all label is second
                    secont_to(ref retval, ref label, value1 + value2);
                }

            }
            else if (labelc(ref label1, ref label, 1))
            {
                if (labelc(ref label2, ref label, 3))
                {//if label2 is day
                    day_plus(ref retval, ref label, value2, menute_to_day(ref value1));
                }
                else if (labelc(ref label2, ref label, 2))
                {//if label2 is hour
                    hour_to(ref retval, ref label, value2, menute_to_hour(ref value1));
                }
                else if (labelc(ref label2, ref label, 1))
                {//if label2 is hour
                    hour_to(ref retval, ref label, value2, second_to_hour(ref value1));
                }
                else
                {//if all label is menute
                    secont_to(ref retval, ref label, value1 + value2);
                }
            }
            else if (labelc(ref label1, ref label, 2))
            {
                if (labelc(ref label2, ref label, 3))
                {
                    day_plus(ref retval, ref label, value2, hour_to_day(ref value1));
                }
                else if (labelc(ref label2, ref label, 1))
                {
                    hour_to(ref retval, ref label, value2, menute_to_hour(ref value1));
                }
                else if (labelc(ref label2, ref label, 1))
                {
                    hour_to(ref retval, ref label, value2, second_to_hour(ref value1));
                }
                else
                {
                    hour_to(ref retval, ref label, value2, value1);
                }
            }
            else
            {
                if (labelc(ref label2, ref label, 2))
                    day_plus(ref retval, ref label, value2, hour_to_day(ref value1));
                else if (labelc(ref label2, ref label, 1))
                    day_plus(ref retval, ref label, value2, menute_to_day(ref value1));
                else if (labelc(ref label2, ref label, 1))
                    day_plus(ref retval, ref label, value2, second_to_day(ref value1));
                else
                    day_plus(ref retval, ref label, value2, value1);

            }
            return retval;
        }
        static void day_plus(ref System.Object[] x, ref string[] y, int value, int p)
        {
            x[0] = value + p;
            x[1] = y[3];
        }
        static void hour_to(ref System.Object[] x, ref string[] y, int value, int p)
        {
            value += p;
            if (value >= 24)
            {
                x[0] = hour_to_day(ref value);
                x[1] = y[3];
            }
            else
            {
                x[0] = value;
                x[1] = y[2];
            }
        }
        static int hour_to_day(ref int hour)
        {
            return hour / 24;
        }
        static void menute_to(ref System.Object[] x, ref string[] y, int value, int p)
        {
            value += p / 60;
            if (value >= 1440)
            {//menute to day
                x[0] = menute_to_day(ref value);
                x[1] = y[3];
            }
            else if (value >= 60)
            {// menute to hour
                x[0] = menute_to_hour(ref value);
                x[1] = y[2];
            }
            else
            {//menute to menute
                x[0] = value;
                x[1] = y[1];
            }
        }
        static int menute_to_hour(ref int menute)
        {
            return menute / 60;
        }
        static int menute_to_day(ref int menute)
        {
            return menute / 1440;
        }
        static void secont_to(ref System.Object[] x, ref string[] y, int value)
        {
            if (value >= 86400)
            {//second to day
                x[0] = second_to_day(ref value);
                x[1] = y[3];
            }
            else if (value >= 3600)
            {//second to hour
                x[0] = second_to_hour(ref value);
                x[1] = y[2];
            }
            else if (value >= 60)
            {//second to minutes
                x[0] = second_to_menute(ref value);
                x[1] = y[1];
            }
            else
            {//second to second
                x[0] = value;
                x[1] = y[0];
            }
        }
        static int second_to_day(ref int second)
        {
            return second / 86400;
        }
        static int second_to_hour(ref int second)
        {
            return second / 3600;
        }
        static int second_to_menute(ref int second)
        {
            return second / 60;
        }
        static bool labelc(ref string x, ref string[] y)
        {
            return x.Equals(y[0]) || x.Equals(y[4]);
        }
        static bool labelc(ref string x, ref string[] y, int z)
        {
            return x.Equals(y[z]) || x.Equals(y[z + 4]);
        }
        static bool errorcheck(ref string[] label, ref string label1, ref string label2, ref int value1, ref int value2)
        {
            bool retval = false;
            retval = !labelc(ref label1, ref label) && !labelc(ref label2, ref label);
            if (labelc(ref label1, ref label, 1))
                retval = value1.Equals(5);
            if (labelc(ref label2, ref label, 1))
                retval = value2.Equals(5);
            return retval;
        }
    }


}
