/*
 * bit_math.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Sleem
 */

#ifndef GPIO_BIT_MATH_H_
#define GPIO_BIT_MATH_H_
#define SET_BIT(REG,BITNO) (REG) |=  (1 << (BITNO))
#define CLR_BIT(REG,BITNO) (REG) &= ~(1 << (BITNO))
#define TOG_BIT(REG,BITNO) (REG) ^=  (1 << (BITNO))
#define GET_BIT(REG,BITNO) (((REG) >> (BITNO)) & 0x01)

// asking for bit value
#define Bit_Is_Set(REG,BITNO) (REG & (1<<BITNO))
#define Bit_Is_Clear(REG,BITNO) (!(REG & (1<<BITNO)))

// this used in caes of rotate register or need of circular register
#define REG_BITS 8 // the width of your register by defult it will equal 8 bit or 16 bit register
#define ROTATE_LEFT(REG,NoOfShifts)(REG = ((REG << NoOfShifts) | (REG >> (REG_BITS-NoOfShifts))))
#define ROTATE_RIGHT(REG,NoOfShifts)(REG = ((REG >> NoOfShifts) | (REG << (REG_BITS-NoOfShifts))))
#define SWAP_NIBBLES(REG) ( (REG & 0x0F)<<4 | (REG & 0xF0)>>4 )

/*int logical_right_shift(int x, int n)
{
    int size = sizeof(char) * 8; // usually sizeof(int) is 4 bytes (32 bits)
    return (x >> n) & ~(((0x1 << size) >> n) << 1);
}*/


#endif /* GPIO_BIT_MATH_H_ */
