# Target to build the 'count-words' executable
all: count-words

# Rule to link the 'count-words' executable
count-words: count-words.o
	gcc -m32 -g -Wall -o count-words count-words.o


# Rule to compile 'count-words.c' into 'count-words.o'
count-words.o: count-words.c
	gcc -m32 -g -Wall -c -o count-words.o count-words.c

# Phony target to clean up object files and the executable
.PHONY: clean
clean:
	rm -f *.o count-words
