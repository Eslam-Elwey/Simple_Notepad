#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "STD_Types.h"
#include "cmd_Handler.h"
#include "Square.h"
#include "app.h"



int current_PosX = SQUARE_LEFT_CORNER_X_VALUE + 1 ;
int current_PosY = SQUARE_TOP_CORNER_Y_VALUE + 1 ;
char Input_Key ;

char Notpad_Content[SQUARE_LENGTH_VALUE-1][SQUARE_WIDTH_VALUE] = {{0}};

char *first_ptrPos = (char*)Notpad_Content ;
char *last_ptrPos = (char*)(&Notpad_Content + 1);
char *current_ptrPos = NULL ;

char Sepcial_Key_Arr[TOTAL_SPECIAL_KEYS] = {UP_BUTTON	,	
		                                    DOWN_BUTTON	,	
											ENTER_BUTTON,
                                            TAB_BUTTON	,	
											ESC_BUTTON	,		
                                            LEFT_BUTTON	,	
                                            RIGHT_BUTTON,	
                                            HOME_BUTTON,		
                                            END_BUTTON,		
                                            BACKSPACE_BUTTON,
                                            DELETE_BUTTON	
											} ;






void Fill_SpacesInArray(void) 
{
	current_ptrPos = first_ptrPos ;

	for (int i = 0 ;i<SQUARE_LENGTH_VALUE-1;i++)
	{
		memset(Notpad_Content[i],' ',SQUARE_WIDTH_VALUE-1);
		Notpad_Content[i][SQUARE_WIDTH_VALUE-1] = '\0' ;
	}

	
}



void Get_PressedKey(void)                   
{
	cmdGoToXY(current_PosX,current_PosY);
	cmdSetConsoleColour(TEXT_DWhite) ;
	fflush(stdin) ;                         
	Input_Key = getch() ;                
	if (Input_Key==EXTENDED_VALUE)          
	{                                       
		Input_Key = getch() ;               
	}
}

key_type CheckIfInputKeyIs_Special (char key)
{
	key_type ret_val = NORMAL_KEY ;
		
	int i ;
	
	for (i=0;i<TOTAL_SPECIAL_KEYS ;i++)
	{
		if (key==Sepcial_Key_Arr[i])
		{
			ret_val = SPECIAL_KEY ;
			break ;
		}
	}	
	
	
	return ret_val ;
}

void Handle_InputKey(void)
{
	key_type key_state ;
	
	
	key_state = CheckIfInputKeyIs_Special(Input_Key);
	
	
	/* Change Position For Special Key*/
	if (SPECIAL_KEY==key_state)
	{
		cmdGoToXY(2,2) ;
		printf("Special Key  ");
		switch (Input_Key)
		{
			case (UP_BUTTON):
				current_PosY--;
				
				if (current_ptrPos<first_ptrPos)
				{
					current_ptrPos = first_ptrPos ;
				}
				
				current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
				current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
				
			break ;
			
			case (DOWN_BUTTON):
				current_PosY++;
				
				if (current_PosY==SQUARE_BOTTOM_CORNER_Y_VALUE)
				{
					current_PosY = SQUARE_BOTTOM_CORNER_Y_VALUE -1 ;
				}
				current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
				current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
				
			break ;
			
			case (RIGHT_BUTTON):
				current_PosX++ ;
				
				if (current_PosX==SQUARE_RIGHT_CORNER_X_VALUE)
				{
					current_PosX = SQUARE_RIGHT_CORNER_X_VALUE-1 ;
				}
				
				current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
				current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
			break ;
			
			case (LEFT_BUTTON):
				current_PosX--;
				
				if (current_PosX==SQUARE_LEFT_CORNER_X_VALUE)
				{
					current_PosX = SQUARE_LEFT_CORNER_X_VALUE+1 ;
				}
				
				current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
				current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
				
			break ;
			
			case (TAB_BUTTON):
			
				
				current_PosY++ ;
				if (current_PosY==SQUARE_BOTTOM_CORNER_Y_VALUE)
				{
					current_PosY = SQUARE_TOP_CORNER_Y_VALUE +1 ;
				}
				current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
				current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
				
			break ;
			
			case (ESC_BUTTON):
				cmdSetConsoleColour(TEXT_DWhite) ;
				Display_Input_String() ;
				
				cmdDelay(3000) ;
				cmdSetConsoleColour(TEXT_DWhite) ;
				exit(1);
			break ;
			
			case (HOME_BUTTON):
				current_ptrPos = first_ptrPos ;
				current_PosX = SQUARE_LEFT_CORNER_X_VALUE + 1 ;
				current_PosY = SQUARE_TOP_CORNER_Y_VALUE + 1 ;
			break ;
			
			case (END_BUTTON):
				
				current_PosX = SQUARE_RIGHT_CORNER_X_VALUE -1 ;
				current_PosY = SQUARE_BOTTOM_CORNER_Y_VALUE -1 ;
				current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
				current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
				
			break ;
			
			case (ENTER_BUTTON):
				current_PosX = SQUARE_LEFT_CORNER_X_VALUE + 1 ;
				current_PosY++ ;
				if (current_PosY==SQUARE_BOTTOM_CORNER_Y_VALUE)
				{
					current_PosY = SQUARE_BOTTOM_CORNER_Y_VALUE -1 ;
				}
				current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
				current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
			break ;
			
			case (DELETE_BUTTON):
			
				if (current_PosX==SQUARE_LEFT_CORNER_X_VALUE)
				{
					current_PosX = SQUARE_LEFT_CORNER_X_VALUE + 1 ;
					current_PosY-- ;
					if (current_PosY==SQUARE_TOP_CORNER_Y_VALUE)
					{
						current_PosY = SQUARE_TOP_CORNER_Y_VALUE + 1 ;
					}
				}
				
				current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
				current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
				Shift_UsingPointers();
				
			break ;
			
			case (BACKSPACE_BUTTON):
				current_PosX-- ;
				
				if (current_PosX==SQUARE_LEFT_CORNER_X_VALUE)
				{
					current_PosX = SQUARE_RIGHT_CORNER_X_VALUE -1 ;
					current_PosY-- ;
					Notpad_Content[current_PosY-SQUARE_TOP_CORNER_Y_VALUE-1]
					[current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1] =' ' ;
					if (current_PosY==SQUARE_TOP_CORNER_Y_VALUE)
					{
						current_PosY = SQUARE_TOP_CORNER_Y_VALUE + 1 ;
						current_PosX = SQUARE_LEFT_CORNER_X_VALUE+1 ;
						
					}
				}
				current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
				current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
				Shift_SpecificRowLeftByOne(current_PosX);
				
			break ;
			
		}
	}
	
	/*Fill In array position*/
	else if (NORMAL_KEY==key_state)
	{
		cmdGoToXY(2,2) ;
		printf("Normal Key  ");
		if (Notpad_Content[current_PosY-SQUARE_TOP_CORNER_Y_VALUE-1][current_PosX-SQUARE_LEFT_CORNER_X_VALUE]!=' ' &&
		Notpad_Content[current_PosY-SQUARE_TOP_CORNER_Y_VALUE-1][current_PosX-SQUARE_LEFT_CORNER_X_VALUE-2]!=' ')
		{
			Shift_RightToInsert() ;
		}
		Notpad_Content[current_PosY-SQUARE_TOP_CORNER_Y_VALUE-1][current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1] = Input_Key ;
		
		current_PosX++ ;
		if(current_PosX==SQUARE_RIGHT_CORNER_X_VALUE)
		{
			current_PosX = SQUARE_LEFT_CORNER_X_VALUE ;
			current_PosY++ ;
			if (current_PosY==SQUARE_BOTTOM_CORNER_Y_VALUE)
			{
				current_PosY = SQUARE_TOP_CORNER_Y_VALUE ;
			}
		}
		current_ptrPos = first_ptrPos + (current_PosY - SQUARE_TOP_CORNER_Y_VALUE-1) ;
		current_ptrPos += (current_PosX-SQUARE_LEFT_CORNER_X_VALUE-1) ;
	}
}

