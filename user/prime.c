#include "kernel/types.h"
#include "user/user.h"
#define MAXNUM  35

void prime(int read_p,int write_p)
{
    int nums[MAXNUM];
    read(read_p,nums,sizeof(int)*MAXNUM);
    int t=0;
    for (int i = 0; i < MAXNUM; i++)
    {
        if(nums[i] == 0)
        {
            t=i;
            printf("prime has %d\n",t);
            break;
        }
    }// 找到第一个没有被筛除的数，其实就是质数
    
    if(t==0) // 数组中的数据全被筛除,说明程序结束
    { 
       exit(0);
    }
    for (int i = 0; i < MAXNUM; i++)
    {
        if (i%t == 0)
        {
            nums[i] = 1; // 筛除该数
        }   
    }

    int pid = fork();
    if(pid==0)
    {
        prime(read_p,write_p);
        exit(0);
    }
    else if(pid>0)
    {
        write(write_p,nums,sizeof(int)*MAXNUM);
        wait(0);
    }

    exit(0);    
    
}

int 
main(int argc,char *argv[])
{
    int p1[2];

    pipe(p1);
    int nums[MAXNUM]; //2-35,下标是数据，1是该数据是被筛除，0是这个数是质数
    
    int pidb=fork();
    if(pidb==0)
    {
        prime(p1[0],p1[1]);
        wait(0);
    }
    else
    {
        nums[0] = 1; //0不是合数
        nums[1] = 1;   //1是质数
       
        write(p1[1],nums,sizeof(int)*MAXNUM);
        wait(0);
        
    }
    exit(0);
}
