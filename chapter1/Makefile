CC = cc
CFLAGS = -Wall
EXS_C = ex1.c ex2.c ex3.c ex4.c
OBJS = $(EXS_C:.c=.o)
TEST_OBJS = $(EXS_C:.c=_test.o)

.PHONY : test clean
test: ex1_test ex2_test ex3_test ex4_test

obj: $(OBJS)
$(OBJS) : defs.h
$(TEST_OBJS) : $(OBJS) defs.h


ex%_test : ex%_test.o $(OBJS)
	$(CC) -o $@ $^
	./$@



clean :
	rm *.o
