#ifndef _GODFORMA_H_
#define _GODFORMA_H_

#include <sys/stat.h>

#undef find
#undef del
extern FILE *opf;	//FILE OPERATING ON

extern long find(const char *phrase, size_t size, char *opts[]);
extern long findrepl(char *phrase1, char *phrase2, char *opts[]);
extern int re(char *phrase, char *opts[]);
extern int givname(char *fname);
extern int givmod(mode_t mask);
extern int dodel();
extern int setandformat(char *phrases[], char *formatstr);

#endif //_GODFORMA_H_
