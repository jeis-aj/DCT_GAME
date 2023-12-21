#include <iostream>
#include <unistd.h>
using namespace std;

void display(int number);
/*
int main(){
	int num;
	while (1){
		printf(" Enter a number (0-10) :" );
		scanf("%d",&num);
		display(num);
	}
//	while ( system("mpg123 bgm.mp3 >> /dev/null 2>&1") ){ }
}
*/
void display(int number){
	system("clear");
	system("echo '\n'");
	system("echo '\n'");
	system("echo '\n'");
	system("echo '\n'");
	system("echo '\n'");
	switch (number){
		case 1:
			system("cat numbers/one	| lolcat ");
			break;
		case 2:
			system("cat numbers/two	| lolcat ");
			break;
		case 3:
			system("cat numbers/three	| lolcat ");
			break;
		case 4:
			system("cat numbers/four	| lolcat ");
			break;
		case 5:
			system("cat numbers/five	| lolcat ");
			break;
		case 6:
			system("cat numbers/six	| lolcat ");
			break;
		case 7:
			system("cat numbers/seven	| lolcat ");
			break;
		case 8:
			system("cat numbers/eight	| lolcat ");
			break;
		case 9:
			system("cat numbers/nine	| lolcat ");
			break;
		case 10:
			system("cat numbers/hurray	| lolcat ");
			break;
		case 0:
			system("cat numbers/zero	| lolcat ");
			break;
		case -1:
			system("cat numbers/lost	| lolcat ");
			break;
	}
}
