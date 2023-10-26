#include<stdio.h>
#include<unistd.h>

int main(){
	while(1){
		char buf[100];
		int x = read(0, buf, sizeof(buf));
		int y = write(1, buf, x);
		
		if(buf == "c"){break;}
	}
}
