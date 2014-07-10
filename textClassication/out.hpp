#include<ostream>
#include<vector>
#include<iterator>
#include<string>
#include<map>
#include<algorithm>
template<typename T>
std::ostream& operator<<(std::ostream& out,const std::vector<T>& vec){
    std::copy(vec.begin(),vec.end(),std::ostream_iterator<T>(out,"\t"));
}
template<typename K,typename T>
std::ostream& operator<<(std::ostream& out,const std::map<K,T>& m){
    for(const auto& word : m){
        out<<word.first<<"\t"<<word.second<<std::endl;
    }
}
std::ostream& operator<<(std::ostream& out,const std::vector<double>& vec){
    std::copy(vec.begin(),vec.end(),std::ostream_iterator<double>(out,"\t"));
}
template<typename T>
std::vector<T> normalize(const std::vector<T>& vec){
    std::vector<T> result(vec);
    return result;
}
template<typename T>
T norm2(const std::vector<T>& v){
    T sum =0;
    for(const auto& d :v){
        sum += d*d;
    }
    return sum;
}
