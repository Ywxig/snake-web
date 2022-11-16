#include <iostream>
#include <fstream >
#include <string>
#include <sstream>
#include <vector>
#include "Tasker.cpp"
#include "Helper.h"
// добовления самого интерпритатора
#include "SnakeWeb.h"
#include "markdown.h"
#include "Tasker.h"

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

		if(command == "start") {
			string type_style_file;
			string file;
			cout << "$: Input name file: ";	cin >> file; // ввод даных имени файла 
			cout << "$: Input type of styil file: ";	cin >> type_style_file; // ввод даных типа стиля файла, какое файл SW использовать
			WriteInFile(file, Read(type_style_file));
		}

		if (command == "run") {
			string file_input;
			string file_out;
			string standart_lang;
			cout << "$: Input file adres for input data: ";	cin >> file_input; // ввод даных для функции SnakeWeb() 
			cout << "$: Input file adres for out data: ";	cin >> file_out; // ввод даных для функции SnakeWeb() 
			cout << "$: Input standart: ";	cin >> standart_lang; // ввод специфекации для Snake-Web

			if ((standart_lang == "snake-web") || (standart_lang == "none")) {
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

		if(command=="markdown") {
			string file_input;
			string file_out;
			cout << "$: Input file adres for input data: ";	cin >> file_input; // ввод даных адреса от куда взять данные
			cout << "$: Input file adres for out data: ";	cin >> file_out; // ввод адреса до файла
			get_text_in_fail_for_markdown(file_input, file_out);
		}

		if (command == "report") {

			/*
			
			Чесно говоря говно какоето не советую пользоватся этой фыичяй, я хотеол реолизовать как git-push а получилось какаето шляпа
			скорее всего я напишу простую прогу с UI на python только дял репортов! но сейчяс очень сыро! 

			*/

			string file_input;
			string data;
			vector<string> content_ruport = split(data, "_");

			cout << "$: Input file adres for input data: ";	cin >> file_input; // ввод даных для функции SnakeWeb() 
			cout << "$: Input report content: ";	cin >> data; // ввод даных 

			for (int i = 0; i < content_ruport.size(); i++) {
				AddInFile(file_input, content_ruport[i]);
				AddInFile(file_input, " ");
			}
			AddInFile(file_input, "\n\n");
		}

		if (command == "login") {
			string name;
			achievement ac;
			cout << "$: Input name: "; cin >> name;

			if (Read("user") == "") {
				WriteInFile("user", "name::" + name);
			}

			else {
				cout << "Err!!!";
			}

			
		}

		if (command == "achi") {
			string name;
			achievement ac;
			cout << "$: Input name achievement: "; cin >> name;
			cout << ac.get_name(name);
		}
		/*
		if (command == "give") {
			string index_str;
			cout << "$: Input name achievement for give: "; cin >> index_str;

			vector<string> content = split(Read("achievement.sws"), "\n");

			AddInFile("user", "\nachievement::" + content[stoi(index_str)]);
		}
		*/
		if (command == "quit") {// комманда выхода из главного цикла!
			return 0;
		}
		



		else {
			cout << "\n\n$: Sorry this command is incorrect" << endl;
		}

	}
	return 0;
}