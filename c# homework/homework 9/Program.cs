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
        static void csv_to_tsv(ref string path ,ref string target)
        {
            if (!File.Exists(path))
            {
                System.Console.WriteLine("file do not Exist");
            }
            else
            {
                File.WriteAllText(target, File.ReadAllText(path).Replace(",","\t"));
                System.Console.WriteLine("don Convert file to tsv (tab-separated)");
            }
        }
        
    }


}
