#include<stdio.h>
void main(){
    int i,n,j,f,k,c=0,t=0,ans=0,z;
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
            if(p[i]==a[j]) h++;
        }
        if(h==0){
            int max=0;
            if(c!=0){
                for(j=0;j<f;j++){
                    z=0;
                    for(k=i+1;k<n;k++){
                        if(a[j]==p[k]) z++;
                    }
                    if(z==0){
                        t=j;
                        break;
                    }
                    else{
                        for(k=i+1;k<n;k++){
                            if(a[j]==p[k]){
                                if(k>max) max=k;
                                break;
                            }
                        }
                    }
                }
                if(z!=0){
                    for(j=0;j<f;j++){
                        if(p[max]==a[j]){
                            t=j;
                            break;
                        }
                    }
                }
            }
            a[t]=p[i];
            t++;
            if(t>=f) c++;
            printf("Page fault sequence is:");
            for(j=0;j<f;j++) a[j]==-1?printf(" "):printf("%d ",a[j]);
            printf("\n");
            ans++;
        }
    }
    printf("No.of Page faults:%d\n",ans);
}

