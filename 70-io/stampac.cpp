// https://stackoverflow.com/questions/6545701/can-ofstream-be-used-for-printing-on-a-printer
#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    ofstream printer ("LPT1");
    if(!printer)
    {  return 1;
    }

    printer.puts("Test Test Test\n");
    printer.putc('\f');
    printer.close();
    return 0;
} 