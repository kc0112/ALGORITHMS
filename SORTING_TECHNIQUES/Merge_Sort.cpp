#include<iostream>
using namespace std;

void merg(int a[],int lb,int mid,int ub)
{
     int i=lb,j=mid+1,k=lb,b[10];
     while(i<=mid&&j<=ub)
     {
         if(a[i]<=a[j])
         {
             b[k]=a[i];
             i++;k++;
         }
         else
         {
             b[k]=a[j];
             j++;k++;
         }
     }
     if(i>mid)
     {
         while(j<=ub)
         {
             b[k]=a[j];
             j++;k++;
         }
     }
     else if(j>ub)
     {
         while(i<=mid)
         {
             b[k]=a[i];
             i++;k++;
         }
     }
 for(k=lb;k<=ub;k++)
   a[k]=b[k];
}

void mergesort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merg(a,lb,mid,ub);
    }

}

int main()
{
     int a[]{15,5,24,8,1,3,16,10,20},i;
     mergesort(a,0,8);
     for(i=0;i<9;i++)
        cout<<a[i]<<" ";

}
