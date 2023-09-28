#include <iostream>
#include <fstream>
#include <SFML/Audio.hpp>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int user;

	sf::SoundBuffer Win;
	if (!Win.loadFromFile("./sounds/win.ogg")) {
		return -1; // ������ ��� �������� �����
	}
	sf::Sound Win_sound;
	Win_sound.setBuffer(Win);

	sf::SoundBuffer Fail;
	if (!Fail.loadFromFile("./sounds/fail.ogg")) {
		return -1; // ������ ��� �������� �����
	}
	sf::Sound Fail_sound;
	Fail_sound.setBuffer(Fail);

	do {
		int rnd = 1 + rand() % 10;
		cout << "������� �����: ";
		cin >> user;
		if (rnd == user) {
			cout << "�� �������!" << endl;
			Win_sound.play();
		}
		else {
			cout << "�� �� �������. ���������� ����� - " << rnd << endl;
			Fail_sound.play();
		}
		}while (user != 0);
		return 0;
}