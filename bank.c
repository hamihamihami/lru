//TO LEARN
#include<stdio.h>
int n,r,i,j;
void print(int alloc[][r],int max[][r],int need[][r],int avail[]);
int safety(int avail[],int need[][r],int alloc[][r]);
void resRequest(int alloc[][r],int max[][r],int need[][r],int avail[]);
int main()
{
        printf("\n enter no of resources:");
        scanf("%d",&r);
        printf("\n enter no of processos:");
        scanf("%d",&n);
        int alloc[n][r],max[n][r],need[n][r],avail[r],s;
        printf("\n enter total instances:");
        for(i=0;i<r;i++)
        {
                scanf("%d",&avail[i]);
        }
        for(i=0;i<n;i++)
        {
                printf("\n enter allocation of p%d:",i);
                for(j=0;j<r;j++)
                {
                         scanf("%d",&alloc[i][j]);
                         avail[j]=avail[j]-alloc[i][j];
                }
                printf("\n enter max resources of p%d:",i);
                for(j=0;j<r;j++)
                {
                         scanf("%d",&max[i][j]);
                         need[i][j]=max[i][j]-alloc[i][j];
                }
        }
        print(alloc,max,need,avail);
        s=safety(avail,need,alloc);
        if(s)
                resRequest(alloc,max,need,avail);
        return 0;
}
void print(int alloc[n][r],int max[n][r],int need[n][r],int avail[r])
{
        printf("\n alloc\t max\t need\n");
        for(i=0;i<n;i++)
        {
                for(j=0;j<r;j++)
                printf("%d ",alloc[i][j]);
                printf("\t");
                for(j=0;j<r;j++)
                printf("%d ",max[i][j]);printf("\t");
                for(j=0;j<r;j++)
                printf("%d ",need[i][j]);printf("\t");
                printf("\n");
        }
        printf("AVAILABLE:\n");
        for(i=0;i<r;i++)
        printf("%d ",avail[i]);
        printf("\n");
}
int safety(int avail[r],int need[n][r],int alloc[n][r])
{
        int work[r],finish[n],k,seq[n],s=0;
        for(i=0;i<r;i++)
        work[i]=avail[i];
        for(i=0;i<n;i++)
        finish[i]=0;
        for(k=0;k<n;k++)
        {
                for(i=0;i<n;i++)
                {
                       if(finish[i]==0)
                       {
                        int flag=0;
                        for(j=0;j<r;j++)
                        {
                                if(need[i][j]>work[j])
                                {
                                        flag=1;
                                        break;
                                }
                        }
                        if(flag==0)
                        {
                                seq[s++]=i;
                                for(j=0;j<r;j++)work[j]=work[j]+alloc[i][j];
                                        finish[i]=1;
                        }
                       }
                }
        }
        for(i=0;i<n;i++)
        {
                if(finish[i]==0)
                {
                        printf("\n the system is not in safe state");
                        printf("\n the dead lock sequence:\n");
                        for(j=i;j<n-1;j++)
                        printf("p%d->",j);
                        printf("p%d\n",n-1);
                        return 0;
                }
        }
        printf("\n the system is in safe state\n the sequence:");
        for(i=0;i<n-1;i++)
                printf("p%d->",seq[i]);
                printf("p%d\n",seq[n-1]);
                return 1;
}
void resRequest(int alloc[n][r],int max[n][r],int need[n][r],int avail[r])
{
        int choice,req[r],pid,f=0;
        printf("\n enter 0 to stop,enter 1 for requesting a resource:");
        scanf("%d",&choice);
        if(choice==1)
        {
                printf("\n enter process for requesting:");
                scanf("%d",&pid);
                printf("\n enter additional request:");
                for(i=0;i<r;i++)
                scanf("%d",&req[i]);
                for(j=0;j<r;j++)
                {
                        if(req[j]>need[pid][j]||req[j]>avail[j])
                        f=1;
            }
            if(f==1)
            printf("\n request cannot be accepted");
                else
                {
                        for(j=0;j<r;j++)
                        {
                                avail[j]=avail[j]-req[j];
                                alloc[pid][j]=alloc[pid][j]+req[j];
                                need[pid][j]=need[pid][j]-req[j];
                    }
                    int p=safety(avail,need,alloc);
                if(p==1)
                printf("\n request accepted");
                else
                {
                        for(j=0;j<r;j++)
                    {
                           avail[j]=avail[j]+req[j];
                                   alloc[pid][j]=alloc[pid][j]-req[j];
                                   need[pid][j]=need[pid][j]+req[j];
                            }
                }
                }
                resRequest(alloc,max,need,avail);
        }
}

