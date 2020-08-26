#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    vector<int> start =  {1, 3, 0, 5, 8, 5};
    vector<int> finish =  {2, 4, 6, 7, 9, 9};

    multimap<int,int>prob;
    for(int i{0};i<start.size();i++){
        prob.insert(make_pair(finish[i],start[i]));
    }
    
    auto it =prob.begin();
    cout<<it->second<<":"<<it->first<<endl;
    it++;
    auto prev=prob.begin();
    while(it!=prob.end()){
        if(prev->first<=it->second){
            cout<<it->second<<":"<<it->first<<endl;
            prev=it;
        }
        it++;
    }
}
