typedef std::map<string,double> Point;
map<Point,set<Point> > KMeans(const Corpus& cor,const int& k=8){
    map<Point,set<Point> > clusters;
    vector<Article> articles= cor.getArticles();
    vector<Article>::iterator it = articles.begin();
    while(true){
        map<string,double> textVector = cor.gettfIdf(*it);
        if(centers.size() <k){
            cluster[textVector].insert(textVector);
            continue;
        }
        auto oldCenter=cluster.end();
        for(auto it1 =clusters.begin();it1!=clusters.end();it1++){
            if(it1.second.count(texVector)!=0){
                oldCenter=it1;
                break;
            }
        }
        double dis;
        Point newCenter;
        for(auto it1 =clusters.begin();it1!=clusters.end();it1++){
            if(dis < cosineDistance(textVector,it1->first))
                newCenter = it1;
        }
        bool hasChange=false;
        if(oldCenter != newCenter){
            cluster[newCenter->first].insert(textVector);
            cluster[oldCenter->first].erase(textVector);
            hasChange=true;
        }
        if(it== articles.end()){
            if(hasChange){
                it=articles.begin();
                continue;
            }else{
                break;
            }
        }else{
            ++it;
        }
    }
    return clusters;
}    
