#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE *out = fopen("/Users/itsc_macbook/Desktop/random.txt", "w");
    
    for(int i = 0; i < 100000; i++)
    {
        int random = rand()%100000;
        fprintf(out, "%d\n", random);
    }
}
