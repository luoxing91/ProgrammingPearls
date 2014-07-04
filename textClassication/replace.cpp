#include<string>
#include<iostream>
#include<sstream>
#include<boost/regex.hpp>
bool validateCardFormat(const string& s){
    const boost::regex e("(\\d{4}[- ]){3}\\d{4}");
    return regex_match(s,e);
}
int main(){
    using namespace std;

    //    istringstream ins(str);
    ostringstream os;
    //boost::regex old("\\\"");
    //const char* newS=" ";
    //boost::regex_replace(os,str.begin(),str.end(),old,newS,
    //			 boost::match_default);
    

	
}
