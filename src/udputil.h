#ifndef UDPUTIL_H
#define UDPUTIL_H

#ifdef __cplusplus
extern "c" {
#endif

typedef struct udputil_st {
	
	char  *name;
	char  major_version;
	char  minor_version;
	char *function;
	
} UDPUTIL;

void init(int argc, char* argv[], UDPUTIL* data);

void usage();

#ifdef __cplusplus
}
#endif

#endif //UDPUTIL_H
