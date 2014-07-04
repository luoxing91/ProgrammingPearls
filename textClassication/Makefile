.PHONY:run all
PROGRAM=processing sample words
CPPFLAGS=-std=c++11
all:$(PROGRAM)
sample:sample.cpp
	g++ -o $@ -losp $<
processing:processing.cpp
	g++ -o $@ -lboost_regex $(CPPFLAGS) $<
replace:replace.cpp
	g++ -o $@ -lboost_regex $(CPPFLAGS) $<
run:
	./processing
clean:
	-rm  -f $(PROGRAM)
