#define 	_ISR_NO_PSV 	__attribute__((__interrupt__, no_auto_psv))
#define VERY_HEAVY   100000 
#define HEAVY   90000
#define MEDIUM  50000   // ok
#define LIGHT   100    

#include <xc.h>
#include "task8.h"
#include "task9.h"

int task8_f;
int task9_f;


void _ISR_NO_PSV _T3Interrupt( void )
{
    task9();
    //task8();
        _T3IF = 0;
}

//8Hz
void _ISR_NO_PSV _T2Interrupt( void )
{
    volatile static char cnt8=0, cnt9=0;    
    if(++cnt8>=1){
        cnt8=0;
        task8_f =1;
    }
    if(++cnt9>=4){
        cnt9=0;
        task9_f =1;
    } 
        _T2IF = 0;
}