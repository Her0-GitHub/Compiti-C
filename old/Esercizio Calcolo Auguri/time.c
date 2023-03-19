#include "auguri.h"
#include <time.h>
int yday()
{
    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL); 
    current_time = localtime(&s);
    return current_time->tm_yday+1;
}
int mday()
{
    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL); 
    current_time = localtime(&s);
    return current_time->tm_mday;
}
int month()
{
    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL); 
    current_time = localtime(&s);
    return current_time->tm_mon + 1;
}
int year()
{
    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL); 
    current_time = localtime(&s);
    int year = current_time->tm_year + 1900;
    return year;
}