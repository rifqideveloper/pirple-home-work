using System.IO;
namespace csaff
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"c:\temp\data.csv", target = @"c:\temp\fifa.tsv";
            csv_to_tsv(ref path, ref target);
        }
        static void csv_to_tsv(ref string path, ref string target)
        {
            if (!File.Exists(path))
            {// error file not Exists
                System.Console.WriteLine("file do not Exist");
            }
            else if (!check_format(ref path,"csv"))
            {// error file extention is not valid
                System.Console.WriteLine("invalid format file");
            }
            else if (!check_format(ref target, "tsv"))
            {// error file extention is not valid
                System.Console.WriteLine("invalid format name target file!!");
            }
            else
            {
                File.WriteAllText(target, File.ReadAllText(path).Replace(",", "\t"));
                System.Console.WriteLine("done Converting {0} to {1} (tab-separated).", path,target);
            }
            static bool check_format(ref string file,string format)
            {
                return file.Split(".")[1] == format;
            }
            
        }

    }


}
