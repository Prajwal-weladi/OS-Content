#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
    int n,pos,t,done=0;
    float mov=0;
    printf("Enter current position of head : ");
    scanf("%d",&pos);
    printf("Enter total no. of tracks : ");
    scanf("%d",&t);
    printf("Enter total no. of I/O requests : ");
    scanf("%d",&n);
    int req[n];
    printf("Enter request queue : ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&req[i]);
    }
    printf("\nSeek sequence : ");
    for(int i=pos; i<t; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(req[j]==i)
            {
                mov=mov+abs(pos-req[j]);
                pos=req[j];
                done++;
                if(done==n)
                {
                    printf("%d\n",req[j]);
                }
                else
                {
                    printf("%d -> ",req[j]);
                }
                req[j]=999;
            }
        }
    }
    if(pos!=t-1)
    {
        mov=mov+abs(t-1-pos);
        pos=t-1;
    }
    for(int i=t-1; i>=0; i--)
    {
        for(int j=0; j<n; j++)
        {
            if(req[j]==i)
            {
                mov=mov+abs(pos-req[j]);
                pos=req[j];
                done++;
                if(done==n)
                {
                    printf("%d\n",req[j]);
                }
                else
                {
                    printf("%d -> ",req[j]);
                }
                req[j]=999;
            }
        }
    }
    printf("Total seek operations : %.0f\n",mov);
    printf("Average seek length : %.2f\n",mov/n);
}
