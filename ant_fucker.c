#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    srand(time(0));
    int age;
    age=rand();
    for(i=0;i<20;++i)
    {
        age=rand()%100;
        printf("蚂蚁一次♂能坚持%d分钟\r", age);
        fflush(stdout);
        usleep(100000);
    }
    putchar('\n');
    return 0;
}