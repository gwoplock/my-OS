#ifndef _PROGRAMMABLE_INTERVAL_TIMER_H_
#define _PROGRAMMABLE_INTERVAL_TIMER_H_

#include "Global.h"
#include "drivers/generic/SpecialDevice.h"
#include "Kernel.h"
#include "drivers/ProgrammableInterruptController.h"
#include "utils/printf/Printf.h"
struct PIT_CMD{
    uint8_t BCD:1;
    uint8_t opMode:3;
    uint8_t accessMode:2;
    uint8_t channel:2;
}__attribute__((__packed__));

class ProgrammableIntervalTimer : public SpecialDevice{
    private:
        uint16_t divisor = 1000;
        //TODO eventually there will be more then one timer
        volatile uint64_t ticksRemaining = 0;
        static const int interruptLine = 0;
    public:
        ProgrammableIntervalTimer() : SpecialDevice(){
            PIT_CMD cmd = {0,3,3,0};
            outb(0x43, *(uint8_t*)&cmd);
            outb(0x40, divisor & 0xFF);
            outb(0x40, (divisor >>8) & 0xFF);
            
        }
        void tick(){
            ticksRemaining--;
        }
        void setTimer(unsigned int ticks){
            ticksRemaining = ticks;
            IRQClearMask(interruptLine);
            while(ticksRemaining != 0){
                ;
            }
            IRQSetMask(interruptLine);

        }
};

#endif