void Display_Content(void)
{
	for (int i = 0 ; i<SQUARE_LENGTH_VALUE-1 ; i++)
	{
		Notpad_Content[i][SQUARE_WIDTH_VALUE-1] = '\0' ;
	}
	for (int i = 0 ; i<SQUARE_LENGTH_VALUE-1 ; i++)
	{
		cmdGoToXY(SQUARE_LEFT_CORNER_X_VALUE+1,SQUARE_TOP_CORNER_Y_VALUE+1+i);
		cmdSetConsoleColour(CONTENT_COLOR);
		puts(Notpad_Content[i]);
	}
}


void Display_Input_String(void)
{
	int i ;
	cmdSetConsoleColour(TEXT_Green);
	cmdGoToXY(3,4) ;
	printf("Notpad_Content : ");
	cmdSetConsoleColour(TEXT_DYellow) ;
	
	for ( i = 0 ; i<SQUARE_LENGTH_VALUE-1 ; i++)
	{
		cmdGoToXY(3,6+i);
		puts(Notpad_Content[i]);
	}
	
	cmdGoToXY(3,6+i+4);
	cmdSetConsoleColour(TEXT_Green);
	printf("Good Bye !!");
	
	cmdGoToXY(3,6+i+6);
}

void Shift_SpecificRowLeftByOne( int xpos)
{
	int i=0 ; 
	Notpad_Content[current_PosY-SQUARE_TOP_CORNER_Y_VALUE-1][xpos-1] = ' ' ;
	for (i=xpos;i<SQUARE_RIGHT_CORNER_X_VALUE-1;i++)
	{
		Notpad_Content[current_PosY-SQUARE_TOP_CORNER_Y_VALUE-1][i-SQUARE_LEFT_CORNER_X_VALUE-1]
		=Notpad_Content[current_PosY-SQUARE_TOP_CORNER_Y_VALUE-1][i-SQUARE_LEFT_CORNER_X_VALUE] ;
	}
}

void Shift_UsingPointers(void)
{
	char *temp_ptr = current_ptrPos ;
	char *next_pos_ptr = temp_ptr +1 ;
	
	while (temp_ptr<last_ptrPos-3)
	{
		temp_ptr++ ;
		next_pos_ptr++ ;
		if (*temp_ptr == '\0')
		{
			temp_ptr++ ;
		}
		if (*next_pos_ptr == '\0')
		{
			next_pos_ptr++ ;
		}
		*temp_ptr = *next_pos_ptr ;
	}
}


void Shift_RightToInsert(void)
{
	char *temp_ptr = last_ptrPos-4 ;
	char *next_pos_ptr = temp_ptr +1 ;
	while (temp_ptr>current_ptrPos)
	{
		temp_ptr-- ;
		next_pos_ptr-- ;
		if (*temp_ptr == '\0')
		{
			temp_ptr-- ;
		}
		if (*next_pos_ptr == '\0')
		{
			next_pos_ptr-- ;
		}
		*next_pos_ptr = *temp_ptr ;
	}
}