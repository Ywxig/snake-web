#include <iostream>
#include <fstream >
#include <string>
#include <sstream>
#include <vector>
#include "Helper.h"
// добовления самого интерпритатора
#include "SnakeWeb.h"

//////////////////////////////////////////////////////////////////////////////////////|
// В даннои файле находится прога предоставляющяя простой интерфейс к интерпритатору//|
//////////////////////////////////////////////////////////////////////////////////////|

using namespace std;


int main() {

	while (true)
	{


		// Перегрузка метода
		string command;
		cout << "\n$: ";	cin >> command; // требуется ввести комманду (run, read, del, help ...)
		if (command == "read") {

			string file_input;
			string file_output;

			cout << "$: Input file adres for read data: ";	cin >> file_input; // ввести адрес файла

			cout << Read(file_input);
		}

		if (command == "write"){
			string file_input;
			string file_output;

			cout << "$: Input data: ";	cin >> file_input; // Даныне для ввода в фаил
			cout << "$: Input file adres for output data: ";	cin >> file_output; // адрес исходящего файла
			
			WriteInFile(file_input, file_output);
		}


		if (command == "help") {
			cout << "Snake-web version 1.3";

			cout << "\n";
		}

		if (command == "run") {
			string file_input;
			string file_out;
			string standart_lang;
			cout << "$: Input file adres for input data: ";	cin >> file_input; // ввод даных для функции SnakeWeb() 
			cout << "$: Input file adres for out data: ";	cin >> file_out; // ввод даных для функции SnakeWeb() 
			cout << "$: Input file adres for out data: ";	cin >> standart_lang; // ввод специфекации для Snake-Web

			if (standart_lang == "snake-web") {
				SnakeWeb(file_input, file_out);
				log("\nStandart Using is: " + standart_lang);
			}

			if (file_out == "print") {
				SnakeWeb(file_input, "print");
				log("\nprint");
			}

			else {
				log("\nError, standart " + standart_lang + " not in Intorpritator!");
			}

		}

		if (command == "quit") {// комманда выхода из главного цикла!
			return 0;
		}

		else {
			cout << "\n\n$: Sorry this command is incorrect" << endl;
		}

	}
	return 0;
}