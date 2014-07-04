#include<unistd.h>
void processFile(int,)
int main(int argc, char* argv[]){
    if(argv >=3){
	int inputFd = open(argv[1],O_RDONLY);
	if(inputFd >=0){
	    struct stat fileStat;
	    if(fstat(inputFd,&fileStat)==0){
		int articleCount =0;
		int articleIndexOffset = strtol(argv[3],NULL,0);
		processFile(inputFd,&fileStat);
	    }
	}
    }
    printf("something wrong!");
}
void processFile(int inputFd,struct stat* const fileStat){
    char* fullData =0;
    readFullData(inputFd,&fullData);
    
    matcher* startMarker, *endMarker;
    build_matcher("<BODY>",startMarker);
    build_matcher("</BODY>",endMarker);
    int lastArticleEndPos =0;
    Articlematch lastArticleMatch=0;
    while(true){
	lastArticleMath
    }

    do{
	char* offsetData = fullData + lastArticleEndPos;
	lastArticleMatch = getMatch(offsetData,*startMarker,*endMarker);
	if(lastArticleMatch ==0){
	    saveArticle(lastArticleMatch,offsetData,
			articleCount+ articleIndexOffset);
	    articleCount++;
	    lastArticleEndPos= lastArticleEndPos + lastArticleMatch->end;
	    delete lastArticleMatch;
	}
    }
}
