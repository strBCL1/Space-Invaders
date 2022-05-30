#include <iostream>
#include "windows.h"
#include "time.h"

char map[20][20] = {
	"###################",
	"#                 #",
	"#  @ @ @ @ @ @ @  #",
	"#   @ @ @ @ @ @   #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#        W        #",
	"###################"
};

bool endgame = false;
int gamespeed = 200;
int randomNum;
int maxHealth = 200;
int yourHealth = maxHealth;

int main()
{


	system("color 0a");

	while (!endgame) {

		srand(time(0));

		system("cls");

		for (int y = 0; y < 20; ++y) {
			std::cout << map[y] << std::endl;
		}

		std::cout << "Health " << yourHealth << "/" << maxHealth;

		for (int y = 0; y < 20; ++y) {
			for (int x = 0; x < 20; ++x) {

				switch (map[y][x]) {
					case 'W': {

						// <- key
						if (GetAsyncKeyState(VK_LEFT) != 0) {
							int newX = x - 1;

							if (map[y][newX] == ' ') {
								map[y][x--] = ' ';
								map[y][newX] = 'W';
							}
						}

						// -> key
						if (GetAsyncKeyState(VK_RIGHT) != 0) {
							int newX = x + 1;

							if (map[y][newX] == ' ') {
								map[y][x++] = ' ';
								map[y][newX] = 'W';
							}
						}

						// SPACEBAR key
						if (GetAsyncKeyState(VK_SPACE) != 0) {
							y--;
							map[y][x] = '^';
						}

						break;
					}

					case '^': {
						map[y][x] = ' ';
						y--;

						if (map[y][x] != '#' && map[y][x] != '@') {
							map[y][x] = '^';
						}
						else if (map[y][x] == '@') {
							map[y][x] = ' ';
						}

						break;

					}

					case '@': {

						randomNum = rand() % 100 + 1;

						if (randomNum == 1) {

							y++;
							map[y][x] = '*';
						}
						break;
					}

					case '*': {

						map[y][x] = ' ';
						y++;

						if (map[y][x] != '#' && map[y][x] != 'W') {
							map[y][x] = '*';
						}
						else if (map[y][x] == 'W') {

							yourHealth -= 20;

						}
						break;
					}


				}
			}

		}
		if (yourHealth <= 0) {

			endgame = true;

		}
		Sleep(gamespeed);

	}

	system("cls");
	std::cout << "You lost" << std::endl;

	system("PAUSE");

	return 0;

}