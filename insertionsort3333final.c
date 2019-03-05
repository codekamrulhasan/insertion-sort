#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
#define SIZE 100000
#define SIZE1 5

void insertionsort(int a[],int n)
{
    int i,j;
    int key;
    for (i=1;i<=n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    struct timeval tv,tv1;
    struct timezone tz,tz1;
    struct tm *tm;
    clock_t start,end;
    int i,n,a1[SIZE1],total;
    long int a[SIZE];
    FILE *fptr;

    printf("Enter 5 numbers:\n");
    for (i=0;i<SIZE1;i++)
    {
        scanf("%d",&a1[i]);
    }
    gettimeofday(&tv, &tz);
    insertionsort(a1,SIZE1);
    printf("The sorted numbers are :\n");
    for (i=0;i<SIZE1;i++)
    {
        printf("%d\n",a1[i]);
    }
    tm=localtime(&tv.tv_sec);
    printf("The time taken to sort 5 numbers by insertion sort is %d milliseconds\n",tm->tm_sec);
    getch();

    fptr = fopen("input.txt","w");
    for (i=0;i<n;i++)
    {
      fprintf(fptr,"%d\n",rand()%1000+1);
    }
    fflush(fptr);
    fclose(fptr);
    fptr = fopen("input.txt","r");
    start = clock();
    for(i=0;i<SIZE;i++)
    {
       fscanf(fptr,"%d",&a[i]);
    }
    fclose(fptr);
    insertionsort(a,SIZE);
    end = clock();
    fptr=fopen("output.txt","w");
    for (i=0;i<SIZE;i++)
    {
        fprintf(fptr,"%d\n",a[i]);
    }
    fclose(fptr);
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("The time taken to sort a million randomized numbers using insertion sort is %d milliseconds\n",total);
    printf("Time difference: %d milliseconds\n",total-tm->tm_sec);
    getch();
    return 0;
}
