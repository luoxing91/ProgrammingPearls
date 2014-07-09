#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T>
struct CompareVector{
    bool operator()(const vector<T>& x,const vector<T>& y) {
        return false;
    }
};
///////////////////////////////////////////////
vector<string> getText(ifstream& in){
    vector<string> words;
    string w;
    while(in>>w){
        words.push_back(w);
    }
    return words;
}
//////////////////////////////////////////////////////////
double _addToMap(double total,const map<string,double>::value_type& data){
    return total+ data.second;
}
template<typename T>
void _normalize(map<string,T>& tf){
    double sum = accumulate(tf.begin(),tf.end(),0 ,_addToMap);
    cout<<sum;
    for(auto& d:tf){
        d.second/=sum;
    }
}
map<string,double> normalize( map<string,int>& tf){
    map<string,double> res;
    for(const auto& l:tf){
        res[l.first] = l.second;
    }
    _normalize(res);
    return res;
}
template<typename T>
void _normalize(vector<T> & tf){
    double sum = accumulate(tf.begin(),tf.end(),0 );
    for(auto& d:tf){
        d.second/=sum;
    }
}
template<typename T>
ostream& operator<<(ostream& out,const map<string,T>& M){
    for(auto m: M){
            out<<m.first<<"\t"<<m.second<<"\n";
    }
}
int main(){
  using namespace std;
  map<string,int> M;
  string t;
  while(cin>>t)
    M[t]++;
  //  cout<<M;
  map<string,double> Md = normalize(M);
  cout<<Md;
  return 0;
}
