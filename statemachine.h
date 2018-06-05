#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "declares.h"

void subtracting_amount(unsigned int type);
void service_machine(void);
void dispense_coffee(unsigned int money, unsigned int moneybevrage);
void menu_filling(void);\
void Fill(char kind,unsigned int amount);
void Fill_Money(int *amount);
void report_writing(void);
void Password_reset(unsigned int new_password);
void password_verifying(void);
void Coffee_init(void);
void money_start(void);

event_t coffee_selection();
event_t check_cents(unsigned int coinValue);
event_t check_amount(unsigned int type);
event_t coin_insertion();
event_t event_handler(event_t event);

#endif // STATEMACHINE_H
