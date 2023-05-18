#include<stdio.h>
int main()
{
	int n,r,i,j,k,c=0,s=0;
	printf("\n enter no of resources:");
	scanf("%d",&r);
	printf("\n enter no of processos:");
	scanf("%d",&n);
	int req[n][r],alloc[n][r],avail[r],work[r],finish[n],seq[n];
	printf("\n enter total instance:");
	for(i=0;i<r;i++)
	scanf("%d",&avail[i]);
	for(i=0;i<n;i++)
	{
		printf("\n enter allocation of p%d:",i);
		for(j=0;j<r;j++)
		{
		scanf("%d",&alloc[i][j]);
        avail[j]=avail[j]-alloc[i][j];
        work[j]=avail[j];
    	}
	}
	for(i=0;i<n;i++)
	{
		printf("\n enter request of p%d:",i);
		for(j=0;j<r;j++)
		scanf("%d",&req[i][j]);
	}
	printf("\n available resources:");
	for(i=0;i<r;i++)
	printf("%d ",avail[i]);
	for(i=0;i<n;i++)
	finish[i]=0;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			int flag=0;
			if(finish[i]==0)
			{
				for(j=0;j<r;j++)
				{
					if(req[i][j]>work[j])
					{
					flag=1;
					break;
					}
				}
				if(flag==0)
				{
					seq[s++]=i;
					for(j=0;j<r;j++)
					work[j]=work[j]+alloc[i][j];
					finish[i]=1;
				}		
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(finish[i]==0)
		c=1;
	}
	if(c==0)
	{
		printf("\n no dead lock occured\n safe sequence:");
		for(i=0;i<n;i++)
		printf("p%d ",seq[i]);
	}
	else
	{
		printf("\n dead lock occured....process effected by dead lock:");
		for(i=0;i<n;i++)
		{
			if(finish[i]==0)
			printf("%d ",i);
		}
	}
	return 0;
}
