#include<iostream>
#include "display.h"

/*****************************display function******************************/

void display_show(const char *text)
{
   printf("\n## %-" DISPLAY_SIZE_STR "s ##\n", text);
}
void display::display_initialise(void)
{
   display::display_debug_info("Display: initialised");
}
void display::dispenser_initialise(void)
{
   display::display_debug_info("Coffee Dispenser: initialised");
}
void display::change_dispenser_initialise(void)
{
   display::display_debug_info("Change Dispenser: initialised");
}
void display::keyboard_initialise(void)
{
   display::display_debug_info("Keyboard: initialised");
}

void display::display_debug_info(const char *text)
{
   printf("\n-- DEBUG      %-" DISPLAY_SIZE_STR "s\n", text);
}


