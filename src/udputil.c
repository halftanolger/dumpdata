//
// UdpUtil - 
//

#include <stdio.h>
#include <string.h>
#include "udputil.h"

int main (int argc, char* argv[]) {

	UDPUTIL data;
	
	init (argc, argv, &data);

	if (data.help == 1) {
		usage (&data);
		return 0;		
	} 
	
	int return_code = 0;
	if (strncmp(data.function, "server",6) == 0) {
		return_code = udputil_server(&data);
	} else if (strncmp(data.function, "client",6) == 0) {
		return_code = udputil_client(&data);
	} 
		
	return return_code;
	
}

int udputil_server(UDPUTIL* data) {

	printf ("server \n");
	
	return 0;

}	


int udputil_client(UDPUTIL* data) {

	printf ("client \n");

	return 0;

}	


void init (int argc, char* argv[], UDPUTIL* data) {
	
	const char *name = "udputil";
	const char major_version = 1;
	const char minor_version = 0;
	
	data->name = strdup(name);
	data->major_version = major_version;
	data->minor_version = minor_version;
	
	const char *server = "server";
	const char *client = "client";
	const char *unknown = "unknown";

	if (argc > 2 && strncmp(argv[1],server,6) == 0) { 
		data->function = strdup(server);	
	} else if (argc > 2 && strncmp(argv[1],client,6) == 0) { 
		data->function = strdup(client);
	} else { 
		data->function = strdup(unknown);
		data->help = 1; 
		return;
	}				

	data->help = 0;
	data->debug = 0;
	for (int i=0; i< argc; i++) {
		if (strncmp(argv[i],"-h",2) == 0) {
			data->help = 1;
			return;
		} else if (strncmp(argv[i],"-d",2) == 0) {
			data->debug = 1;
		} 
	} 	
			
	//todo: parse read ip:port, if error then data->help=1 and return
	
	//todo: parse write ip:port, if error then data->help=1 and return
	
											
}

void usage(UDPUTIL* data) {

	printf ("\n%s version %d.%d\n", data->name,data->major_version,data->minor_version);	
	printf ("\nThe purpose of %s is to send udp-packages further to one or more clients.\nThe tool can akt as both server and client.\n",data->name);	
	printf ("\n%s as server.\n\n",data->name);
	printf ("  %s server [read-ip:read-port] [write-ip:write-port,write-ip:write-port] <-d> <-h>  \n",data->name);
	printf ("\n%s as client, for testing purpose.\n\n",data->name);
	printf ("  %s client [read-ip:read-port]  <-d> <-h>  \n",data->name);	
	printf ("\nwhere\n\n");
	printf ("  -d                   write debug to console.\n");
	printf ("  -h                   write this text.\n");
	printf ("  read-ip:read-port    the ip:port which we read from.\n");
	printf ("  write-ip:write-port  the ip:port which we write to, these\n");
	printf ("                       can be separated by ',' if you wish to\n");
	printf ("                       write to several clients.\n\n");
	
}
