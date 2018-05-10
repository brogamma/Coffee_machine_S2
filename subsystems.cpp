//standard c-libaries that are needed to run the subsystems of the state_machine
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>

//Source and headerfiles from the code itself
#include "declares.h"
#include "subsystems.h"
#include "display.h"
#include "display.cpp"

using std::cout;
using std::cin;

Declares dec;
subsystems sub;
display disp;
/***************************** Methods and Functions**************************************/
void money_start(void)
{
    dec.setInsertedMoney(0);//sets the ammount of money at the start to 0
}


void Coffee_init(void)//Method that prepares the machine to start working
{
    dec.setChange_Dispensed(0);
    dec.setMoney_Recieved(0);

    //init methodes that prepare the machine
    disp.dispenser_initialise();
    disp.keyboard_initialise();
    disp.dispenser_initialise();
    disp.change_dispenser_initialise();
    //startline of the display
    disp.display_show("----------------------- Coffee Vending Machine--------------------------");
}

void password_verifying(void)//verifies the password
{

    do{
    unsigned int pas;
    cin >> pas;
    dec.setPassword_enter(pas);

    }while ((dec.getPassword_enter()== dec.getPasswordset())!=0);
}

void Password_reset(unsigned int new_password)
{
    dec.setPasswordset(new_password);
}

void report_writing()//Starts the logging for the maintainance
{
    std::ofstream Outfile;
    Outfile.open("Report.txt");

    //writes all the nessacery files to the .txt file
    Outfile << "\nThe total amount of inserted money is:" << dec.getMoney_Recieved();
    Outfile << "\nThe total amount of profit is:" << dec.getMoney_Recieved() - dec.getChange_Dispensed();
    Outfile << "\nThe amount of change still available is:" << dec.getChangeLeft();
    Outfile << "\nThe amount of Cuppuccino still availble is:"<<  dec.getCappuccino_amount();
    Outfile << "\nThe amount of Macchiato still availble is:"<< dec.getMacchiato_ammount();
    Outfile << "\nThe amount of Normal coffee still availble is:"<< dec.getCoffee_Ammount();
    Outfile.close();

}

void Fill_Money(int *amount)
{
    dec.setChange(dec.getChangeLeft()+*amount);
}

void Fill(char kind,unsigned int amount)//void function that fills up the Machine
{
    int amountfilled;
    switch (kind) {
    case 'A':
        amountfilled = amount + dec.getCappuccino_amount();
        if(amountfilled <= 0)
        {
            cout << "The Amount of Cappucino that is in the system is low.\n";
            cout <<  "Please add some more to let the machine work. The machine will order 50 Grams of Cappucino also\n";
        }
        dec.setCappuccino_amount(amountfilled);
        break;
    case 'B':
        amountfilled = amount + dec.getCoffee_Ammount();
        if(amountfilled <= 0)
        {
            cout << "The Amount of Coffee that is in the system is low.\n";
            cout << "Please add some more to let the machine work. The machine will order 50 Grams of cofffe also\n";
        }
        dec.setCoffee_Ammount(amountfilled);
        break;
    case 'C':
        amountfilled = amount + dec.getMacchiato_ammount();
        {
            cout << "The Amount of Coffee that is in the system is low.\n";
            cout << "Please add some more to let the machine work. The machine will order 50 Grams of cofffe also\n";
        }
        dec.setMacchiato_ammount(amountfilled);
        break;
    default:
        break;
    }
}

void menu_filling(void)//void method that displays a menu to fill up the machine with new bevrages
{
    char Fill_Select;
    unsigned int amount;
    //displays a menu for filling
    puts("\nWhat type of coffee that you want to fill?");
    puts("Press 1 for Cappuccino.");
    puts("Press 2 for Normal coffee.");
    puts("Press 3 for Macchiato.");
    cin >> Fill_Select;
    getchar();

    switch (Fill_Select){
    //case 'c' is for filling the Cappuccino
    case '1': cout << "Enter the amount of Cappuccino that you have filled(in grams):";
        cin >> amount;
        Fill('A',amount);
        break;
        //case 'n' is for filling the Normall Cofeve
    case '2': cout << "Enter the amount of Normal coffee that you have filled(in grams):";
        cin >> amount;
        Fill('B',amount);
        break;
        //case 'm' is for filling the Macchiato
    case '3': cout << "Enter the amount of Macchiato that you have filled(in grams):";
        cin >> amount;
        Fill('C',amount);
        break;

    default: //default output
        cout << "Wrong Selection";
    }
}

void dispense_coffee(const int *money, unsigned int moneybevrage)//a void method that dispenses the bevrage
{
    dec.setMoney_Recieved(dec.getMoney_Recieved()+*money);
    cout << "\nEnough Money!(%d)Thanks!"<< *money;
    cout << "\nYour Change is:%d cent"<< *money-moneybevrage;
    cout << "\nTake your Coffee!\n\n\n";
    sleep(1);
}

