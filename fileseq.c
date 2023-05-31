#include<stdio.h>
#include<string.h>
struct file{
char name[50];
int len,st,a;
};
#define MAX 100
void insert();
void del();
void traverse();
int find();
int n,ind=0,i,j;
int b[MAX];
struct file f[MAX];
void main(){
int c,z=1;
printf("Enter no.of Blocks:");
scanf("%d",&n);
b[n];
f[n];
for(i=0;i<n;i++) b[i]=-1;
while(z!=0){
printf("Select 1.Insert\n2.Delete\n3.Traverse\n0.Exit\n");
scanf("%d",&c);
switch(c){
case 1:
insert();
break;
case 2:
del();
break;
case 3:
traverse();
break;
case 0:
z=0;
break;
default:
printf("Select correct option\n");
}
}
}
void insert(){
int t,flag=0,count=0;
printf("Enter file name:");
scanf("%s",f[ind].name);
t=find();
if(t==1){
printf("File with same name already exists\n");
return;
}
printf("Enter length:");
scanf("%d",&f[ind].len);
printf("Enter Starting pos:");
scanf("%d",&f[ind].st);
if(f[ind].st+f[ind].len<=n){
for(i=f[ind].st;i<f[ind].st+f[ind].len;i++){
if(b[i]!=-1){
flag++;
break;
}
}
if(!flag){
for(i=f[ind].st;i<f[ind].st+f[ind].len;i++) b[i]=1;
printf("File succesfully inserted\n");
f[ind++].a=1;
}
else printf("Insufficient space File not allocated check starting location\n");
}
else printf("Insufficient storage File not allocated\n");
}
void del(){
char s[50];
printf("Enter file name:");
scanf("%s",s);
for(i=0;i<ind,f[i].a==1;i++){ 
if(strcmp(s,f[i].name)==0){
for(j=f[i].st;j<f[i].st+f[i].len;j++){
b[j]=-1;
}
f[i].a=0; 
printf("File succesfully deleted\n");
return;
}
}
printf("File doesn't exist\n");
}
void traverse(){
int flag=0;
printf("File name\tstart\tend\tlength\n");
for(i=0;i<ind;i++){
if (f[i].a==1){
printf("%s\t\t%d\t%d\t%d\n",f[i].name,f[i].st,f[i].st+f[i].len-1,f[i].len);
flag++;
}
}
if(flag==0) printf("---\t\t---\t---\t---\n");
printf("\n blocks:");
for(i=0;i<n;i++)
printf("%d ",b[i]);
printf("\n");
}
int find(){
for(i=0;i<n;i++){
if(f[ind].name==f[i].name&ind!=i) return 1;
}
}
