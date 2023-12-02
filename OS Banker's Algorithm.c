#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,m;
    printf("Enter no. of process : ");
    scanf("%d",&n);
    printf("Enter no. of resources : ");
    scanf("%d",&m);
    int alloc[n][m], max[n][m], need[n][m], av[m];
    printf("\nEnter allocated resources for each process : \n");
    for(int i=0; i<n; i++)
    {
        printf("Process %d: ",i+1);
        for(int j=0; j<m; j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\nEnter max need of resources for each process : \n");
    for(int i=0; i<n; i++)
    {
        printf("Process %d: ",i+1);
        for(int j=0; j<m; j++)
        {
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\nEnter available matrix : ");
    for(int i=0; i<m; i++)
    {
        scanf("%d",&av[i]);
    }
    printf("\n");
    int done=0, safeSeq[n], j;
    while(done!=n)
    {
        int found=0;
        for(int i=0; i<n ; i++)
        {
            if(need[i][0]!=999) //to check if process is completed
            {
                for(j=0; j<m; j++)
                {
                    if(need[i][j]>av[j])
                    {
                        break;
                    }
                }
                if(j==m) //need can be fulfilled
                {
                    for(int k=0; k<m; k++)
                    {
                        av[k]=av[k]+alloc[i][k];
                    }
                    need[i][0]=999;
                    safeSeq[done]=i+1;
                    done++;
                    found=1;
                }
            }
        }
        if(found==0)
        {
            printf("System is not in safe state\n");
            exit(0);
        }
    }
    printf("Safe sequence : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",safeSeq[i]);
    }
}