void service_machine()//method that starts up a reviceing programm for the machine
{
    int number;
    //startup for maintainance
    password_verifying();
    cout << "\n\n##Service Menu##\n";
    cout << "What would you like to do?";
    cout << "Select your choice:";

    //Menu for maintainance
    cout << "Press:1, to fill coffee.";
    cout << "Press:2, to fill change.";
    cout << "Press:3, to go back to the main menu.";
    cout << "Press:4, to restart(Report Writing).";
    cin >> number;
    dec.setService_Sel(number);

    switch(dec.getService_Sel())
    {
    case 1:
        menu_filling();
        break;

    case 2://refills the change of the machine
        int amount_money_filled;
        cout << "Enter the amount of change that you have filled (in cent):";
        cin >> amount_money_filled ;
        Fill_Money(&amount_money_filled);
        break;

    case 3://returns to startmenu
        dec.next_state= dec.S_INITIALISED;
        break;

    case 4://writes a report for the
        cout << "Writing report.\n";
        report_writing();
        cout << "Restrating.......\n";
        fflush(stdin);
        dec.next_state = dec.S_START;
        break;
        /* case 5:
      puts("Type in new password:\n");
      Password_reset(&passwordset);
      scanf("%d",&passwordset);
      break;*/

    default: //if there is no valid input, returns a default
        cout << "Wrong Selection";
    }
}

void subtracting_amount(unsigned int *type) // method that reduces the emptys the machine with ammounts of 10
{
    switch(*type){
    case (0): dec.setCoffee_Ammount(dec.getCoffee_Ammount()-10);
        break;
    case (1): dec.setCappuccino_amount(dec.getCappuccino_amount()-10);
        break;
    case (2): dec.setMacchiato_ammount(dec.getMacchiato_ammount()-10);
        break;
    }
}

/**********************************EVENTS******************************/

subsystems::event_t check_amount(unsigned int *type)//Event that checks the amount of bevrages in the machine
{
    if(*type=0)//if the ammount of the bevarge is empty it will return a fault
    {
        cout<< "\nSorry,there is not enough coffee of this type\n";
        cout<< "Please select anothor type\n";
        dec.next_state = dec.S_COFFEE_SELECTION;
    }

    else
    {
        dec.next_state = dec.S_WAIT_FOR_COINS;
    }
}

event_t subsystems::check_cents(unsigned int coinValue)//event that checks if the amount of money is enough to buy the bevrage
{
    insertedMoney += coinValue;
    if (insertedMoney >= cost_bevrage)
    {
        return E_ENOUGH;
    }

    else
    {
        return E_NOT_ENOUGH;
    }
}

event_t check_change(void)//checks if there is enough changed
{
    change = insertedMoney - cost_bevrage;
    if (ChangeLeft >= change)
    {
        ChangeLeft -= change;
        Change_Dispensed += change;
        return E_ENOUGH_CHANGE;
    }
    return E_NOT_ENOUGH_CHANGE;
}
event_t coffee_selection()//event that select the bevrage that is wanted
{
    unsigned int bevrage_select;
    while(1){
        puts("\n\n##Select your bevrage##");

        puts("1-- MACCHIATO       price: 90 cent ");
        puts("2-- NORMAL COFFEE   price: 60  cent ");
        puts("3-- CAPPUCCINO      price: 110  cent ");
        puts("4-- Service");
        scanf("%d", &bevrage_select);
        getchar();

        switch(bevrage_select)
        {
        case 1:
            return E_MACCHIATO;
            break;
        case 2:
            return E_NORMAL_COFFEE;
            break;
        case 3:
            return E_CUPPUCCINO;
            break;
        case 4:
            return E_SERVICE;
            break;
        default:
            puts("Wrong Selection");

        }
    }
}

event_t coin_insertion()//event for adding the money into the machine
{
    unsigned int input_money;
    while(1)
    {
        puts("##Select your input##");
        puts("1-- 10 Cent");
        puts("2-- 20 Cent");
        puts("3-- 50 Cent");
        puts("4-- 100 Cent");
        puts("5-- Main Menu");
        scanf("%d", &input_money);
        getchar();

        switch(input_money)
        {
        case 1:
            return dec.E_10C;
            break;
        case 2:
            return dec.E_20C;
            break;
        case 3:
            return dec.E_50C;
            break;
        case 4:
            return dec.E_100C;
            break;
        case 5:
            return dec.E_BACK;
            break;

        default:
            puts("Wrong Selection");
        }
    }
}

