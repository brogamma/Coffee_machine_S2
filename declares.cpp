#include <iostream>
#include "declares.h"

using std::cout;
using std::cin;
using std::endl;

void Declares::setChange(int value)
{
    change = value;
}

void Declares::setService_Sel(int value)
{
     Service_Sel = value;
}

void Declares::setKind_Bevrage(int value)
{
    Kind_Bevrage = value;
}

unsigned int Declares::getPassword_enter()
{
    return password_enter;
}

void Declares::setPassword_enter(unsigned int value)
{
    password_enter = value;
}

unsigned int Declares::getPasswordset()
{
    return passwordset;
}

void Declares::setPasswordset(unsigned int value)
{
    passwordset = value;
}

unsigned int Declares::getCost_bevrage()
{
    return cost_bevrage;
}

void Declares::setCost_bevrage(unsigned int value)
{
    cost_bevrage = value;
}

unsigned int Declares::getChange_Dispensed()
{
    return Change_Dispensed;
}

void Declares::setChange_Dispensed(unsigned int value)
{
    Change_Dispensed = value;
}

unsigned int Declares::getPricebevrage(int value)
{
    switch (value) {
    case 0:
        return price_Cappuccino;
        break;
    case 1:
        return price_Normal_Coffee;
        break;
    case 2:
        return price_Macchiato;
        break;
    default:
        cout<< "wrong slection"<< endl;
        break;
    }
}

void Declares::setPricebevrage(unsigned int value, int price)
{
    switch (value) {
    case 0:
        price_Cappuccino = price;
        break;
    case 1:
        price_Normal_Coffee = price;
        break;
    case 2:
        price_Macchiato = price;
        break;
    default:
        cout<< "wrong slection"<< endl;
        break;
    }
}

unsigned int Declares::getInsertedMoney()
{
    return insertedMoney;
}

void Declares::setInsertedMoney(unsigned int value)
{
    insertedMoney = value;
}

unsigned int Declares::getMoney_Recieved()
{
    return Money_Recieved;
}

void Declares::setMoney_Recieved(unsigned int value)
{
    Money_Recieved = value;
}

unsigned int Declares::getMacchiato_ammount()
{
    return Macchiato_ammount;
}

void Declares::setMacchiato_ammount(unsigned int value)
{
    Macchiato_ammount = value;
}

unsigned int Declares::getCappuccino_amount()
{
    return Cappuccino_amount;
}

void Declares::setCappuccino_amount(unsigned int value)
{
    Cappuccino_amount = value;
}

unsigned int Declares::getCoffee_Ammount()
{
    return Coffee_Ammount;
}

void Declares::setCoffee_Ammount(unsigned int value)
{
    Coffee_Ammount = value;
}

unsigned int Declares::getChangeLeft()
{
    return ChangeLeft;
}

void Declares::setChangeLeft(unsigned int value)
{
    ChangeLeft = value;
}

char Declares::getFill_Select()
{
    return Fill_Select;
}

void Declares::setFill_Select(char value)
{
    Fill_Select = value;
}

int Declares::getService_Sel()
{
    return Service_Sel;
}

int Declares::getChange()
{
    return change;
}

int Declares::getKind_Bevrage()
{
    return Kind_Bevrage;
}
