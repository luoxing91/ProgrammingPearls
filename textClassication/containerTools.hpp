#include<vector>
template<typename T>
int __index(const std::vector<T>& _sortedWords,const T& str){
    typename std::vector<T>::const_iterator it=
        lower_bound(_sortedWords.begin(),
                    _sortedWords.end(),str);
    return it-_sortedWords.begin();
}

template<typename T,typename K>
double innerProduct(const std::map<K,T>& x,const std::map<K,T>& y){
    double sum =0.0;
    typename std::map<K,T>::const_iterator it;
    for(const auto& point:x){
        it =y.find(point.first);
        if(it!=y.end()){
            sum +=x.at(point.first) * y.at(point.first);
        }
    }
    return sum;
}
template<typename T,typename K>
double norm(const std::map<K,T>& x){
    double sum=0.0;
    for(const auto& point:x){
        sum += point.second*point.second;
    }
    return sum;
}
template<typename T,typename K>
double cosineDistance(const std::map<K,T>& x,const std::map<K,T>& y){
    return innerProduct(x,y)/sqrt(norm(x)*norm(y));
}
