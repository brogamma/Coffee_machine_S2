#include <iostream>
#include "declares.h"
#include "settings.h"
#include "subsystems.h"

Declares declares;
settings setings;

using namespace std;
void Subsystems::Check_quantity(int value)
{
    int amount;
    switch (value) {
    case 0:
        amount =declares.getMacchiato_ammount();
        if(amount <= setings.getStockMin(0))
        {
            order(setings.getStockMin(0)-setings.getAmountInstock(0));
        }
        break;
    case 1:
        amount = declares.getCappuccino_amount();
        if(amount <= setings.getStockMin(1))
        {
            order(setings.getStockMin(1)-setings.getAmountInstock(1));
        }
        break;
    case 2:
        amount =declares.getCoffee_Ammount();
        if(amount <= setings.getStockMin(2))
        {
            order(setings.getStockMin(2)-setings.getAmountInstock(2));
        }
        break;
    default:
        break;
    }
}

void Subsystems::order(int value)
{
    // value = <HAL driver here to send data out via the driver>;
    cout<<"Order has been sent."<<endl;
}

void Subsystems::Order_money(const int amount)
{
    //amount = <HAL driver here to send out data for order money>;
    cout<<"New change has been orderd"<< endl;
}
