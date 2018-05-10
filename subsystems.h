#ifndef SUBSYSTEMS_H
#define SUBSYSTEMS_H

#include "Declares.h"
#include "display.h"

class subsystems
{
public:
//**********************The requird function*********************//
const void password_verifying(void);

void money_start(void);
void Fill(unsigned int *amount_type);
void menu_filling(void);
void report_writing();
void dispense_coffee(const int *money);
void service(void);
void Coffee_init(void);

int subtracting_amount(unsigned int *type);

state_t event_handler(event_t event);
event_t check_amount(unsigned int *type);
event_t check_cents(unsigned int coinValue);
event_t coin_insertion();
event_t coffee_selection();
event_t check_change(void);

};
#endif // SUBSYSTEMS_H
