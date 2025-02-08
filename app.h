#ifndef APP_H
#define APP_H



#define UP_BUTTON					72
#define DOWN_BUTTON					80
#define ENTER_BUTTON				13
#define TAB_BUTTON					9
#define ESC_BUTTON					27
#define LEFT_BUTTON					75
#define RIGHT_BUTTON				77
#define HOME_BUTTON					71
#define END_BUTTON					79
#define BACKSPACE_BUTTON			8
#define DELETE_BUTTON				83

#define EXTENDED_VALUE			    -32

#define TOTAL_SPECIAL_KEYS			11

typedef enum 
{
	SPECIAL_KEY = 0 ,
	NORMAL_KEY=1
}key_type;

void Fill_SpacesInArray(void) ;

void Display_Content(void) ;

void Get_PressedKey(void);

key_type CheckIfInputKeyIs_Special (char key) ;

void Handle_InputKey(void);

void Display_Input_String(void);

void Shift_SpecificRowLeftByOne( int xpos);

void Shift_UsingPointers(void);

void Shift_RightToInsert(void) ;


#endif //APP_H