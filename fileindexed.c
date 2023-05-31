#include<stdio.h>
#include<string.h>
#define MAX 100
struct file{
        char name[50];
        int len,indexf[MAX],fs;
};
struct block{
        int index[MAX];
};
void insert();
void del();
void traverse();
int find();
int i,j,count,ind,n,size;
struct file f[MAX];
struct block b[MAX];
void main(){
        int c;
        printf("Enter no.of blocks:");
        scanf("%d",&n);
        printf("Enter size of index:");
        scanf("%d",&size);
        f[n];
        b[n];
        for(i=0;i<n;i++) b[i].index[0]=-1;
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
                        default:printf("Inappropriate selection\n");
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
        int t,num,x,track=0,l=0;
        printf("Enter file name:");
        scanf("%s",f[ind].name);
        t=find();
        if(t!=0){
                printf("File with same name already exists\n");
                return;
        }
        printf("Enter file length:");
        scanf("%d",&f[ind].len);
        x=f[ind].len/(size-1);
        if(f[ind].len%(size-1)!=0){
                x+=1;
        }
        f[ind].fs=x;
        if(f[ind].len+x>n-count){
                printf("Insufficient storage File not allocated\n");
                return;
        } 
        for(i=0;i<n;i++){
        if(track==x) break;
        if(b[i].index[0]==-1){
                int flag=0;
                l++;
                f[ind].indexf[track++]=i;
                for(j=i+1;j<n;j++){
                        if(flag==size-1){
                                b[i].index[flag]=j;
                                break;
                        }
                        if(l==f[ind].len+x) break;
                        b[i].index[flag++]=j;
                        b[j].index[0]=1;
                        l++;
                        }         
                }
        }                   
        ind++;
        count+=l;
        printf("File sucessfully inserted\n");
}
void traverse(){
        int flag=0;
        printf("File_name\tlength\tindex\n");
        for(i=0;i<ind;i++){
                printf("%s\t\t%d\t",f[i].name,f[i].len);
                for(j=0;j<f[i].fs-1;j++) printf("%d->",f[i].indexf[j]);
                if(j==f[i].fs-1) printf("%d\n",f[i].indexf[j]);
                flag++;
        }
        if(flag==0) printf("---\t\t---\t---\n");
        for(i=0;i<n;i++){
                printf("%d\t",b[i].index[0]);
        }
        printf("\n");
}
void del(){
        char s[50];
        printf("Enter file name:");
        scanf("%s",s);
        int inx1,inx2,l=0;
        for(i=0;i<ind;i++){
                if(strcmp(s,f[i].name)==0){           
                        int inx;
                        inx=inx1=f[i].indexf[0];
                        int range;
                        range=f[i].len+f[i].fs;
                        while(l<range){
                                for(j=0;j<size;j++){
                                        inx2=b[inx].index[j];
                                        b[inx1].index[0]=-1;
                                        inx1=inx2;
                                        l++;
                                }
                                inx=inx1;
                        }
                        
                        count-=range;
                        for(j=i;j<ind-1;j++){
                                int k=0;
                                f[j].fs=f[j+1].fs;
                                for(k=0;k<f[j].fs;k++) f[j].indexf[k]=f[j+1].indexf[k];                                         
                                f[j].len=f[j+1].len;
                                strcpy(f[j].name,f[j+1].name);
                        }
                        printf("File succesfully deleted\n");
                        ind--;
                        return;
                }
        }  
        printf("File name doesn't exit check file name\n");           
}


