#define CHIP_6713

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dsk6713.h"
#include "dsk6713_led.h"
#include "dsk6713_aic23.h"

#define SAMPLE_SIZE 16000
#define PI 3.1415

int buffer_in[SAMPLE_SIZE];
int buffer_out[SAMPLE_SIZE];

void main(void)
{
    DSK6713_AIC23_Config config = DSK6713_AIC23_DEFAULTCONFIG; //codec initialization with default settings
    DSK6713_AIC23_CodecHandle hCodec; //allows audio to be read and write

    hCodec = DSK6713_AIC23_openCodec(0, &config); //initialize and opens the audio codec device

    DSK6713_AIC23_setFreq(hCodec, DSK6713_AIC23_FREQ_48KHZ); //sets the sampling frequency

    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int i4 = 0;

    while(1)
    {
        int i;
        for (i = 0; i < SAMPLE_SIZE; i++)
        {
            while(!DSK6713_AIC23_read(hCodec, &buffer_in[i]));
            buffer_out[i] = (short)((buffer_in[i]*5 + i1 + i2 + i3 + i4)/5);
                        i1 = i2;
                        i2 = i3;
                        i3 = i4;
                        i4 = buffer_out[i];
            buffer_out[i] = (short)(buffer_in[i]*4);
            while(!DSK6713_AIC23_write(hCodec, buffer_out[i]*5));
        }
    }
}
