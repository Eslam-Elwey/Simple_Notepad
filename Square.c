#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "cmd_Handler.h"
#include "Square.h"




void Draw_Square(void)
{
	int row  , col ;
	
	cmdClearScreen() ;
	cmdSetConsoleColour(SQUARE_BORDER_COLOR);
	SetConsoleOutputCP(437);
	
	for (row=SQUARE_TOP_CORNER_Y_VALUE;row<=SQUARE_BOTTOM_CORNER_Y_VALUE;row++)
	{
		for (col=SQUARE_LEFT_CORNER_X_VALUE;col<=SQUARE_RIGHT_CORNER_X_VALUE;col++)
		{
			if ((row==SQUARE_TOP_CORNER_Y_VALUE)&&(col==SQUARE_LEFT_CORNER_X_VALUE))
			{
				cmdGoToXY(col,row);
				printf("%c",TOP_LEFT_CORNER_ASCII_VALUE);
			}
			else if  ((row==SQUARE_BOTTOM_CORNER_Y_VALUE)&&(col==SQUARE_LEFT_CORNER_X_VALUE))
			{
				cmdGoToXY(col,row);
				printf("%c",BOTTOM_LEFT_CORNER_ASCII_VALUE);
			}
			else if  ((row==SQUARE_TOP_CORNER_Y_VALUE)&&(col==SQUARE_RIGHT_CORNER_X_VALUE))
			{
				cmdGoToXY(col,row);
				printf("%c",TOP_RIGHT_CORNER_ASCII_VALUE);
			}
			else if  ((row==SQUARE_BOTTOM_CORNER_Y_VALUE)&&(col==SQUARE_RIGHT_CORNER_X_VALUE))
			{
				cmdGoToXY(col,row);
				printf("%c",BOTTOM_RIGHT_CORNER_ASCII_VALUE);
			}
			else if  ((col==SQUARE_LEFT_CORNER_X_VALUE)||(col==SQUARE_RIGHT_CORNER_X_VALUE))
			{
				cmdGoToXY(col,row);
				printf("%c",VERTICCAL_LINE_ASCII_VALUE);
			} 
			else if  ((row==SQUARE_TOP_CORNER_Y_VALUE)||(row==SQUARE_BOTTOM_CORNER_Y_VALUE))
			{
				cmdGoToXY(col,row);
				printf("%c",HORIZONTAL_LINE_ASCII_VALUE);
			} 
			
		}
	}
	
	for (row=SQUARE_TOP_CORNER_Y_VALUE+1;row<SQUARE_BOTTOM_CORNER_Y_VALUE;row++)
	{
		for (col=SQUARE_LEFT_CORNER_X_VALUE+1;col<SQUARE_RIGHT_CORNER_X_VALUE;col++)
		{
			cmdGoToXY(col,row);
			cmdSetConsoleColour(CONTENT_COLOR) ;
			printf(" ");
		}
	}
	
	cmdSetConsoleColour(TEXT_DWhite) ;
	
	cmdGoToXY(SQUARE_LEFT_CORNER_X_VALUE+1,SQUARE_TOP_CORNER_Y_VALUE+1);
	
}