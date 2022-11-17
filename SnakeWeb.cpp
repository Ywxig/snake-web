#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Helper.h"
#include "markdown.h"
#include "Tasker.h"

class Matrix {

public:
	
	vector<string> matrix_str_names_var;
	const string file_matrix = "matrix.mx";
	

public:
	void addMatrix(string data) {
		AddInFile(file_matrix,"\n" + data);
	}

public:
	string getElement(int index_str, int index_block, string split_teg=",") {

		vector<string> matrix_str = split(Read(file_matrix), "\n");

		for (int i = 0; i < matrix_str.size(); i++) {
			if (i == index_str) {
				vector<string> str_in_matrix = split(matrix_str[index_str], split_teg);
				for (int q = 0; q < str_in_matrix.size(); q++) {
					if (q == index_block) {
						return str_in_matrix[index_block];
					}
				}
			}
		}
	}

public:

	void garbage_collector() {
		WriteInFile(file_matrix, "0,0,0");
	}

};

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

void add_in_sirealize(string file_for_add, string content) {
	vector<string> zero_string_content = split(Read(file_for_add), "::");
	if (zero_string_content.size() > 1) {
		AddInFile(file_for_add, "bd::" + content);
	}
	else {
		cout << "Sory, add_in_sirealize return error" << endl;
	}
}

