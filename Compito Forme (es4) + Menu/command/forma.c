#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int y, x, n = (atoi(argv[1]));
    for(y=1; y<=n; y++)
    {
        for(x=0; x<n; x++)  printf("%c ", 223);
        puts("");
    }
}