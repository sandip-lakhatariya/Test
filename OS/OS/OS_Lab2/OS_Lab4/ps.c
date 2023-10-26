#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

int digits_only(const char *s)
{
    while (*s) {
        if (isdigit(*s++) == 0) return 0;
    }

    return 1;
}

int main(){

	char c[100] = "/proc";
	DIR *dp = opendir(c);
	struct dirent *d;
	char temp[100000][1000];
	int i = -1;
	
	while ((d = readdir(dp)) != NULL)
	{	
		//char s[100] = "/proc/";
		char *s;
		s = (char*)malloc(6*sizeof(char));
		s = "/proc/";
		if(d->d_type == DT_DIR && digits_only(d->d_name)){
		
			int n = strlen(s);	
			int k = 0, len = d->d_reclen;
			
		  	while(len--){
				s[n + k] = d->d_name[k]; 
				k++;	
			}
			i++;
			temp[i] = s;
			if(i > 3)
				printf("%s  %s\n", temp[i-2], temp[i - 1]);
		}
	}
	
	printf("\n");
	int l = i;
	int k = 0;
	while(l--){
		//printf("%s\n", temp[k]);
		k++;
	} 
	return 0;
}
