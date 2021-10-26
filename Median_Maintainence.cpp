#include<iostream>
#include<queue>
using namespace std;

int main(){
    int num;
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    cout<<"MEDIAN OF STREAM OF RUNNING INTEGERS"<<endl;
    cout<<"PLEASE INPUT NO. (enter -1 to exit ): "<<endl;
    while(cin>>num){
        if(num==-1)
           return 0;
        if(max_heap.empty()||max_heap.top()>num){
            max_heap.push(num);
        }
        else
            min_heap.push(num);
        if(max_heap.size()>min_heap.size()+1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(max_heap.size()<min_heap.size()+1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        cout<<"Currrent Median is : ";
        if(max_heap.size()==min_heap.size()){
            cout<<((double)(max_heap.top()+min_heap.top()))/2<<endl;
        }
        else if(max_heap.size()>min_heap.size()){
            cout<<max_heap.top()<<endl;
        }
        else
            cout<<min_heap.top()<<endl;
    }

}
