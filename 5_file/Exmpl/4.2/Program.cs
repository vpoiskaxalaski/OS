using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4._2
{
    class Program
    {
        //2.	Создать программно два каталога.
        static void Main(string[] args)
        {
            TCHAR Buffer[256];
            TCHAR Buffer2[] = TEXT("e:\\University");
            TCHAR Buffer3[] = TEXT("e:\\University");

            DWORD dwResult = GetCurrentDirectory(256, Buffer);
            std::wcout << "Dir: " << Buffer << '\n';


            BOOL b = SetCurrentDirectory(Buffer2);

            dwResult = GetCurrentDirectory(256, Buffer);
            std::wcout << "Dir: " << Buffer << '\n';



            if (CreateDirectory(Buffer3, NULL))
                std::wcout << "directory create" << '\n';
            else
                std::wcout << "error create directory" << '\n';
            getchar();
        }
    }
}
