#include <linux/time.h>
#include"errors.h"
unsigned int system_get_usec(void)
{
	unsigned int usec;
	struct timeval ts;
 
	do_gettimeofday(&ts);
 
	usec = (unsigned int)ts.tv_usec;
 
	return usec;
}
 

#if 0
unsigned long system_get_msec(void)
{
	unsigned long milliseconds;
	struct timeval ts;
 
	do_gettimeofday(&ts);
 
	milliseconds = ts.tv_sec*1000LL + ts.tv_usec/1000;
	
	return milliseconds;
}
 
unsigned int system_get_sec(void)
{
	unsigned int sec;
	struct timeval ts;
 
	do_gettimeofday(&ts);
 
	sec = (unsigned int)ts.tv_sec;
 
	return sec;
}
 
void system_mdelay(unsigned int dly)
{
	mdelay(dly);
}
 
void system_udelay(unsigned int dly)
{
	udelay(dly);
}

#endif

int main(void)
{
    unsigned int time = 0;
    time = system_get_usec();

    printf("%d\n",time);
}