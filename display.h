#ifndef DISPLAY_H
#define DISPLAY_H

class display
{
public:
void display_show(const char *text);
void display_initialise(void);
void dispenser_initialise(void);
void change_dispenser_initialise(void);
void keyboard_initialise(void);
void display_debug_info(const char *text);
};

#endif // DISPLAY_H
