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
	char  help;
	char  debug;	
	
} UDPUTIL;

void init(int argc, char* argv[], UDPUTIL* data);

void usage();

int udputil_server(UDPUTIL* data);

int udputil_client(UDPUTIL* data);

#ifdef __cplusplus
}
#endif

#endif //UDPUTIL_H
