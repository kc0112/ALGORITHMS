#include<iostream>
using namespace std;
int merge_sort(int a,int n);
int merg(int a[],int b[],int lb,int mid,int ub);
int mergesort(int a[],int temp[],int lb,int ub);

int merg(int a[],int b[],int lb,int mid,int ub)
{
     int i=lb,j=mid+1,k=lb,inv=0;
     while(i<=mid&&j<=ub)
     {
         if(a[i]<=a[j])
         {
             b[k++]=a[i++];
         }
         else
         {
             b[k++]=a[j++];
             inv=inv+(mid+1-i);
        }
     }

         while(j<=ub)
         {
             b[k++]=a[j++];
         }

         while(i<=mid)
         {
             b[k++]=a[i++];
         }

 for(k=lb;k<=ub;k++)
   a[k]=b[k];

   return inv;
}


int  mergesort(int a[],int temp[],int lb,int ub)
{
   int inv=0;
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        inv+=mergesort(a,temp,lb,mid);
        inv+=mergesort(a,temp,mid+1,ub);
        inv+=merg(a,temp,lb,mid,ub);
    }
  return inv;
}

int merge_sort(int a[],int n)
{
    int temp[n];
    return mergesort(a,temp,0,n-1);
}

int main()
{
     int a[]{1, 20, 6, 4, 5},i;
     int n=sizeof(a)/sizeof(a[0]);
    int inv= merge_sort(a,n);
     cout<<inv;
}
