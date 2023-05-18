#include<stdio.h>
#include<limits.h>
int main()
{
int m,o,am,p,i,ch,par,count=0,sum=0,algo,k,min,max,j;
float s,totf=0;
printf("\n enter size of memory:");
scanf("%d",&m);
printf("\n enter memory used by the os:");
scanf("%d",&o);
am=m-o;
printf("\n available memory=%d",am);
printf("\n enter no.of processos:");
scanf("%d",&p);
int alloc[p],allocmem[p];
float pm[p],inf[p];
for(i=0;i<p;i++)
{
inf[i]=0;
printf("\n memory required for process %d:",i+1);
scanf("%f",&pm[i]);
alloc[i]=0;
}
printf("\n enter 0 for equal no.of partitions \n enter 1 for unequal no.of partitions");
scanf("%d",&ch);
if(ch==0)
{
printf("\n enter no.of partitions:");
scanf("%d",&par);
s=(float)am/par;
for(i=0;i<p;i++)
{
if(pm[i]<=s)
{
alloc[i]=++count;
allocmem[i]=s;
inf[i]=s-pm[i];
totf=totf+inf[i];
   }
   if(count==par)
break;
}
}
else if(ch==1)
{
printf("\n enter no of partions:");
scanf("%d",&par);
int ps[par],parcmp[par];
for(i=0;i<(par-1);i++)
{
printf("\n size of partition%d:",i+1);
scanf("%d",&ps[i]);
sum=sum+ps[i];
parcmp[i]=-1;
}
ps[par-1]=am-sum;
parcmp[par-1]=-1;
printf("\n select the algorithm : 1.Best fit\t 2.Worst fit\t 3.First fit 4.Next fit");
scanf("%d",&algo);
switch(algo){
case 1:
 count=0;
 for(i=0;i<p;i++){
  k=-1,min=INT_MAX;
  for(j=0;j<par;j++)
  {
   if(ps[j]<min&&pm[i]<=ps[j]&&parcmp[j]==-1)
   {
   min=ps[j];
   k=j;
   }
  }
  if(k==-1)
  {
   continue;
  }
  alloc[i]=k+1;
  allocmem[i]=ps[k];
// printf("%f %f\n",min,pm[i]);
  inf[i]=min-pm[i];// p[j] --> min since j value will be unreferenced which is j==par
       // instead of min you can also use p[k];
// printf("%f",inf[i]);
  totf=totf+inf[i];
  parcmp[k]=1;
  count++;
  if(count==par){
   break;
  }
 }
break;
case 2:
 count=0;
 for(i=0;i<p;i++){
  k=-1,max=INT_MIN; //changed INT_MAX to INT_MIN
  for(j=0;j<par;j++)
  {
   if(ps[j]>max&&pm[i]<=ps[j]&&parcmp[j]==-1)
   {
    max=ps[j];
    k=j;
   }
  }
  if(k==-1)
  {
   continue;
  }
  alloc[i]=k+1;
  allocmem[i]=ps[k];
  inf[i]=max-pm[i]; // p[j] --> min since j value will be unreferenced which is j==par
       // instead of min you can also use p[k];
  totf=totf+inf[i];
  parcmp[k]=1;
  count++;
  if(count==par){
   break;
  }
 }
break;
case 3:
 count=0;
 for(i=0;i<p;i++)
 {
  for(j=0;j<par;j++){
   if(pm[i]<=ps[j]&&parcmp[j]==-1){
    alloc[i]=j+1;
    allocmem[i]=ps[j];
    inf[i]=ps[j]-pm[i];
    totf=totf+inf[i];
    parcmp[j]=1;
    count++;
    break;
   }
  }
  if(count==par){
   break;
  }
 }
break;
case 4:
printf("\n enter previous partition position:");
scanf("%d",&j);
for(i=0;i<p;i++)
{
        count=0;
        while(count<par){
                if(ps[j]>=pm[i]&&parcmp[j]==-1){
                        alloc[i]=j+1;
                        allocmem[i]=ps[j];
                        inf[i]=ps[j]-pm[i];
                        totf=totf+inf[i];
                        parcmp[j]=1;
                        break;
                }
                else if(j==par-1){
                        j=0;
                }
                else{
                        j++;
                }
                count++;
        }
}
break;
}
}
/*printf("\n process  reqmemory  partitionno partitionsize  internalfrag\n");
for(i=0;i<p;i++)
{
printf("     %d \t %.2f \t\t",i+1,pm[i]);
if(alloc[i]==0){
printf("not allocated\t\t --\n");
}
else
{
printf(" %d \t %d \t %.2f\n",alloc[i],allocmem[i],inf[i]);
}
} */
printf("\n process\treqmemory\tpartition no\tpartitionsize\tinternalfrag\n");
for(i=0;i<p;i++)
{
printf("     %d  \t%.2f\t",i+1,pm[i]);
if(alloc[i]==0){
printf("  \tnot allocated\t    --\t  \t   --\n");
}
else
{
printf("\t\t%d  \t    %d   \t   %.2f\n",alloc[i],allocmem[i],inf[i]);
}
}
printf("\n Total fragmentation=%.2f\n",totf);
return 0;
}

