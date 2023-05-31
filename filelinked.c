#include<stdio.h>
#include<string.h>
struct file{
        char name[50];
        int len,a;
        struct node{
                int next[100],last;
        }addr;
};
#define MAX 100
void insert();
void del();
void traverse();
int find();
int b[MAX];
struct file f[MAX];
int n,i,j,ind,count;
void main(){
        int c;
        printf("Enter number of blocks:");
        scanf("%d",&n);
        b[n];
        f[n];
        for(i=0;i<n;i++) b[i]=-1;
        while(1){
                printf("Select 1.Insert\n2.Delete\n3.Traverse\n0.Exit\n");
                scanf("%d",&c);
                switch(c){
                        case 1:insert();
                               break;
                     case 2:del();
                               break;
                        case 3:traverse();
                               break;
                        case 0:return;
                        default:printf("Inappropriate Selection\n");
                }
        }
}
int find(){
        for(i=0;i<ind;i++){
                if(f[ind].name==f[i].name) return i;
        }
        return 0;
}
void insert(){
        int t;
        printf("Enter file name:");
        scanf("%s",f[ind].name);
        t=find();
        if(t!=0){
                printf("File already exists\n");
                return;
        }
        printf("Enter file length:");
        scanf("%d",&f[ind].len);
        int flag=0;
        f[ind].addr.next[flag]=0;
        if(n-count>=f[ind].len){
                for(i=0;i<n;i++){
                        if(flag==f[ind].len) break;
                        if(b[i]==-1){
                                f[ind].addr.next[flag++]=i;
                                b[i]=1;
                                count++;
                        }
                }
                printf("File succesfully inserted\n");
                f[ind].addr.last=flag;
                f[ind++].a=1;
        }
        else printf("Insufficient storage File not allocated\n");
}
void del(){
 int t;
 char s[50];
    printf("Enter file name:");
    scanf("%s",s);
    for(i=0;i<ind;i++){
     if(strcmp(s,f[i].name)==0){
      for(j=0;j<f[i].addr.last;j++){
       count--;
       b[f[i].addr.next[j]]=-1;
   }
   printf("%d",count);
      f[i].a=0;
      printf("File succesfully deleted\n");
      return;
  }
 }
 printf("File doesn't exit\n");
}
void traverse(){
        printf("File_name\tlength\tlocation\n");
        for(i=0;i<ind;i++){
                if(f[i].a==1){
                 int st=f[i].addr.next[0];
                        printf("%s\t\t%d\t",f[i].name,f[i].len);
                        for(j=0;j<f[i].addr.last-1;j++) printf("%d->",f[i].addr.next[j]);
                        if(j==f[i].addr.last-1) printf("%d\n",f[i].addr.next[j]);
                }
        }
        for(i=0;i<n;i++) printf("%d\t",b[i]);
        
}

