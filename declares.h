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

    /*Static variables*/
    static unsigned int Money_Recieved;
    static unsigned int Macchiato_ammount;
    static unsigned int Cappuccino_amount;
    static unsigned int Coffee_Ammount;
    static unsigned int ChangeLeft;

    /*rest variables*/
    char Fill_Select;

public:

    /**************************public variabels*************************/

    state_t next_state;

    /*********************Getters and setters************************/
    int getChange() const;
    int getService_Sel() const;
    int getKind_Bevrage() const;
    char getFill_Select() const;
    unsigned int getChange_Dispensed() const;
    unsigned int getPasswordset() const;
    unsigned int getPricebevrage(unsigned int input) const;
    unsigned int getPassword_enter() const;
    unsigned int getInsertedMoney() const;

    void setKind_Bevrage(int value);
    void setFill_Select(char value);
    void setPasswordset(unsigned int value);
    void setService_Sel(int value);
    void setChange(int value);
    void setInsertedMoney(unsigned int value);
    void setChange_Dispensed(unsigned int value);
    void setPrice_Cappuccino(unsigned int value);
    void setPrice_Macchiato(unsigned int value);
    void setPrice_Normal_Coffee(unsigned int value);
    void setPassword_enter(unsigned int value);

    static unsigned int getMoney_Recieved();
    static int getChangeLeft();
    static int getMacchiato_ammount();
    static int getCappuccino_amount();
    static int getCoffee_Ammount();

    static void setMoney_Recieved(unsigned int value);
    static void setMacchiato_ammount(int value);
    static void setCappuccino_amount(int value);
    static void setCoffee_Ammount(int value);
    static void setChangeLeft(int value);

};

#endif // DECLARES_H
