#include<iostream>
#include<algorithm>
using namespace std;

 int partition(int a[],int lb,int ub)
{
    int pivot=a[lb];
    int start=lb,end=ub;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            swap(a[start],a[end]);
    }
    swap(a[end],a[lb]);
    return end;
}

void quicksort(int a[],int lb,int ub)
{
    if(ub>lb)
    {
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}

int main()
{
    int a[]{7,6,10,5,9,2,1,15,7};
    quicksort(a,0,8);
    for(int i=0;i<9;i++)
      cout<<a[i]<<" ";
}
