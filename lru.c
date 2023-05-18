#include<stdio.h>
void main(){
    int i,n,j,f,t=0,k,ans=0;
    printf("Enter number of pages:");
    scanf("%d",&n);
    int p[n];
    printf("Enter the page stream:\n");
    for(i=0;i<n;i++) scanf("%d",&p[i]);
    printf("Enter no.of frames:");
    scanf("%d",&f);
    int a[f];
    for(i=0;i<f;i++) a[i]=-1;
    for(i=0;i<n;i++){
        int h=0;
        for(j=0;j<f;j++){
            if(p[i]==a[j]){
                h++;
                break;
            }
        }
        if(h==0){
            a[t]=p[i];
            t++;
            for(k=0;k<t;k++){
                if(p[i-(f-1)]==a[k]){
                    t=k;
                    break;
                }
            }
            printf("Page fault sequence is:");
            for(j=0;j<f;j++) a[j]==-1?printf(" "):printf("%d ",a[j]);
            printf("\n");
            ans++;
        }
        else{
            if(a[t]==p[i]){
                t++;
                for(k=0;k<t;k++){
                    if(p[i-(f-1)]==a[k]){
                        t=k;
                        break;
                    }
                }
            }
        }
    }
    printf("No.of Page faults:%d\n",ans);
}
