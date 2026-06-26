#include<stdio.h>
#include<unistd.h>
int main(){
	printf("Parent\n");
	fork();
	printf("Child/n");
	return 0;
}
