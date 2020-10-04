#include<bits/stdc++.h>
using namespace std;

void countSort(int a[],int n,int max,int min){
    int range=max-min+1;
    int freq[range]{0};

    for(int i{0};i<n;i++){
        int idx=a[i]-min;
        freq[idx]++;
    }

    for(int i{1};i<range;i++){
        freq[i]+=freq[i-1];
    }
    int ans[n];

    for(int i=n-1;i>=0;i--){
        int idx=a[i]-min;
        int pos=freq[idx]-1;
        ans[pos]=a[i];
        freq[idx]--;
    }

    for(int i{0};i<n;i++){
        a[i]=ans[i];
    }
}

void print(int a[],int n){
    cout<<"Sorted elements are "<<endl;
    for(int i{0};i<n;i++){
        cout<<a[i]<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    int max=INT_MIN,min=INT_MAX;
    for(int i{0};i<n;i++){
        cin>>a[i];
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }
    }
    countSort(a,n,max,min);
    print(a,n);
}
