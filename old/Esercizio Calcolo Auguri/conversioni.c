#include "auguri.h"
int conversione_mday_yday(int g, int m, int y)
{
    int g_f;
    if(bisestile(y))        g_f = 29;
    else                    g_f = 28;
    switch(m)
    {
        case 1:
            return g;
        case 2:
            return g+31;
        case 3:
            return g+31+g_f;
        case 4:
            return g+31+g_f+31;
        case 5:
            return g+31+g_f+31+30;
        case 6:
            return g+31+g_f+31+30+31;
        case 7:
            return g+31+g_f+31+30+31+30;
        case 8:
            return g+31+g_f+31+30+31+30+31;
        case 9:
            return g+31+g_f+31+30+31+30+31+31;
        case 10:
            return g+31+g_f+31+30+31+30+31+31+30;
        case 11:
            return g+31+g_f+31+30+31+30+31+31+30+31;
        case 12:
            return g+31+g_f+31+30+31+30+31+31+30+31+30;
    }
}