#include <iostream>
#include <unistd.h>
using namespace std;

void display(int number);
int main(){
	int num;
	while (1){
		printf(" Enter a number (0-10) :" );
		scanf("%d",&num);
		display(num);
	}
	/* while ( system("mpg123 bgm.mp3 >> /dev/null 2>&1") ){ } */
}
void display(int number){
	switch (number){
		case 1:
			system("cat numbers/one");
			break;
		case 2:
			system("cat numbers/two");
			break;
		case 3:
			system("cat numbers/three");
			break;
		case 4:
			system("cat numbers/four");
			break;
		case 5:
			system("cat numbers/five");
			break;
		case 6:
			system("cat numbers/six");
			break;
		case 7:
			system("cat numbers/seven");
			break;
		case 8:
			system("cat numbers/eight");
			break;
		case 9:
			system("cat numbers/nine");
			break;
		case 10:
			system("cat numbers/hurray");
			break;
		case 0:
			system("cat numbers/zero");
			break;
		case -1:
			system("cat numbers/lost");
			break;
	}
}
