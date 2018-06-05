//#include <QApplication>
#include <string>
#include <iostream>
#include "declares.h"
#include "statemachine.h"
#include "display.h"

using namespace std;

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //Mainwindow disp;
    //disp.show();
    event_handler(E_START);
    return 0 ;//a.exec()//;
}
