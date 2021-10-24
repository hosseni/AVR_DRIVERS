#ifndef Utili
#define Utili

#define SET_BIT(num, Bit_num) num |= (1 << Bit_num)
#define CLR_BIT(num, Bit_num) num &=  ~(1 << Bit_num)
#define TOGGLE_BIT(num, Bit_num)   num ^= (1 << Bit_num)
#define GET_BIT(num, Bit_num) (num >> Bit_num) & 1

#endif
