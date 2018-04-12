#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <regex.h>

int isValid(char *filename){
	char *regexp = "^test-[[:digit:]]{4}\\.txt$";
	regex_t regexComp;

	if(regcomp(&regexComp, regexp, REG_EXTENDED)){
		return 0;
	}
	
	return regexec(&regexComp, filename, 0, NULL, 0) == 0;
}

void printFile(char* filename, int pad){
	FILE *f = fopen(filename, "r"); // "r", "w", "a"
	if(!f)
		return;
	for(int i=0;i<pad;i++)
		printf("\t");
	printf("%s:\n", filename);
	char s[100];
	while(fgets(s, 100, f)){
		for(int i=0;i<pad;i++)
			printf("\t");
		printf("\t%s", s);
	}
	printf("\n");
	fclose(f);
}

void listDir(char *startDir, int pad){
	char nextDir[200]={0};
	strcpy(nextDir, startDir);
	DIR *dir = opendir(startDir);
	if(!dir)
		return;
	struct dirent *de = readdir(dir);
	while(de){
		if(de->d_type == DT_DIR && strcmp(de->d_name, ".") != 0 &&
								   strcmp(de->d_name, "..") != 0){
			int len = strlen(nextDir);
			strcat(nextDir, "/");
			strcat(nextDir,de->d_name);
			listDir(nextDir, pad+1);
			nextDir[len] = '\0';
		}
		if(de->d_type == DT_REG && isValid(de->d_name)){
            int len = strlen(nextDir);
            strcat(nextDir, "/");
            strcat(nextDir,de->d_name);
			printFile(nextDir, pad);
            nextDir[len] = '\0';
		}
		de = readdir(dir);
	}
	closedir(dir);

}

int main(int argc, char **argv, char **env){
/*char **tmp = env;
while(*tmp){
	printf("%s", *tmp);
	tmp++;
}*/
if(argc != 2){
	printf("use ./prog <path>\n");
	return 0;
}

listDir(argv[1], 0);


return 0;
}
