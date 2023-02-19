//
// UdpUtil - 
//

#include <stdio.h>
#include <string.h>
#include "udputil.h"

int main (int argc, char* argv[]) {

	UDPUTIL data;
	
	init (argc, argv, &data);
	
	printf ("function: %s\n",data.function);
	
	usage (&data);
		
	return 0;
	
}

void init (int argc, char* argv[], UDPUTIL* data) {
	
	const char *name = "udputil";
	const char major_version = 1;
	const char minor_version = 0;

	const char *server = "server";
	const char *client = "client";
	const char *unknown = "unknown";

	data->name = strdup(name);
	data->major_version = major_version;
	data->minor_version = minor_version;
	
	if (argc > 2 && strncmp(argv[1],server,6) == 0) 
		data->function = strdup(server);	
	else if (argc > 2 && strncmp(argv[1],client,6) == 0) 
		data->function = strdup(client);
	else 
		data->function = strdup(unknown);				
	
											
}

void usage(UDPUTIL* data) {

	printf ("\n%s version %d.%d\n", 
		data->name,
		data->major_version,
		data->minor_version);
	
	printf ("usage:\n");	
	printf ("\nThe purpose of %s is to send an udp-package further to one or more clients.\nThe tool can akt as both server and client.\n",data->name);	
	printf ("\n%s as server.\n\n",data->name);
	printf ("  %s server [read-ip:read-port] [write-ip:write-port,write-ip:write-port] <-d>  \n",data->name);
	printf ("\n%s as client, for testing purpose.\n\n",data->name);
	printf ("  %s client [read-ip:read-port]  <-d>  \n",data->name);
	
	printf ("\nwhere\n\n");
	printf ("  -d                   write debug to console.\n");
	printf ("  read-ip:read-port    the ip:port which we read from.\n");
	printf ("  write-ip:write-port  the ip:port which we write to, these\n");
	printf ("                       can be separated by ',' if you wish to\n");
	printf ("                       write to several clients.\n\n");
	
}
