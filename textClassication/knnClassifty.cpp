
#include<string>
#include<queue>
typedef std::pair<string,double> Pair;
struct compPair{
    bool operator()(const Pair& lhs,const Pair& rhs){
        return lhs.second > rhs.second;
    }
};
typedef std::priority_queue<Pair,vector<Pair>,compPair> Tops;
string knnClassifty(const Corpus& cor ,const Article art, int k){
    Tops tops;
    for(const auto & a:cor.getArticles()){
        tops.push(std::pair(a.getTopic,sim(a,art)));
        if(tops.size()>k) tops.pop();
    }
    map<string,int> count;
    int maxCount=0;
    string cl="nodefine";
    for(const auto& topic:tops){
        string topicStr= topic.first;
        count[topicStr]++;
        if(count[topicStr] > maxCount){
            maxCount=count[topicStr];
            cl=topicStr;
        }
    }
    return cl;
}
