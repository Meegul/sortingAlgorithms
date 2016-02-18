CC=gcc

OPTIONS= -Wall -Werror -g

OUTPUTFILE=sortit

SOURCEFILES=sortit.c mergeSort.c

all: sortit.c mergeSort.c
	$(CC) $(OPTIONS) $(SOURCEFILES) -o $(OUTPUTFILE) 
clean:
	$(RM) $(OUTPUTFILE)
