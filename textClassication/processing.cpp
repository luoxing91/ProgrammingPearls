#include<stdio.h>
#include<string>
#include<queue>
#include<vector>
#include<fstream>
#include<algorithm>
#include<boost/regex.hpp>
#include<boost/algorithm/string.hpp>
using namespace std;

std::string stripLower(const std::string& str="\"&lt;jljd"){
    std::string newtext = "";
    boost::regex re("\\\"|&lt;|$|&#127;|&amp;|[[:punct:]]|[[:digit:]]");
    std::string result = boost::regex_replace(str, re, newtext);
    //    transform(result.begin(),result.end(),result.begin(),::tolower);
    boost::algorithm::to_lower(result);
    return result;
} 

typedef std::pair<string,int> Pair;
bool sortPred(const Pair& a,const Pair& b){
    return a.second > b.second;
}
struct sortPredClass{
    bool operator()(const Pair&lhs,const Pair&rhs){
	return (lhs.second < rhs.second);
    }
};

class Article{
public:
    Article(const string& topic,const string& body):
	_topic(topic),_body(body){
	_getWords();
	_getFrequency();
	_getNormFrequency();
    }
    string getTopic() const{
	return _topic;
    }
    map<string,int> getFrequency() const{
	return _M;
    }
private:
    void _getFrequency(){
	istringstream ins(_body);
	string str;
	map<string,int> M;
	while(ins>>str){
	    M[stripLower(str)]++;
	}
	_M=M;
    }
    vector<string> _getWords(){
	vector<string> words;
	istringstream ins(_body);
	std::copy(istream_iterator<string>(ins),istream_iterator<string>(),
		  back_inserter(words));
	return words;
    }
    void _getNormFrequency(){
	int sum =0;
	for(const auto& it: _M){
	    sum += it.second;
	}
	_sum =sum;
    }
    vector<string> words;
    map<string,int> _M;
    int _sum;
    string _topic;
    string _body;
};


class Corpus{
private:
    map<string,int> _M;
public:
    void addWords(const map<string,int>& words){
	for(const auto& word: words){
	    _M[word.first] += word.second;
	}
    }
    
    map<string,int> tfIdf(const Article& art){
	_idf();
	auto M=art.getFrequency();
	for(auto& word:M){
	    M[word.first] *=_M[word.first];
	}
	
    }
    void createMartix(){
	
    }
    vector<string> getVocabulary(){
	map<string,int>::iterator vo = _M.begin();
	vector<string> vs;
	while(vo!=_M.end()){
	    vs.push_back(vo->first);
	    ++vo;
	}
	return vs;
	// priority_queue<Pair,vector<Pair>,sortPredClass> vos;
	// for(const Pair& vo:_M){
	//     vos.push(vo);
	//     cout<<vo.first<<endl;
	// }
	// while(!vos.empty()){
	//     Pair p = vos.top();
	//     cout<<p.second<<endl;
	//     vos.pop();
	//}
    }
    Corpus(){}
    void addArticles(const vector<Article>& arts){
	for(const auto& art: arts ){
	    addArticle(art);
	}
    }
    Corpus(const vector<Article>& arts){
	for(const auto& art: arts ){
	    addArticle(art);
	}
    }
    void addArticle(const Article& art ){
	col.push_back(art);
	for(const auto x: art.getFrequency()){
	    _M[x.first] += x.second;
	    //cout<<"addArticle" <<endl;
	}
    }
    map<string,int> getTopics() const{
	return _getTopics();
    }
    int getTotalArticleNumber()const {
	return col.size();
    }
    vector<Article> getArticles()const{
	return col;
    }
    
private:
    vector<Article> col;
    vector<string> _v;
    void _idf(){
	
	for(auto& word:_M){
	    _M[word.first] = log(getTotalArticleNumber()+0.5/word.second+0.5);
	    if(_M[word.first]<=0) _M[word.first]=0;
	}
    }
    