int scoreCss = 0;
int scoreVar = 0;
int scoreMD = 0;

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
				scoreCss++;
				if (scoreCss > 10) { 
					give(1);
				}

				else {
					give(0);
				}

			}

			if (Word[0] == "cls") {
				WriteInFile(file_out, "");
			}

			if (Word[0] == "tag") {
				string teg_style = "\n<" + Word[1] + " " + "id = \"" + Word[2] + "\">" + "</" + Word[1] + ">";// создание тега и привезание его к id
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

			if (Word[0] == "var") {
				scoreVar++;
				give(3);
				if (Word[1] == "color") {
					Matrix matrix;
					

					if (Word[2] != "") {
						matrix.addMatrix(Word[2]);
						cout << "RGB var is crat!";
					}

					else {
						matrix.addMatrix("0, 0, 0");
					}
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
					string id = "\n}";
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

					if (Word[2] == "js") {
						AddInFile(file_out, "\n<script>");
					}

					if (Word[2] == "btn-top") {
						give(4);
						AddInFile(file_out, "\n<div class=\"button-palce-top\">");
					}

				}

				if (Word[1] == "close") {
					if (Word[2] == "doc") {
						AddInFile(file_out, "\n</body>\n</html> ");
					}

					if (Word[2] == "style") {
						AddInFile(file_out, "\n</style>\n<body class=\"main\">");
					}

					if (Word[2] == "js") {
						AddInFile(file_out, "\n</script>");
					}

					if (Word[2] == "btn") {
						AddInFile(file_out, "\n</div>");
					}

				}
			}


			if (Word[0]=="link") {
				AddInFile(file_out, "\n<p class=\"Link-Text\"><a class=\"Link\" href=\"" + Word[1] + "\">  " + Word[2] + "</a></p>");
			}

			if (Word[0] == "canvas") {
				AddInFile(file_out, "\n<canvas wight=\"" + Word[1] + "\" height=\"" + Word[2] + "\"> </canvas>");
			}

			if (Word[0] == "md") {
				scoreMD++;
				give(8);
				if (scoreMD > 3) { give(9); }
				if (scoreMD > 6) { give(10); }
				if (scoreMD > 12) { give(11); }
				get_text_in_fail_for_markdown(Word[1], file_out);
			}

			if (Word[0] == "button") {
				if (Word[1] == "def") {
					AddInFile(file_out, "\n<button class=\"button-defolt\">" + Word[2] + "</botton>");
				}

				if (Word[1] == "custom") {
					AddInFile(file_out, "\n<button class=\""+ Word[2]+"\">" + Word[3] + "</botton>\n");
				}

			}

			if ( Word[0] == "tr") {
				if ( Word[1] == "oopen") {
					AddInFile(file_out, "\n<table>\n");
				}

				if ( Word[1] == "close") {
					AddInFile(file_out, "\n</table>\n");
				}
			}

			if ( Word[0] == "td") {
				int index_col = stoi(Word[1]);
				if (index_col > 50) { give(6); }
				vector<string> col;
					for (int i = 0; i < index_col; i++) {
						AddInFile(file_out, "<tr>\n<td> ... </td></tr>\n");
					}
			}


			if (Word[0] == "use") {
				if (Word[1] == "css") {
					give(2);
					int index_var = 1;
					vector<string> content_file_css = split(Read(Word[2]));
					for (int i = 0; i < content_file_css.size(); i++) {

						if (content_file_css[i] == "Var") {

							Matrix matrix;
							if ((stoi(matrix.getElement(index_var, 0)) < 255) && (stoi(matrix.getElement(index_var, 0)) > 0)) {
								content_file_css.at(i) = matrix.getElement(index_var, 0) + "," + matrix.getElement(index_var, 1) + "," + matrix.getElement(index_var, 2);
								index_var++;
							}
							
						}
					}

					for (int q = 0; q < content_file_css.size(); q++) {
						AddInFile(file_out, " " + content_file_css[q]);
					}

				}

				if (Word[1] == "js") {
					string content = Read(Word[2]);
					AddInFile(file_out, "\n" + content + "\n");
					give(12);
				}

				if (Word[1] == "form") {
					Forms Form;
					Form = Forms();
					AddInFile(file_out, Form.GetForm(Word[2], stoi(Word[3])));
					give(7);
				}
			}
			if (Word[0] == "color") {
				if ((Word[1] == "bg") || (Word[1] == "background")) {
					if (Word[2] == "var") {
						Matrix matrix;

						if (stoi(matrix.getElement(stoi(Word[3]), 0)) <= 0) { give(5); }

						AddInFile(file_out, "\nbackground-color: rgb(" + matrix.getElement(stoi(Word[3]), 0) + ", " + matrix.getElement(stoi(Word[3]), 1) + ", " + matrix.getElement(stoi(Word[3]), 2) + ");\n");

					} else {
						// Работа с цветом
						Matrix matrix;

						vector<string> str_color_vector = split(Word[2], ",");
						vector<string> color_fin_vector;

						for (int i = 0; i < str_color_vector.size(); i++) {
							if (stoi(str_color_vector[i]) > 255) {
								int tail_color_value = 255 - stoi(str_color_vector[i]);
								int fin_color = stoi(str_color_vector[i]) - tail_color_value;
								color_fin_vector.push_back(int_to_str(fin_color));
							}

							else {
								string fin_color = str_color_vector[i];
								color_fin_vector.push_back(fin_color);
							}
						}
						AddInFile(file_out, "\nbackground-color: rgb(" + color_fin_vector[0] + ", " + color_fin_vector[1] + ", " + color_fin_vector[2] + ");\n");
						give(13);
					}

					
				}

				if ((Word[1] == "fg") || (Word[1] == "forgeground")) {
					// Работа с цветом
					vector<string> str_color_vector = split(Word[2], ",");
					vector<string> color_fin_vector;

					for (int i = 0; i < str_color_vector.size(); i++) {
						if (stoi(str_color_vector[i]) > 255) {
							int tail_color_value = 255 - stoi(str_color_vector[i]);
							int fin_color = stoi(str_color_vector[i]) - tail_color_value;
							color_fin_vector.push_back(int_to_str(fin_color));
						}

						else {
							string fin_color = str_color_vector[i];
							color_fin_vector.push_back(fin_color);
						}
					}

					AddInFile(file_out, "\ncolor: rgb(" + color_fin_vector[0] + ", " + color_fin_vector[1] + ", " + color_fin_vector[2] + ");\n");
					give(14);

				}
			}

			i++;
		}

	}
	cout << Read("print"); // чьтение файла    } Небольшой велосипед написанный для чьтения файла 
	WriteInFile("print", ""); // очистка файла просто вводим пустую строку
	Matrix matrix;
	matrix.garbage_collector(); // очищяем мусор, проше говоря уничьтожаем всё в mstrix.mx
	return 0;
}