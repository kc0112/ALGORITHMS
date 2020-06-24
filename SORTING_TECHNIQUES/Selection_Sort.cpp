#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[]{5,2,4,6,1,3},j,i,n=6,low;

    for(i=0;i<n;i++)
    {
        low=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[low])
                low=j;
        }
        swap(a[i],a[low]);
    }

    cout<<"INCREASING ORDER : ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
