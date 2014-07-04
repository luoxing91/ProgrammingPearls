#include<map>

typedef pair<string,int> Pair ;
bool cmp(const Pair& a ,const Pair& b){
    return a->second > b->second;
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
	return Vo;
    }
    map<string> getFrequency(){
	map<string,int> Fre;
	for(const string& w:_context){
	    Fre[string]++;
	}
	return Fre;
    }
    
private:
    vector<string> _context;
    vector<Pair> _vocabulary;
    
};
int main(){
    
}
