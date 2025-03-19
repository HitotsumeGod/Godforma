#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <godforma.h>

int mhandler(char *buf, size_t bufsize);

int main(void) {

	printf("%s\n", "Format requests as follows: [FILE] [COMMAND] [OPTS].");
	char *primbuf, *tempbuf;
	size_t bufsize;
	int count, c;
	bufsize = 2;
	if ((primbuf = malloc(sizeof(char) * bufsize)) == NULL) {
		perror("malloc err");
		exit(EXIT_FAILURE);
	}
	while (1) {
		printf("%s", "* ");
		count = 0;
		while ((c = fgetc(stdin)) != EOF && c != '\n') {
			if (count > bufsize) {
				bufsize *= 2;
				if ((tempbuf = realloc(primbuf, sizeof(char) * bufsize)) == NULL) {
					perror("malloc err");
					exit(EXIT_FAILURE);
				}
				memcpy(primbuf, tempbuf, count - 1);
			}
			*(primbuf + count++) = (char) c;
		}
		*(primbuf + count) = '\0';
		if (strcmp(primbuf, "exit") == 0)
			exit(2);
		printf("%d\n", mhandler(primbuf, bufsize));
	}
	free(primbuf);
	free(tempbuf);
	return 0;

}

int mhandler(char *buffer, size_t size) {

	char *token;
	token = strtok(buffer, " ");
	FILE *opf = fopen(token, "r");
	token = strtok(NULL, " ");
	token = strtok(NULL, " ");
	return find(token, strlen(token), NULL);

}
