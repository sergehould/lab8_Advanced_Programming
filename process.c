/* Standard includes. */
#include <stdio.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "config.h"
#include "process.h"
#include "include/pmp_lcd.h"

/* Semaphores and mutexes declarations*/
extern xSemaphoreHandle xMutex1;

void process1(void){
                static char i=0, sec=0;   
                static char textBuff1[17];
                xSemaphoreTake( xMutex1, portMAX_DELAY );
                LCDL1Home(); 
                sprintf(textBuff1,"1 ");
                LCDPos1(0);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                sprintf(textBuff1,"%d",sec);
                LCDPos2(0);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                xSemaphoreGive( xMutex1 );
                 __delay32(DELAY_TASK1_7); 
                if(++sec >=10) sec =0;
}
void process2(void){
                static char i=0, sec=0;                                                            
                static char textBuff1[16];
                xSemaphoreTake(xMutex1,portMAX_DELAY);
                LCDL1Home(); 
                sprintf(textBuff1,"2 ");
                LCDPos1(2);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                sprintf(textBuff1,"%d",sec);
                LCDPos2(2);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                xSemaphoreGive( xMutex1 );
                 __delay32(DELAY_TASK1_7); 
                if(++sec >=10) sec =0;
}


void process3(void){
                static char i=0, sec=0;                                                            
                static char textBuff1[16];
                 xSemaphoreTake( xMutex1, portMAX_DELAY );
                LCDL1Home(); 
                sprintf(textBuff1,"3");
                LCDPos1(4);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                sprintf(textBuff1,"%d",sec);
                LCDPos2(4);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                xSemaphoreGive( xMutex1 );
                 __delay32(DELAY_TASK1_7); 
                if(++sec >=10) sec =0;
}
void process4(void){
                static char i=0, sec=0;                                                            
                static char textBuff1[16];
                  xSemaphoreTake( xMutex1, portMAX_DELAY );
                LCDL1Home(); 
                sprintf(textBuff1,"4");
                LCDPos1(6);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                sprintf(textBuff1,"%d",sec);
                LCDPos2(6);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                xSemaphoreGive( xMutex1 );
                 __delay32(DELAY_TASK1_7); 
                if(++sec >=10) sec =0;
}
void process5(void){
                static char i=0, sec=0;                                                            
                static char textBuff1[16];
                  xSemaphoreTake( xMutex1, portMAX_DELAY );
                LCDL1Home(); 
                sprintf(textBuff1,"5");
                LCDPos1(8);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                sprintf(textBuff1,"%d",sec);
                LCDPos2(8);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                xSemaphoreGive( xMutex1 );
                 __delay32(DELAY_TASK1_7); 
                if(++sec >=10) sec =0;
}
void process6(void){
                static char i=0, sec=0;                                                            
                static char textBuff1[16];
                  xSemaphoreTake( xMutex1, portMAX_DELAY );
                LCDL1Home(); 
                sprintf(textBuff1,"6");
                LCDPos1(10);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                sprintf(textBuff1,"%d",sec);
                LCDPos2(10);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                xSemaphoreGive( xMutex1 );
                 __delay32(DELAY_TASK1_7); 
                if(++sec >=10) sec =0;
}

void process7(void){
                static char i=0, sec=0;                                                            
                static char textBuff1[16];
                  xSemaphoreTake( xMutex1, portMAX_DELAY );
                LCDL1Home(); 
                sprintf(textBuff1,"7");
                LCDPos1(12);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                sprintf(textBuff1,"%d",sec);
                LCDPos2(12);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                xSemaphoreGive( xMutex1 );
                 __delay32(DELAY_TASK1_7); 
                if(++sec >=10) sec =0;

}
void process8(void){
            static unsigned int shift =0x0003;
            LATA = shift & 0x00ff;
            if(shift == 0b11000000) shift  = 0b10000001;
            else if(shift == 0b10000001) shift  = 0b000000011;
            else shift = shift << 1;
              __delay32( DELAY_TASK8);
             //  __delay32(DELAY10MS); // for test only

}
void process9(void){
                static int sec=0;
                static char blink = 0, i=0;
                static char textBuff1[17];
                  xSemaphoreTake( xMutex1, portMAX_DELAY );
                sprintf(textBuff1,"9");
                LCDPos1(14);
                i=0;
                while(textBuff1[i]){
                        LCDPut(textBuff1[i]);
                        i++;
                }
                
                if (blink ==1) {
                    if (++sec >= 10) sec = 0;
                    sprintf(textBuff1,"%d",sec);
                    blink = 0; //space   
                }
                else{
                    blink=1;
                    sprintf(textBuff1,"%c",42);
                }
                LCDPos2(14);
                i=0;
                while(textBuff1[i]){
                    LCDPut(textBuff1[i]);
                    i++;
                }
                xSemaphoreGive( xMutex1 );
                __delay32(DELAY_TASK9);
          //          __delay32(DELAY30MS);

}