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
void dispense_coffee(const unsigned int *money, unsigned int moneybevrage);
void service(void);
void Coffee_init(void);
void event_handler(event_t event);
void check_amount(unsigned int *type);

event_t subtracting_amount(unsigned int *type);
event_t check_change(void);
event_t coffee_selection(void);
event_t coin_insertion();
event_t check_cents(unsigned int coinValue);

};
#endif // SUBSYSTEMS_H
