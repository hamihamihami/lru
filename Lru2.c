#include<stdio.h>

#include<limits.h>

void main(){

    int i,n,j,f,t=0,ans=0,c=0,k=0,l,flag=0;

    printf("Enter number of pages:");

    scanf("%d",&n);



int p[n];

    printf("Enter the page stream:\n");

    for(i=0;i<n;i++) scanf("%d",&p[i]);

    printf("Enter no.of frames:");

    scanf("%d",&f);

    int a[f],temp[f]; 

    for(i=0;i<f;i++){

    a[i]=-1;

    temp[i]=p[i];

}

    for(i=0;i<n;i++){

        int h=0;

        for(j=0;j<f;j++){

        if(a[j]==p[i]){

        h++;

for(l=0;l<f;l++) if(a[j]==temp[l]) flag=l; 

for(l=flag;l<f-1;l++){

temp[l]=temp[l+1];

}

temp[l]=p[i];

        break;

}

}

        if(h==0){

       

        if(c!=0){

        for(j=0;j<f;j++){ 

        if(a[j]==temp[0]){

        t=j;

        break;

}

}



for(j=0;j<f-1;j++){

temp[j]=temp[j+1];

}

temp[j]=p[i];

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

