#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

void ls(char buf[], DIR *dp){
	struct dirent *d;
	char *temp[100];
	int i = 0;
	while ((d = readdir(dp)) != NULL)
	{
		if (d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if(d->d_type == DT_DIR){
			int n = strlen(buf);	
			buf[n] = '/';
			int k = 0, len = d->d_reclen;
			while(len--){
				buf[n + k + 1] = d->d_name[k]; 
				k++;	
			}
			temp[i] = buf;
			i++;
		}
	}
	printf("\n");
	int l = i;
	i = 0;
	while(l--){
		DIR *dp1 = opendir(temp[i]);
		ls(buf, dp1);
		i++;
	}
}

int main(){
	char buf[100];
	char *c = getcwd(buf, sizeof(buf));
	DIR *dp = opendir(c);
	//printf("Dir : %s\n", buf);
	//int n = strlen(buf);	
	//printf("%d ", n);
		
	ls(buf, dp);
	return 0;
}
