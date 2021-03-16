#ifndef __NB_DDS
#define __NB_DDS

#include "nworkbench.h"

class nBlock_DDS: public nBlockNode<1> {
public:
    nBlock_DDS(PinName MOSI, PinName SCK, PinName pinSelect, uint32_t freqDefault);
    uint16_t cRegister = 0; 
    #define RESET      8     
    #define B28       13  
    #define TRIANGLE   1  
    #define SQUARE1    5  
    #define SQUARE2    3
    #define SINUS      0
   
    uint16_t setBit(uint16_t reg, uint16_t bit);
    uint16_t clearBit(uint16_t reg, uint16_t bit);

    void write_SPI(uint16_t dat);
    void setFreq(uint32_t FREQ);
    void setFreq(uint32_t FUNCTION);

    void triggerInput(nBlocks_Message message);
	void endFrame();

    uint32_t frequency;
    uint32_t function;

private:
    SPI _spi;
    DigitalOut _fsync;
    uint32_t must_update = 0;
};

#endif
