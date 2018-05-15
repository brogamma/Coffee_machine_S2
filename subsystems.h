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

int subtracting_amount(unsigned int *type);
int check_change(void);
int coffee_selection(void);
int coin_insertion();
int event_handler(int event);
int check_cents(unsigned int coinValue);

void check_amount(unsigned int *type);

};
#endif // SUBSYSTEMS_H
