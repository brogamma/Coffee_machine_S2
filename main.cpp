//Main file that only starts the machine code
#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include "declares.h"
#include "subsystems.h"

subsystems subs;

//******************Main program**************//
int main()
{
   subs.event_handler(E_START);

return 0;
}
