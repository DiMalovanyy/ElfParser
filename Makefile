CCFLAG = gcc

elfparser: elfparser.o file_type.o
	$(CCFLAG) elfparser.o file_type.o -o elfparser

elfparser.o: elfparser32.c
	$(CCFLAG) -c elfparser32.c -o elfparser.o

file_type.o: file_type.c
	$(CCFLAG) -c file_type.c -o file_type.o

clean:
	rm -rf elfparser
	rm -rf *.o
