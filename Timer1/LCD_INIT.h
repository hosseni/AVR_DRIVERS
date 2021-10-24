
#ifndef LCD_INIT_H_
#define	LCD_INIT_H_

#include "Std_Types.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"

void LCD_INIT(void);
void LCD_COMMAND(u8 cmd);
void LCD_CHAR(u8 data);
void LCD_WORD(u8 * ptr);
void CLEAR_LCD(void);
void RowAndColume_SET(u8 RowNo, u8 ColumeNo);
#endif
