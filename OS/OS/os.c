#include<stdio.h>
#include<unistd.h>

int main(){
	//int n = write(1, "Hello", 100);
	char buf[100];
	int n = read(0, buf, sizeof(buf));
	int x = write(1, buf, n);
	return 0;
}