// start of the machine itself
event_t event_handler(event)
{
    static state_t state = dec.S_START;

    dec.setPrice_Cappuccino(110);
    dec.setPrice_Macchiato(90);
    dec.setPrice_Normal_Coffee(60);
    dec.setMacchiato_ammount(10);
    dec.setCappuccino_amount(10);
    dec.Coffee_Ammount(10);
    dec.setChangeLeft(100);


    while (1){
        // ********************************Switch for States ********************************//
        switch(state){

        case dec.S_START:
            switch(event){
            case dec.E_START:
                Coffee_init();
                next_state = dec.S_INITIALISED;
                break;
            }
            break;
        case dec.S_INITIALISED:
            switch(event){
            case dec.E_CONTINUE:
                next_state = dec.S_COFFEE_SELECTION;
                break;
            }
            break;

        case dec.S_COFFEE_SELECTION:
            switch(event){
            case E_MACCHIATO:
                printf("You have chosen #Macchiato#!");
                cost_bevrage= price_Macchiato;
                check_amount(&Macchiato_ammount);
                Kind_Bevrage= 2;
                break;

            case E_NORMAL_COFFEE:
                printf("You have chosen #Normal coffee#!");
                cost_bevrage= price_Normal_Coffee;
                check_amount(&Coffee_Ammount);
                Kind_Bevrage=0;
                break;

            case E_CUPPUCCINO:
                printf("You have chosen #Cuppuccino#!");
                cost_bevrage =price_Cappuccino;
                check_amount(&Cappuccino_amount);
                Kind_Bevrage= 1;
                break;

            case E_SERVICE:
                puts("You have chosen #Service#!");
                puts("Please insert your password:");
                service_machine();
            }
            break;//end of state selection

        case S_WAIT_FOR_COINS:
            switch (event)
            {
            case E_10C:
                next_state = S_DETECTED_10C;
                break;

            case E_20C:
                next_state = S_DETECTED_20C;
                break;

            case E_50C:
                next_state = S_DETECTED_50C;
                break;

            case E_100C:
                next_state = S_DETECTED_100C;
                break;

            case E_BACK:
                next_state = S_INITIALISED;
                break;

            default:
                next_state = S_WAIT_FOR_COINS;
            }
            break;//end of case for money input

        case S_DETECTED_10C:
            switch (event)
            {
            case E_ENOUGH:
                next_state = S_DISPENSE_CHANGE;
                break;
            case E_NOT_ENOUGH:
                next_state = S_WAIT_FOR_COINS;
                break;
            default:
                display_show("S_10C received unknown event");
                next_state = S_WAIT_FOR_COINS;
                break;
            }
            break;

        case S_DETECTED_20C:
            switch (event)
            {
            case E_ENOUGH:
                next_state = S_DISPENSE_CHANGE;
                break;

            case E_NOT_ENOUGH:
                next_state = S_WAIT_FOR_COINS;
                break;

            default:
                display_show("S_DETECTED_20C received event not handled");
                next_state = S_WAIT_FOR_COINS;
                break;
            }
            break;

        case S_DETECTED_50C:
            switch (event)
            {
            case E_ENOUGH:
                next_state = S_DISPENSE_CHANGE;
                break;

            case E_NOT_ENOUGH:
                next_state = S_WAIT_FOR_COINS;
                break;

            default:
                display_show("S_DETECTED_50C received event "
                             "not handled");
                next_state = S_WAIT_FOR_COINS;
                break;
            }
            break;

        case S_DETECTED_100C:
            switch (event)
            {
            case E_ENOUGH:
                next_state = S_DISPENSE_CHANGE;
                break;

            case E_NOT_ENOUGH:
                next_state =  S_WAIT_FOR_COINS;
                break;

            default:
                display_show("S_DETECTED_100C received event "
                             "not handled");
                next_state = S_WAIT_FOR_COINS;
                break;
            }
            break;

        case S_DISPENSE_CHANGE:
            switch (event){
            case E_ENOUGH_CHANGE:
                next_state = S_DISPENSE_COFFEE;
                break;

            case E_NOT_ENOUGH_CHANGE:
                puts("The machine has been stopped");
                puts("Ask administrator to fill change storage\n");
                puts("Waiting for service to start\n");
                next_state = S_SERVICE;
                break;
            }
            break;

        case S_DISPENSE_COFFEE:
            dispense_coffee(&insertedMoney);
            system("@cls||clear");
            next_state= S_INITIALISED;
            break;

        case S_SERVICE:
            next_state= S_INITIALISED;
            system("@cls||clear");
            break;

        }
        // ********************************Switch for Events ********************************//
        switch(next_state){

        case S_START:
            event= E_START;
            break;

        case S_INITIALISED:
            money_start();
            event = E_CONTINUE;
            break;

        case S_COFFEE_SELECTION:
            event = coffee_selection();
            break;

        case S_WAIT_FOR_COINS:
            puts("\n\nPlease insert some coins!");
            event=coin_insertion();
            event = event;
            break;

        case S_DETECTED_10C:
            event= check_cents(10);
            break;

        case S_DETECTED_20C:
            event= check_cents(20);
            break;

        case S_DETECTED_50C:
            event= check_cents(50);
            break;

        case S_DETECTED_100C:
            event= check_cents(100);
            break;

        case S_DISPENSE_CHANGE:
            event=check_change();
            break;

        case S_DISPENSE_COFFEE:
            subtracting_amount(&Kind_Bevrage);
            break;

        case S_SERVICE:
            service_machine();
            break;
        }
        state = next_state;
    }
}
