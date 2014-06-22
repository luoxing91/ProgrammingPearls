#include<stdio.h>
#include<set>
#include<string>
#include<iostream>
int main(){
  using namespace std;
  set<string> S;
  string t;
  while(cin>>t)
    S.insert(t);
  for(set<string>::iterator j=S.begin();j!=S.end();++j)
    cout<<*j<<"\n";
  return 0;
}
