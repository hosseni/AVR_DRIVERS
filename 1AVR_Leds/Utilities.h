

#define set_bit(num, Bit_num) num |= (1 << Bit_num)
#define clear_bit(num, Bit_num) num &=  ~(1 << Bit_num)
#define toggle_bit(num, Bit_num)   num ^= (1 << Bit_num)
#define get_bit(num, Bit_num) (num >> Bit_num) & 1