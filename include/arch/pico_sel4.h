/*********************************************************************
   PicoTCP. Copyright (c) 2012-2017 Altran Intelligent Systems. Some rights reserved.
   See COPYING, LICENSE.GPLv2 and LICENSE.GPLv3 for usage.
 *********************************************************************/
#ifndef PICO_SUPPORT_SEL4
#define PICO_SUPPORT_SEL4

#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define dbg printf

#define pico_zalloc(x) calloc(x, 1)
#define pico_free(x) free(x)

/* time prescaler */
#ifdef TIME_PRESCALE
extern int32_t prescale_time;
#endif

/* pico_ms_tick must be defined */
extern volatile unsigned long int pico_ms_tick;


static inline uint32_t PICO_TIME(void)
{
    return pico_ms_tick / 1000;
}

static inline uint32_t PICO_TIME_MS(void)
{
    return pico_ms_tick;
}

static inline void PICO_IDLE(void)
{
    unsigned long int tick_now = pico_ms_tick;
    while(tick_now == pico_ms_tick);
}


#endif  /* PICO_SUPPORT_SEL4 */
