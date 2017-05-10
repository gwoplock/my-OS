/*
 * InterruptDiscriptorTable.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: garrett
 */

#include "InterruptDiscriptorTable.h"

InterruptDiscriptorTable::InterruptDiscriptorTable( ) {
	// Possibly put &'s infront of isr_x etc
	idt[0] = encode((uint32_t) (unsigned) &isr_0, (uint16_t) 0x08);
	idt[1] = encode((uint32_t) (unsigned) &isr_1, (uint16_t) 0x08);
	idt[2] = encode((uint32_t) (unsigned) &isr_2, (uint16_t) 0x08);
	idt[3] = encode((uint32_t) (unsigned) &isr_3, (uint16_t) 0x08);
	idt[4] = encode((uint32_t) (unsigned) &isr_4, (uint16_t) 0x08);
	idt[5] = encode((uint32_t) (unsigned) &isr_5, (uint16_t) 0x08);
	idt[6] = encode((uint32_t) (unsigned) &isr_6, (uint16_t) 0x08);
	idt[7] = encode((uint32_t) (unsigned) &isr_7, (uint16_t) 0x08);
	idt[8] = encode((uint32_t) (unsigned) &isr_8, (uint16_t) 0x08);
	idt[9] = encode((uint32_t) (unsigned) &isr_9, (uint16_t) 0x08);
	idt[10] = encode((uint32_t) (unsigned) &isr_10, (uint16_t) 0x08);
	idt[11] = encode((uint32_t) (unsigned) &isr_11, (uint16_t) 0x08);
	idt[12] = encode((uint32_t) (unsigned) &isr_12, (uint16_t) 0x08);
	idt[13] = encode((uint32_t) (unsigned) &isr_13, (uint16_t) 0x08);
	idt[14] = encode((uint32_t) (unsigned) &isr_14, (uint16_t) 0x08);
	idt[15] = encode((uint32_t) (unsigned) &isr_15, (uint16_t) 0x08);
	idt[16] = encode((uint32_t) (unsigned) &isr_16, (uint16_t) 0x08);
	idt[17] = encode((uint32_t) (unsigned) &isr_17, (uint16_t) 0x08);
	idt[18] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[19] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[20] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[21] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[22] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[23] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[24] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[25] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[26] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[27] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[28] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[29] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[30] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[31] = encode((uint32_t) (unsigned) &isr_18, (uint16_t) 0x08);
	idt[32] = encode((uint32_t) (unsigned) &irq_0, (uint16_t) 0x08);
	idt[33] = encode((uint32_t) (unsigned) &irq_1, (uint16_t) 0x08);
	idt[34] = encode((uint32_t) (unsigned) &irq_2, (uint16_t) 0x08);
	idt[35] = encode((uint32_t) (unsigned) &irq_3, (uint16_t) 0x08);
	idt[36] = encode((uint32_t) (unsigned) &irq_4, (uint16_t) 0x08);
	idt[37] = encode((uint32_t) (unsigned) &irq_5, (uint16_t) 0x08);
	idt[38] = encode((uint32_t) (unsigned) &irq_6, (uint16_t) 0x08);
	idt[39] = encode((uint32_t) (unsigned) &irq_7, (uint16_t) 0x08);
	idt[40] = encode((uint32_t) (unsigned) &irq_8, (uint16_t) 0x08);
	idt[41] = encode((uint32_t) (unsigned) &irq_9, (uint16_t) 0x08);
	idt[42] = encode((uint32_t) (unsigned) &irq_10, (uint16_t) 0x08);
	idt[43] = encode((uint32_t) (unsigned) &irq_11, (uint16_t) 0x08);
	idt[44] = encode((uint32_t) (unsigned) &irq_12, (uint16_t) 0x08);
	idt[45] = encode((uint32_t) (unsigned) &irq_13, (uint16_t) 0x08);
	idt[46] = encode((uint32_t) (unsigned) &irq_14, (uint16_t) 0x08);
	idt[47] = encode((uint32_t) (unsigned) &irq_15, (uint16_t) 0x08);
	size = 48;
}

IdtEntry InterruptDiscriptorTable::encode(uint32_t offset, uint16_t selector) {
	//make our selfs something to put this shit in
	IdtEntry toReturn;
	//probably not necissary but one can never be too careful
	toReturn.zero = 0;
	//get the upper 1/2 of the offset
	toReturn.offset_1 = offset & 0x0000FFFF;
	//what segment this should run in. (bullshit)
	toReturn.selector = selector;
	//how selector should be done
	/*toReturn.type_attr = (1 << 7);
	 toReturn.type_attr |= (dpl << 6);
	 toReturn.type_attr |= (s << 4);
	 toReturn.type_attr |= type;*/
	//what type of gate we are dealing with. (more bullshit, if im loading it with LIDT it should know its an idt)
	toReturn.type_attr = 0x8E;
	//other bit of the offset
	toReturn.offset_2 = (offset & 0xFFFF0000) >> 16;
	//send it back
	return toReturn;
}
