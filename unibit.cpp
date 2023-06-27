#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>&ans,vector<int>&num,vector<int>temp,int target,int i){
   if(target==0 && temp.size()==2){
      ans.push_back(temp);
      return;
   }
   else if(target!=0 && temp.size()==2)
   {
       return;
   }
   else if(i>=num.size()){
    return;
   }
   solve(ans,num,temp,target,i+1);
   temp.push_back(num[i]);
   solve(ans,num,temp,target-num[i],i+1);

}
void solve2(vector<vector<int>>&ans,vector<int>&num,vector<int>temp,int target,int i){
   if(target==0){
      ans.push_back(temp);
      return;
   }
   else if(i>=num.size())
   {
    return;
   }
   solve2(ans,num,temp,target,i+1);
   temp.push_back(num[i]);
   solve2(ans,num,temp,target-num[i],i+1);

}
int main() {
    vector<int>num={1,3,2,2,-4,6,-2,8};
    vector<vector<int>>ans;
    vector<vector<int>>ans2;
    vector<int>temp;
    int target=4;
solve(ans,num,temp,target,0);
cout<<"All the pair of the target value"<<endl;
for(auto arr:ans){
   for(auto element :arr){
      cout<<element<<" ";
   }
   cout<<endl;
}
vector<int>mergearray;
for(auto arr:ans){
   for(auto element :arr){
      mergearray.push_back(element);
   }
}
sort(mergearray.begin(),mergearray.end());
cout<<"Merge array in sorted Order"<<endl;
for(int i=0;i<mergearray.size();i++){
   cout<<mergearray[i]<<" ";
}
cout<<endl;
solve2(ans2,num,temp,2*target,0);
cout<<"All the combination of double target value"<<endl;
for(auto arr:ans2){
   for(auto element :arr){
      cout<<element<<" ";
   }
   cout<<endl;
}
    return 0;
}
