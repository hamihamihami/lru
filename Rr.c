

#include<stdio.h>

struct process{

    int st[10],at[10],arr,bt,ft,wt,tat,name,rt,c;

};

int time;

int main(){

    int n,i,remaining,j,k,ct=0,x;

    float avgwt=0,avgtat=0;

    printf("Enter the no: of Processes: ");

    scanf("%d",&n);

    printf("Enter the Time Quantum: ");

    scanf("%d",&time);

    struct process p[n],temp;

    for(i=0;i<n;i++){

        p[i].name=i+1;

        printf("Process:%d\n",p[i].name);

        printf("Arrival time: ");

        scanf("%d",&p[i].arr);

        printf("Burst time: ");

        scanf("%d",&p[i].bt);

        p[i].c=0;

        p[i].at[0]=p[i].arr;

        p[i].rt=p[i].bt;

        p[i].wt=0;

    }

    remaining=n;

    while(remaining>0){

        for(j=0;j<n-1;j++){

            for(k=0;k<n-j-1;k++){

                if(p[k].at[p[k].c]>p[k+1].at[p[k+1].c]){

                    temp=p[k];

                    p[k]=p[k+1];

                    p[k+1]=temp;

                }

                else if(p[k].at[p[k].c]==p[k+1].at[p[k+1].c]){

                    if(p[k].c>p[k+1].c){

                        temp=p[k];

                        p[k]=p[k+1];

                        p[k+1]=temp;

                    }

                }

            }

        }

        j=0;

        while(p[j].rt<0){

            j=(j+1)%n;

        }

        if(p[j].rt==0){

            printf("PROCESS: %d\t",p[j].name);

            i=0;

            printf("ARRIVAL :");

            while(i<=p[j].c){

                printf("%d,",p[j].at[i]);

                i++;

            }

            printf("\t");

            printf("BURST:");

            printf("%d\t",p[j].bt);

            i=0;

            printf("STARTING :");

            while(i<=p[j].c){

                printf("%d,",p[j].st[i]);

                i++;

            }

            printf("\t");

            printf("FINISHING :%d\t",p[j].ft);

            printf("WAITING :%d\t",p[j].wt);

            printf("TURN AROUND :%d\n",p[j].tat);

            p[j].rt=-1;

            remaining=remaining-1;

            avgwt=avgwt+p[j].wt;

            avgtat=avgtat+p[j].tat;

        }

        if(p[j].rt>0){

            if(p[j].rt<=time){

                if(p[j].at[p[j].c]<=ct){

                    p[j].st[p[j].c]=ct;

                }

                else{

                    p[j].st[p[j].c]=p[j].at[p[j].c];

                }

                p[j].ft=p[j].st[p[j].c]+p[j].rt;

                p[j].rt=0;

                p[j].tat=p[j].ft-p[j].arr;

                ct=p[j].ft;

                p[j].wt=p[j].wt+(p[j].st[p[j].c]-p[j].at[p[j].c]);

            }

            else{

                if(p[j].at[p[j].c]<=ct){

                    p[j].st[p[j].c]=ct;

                    x=ct+time;

                }

                else{

                    p[j].st[p[j].c]=p[j].at[p[j].c];

                    x=p[j].at[p[j].c]+time;

                }

                p[j].rt=p[j].rt-time;

                p[j].wt=p[j].wt+(p[j].st[p[j].c]-p[j].at[p[j].c]);

                p[j].c=p[j].c+1;

                p[j].at[p[j].c]=x;

                ct=x;

            }

        }

    }

    printf("AVERAGE WAITING :%.2f\n",avgwt/n);

    printf("AVERAGE TURN AROUND :%.2f",avgtat/n);

    return 0;

}

