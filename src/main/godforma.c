#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <godforma.h>

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
				if (strcpy(primbuf, tempbuf) == NULL) {
					perror("strcpy err");
					exit(EXIT_FAILURE);
				}
			}
			*(primbuf + count++) = (char) c;
		}
		*(primbuf + count) = '\0';
		if (strcmp(primbuf, "exit") == 0)
			exit(2);
		printf("%s\n", primbuf);
	}
	free(primbuf);
	free(tempbuf);
	return 0;

}
