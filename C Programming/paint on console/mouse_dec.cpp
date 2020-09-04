
#include "mouse_dec.h"


void mouse(PDMOUSE m)
{
      HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
      DWORD mode;
      DWORD read;
      INPUT_RECORD go[1];

      BOOL buttonMouseValidate = FALSE;

      GetConsoleMode(in, &mode);
      SetConsoleMode(in, (mode | ENABLE_MOUSE_INPUT) & ~ENABLE_QUICK_EDIT_MODE & ~ENABLE_INSERT_MODE);

      while(!buttonMouseValidate)
      {
        ReadConsoleInput(in, go, 1, &read);
        if(go[0].EventType == MOUSE_EVENT)
        {
          if((buttonMouseValidate = go[0].Event.MouseEvent.dwButtonState) == FROM_LEFT_1ST_BUTTON_PRESSED)
            m->buttonPressed = MOUSE_BUTTON_LEFT;
          else if((buttonMouseValidate = go[0].Event.MouseEvent.dwButtonState) == RIGHTMOST_BUTTON_PRESSED)
            m->buttonPressed = MOUSE_BUTTON_RIGHT;

          if(buttonMouseValidate)
          {
            m->coordinates.X = go[0].Event.MouseEvent.dwMousePosition.X;
            m->coordinates.Y = go[0].Event.MouseEvent.dwMousePosition.Y;
          }
        }
      }
      SetConsoleMode(in, mode);
}





