#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void printHelp(){
printf("getopt example\n");
printf("-f <value> - final value\n");
printf("-r - reverse\n");
printf("-v - verbose\n");
printf("-h -? - help\n");
}

struct Configs{
	int final;
	int reverse; // 0 - false
	int verbose; // 0 - false
};

int main(int argc, char* argv[]){
	struct Configs config = {0, 0, 0};
	char *opts = "f:rvh?";
	int opt;
	opt = getopt(argc, argv, opts);
	while(opt!=-1){
		switch(opt){
			case 'f':
//				printf("get f with value: %d\n", atoi(optarg));
				config.final = atoi(optarg);
				break;
			case 'r':
				config.reverse = 1;
				//printf("get r\n");
				break;
			case 'v':
				//printf("get v\n");
				config.verbose = 1;
				break;
			case 'h':
			case '?':
				printHelp();
				return 0;
		}
		opt = getopt(argc, argv, opts);
	}
	argc -= optind;
	argv += optind;	
	printf("final = %d\n", config.final);
	printf("verbose = %d\n", config.verbose);
	printf("reverse = %d\n", config.reverse);
	for(int i=0; i<argc; i++)
		printf(">>%s\n", argv[i]);
	return 0;
}
