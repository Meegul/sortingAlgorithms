CC=gcc

OPTIONS= -Wall -Werror -g

OUTPUTFILE=sortit

SOURCEFILES=sortit.c

all: sortit.c
	$(CC) $(OPTIONS) $(SOURCEFILES) -o $(OUTPUTFILE) 
clean:
	$(RM) $(OUTPUTFILE)