    map<string,int> _getTopics() const{
	map<string,int> M;
	for(const auto &art: col){
	    M[art.getTopic()]++;
	}
	return M;
    }
    vector<string> getTopTopics(const int& n=8) const{
	map<string,int> M =_getTopTopics(n);
	vector<string> ve;
	for(const auto &x:M){
	    ve.push_back(x.first);
	}
	return ve;
    }
    map<string,int> _getTopTopics(const int& n=8) const {
    
	int i=0;
	map<string,int> _M = getTopics();
	map<string,int>::iterator it = _M.begin();
	
	vector<string> vec;
	while(i<n && it !=_M.end()){
	    vec.push_back(it->first);
	    i++;
	    it++;
	}
	int minIndex=0;
	while(it!=_M.end()){
	    if(it->second < _M[vec[minIndex]]){
		vec[minIndex] =it->first;
		minIndex =0;
		for(int i=1 ;i<n;i++){
		    if(_M[vec[i]]< _M[vec[minIndex]]) minIndex = i;
		}
	    }
	    it++;
	}
	map<string,int> m;
	for(int i=0;i<n;i++){
	    m[vec[i]] = _M[vec[i]];
	}
	return m;
    }
    
};



vector<Article> findArticles(const string& rawtext){
    boost::regex regdoc("<REUTERS.*?>(.*?)</REUTERS>",
			boost::regbase::icase|boost::regbase::mod_s);
    boost::smatch mDoc;

    boost::regex regtopic("<TOPICS><D>(.*?)</D>.*?</TOPICS>",
			  boost::regbase::icase|boost::regbase::mod_s);
    boost::smatch mTopic;

    boost::regex regcontent("<BODY>(.*?)Reuter&#3;</BODY>"
			    ,boost::regbase::icase|boost::regbase::mod_s);
    boost::smatch mContent;

    string::const_iterator it = rawtext.begin();
    vector<Article> articleCollection;
    while(boost::regex_search(it,rawtext.end(),mDoc,regdoc)){
	string doc = mDoc[0];
	string topic,content;
	if(boost::regex_search(doc,mTopic,regtopic)){
	    topic=mTopic[1];
	}
	if(boost::regex_search(doc,mContent,regcontent)){
	    content=mContent[1];
	}
	it = mDoc[0].second;
	if(!topic.empty() && !content.empty()){
	    articleCollection.push_back(Article(topic,content));
	}
    }
    return articleCollection;
}
map<string,int> tops(const map<string,int>& topics){    
    Pair tops[9];
    map<string,int>::const_iterator it = topics.begin();
    for(int i=0;i<8;i++){
	tops[i]=Pair(*it);
	if(it == topics.end()) break;
	it++;
    }
    make_heap(tops,tops+8,sortPred);
    while(it !=topics.end()){
	tops[8]=Pair(*it);
	push_heap(tops,tops+9,sortPred);
	pop_heap(tops,tops+9,sortPred);
	it++;
    }
    sort_heap(tops,tops+8,sortPred);
    map<string,int> M;
    for(int i=0;i<8;i++){
	M[tops[i].first] = tops[i].second;
    }
    return M;
}
string getText(ifstream& infile){
    string line;
    string rawtext;
    while(true){
	if(getline(infile,line)==0) break;
	rawtext += line;
    }
    return rawtext ;
}
Corpus topCorpus(const Corpus& cor){
    map<string,int> topALL = cor.getTopics();
    map<string,int> topT = tops(topALL);
    vector<string> tops;
    for(auto x:topT){
	tops.push_back(x.first);
    }
    Corpus corpus;
    for(const auto& art: cor.getArticles()){
	string top = art.getTopic();
	
	vector<string>::iterator it = find(tops.begin(),tops.end(),top);
	if(it!=tops.end()) corpus.addArticle(art);
    }
    return corpus;
}
int main(){
    string file("reuters21578/reut2-0");
    Corpus corpus;
    for(int i=0;i<21;i++){
	ostringstream convert;
	convert<<file;
	if(i<10)convert<<"0";
	convert<<i;
	convert<<".sgm";
	ifstream infile(convert.str(),ifstream::in);
	if(!infile){
	    cout<<"can't open"<<convert.str()<<endl;
	}
	string rawtext = getText(infile) ;
	vector<Article> articles = findArticles(rawtext);
	corpus.addArticles(articles);
    }
    for(auto word : corpus.getVocabulary()){
	//	cout<<word <<endl;
    }
    map<string,int> topics =corpus.getTopics();
    Corpus topCor = topCorpus(corpus);

}
