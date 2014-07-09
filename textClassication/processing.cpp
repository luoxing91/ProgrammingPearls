#include<stdio.h>
#include<cstdlib>
#include<string>
#include<queue>
#include<vector>
#include<fstream>
#include<algorithm>
#include<boost/regex.hpp>
#include<boost/algorithm/string.hpp>
#include "out.hpp"
#include "containerTools.hpp"
using namespace std;
//////////////for pait<string ,int> ////
typedef std::pair<string,int> Pair;
typedef std::pair<string,double> PairDouble;
bool sortPred(const Pair& a,const Pair& b){
    return a.second > b.second;
}
struct sortPredClass{
    bool operator()(const Pair&lhs,const Pair&rhs){
        return (lhs.second < rhs.second);
    }
};
vector<string> top8(const map<string,int>& topics);
//return the top 8 Frequency pair<sting,int> ;
////////////////////////////////////tools for string///////////////////////////
std::string stripLower(const std::string& str="\"&lt;jljd");
string getText(ifstream& infile);
///////////////////////////////////////////////////////////////////// 


/////////////tools for vector<double>//////////////////////////////////////////
void operator-=(vector<float>& l,const vector<float>& r){
    auto lit= l.begin();
     vector<float>::const_iterator rit= r.begin();
    while(rit!=r.end() && lit!=l.end()){
        *lit -=*rit;
        ++lit;
        ++rit;
    }
}
template<typename T>
double distance(const map<string,T>& a,const  map<string,T>& b){
    map<string,T> c(a);
    for(const auto w:b){
        if(c[w.first]==0) c[w.first]= -w.second; 
        else c[w.first]-=w.second;
    }
    double sum =0;
    for(auto w:c){
        sum += w.second * w.second;
    }
    return sum;
}
/////////////tool fot map /////////////////////////////////////////////////


//vector<float> normalize(const vector<float>& tf);
vector<float> Mapsecond(const set<string> &words,
                         const map<string,float>& fre){
    vector<float> result;
    map<string,float>::const_iterator it;
    for(const auto& word:words){
        it = fre.find(word);
        if(it!=fre.end())
            result.push_back(it->second);
        else
            result.push_back(0.0);
    }
    return result;
}




//////////////////////////Article//////////////////////////////////////////////
class Article{
private:
    map<string,int> _M;
    int _sum;
    string _topic;
    string _body;
public:
    Article(const string& topic,const string& body):
        _topic(topic),_body(body){
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
        while(ins>>str){
            _M[stripLower(str)]++;
        }
    }
    set<string> _getWords(){
        set<string> words;
        string word;
        istringstream ins(_body);
        while(ins>>word)
            words.insert(word);
        return words;
    }
    // not using!!
    void _getNormFrequency(){
        int sum =0;
        for(const auto& it: _M){
            sum += it.second;
        }
        _sum =sum;
    }

};

