
#include "kernel/types.h"
#include"user/user.h"
void main(int argc , char* argv[])
{
    if(argc != 2)
    {
        printf("只需要一个参数");
        exit(0);
    }
    else{
        printf("sleeping for :%s clocks\n",argv[1]);
        sleep(atoi(argv[1]));

    }
    exit(0);
    
    
}