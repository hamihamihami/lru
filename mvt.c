#include<stdio.h>
int main()
{
	int m,o,am,tq,n,i,j,k,h=0,temp,time=0,min,ef=0,l;
	printf("\n enter memory size:");
	scanf("%d",&m);
	printf("\n enter memory used by the os:");
	scanf("%d",&o);
	am=m-o;
	printf("\n available memory is %d",am);
	printf("\n enter time quantum:");
	scanf("%d",&tq);
	printf("\n enter no of processos:");
	scanf("%d",&n);
	int pm[n],bt[n],alloc[n],p[n][2],b[n][2];
	for(i=0;i<n;i++)
	{
		printf("\n enter memory,burstTime for process %d:",i+1);
		scanf("%d%d",&pm[i],&bt[i]);
		alloc[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(pm[i]<=am){
			/*alloc[i]=1;
			am=am-pm[i];
			if(bt[i]<tq)
			alloc[i]=2;*/
			p[i][0]=m-am;
			am=am-pm[i];
			p[i][1]=m-am;
			alloc[i]=1;
		}
		else{
			//alloc[i]=0;
			if(am!=0){
				b[0][0]=m-am;
				b[0][1]=m;
				h++;
			}
			break;
		}
	}
	l:while(time<=tq){
		temp=0,min=1000;
		for(i=0;i<n;i++){
			if(alloc[i]==1&&bt[i]<min&&bt[i]<=tq-time){
				min=bt[i];
				k=i;
				temp=1;
			}
		}
		if(temp==0){ 
			break;
		}
		time=time+min;
		alloc[k]=2;
		b[h][0]=p[k][0];
		b[h++][1]=p[k][1];
		 k:for(i=0;i<h;i++){
                        for(j=0;j<h;j++){
                                if(b[i][1]==b[j][0] && i!=j && b[i][1]!=0){
                                        b[i][1]=b[j][1];
                                        b[j][0]=b[j][1]=0;
                                        goto k;
                                }
                        }
                }
                for(i=0;i<h;i++){
                        if(b[i][0]==b[i][1]){
                                for(j=i+1;j<h;j++){
                                        b[j-1][0]=b[j][0];
                                        b[j-1][1]=b[j][1];
                                }
                                h--;
                        }
                }
                for(i=0;i<n;i++){
                        if(alloc[i]==0){
                                temp=0;
                                for(j=0;j<h;j++){
                                        if(b[j][1]-b[j][0]>=pm[i]){
                                                p[i][0]=b[j][0];
                                                p[i][1]=p[i][0]+pm[i];
                                                if(b[j][1]-b[j][0]==pm[i]){
                                                        b[j][0]=b[j][i]=0;
                                                }
                                                else{
                                                        b[j][0]=p[i][1];
                                                }
                                                alloc[i]=1;
                                                temp=1;
                                                goto k;
                                        }
                                }
                                if(temp==0){
                                        goto l;
                                }
                        }
                }
        }
        for(i=0;i<h;i++){
                printf("Free space from %d is from %d to %d\n",i+1,b[i][0],b[i][1]);
                ef=ef+b[i][1]-b[i][0];
        }
	printf("Process\tMemory req\t BT\tMemory alloc/not\n");
        for(i=0;i<n;i++){
                printf("  %d\t  %d\t\t  %d\t",i+1,pm[i],bt[i]);
                if(alloc[i]==0){
                        printf("  Memory not allocated\n");
                }
                else if(alloc[i]==1){
                        printf("allocated from(%d-%d) & process still going\n",p[i][0],p[i][1]-1);
                }
                else if(alloc[i]==2){
                        printf("allocated from(%d-%d),proc completed at time %d\n",p[i][0],p[i][1]-1,bt[i]);
                }
        }
        printf("\nThe EXTERNAL FRAGMENTATION is %d\n",ef);
	return 0;
}
