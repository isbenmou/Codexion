#include <Codexion.h>

unsigned long long getmsseccond(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec * 1000);
}

unsigned long long get_albased_time(unsigned long long start)
{
    return (getmsseccond() - start);
}

unsigned long long mssleep(unsigned long long sleeping)
{
    usleep(sleeping * 1000);
}

char check_time(unsigned long long start_timing, unsigned long long time)
{
    return ((getmsseccond() - start_timing) >= time);
}

