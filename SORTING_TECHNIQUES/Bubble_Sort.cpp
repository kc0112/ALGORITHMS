#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
     int a[]{5,2,4,6,1,3},j,i,n=6;

     for(i=1;i<n;i++)
     {
         for(j=0;j<n-i;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
     }
   cout<<"INCREASING ORDER : ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