////////////////////////////////Corpus class //////////////////////////////////
class Corpus{
private:
    map<string,int> _M;
    map<string,float> _IDF;
    vector<Article> col;
    set<string> _v;
    vector<string> _sortedWords;
    bool _hasSorted ;
    int _index(const string& str){
        if(!_hasSorted){
            for(const auto w : _v)
                _sortedWords.push_back(w);
            sort(_sortedWords.begin(),_sortedWords.end());
        }
        return __index(_sortedWords,str);

    }
public:
    void addWords(const map<string,int>& words){
        for(const auto& word: words){
            _M[word.first]++;
            _v.insert(word.first);
        }

    }
    map<int,float>  indexIfIdf(const Article& art){
        
        map<string,float> t= tfIdf(art);
        map<int,float> res;
        for(const auto w:t){
            if(w.second)
                res[_index(w.first)]=w.second;
        }
        return res;
    }
    map<string,float> tfIdf(const Article& art){
        if(!_hasIdf)
            _idf();
        map<string,int> M=art.getFrequency();
        map<string,float> tf;
        for(auto& word:M){
            tf[word.first] =M[word.first]*_IDF[word.first];
        }

        return tf;
    }
    const vector<Article> _getArticles() const {
        return col;
    }
    
vector<vector<float> >  getMartix(){
        
        if(!_hasIdf)
            _idf();

        vector<vector<float> > ifidf;        
        for(const auto& article :col){
            map<string,float> vec= tfIdf(article);
            cout<<vec.size()<<endl;
            // ifidf.push_back(vec);
        }
        return ifidf;
    }

vector<string> getVocabulary(){
    map<string,int>::iterator vo = _M.begin();
        vector<string> vs;
        while(vo!=_M.end()){
            vs.push_back(vo->first);
            ++vo;
        }
        return vs;
    }
Corpus(){
    _hasSorted=false;}
    void addArticles(const vector<Article>& arts){
        for(const auto& art: arts ){
            addArticle(art);
        }
        _hasIdf=false;
    }
    Corpus(const vector<Article>& arts){
        for(const auto& art: arts ){
            addArticle(art);
        }
        _hasIdf=false;
    }
    void addArticle(const Article& art ){
        col.push_back(art);
        addWords(art.getFrequency());
        _hasIdf=false;
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
    bool _hasIdf;
    void _idf(){
        for(const auto& word:_M){
            _IDF[word.first] = log(getTotalArticleNumber()+1
                                   /word.second+1);
            if(_M[word.first]<=0) _IDF[word.first]=0;
        }
        _hasIdf=true;
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
/////////////////////////////////////////////////////////


Corpus topCorpus(const Corpus& cor){
    map<string,int> topALL = cor.getTopics();

    vector<string> tops = top8(topALL); ;

    Corpus corpus;
    for(const auto& art: cor.getArticles()){
        string top = art.getTopic();
	
        vector<string>::iterator it = find(tops.begin(),tops.end(),top);
        if(it!=tops.end()) corpus.addArticle(art);
    }
    return corpus;
}
//////////////////////////////////////////////

int main(){
    string file("reuters21578/reut2-0");
    Corpus corpus;
    for(int i=0;i<2;i++){
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

    map<string,int> topics =corpus.getTopics();
    Corpus topCor = topCorpus(corpus);
    cout<<"ok1\n";
    //vector<vector<float> > mat= topCor.getMartix();


    for(auto current: topCor.getArticles()){
        //        if(rand()%2) const Article next(current);
        //cout<<topCor.tfIdf(current);
        cout<<distance(topCor.tfIdf(current),topCor.tfIdf(current))<<endl;;
        
    }
    cout<<"ok2\n";

    cout<<"ok3\n";
}
////////////////////////////////////////////////////////////
vector<string> top8(const map<string,int>& topics){    
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
    vector<string> M;
    for(int i=0;i<8;i++){
        M.push_back(tops[i].first);
    }
    return M;
    
}
string stripLower(const string& str){
    string newtext = "";
    boost::regex re("\\\"|&lt;|$|&#127;|&amp;|[[:punct:]]|[[:digit:]]");
    std::string result = boost::regex_replace(str, re, newtext);
    //    transform(result.begin(),result.end(),result.begin(),::tolower);
    boost::algorithm::to_lower(result);
    return result;
}
string getText(ifstream& infile){
    string line;
    ostringstream rawtext;
    while(getline(infile,line)){
        rawtext<<line;
        //rawtext<<"\n";
    }
    return rawtext.str() ;
}
double _addToMap(double total,const map<string,double>::value_type& data){
    return total+ data.second;
}
vector<double> normalize(const vector<double> & _tf){
    vector<double> tf(_tf);
    double sum = accumulate(tf.begin(),tf.end(),0 );
    for(auto& d:tf){
        d /=sum;
    }
}
void _normalize(map<string,double>& tf){
    double sum = accumulate(tf.begin(),tf.end(),0 ,_addToMap);
    for(auto& d:tf){
        d.second/=sum;
    }
}
void normalize(map<string,double>& tf){
    _normalize(tf);
}

map<string,double> normalizeC(const  map<string,int>& tf){
    map<string,double> res;
    for(const auto& l:tf){
        res[l.first] = l.second;
    }
    _normalize(res);
    return res;
}


