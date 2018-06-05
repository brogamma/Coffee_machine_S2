#ifndef DECLARES_H
#define DECLARES_H

typedef enum {
   S_START,
   S_INITIALISED,
   S_COFFEE_SELECTION,
   S_WAIT_FOR_COINS,
   S_DETECTED_10C,
   S_DETECTED_20C,
   S_DETECTED_50C,
   S_DETECTED_100C,
   S_DISPENSE_COFFEE,
   S_DISPENSE_CHANGE,
   S_SERVICE
} state_t;

/*********************The events in FSM************************/
typedef enum {
   E_START,
   E_CONTINUE,
   E_MACCHIATO,
   E_NORMAL_COFFEE,
   E_CUPPUCCINO,
   E_10C,
   E_20C,
   E_50C,
   E_100C,
   E_BACK,
   E_NOT_ENOUGH,
   E_ENOUGH,
   E_ENOUGH_CHANGE,
   E_NOT_ENOUGH_CHANGE,
   E_SERVICE
} event_t;

class Declares
{
private:

    /*interger variables*/
    int change;
    int Service_Sel;
    int Kind_Bevrage;

    /*Unsigned variables*/
    unsigned int password_enter;
    unsigned int passwordset;
    unsigned int cost_bevrage;
    unsigned int Change_Dispensed;
    unsigned int password[1];
    unsigned int price_Cappuccino;
    unsigned int price_Macchiato;
    unsigned int price_Normal_Coffee;
    unsigned int insertedMoney;
    unsigned int Money_Recieved;
    unsigned int Macchiato_ammount;
    unsigned int Cappuccino_amount;
    unsigned int Coffee_Ammount;
    unsigned int ChangeLeft;

    /*rest variables*/
    char Fill_Select;

public:

    /**************************public variabels*************************/

    state_t next_state;

    /*********************Getters and setters************************/
    int getService_Sel();
    int getChange();
    int getKind_Bevrage();
    char getFill_Select();

    void setService_Sel(int value);
    void setChange(int value);
    void setPassword_enter(unsigned int value);
    void setPasswordset(unsigned int value);
    void setCost_bevrage(unsigned int value);
    void setChange_Dispensed(unsigned int value);
    void setPricebevrage(unsigned int value, int price);
    void setInsertedMoney(unsigned int value);
    void setMoney_Recieved(unsigned int value);
    void setMacchiato_ammount(unsigned int value);
    void setCappuccino_amount(unsigned int value);
    void setCoffee_Ammount(unsigned int value);
    void setChangeLeft(unsigned int value);
    void setFill_Select(char value);
    void setKind_Bevrage(int value);

    unsigned int getPassword_enter();
    unsigned int getPasswordset();
    unsigned int getCost_bevrage();
    unsigned int getChange_Dispensed();
    unsigned int getPricebevrage(int value);
    unsigned int getInsertedMoney();
    unsigned int getMoney_Recieved();
    unsigned int getMacchiato_ammount();
    unsigned int getCappuccino_amount();
    unsigned int getCoffee_Ammount();
    unsigned int getChangeLeft();

};

#endif // DECLARES_H
