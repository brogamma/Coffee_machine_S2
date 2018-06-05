#ifndef SETTINGS_H
#define SETTINGS_H

class settings{
private:
    unsigned int Stock_machiato;
    unsigned int Stock_Coffee;
    unsigned int Stock_Cap;
    unsigned int Min_stock_mac;
    unsigned int Min_stock_cof;
    unsigned int Min_stock_cap;

public:
    int getStockMin(int value);
    int getAmountInstock(int value);
    void setAmountInStock(int bevrage, int amount);
    void setMinInStock(int bevrage, int new_amount);
};
#endif // SETTINGS_H
