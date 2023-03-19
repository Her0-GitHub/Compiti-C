#include "auguri.h"
int bisestile(int y)
{
    if(((y%4==0)&&(y%100!=0))||(y%400==0))      return 1; // L'anno è bisestile
    else                                        return 0; // L'anno non è bisestile
}