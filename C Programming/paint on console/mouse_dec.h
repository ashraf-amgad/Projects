#include <windows.h>

#define NO_MOUSE_BUTTON         0
#define MOUSE_BUTTON_LEFT       1
#define MOUSE_BUTTON_RIGHT      2

typedef struct _DATA_MOUSE{
        unsigned char buttonPressed;
        COORD coordinates;
}DMOUSE, *PDMOUSE;


void mouse(PDMOUSE m);


