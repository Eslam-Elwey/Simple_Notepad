#ifndef SQUARE_H_
#define SQUARE_H_

/* Single Line Values 
    218 for the top-left corner (┌)
	191 for the top-right corner (┐)
	192 for the bottom-left corner (└)
	217 for the bottom-right corner (┘)
	196 for horizontal lines (─)
	179 for vertical lines (│)

	*/

#define SQUARE_BORDER_COLOR					TEXT_Pink

/* 5F  1F  8E */
#define CONTENT_COLOR						0x8E

#define SQUARE_LEFT_CORNER_X_VALUE			55
	
#define SQUARE_WIDTH_VALUE					40
	
#define SQUARE_RIGHT_CORNER_X_VALUE			(SQUARE_LEFT_CORNER_X_VALUE + SQUARE_WIDTH_VALUE)
	
#define SQUARE_TOP_CORNER_Y_VALUE			10
	
#define SQUARE_LENGTH_VALUE					15
	
#define SQUARE_BOTTOM_CORNER_Y_VALUE		(SQUARE_TOP_CORNER_Y_VALUE + SQUARE_LENGTH_VALUE)
	
#define TOP_LEFT_CORNER_ASCII_VALUE			201

#define TOP_RIGHT_CORNER_ASCII_VALUE		187

#define BOTTOM_LEFT_CORNER_ASCII_VALUE		200

#define BOTTOM_RIGHT_CORNER_ASCII_VALUE		188

#define HORIZONTAL_LINE_ASCII_VALUE			205

#define VERTICCAL_LINE_ASCII_VALUE			186



void Draw_Square(void) ;


#endif //SQUARE_H_ 