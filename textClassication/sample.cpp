#include "OpenSP/ParserEventGeneratorKit.h"
#include <stdio.h>
#include <iostream>
using namespace std;
ostream &operator<<(ostream &os, SGMLApplication::CharString s)
{
    for (size_t i = 0; i < s.len; i++)
	os << char(s.ptr[i]);
    return os;
}

class OutlineApplication : public SGMLApplication {
public:
    OutlineApplication() : depth_(0) { }
    void startElement(const StartElementEvent &event) {
	printf("%*s\n",depth_*4,"");
	//cout << event.gi << '\n';
	depth_++;
    }
    void endElement(const EndElementEvent &) { depth_--; }
private:
    unsigned depth_;
};

int main(int argc, char **argv){

    ParserEventGeneratorKit parserKit;
    // Use all the arguments after argv[0] as filenames.
    EventGenerator *egp = parserKit.makeEventGenerator(argc - 1, argv + 1);
    OutlineApplication app;
    unsigned nErrors = egp->run(app);
    delete egp;
    return nErrors > 0;
}
