#include<iostream>
using namespace std;

int LS (int a[],int n,int key)
{
    for(int i{0};i<n;i++)
        if(a[i]==key)
          return i;
    return -1;
}

int main()
{
  int a[] = {2, 4, 0, 1, 9};
  int n=sizeof(a)/sizeof(a[0]);
  int key = 1;
  int result=LS(a,n,key);
  (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;
}

