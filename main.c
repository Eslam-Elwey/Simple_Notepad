#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "STD_Types.h"
#include "cmd_Handler.h"
#include <string.h>
#include "Square.h"
#include "app.h"




/* gcc app.c cmd_Handler.c main.c Square.c */


int main(void)
{
	
	Draw_Square();
	Fill_SpacesInArray();
	
	while (1)
	{
		Display_Content() ;
		Get_PressedKey() ;
		Handle_InputKey() ;
	}
	
	
	return 0;
}

