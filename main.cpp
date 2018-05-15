//Main file that only starts the machine code
#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include "declares.h"
#include "subsystems.h"

Declares declare;
subsystems subs;

//******************Main program**************//
int main()
{
   event_handler(declare.E_START);

return 0;
}
