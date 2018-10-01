
#include<stdio.h>
main()
{
int n,a[10],b[10],t[10],w[10],g[10],i;
float att=0,awt=0;
            for(i=0;i<10;i++)
            {
                        a[i]=0; b[i]=0; w[i]=0; g[i]=0;
            }
printf("enter the number of process");
            scanf("%d",&n);
printf("enter the burst times");
            for(i=0;i<n;i++)
                scanf("%d",&b[i]);
    printf("\nenter the arrival times");
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
    g[0]=0;
             for(i=0;i<10;i++)
                   g[i+1]=g[i]+b[i];
             for(i=0;i<n;i++)
            {
w[i]=g[i]-a[i];
                        t[i]=g[i+1]-a[i];
                        awt=awt+w[i];
                        att=att+t[i];
            }
     awt =awt/n;
            att=att/n;
            printf("\n\tprocess\twaiting time\tturn arround time\n");
            for(i=0;i<n;i++)
            {
                        printf("\tp%d\t\t%d\t\t%d\n",i,w[i],t[i]);
            }
printf("the average waiting time is %f\n",awt);
printf("the average turn around time is %f\n",att);
}

#include<stdio.h>

void main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }


    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;


    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=(float)total/n;
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

#include<stdio.h>

void main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }


    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;


    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=(float)total/n;
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}


rr
#include<stdio.h>

struct process
{
 char pr[20];
int bt,ct,time;
}p[10];

void main()
{
   int i,n,full,tq,wt[10],tat[10],time1=0;
float avgwt=0.0;
printf("\n enter the no of process:");
scanf("%d",&n);
printf("\n enter process name and burst time of%d process\n:",n);
for(i=0;i<n;i++)
{
scanf("%s%d",&p[i].pr,&p[i].bt);
p[i].time=p[i].bt;
}
printf("\n enter quantum:");
scanf("%d",&tq);
full=n;
while(full)
{
  for(i=0;i<n;i++)
   {
    if(p[i].bt>=tq)
    {
      p[i].bt-=tq;
      time1=time1+tq;
    }
   else if(p[i].bt!=0)
  {
   time1+=p[i].bt;
p[i].bt=0;
}
else
  continue;
  if(p[i].bt==0)
  {
   full=full-1;
   tat[i]=time1;
   }
 }
}
for(i=0;i<n;i++)
{
p[i].ct=tat[i];
wt[i]=tat[i]-p[i].time;
}
printf("pr\tbt\tct\ttat\twt\n");

for(i=0;i<n;i++)
{
  printf("%2s\t%2d\t%2d\t%2d\t%2d\n",p[i].pr,p[i].time,p[i].ct,tat[i],wt[i]);
avgwt+=wt[i];
}
avgwt=avgwt/n;
printf("\n average waiting time =%2f\n",avgwt);
}
*/
