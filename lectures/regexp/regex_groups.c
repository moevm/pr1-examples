#include <stdio.h>
#include <regex.h>
#include <string.h>


int main ()
{
    char * regexString = "\\+?[[:digit:]][\\( ]?([[:digit:]]{3})[\\) ]?([[:digit:]]{3}.?[[:digit:]]{2}.?[[:digit:]]{2})";
    size_t maxGroups = 3;

    regex_t regexCompiled;
    regmatch_t groupArray[maxGroups];

    if (regcomp(&regexCompiled, regexString, REG_EXTENDED))
    {
        printf("Wowm no - can't compile regular expression\n");
        return 0;
    };

    FILE *f = fopen("inp.txt", "r");
    if(!f){
	printf("Wow, no - can't open file\n");
	return 0;
    }
    char s[100];
    while (fgets(s,100,f)){
        printf("%s",s);
        if (regexec(&regexCompiled, s, maxGroups, groupArray, 0) == 0)
        {
	    printf("matched!\n");
            for (int i = 0; i < maxGroups; i++)
            {
                if (groupArray[i].rm_so == -1)
                    break;

                printf("Group %d: [%2d-%2d]: ", i, groupArray[i].rm_so, groupArray[i].rm_eo);
                for(int j=groupArray[i].rm_so;j<groupArray[i].rm_eo;j++)
                    printf("%c",s[j]);
                printf("\n");
            }
        } else {
	    printf("NO matched!\n");
	}
	printf("-----------------------------------\n");

    }

    regfree(&regexCompiled);

    return 0;
}

