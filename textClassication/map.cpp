#include<map>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;
int main(){
    string S="text text fg";
    istringstream ifs(S);
    string str;
    map<string,int> M;
    while(ifs>>str){
	M[str]++;
    }
    for(auto &x : M){
	cout<<x.first<<"\t"<<x.second<<endl;
    }
}
