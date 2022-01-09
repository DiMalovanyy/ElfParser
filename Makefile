CCFLAG = gcc

elfparser: elfparser.o
	$(CCFLAG) elfparser.o -o elfparser

elfparser.o: elfparser32.c
	$(CCFLAG) -c elfparser32.c -o elfparser.o

clean:
	rm -rf elfparser
	rm -rf elfparser.o
