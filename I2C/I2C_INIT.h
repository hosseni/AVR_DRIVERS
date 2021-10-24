#ifndef I2C_NIT_H_
#define I2C_NIT_H_

#define TWCR *((volatile u8 *)0x56)
#define TWSR *((volatile u8 *)0x21)
#define TWDR *((volatile u8 *)0x23)
#define TWAR *((volatile u8 *)0x22)
#define TWBR *((volatile u8 *)0x52)



#include "Std_Types.h"

void I2C_Master_INIT(void);
void I2C_Slave_INIT(void);

void I2C_Start_Condition(void);
void I2C_Stop_Condition(void);
void I2C_Repeat_Start(void);

void I2C_Send_Slave_Address_With_Write_Req(u8 Slave_Address);
void I2C_Send_Slave_Address_With_Read_Req(u8 Slave_Address);
void I2C_Write_Data(u8 data);
u8 I2C_Read_Data(void);

#endif
