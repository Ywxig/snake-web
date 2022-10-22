#include <iostream>
#include <fstream >
#include <string>
#include <sstream>
#include <vector>
#include "Helper.h"

using namespace std;


class Forms {// класс для работы с формой

public:
	vector<string> GetForms(string file_form) {
	
		string Form = Read(file_form);
		vector<string> content = split(Form, "/*cut*/");
		return content;
	}
public:
	string GetForm(string file_form, int index_form) {
		vector<string> content = GetForms(file_form);
		if (index_form <= content.size()) {
			cout << "Form return;" << endl;
			return content[index_form];
		}
		else {
			cout << "sory form not in file_form!;" << endl;
			return content[content.size()];
		}
	}
public:
	string CreatForm(string name_form, string form_content = "") {
		if (form_content == "") {
			WriteInFile(name_form, form_content);
			return "Form content is NULL";
		}
		else {
			WriteInFile(name_form, form_content);
			return "Form creat succes!";
		}
	}
};



int SnakeWeb(string file_input, string file_out) {// Функция с самим языком. Тут описана вся логика языка 

	std::string line;

	std::ifstream in(file_input); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			vector<string> content = split(line, "\n");
			int i = 0;
			string word = content[i];
			vector<string> Word = split(word, "::");

			// Используем условный оператор витвления для разбора текста на слова и строчьки
			if (Word[0] == "css") {// проверка, если первое слово == какомуто значению то;
				// То что делаеа какаето конструкция из четаемого файла
				AddInFile(file_out, "\n" + Word[1] + "\n");
			}

			if (Word[0] == "tag") { 
				string teg_style = "<" + Word[1] + "> " +"id = \"" + Word[2] + "\"" + "</" + Word[1] + ">";// создание тега и привезание его к id
				AddInFile(file_out, teg_style);// ввод в фаил
			}

			if (Word[0] == "id") {
				if (Word[1] == "open") {
					string id = "#" + Word[2] + "{";
					AddInFile(file_out, id);
				}
				if (Word[1] == "close") {
					string id = "}";
					AddInFile(file_out, id);
				}
			}

			if (Word[0] == "element") {
				string elemrnt = "\n<div class=\"" + Word[1] + "\">\n" + "\t" + Word[2] + "\n</div>\n";
				AddInFile(file_out, elemrnt);
			}

			if (Word[0] == "class") {
				if (Word[1] == "open") {
					string id = "." + Word[2] + "{";
					AddInFile(file_out, id);
				}
				if (Word[1] == "close") {
					string id = "}";
					AddInFile(file_out, id);
				}
			}

			if (Word[0] == "code") {
				if (Word[1] == "open") {
					if (Word[2] == "doc") {
						AddInFile(file_out, "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n\t<meta charset=\"UTF - 8\">\n\t<meta http-equiv=\"X - UA - Compatible\" content=\"IE = edge\">\n\t<meta name=\"viewport\" content=\"width = device - width, initial - scale = 1.0\">\n\t<title>Document</title>\n</head>\n");
					}

					if (Word[2] == "style") {
						AddInFile(file_out, "\n<style>");
					}
				}

				if (Word[1] == "close") {
					if (Word[2] == "doc") {
						AddInFile(file_out, "\n</body>\n</html> ");
					}

					if (Word[2] == "style") {
						AddInFile(file_out, "\n</style>\n<body>");
					}
				}
			}

			if (Word[0] == "use"){
				if (Word[1] == "css") {
					string content_file_css = Read(Word[2]);
					AddInFile(file_out, content_file_css);
				}

				if (Word[1] == "form") {
					Forms Form;
					Form = Forms();
					Form.GetForm(Word[2], stoi(Word[3]));
				}
			}

		i++;
		}
	}
	return 0;
}




int main() {

	while (true)
	{


		// Перегрузка метода
		string command;
		cout << "\nInput command: " << endl;	cin >> command; // требуется ввести комманду (run, read, del, help ...)
		if (command == "run") {

			string file_input;
			string file_output;

			cout << "Input file adres for input data: ";	cin >> file_input; // ввести адрес файла

			Read(file_input);
		}

		if (command == "write"){
			string file_input;
			string file_output;

			cout << "Input data: ";	cin >> file_input; // Даныне для ввода в фаил
			cout << "Input file adres for output data: ";	cin >> file_output; // адрес исходящего файла
			
			WriteInFile(file_input, file_output);
		}


		if (command == "help") {
			cout << "Snake-web version 1.2" << endl;
		}

		if (command == "read") {
			string file_input;
			string file_out;
			string standart_lang;
			cout << "Input file adres for input data: ";	cin >> file_input; // ввод даных для функции SnakeWeb() 
			cout << "Input file adres for out data: ";	cin >> file_out; // ввод даных для функции SnakeWeb() 
			cout << "Input file adres for out data: ";	cin >> standart_lang; // ввод специфекации для Snake-Web

			if (standart_lang == "snake-web") {
				SnakeWeb(file_input, file_out);
				log("Standart Using is: " + standart_lang);
			}

			else {
				log("Error, standart " + standart_lang + " not in Intorpritator!");
			}

		}

		if (command == "quit") {// комманда выхода из главного цикла!
			return 0;
		}

	}
	return 0;
}