#include <iostream>

using namespace std;

int main()
{
  for (int x1 = 0; x1 < 10; x1++)
  {
    for (int x2 = 0; x2 < 10; x2++)
    {
      for (int x3 = 0; x3 < 10; x3++)
      {
        for (int x4 = 0; x4 < 10; x4++)
        {
          for (int x5 = 0; x5 < 10; x5++)
          {
            for (int x6 = 0; x6 < 10; x6++)
            {
              for (int x7 = 0; x7 < 10; x7++)
               {
                 for (int x8 = 0; x8 < 10; x8++)
                 {
                   for (int x9 = 0; x9 < 10; x9++)
                   {
                     for (int x10 = 0; x10 < 10; x10++)
                     {
                       for (int x11 = 0; x11 < 10; x11++)
                       {
                         for (int x12 = 0; x12 < 10; x12++)
                         {
                           if (((x1 + x2 + x3) % 2 == 0) && ((x10 + x11 + x12) % 3 == 0) && ((x3 + x6 + x9 + x12) % 11 == 0) && (x2 + x4 + x6 + x8 + x10 == 21))
                             cout << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << x10 << x11 <<x12;
                         }

                       }
                     }
                   }
                 }
               }
             }
           }
         }
       }
     }
   }
    return 0;
}














/*все возможные пароли*/
