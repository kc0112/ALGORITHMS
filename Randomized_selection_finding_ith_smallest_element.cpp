#include<iostream>
#include<algorithm>
using namespace std;

 int partition(int a[],int lb,int ub)
{
    int pivot=lb;
    int start=lb,end=ub;
    while(start<end)
    {
        while(a[start]<=a[pivot])
            start++;
        while(a[end]>a[pivot])
            end--;
        if(start<end)
            swap(a[start],a[end]);
    }
    swap(a[end],a[pivot]);
    return end;
}

int quicksort(int a[],int lb,int ub,int i)
{
    if(ub>lb)
    {
        int loc=partition(a,lb,ub);
        if(loc==i)
            return loc;
        else if(loc>i)
            return quicksort(a,lb,loc-1,i);
        else
            return quicksort(a,loc+1,ub,i);
    }
}

int main()
{
    int a[]{7,6,10,5,9,2,1,15,7};
    int i;
    cin>>i;
    int res=quicksort(a,0,8,i-1);
    cout<<"The "<<i<<"th order statistic is : "<<a[res]<<endl;
}
