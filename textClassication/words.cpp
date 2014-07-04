#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
vector<string> getText(ifstream& in){
    vector<string> words;
    string w;
    while(in>>w){
	words.push_back(w);
    }
    return words;
}
int main(){
  using namespace std;
  map<string,int> M;
  string t;
  while(cin>>t)
    M[t]++;
  for(map<string,int>::iterator j=M.begin();j!=M.end();++j)
    cout<<j->first<<"\t"<<j->second<<"\n";
  return 0;
}
