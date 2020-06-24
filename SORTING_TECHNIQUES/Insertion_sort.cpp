#include<iostream>
using namespace std;

int main()
{
    int a[]{5,2,4,6,1,3},j,i,n=6;
    for(i=1;i<n;i++)
        {
            int temp=a[i];
            for(j=i;j>0&&temp<a[j-1];j--)
               a[j]=a[j-1];
            a[j]=temp;
        }
        cout<<"INCREASING ORDER : ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

                cout<<endl<<"DECREASING ORDER : ";
        for(i=1;i<n;i++)
        {
            int temp=a[i];
            for(j=i;j>0&&temp>a[j-1];j--)
               a[j]=a[j-1];
            a[j]=temp;
        }
        for(i=0;i<n;i++)
        cout<<a[i]<<" ";

}
