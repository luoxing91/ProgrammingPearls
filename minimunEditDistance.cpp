int mininumEditDistance(const char* a,int m, const char*b ,int n){
  if(a[m-1]==b[n-1]){
    return mininumEditDistance(a,m-1,b,n-1);
  }else{
    return std::min(mininumEditDistance(a,m-1,b,n)+1,
                    mininumEditDistance(a,m,b,n-1)+1);
  }
}
void mininumEditDistance(char* a , char* b){
  int m =strlen(a)+1;
  int n =strlen(b)+1;
  vector<int> E(m*n);
  for(int i=0;i<m;++i){
    E[i*n]=i;
  }
  for(int i=0;i<n;++i){
    E[i]=i;
  }
  for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
      int e1 = E[i*n+j-1]+1;
      int e2 = E[(i-1)*n+j]+1;
      if(a[i] != b[j]){
        int e3 = E[(i-1)*n+j-1]+1;
      }else{
        int e3 = E[(i-1)*n +j-1]
      }
      E[i*n+j]=std::min(std::min(e1,e2),e3);
    }
  }
  cout<<E[n*m-1]<<endl;
}
