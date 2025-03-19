#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <godforma.h>

long find(const char *phrase, size_t phsize, char *opts[]) {		//ASSUMES THAT OPF IS OPEN; OTHERWISE UNDEFINED

	char *buf, *tbuf;
	size_t bufsize;
	int c, count;
	long counter;
	count = counter = 0;
	bufsize = 2;
	if ((buf = malloc(sizeof(char) * bufsize)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	while ((c = fgetc(opf)) != EOF) {
		if (count > bufsize) {
			bufsize *= 2;
			if ((tbuf = realloc(buf, sizeof(char) * bufsize)) == NULL) {
				perror("realloc err");
				exit(EXIT_FAILURE);
			}
			memcpy(buf, tbuf, count);
		}
		if (count > phsize) {	//ACCOUNT FOR INCREMENTING COUNT
			*(buf + count) = '\0';
			if (strcmp(phrase, buf) == 0)
				counter++;	//COUNTS MATCHES
			count = 0;	//COUNTS CURRENT ARRAY POSITION
		} else
			*(buf + count++) = (char) c;
	}
	return counter;

}
