#include <iostream>
#include "settings.h"

int settings::getStockMin(int value)
{
    switch (value) {
    case 0:
        return Min_stock_mac;
        break;
    case 1:
        return Min_stock_cap;
        break;
    case 2:
        return Min_stock_cof;
        break;
    default:
        break;
    }
}

int settings::getAmountInstock(int value)
{
    switch (value) {
    case 0:
        return Stock_machiato;
        break;
    case 1:
        return Stock_Cap;
        break;
    case 2:
        return Stock_Coffee;
        break;
    default:
        break;
    }
}

void settings::setMinInStock(int bevrage, int new_amount)
{
    switch (bevrage) {
    case 0:
        if(Min_stock_mac > new_amount)
        {
             //display.out("New amount smaller then old one!");
        }
        Min_stock_mac = new_amount;
        break;
    case 1:
        if(Min_stock_mac > new_amount)
        {
             //display.out("New amount smaller then old one!");
        }
        Min_stock_cap = new_amount;
        break;
    case 2:
        if(Min_stock_mac > new_amount)
        {
             //display.out("New amount smaller then old one!");
        }
        Min_stock_cof = new_amount;
        break;
    default:
        break;
    }
}

void settings::setAmountInStock(int bevrage, int amount)
{
        switch (bevrage) {
        case 0:
            Stock_machiato = amount;
            break;
        case 1:
            Stock_Cap = amount;
            break;
        case 2:
            Stock_Coffee = amount;
            break;
        default:
            break;

    }
}

