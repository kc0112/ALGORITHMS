#include<iostream>
using namespace std;
void merge_sort(int a,int n);
void merg(int a[],int b[],int lb,int mid,int ub);
void mergesort(int a[],int temp[],int lb,int ub);

void merg(int a[],int b[],int lb,int mid,int ub)
{
     int i=lb,j=mid+1,k=lb;
     while(i<=mid&&j<=ub)
     {
         if(a[i]<=a[j])
         {
             b[k++]=a[i++];
         }
         else
         {
             b[k++]=a[j++];
        }
     }
     if(i>mid)
     {
         while(j<=ub)
         {
             b[k++]=a[j++];
         }
     }
     else if(j>ub)
     {
         while(i<=mid)
         {
             b[k++]=a[i++];
         }
     }
 for(k=lb;k<=ub;k++)
   a[k]=b[k];
}


void mergesort(int a[],int temp[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,temp,lb,mid);
        mergesort(a,temp,mid+1,ub);
        merg(a,temp,lb,mid,ub);
    }

}

void merge_sort(int a[],int n)
{
    int temp[n];
    mergesort(a,temp,0,n-1);
}

int main()
{
     int a[]{15,5,24,8,1,3,16,10,20},i;
     int n=sizeof(a)/sizeof(a[0]);
     merge_sort(a,n);
     for(i=0;i<9;i++)
        cout<<a[i]<<" ";

}
