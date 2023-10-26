#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	char buf[100];
	char *c = getcwd(buf, sizeof(buf));
	DIR *dp = opendir(c);
	
	struct dirent *d;
	while ((d = readdir(dp)) != NULL)
	{
		if (d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
	}
	return 0;
}
