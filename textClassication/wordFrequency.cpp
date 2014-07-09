#include<map>
#include<set>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include "out.hpp"
using namespace std;
typedef pair<string,int> Pair ;
bool cmp(const Pair& a ,const Pair& b){
    return a.second > b.second;
}

class wordFrequency{
public:
    void add(const string& word){
        _context.push_back(word);
    }
    vector<string> getVocabulary(){
        set<string> Vo;
        for(const string& w: _context){
            Vo.insert(w);
        }
        vector<string> res;
        for(const auto& w: Vo){
            res.push_back(w);
        }
    }
    map<string,int> getFrequency(){
        map<string,int> Fre;
        for(const string& w:_context){
            Fre[w]++;
        }
        return Fre;
    }
    
private:
    vector<string> _context;
    vector<Pair> _vocabulary;
    
};
int main(){

    string str="sfdhkfhj hhjkj hh jj hh hh ";
    istringstream ins(str);
    string word;
    wordFrequency fre;
    while(ins>>word){
        fre.add(word);
    }
    cout<<fre.getVocabulary();
}
