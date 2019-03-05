#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
#define SIZE 100000
#define SIZE1 5


void merge(int a[],int low, int mid, int high)
    {
        int b[high+1];
        int x, y, z;

        for(x=low,y=mid+1,z=low; x<=mid && y<= high; z++)
        {
            if(a[x]<=a[y])
                b[z] = a[x++];
            else
                b[z] = a[y++];
        }

        while(x<=mid)
            b[z++] = a[x++];
        while (y<= high)
            b[z++] = a[y++];
        for (z=low; z<=high;z++){
            a[z]=b[z];}
    }

void sort (int a[], int low, int high){

    int mid;

    if(low<high){
        mid = (low+high)/2;
        sort(a,low,mid);
        sort(a,mid+1,high);
        merge(a,low,mid,high);}
    else
        return;
}


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
    sort(a1,0,SIZE1);
    printf("The sorted numbers are :\n");
    for (i=0;i<SIZE1;i++)
    {
        printf("%d\n",a1[i]);
    }
    tm=localtime(&tv.tv_sec);
    printf("The time taken to sort 5 numbers by merge sort is %d milliseconds\n",tm->tm_sec);
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
    sort(a,0,SIZE);
    end = clock();
    fptr=fopen("output.txt","w");
    for (i=0;i<SIZE;i++)
    {
        fprintf(fptr,"%d\n",a[i]);
    }
    fclose(fptr);
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("The time taken to sort a million randomized numbers using merge sort is %d milliseconds\n",total);
    printf("Time difference: %d milliseconds\n",total-tm->tm_sec);
    getch();
    return 0;
}
