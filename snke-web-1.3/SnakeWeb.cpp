#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Helper.h"

//
//���� �������������� � ����� ������������ ����� � CSS �������
//

class Forms {// ����� ��� ������ � ������

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


int SnakeWeb(string file_input, string file_out) {// ������� � ����� ������. ��� ������� ��� ������ ����� 

	std::string line;

	std::ifstream in(file_input); // �������� ���� ��� ������
	if (in.is_open())
	{
		while (getline(in, line))
		{
			vector<string> content = split(line, "\n");
			int i = 0;
			string word = content[i];
			vector<string> Word = split(word, "::");

			// ���������� �������� �������� ��������� ��� ������� ������ �� ����� � ��������
			if (Word[0] == "css") {// ��������, ���� ������ ����� == �������� �������� ��;
				// �� ��� ������ ������� ����������� �� ��������� �����
				AddInFile(file_out, "\n" + Word[1] + "\n");
			}

			if (Word[0] == "tag") {
				string teg_style = "<" + Word[1] + "> " + "id = \"" + Word[2] + "\"" + "</" + Word[1] + ">";// �������� ���� � ���������� ��� � id
				AddInFile(file_out, teg_style);// ���� � ����
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

			if (Word[0] == "use") {
				if (Word[1] == "css") {
					string content_file_css = Read(Word[2]);
					AddInFile(file_out, content_file_css);
				}

				if (Word[1] == "form") {
					Forms Form;
					Form = Forms();
					AddInFile(file_out, Form.GetForm(Word[2], stoi(Word[3])));
				}
			}
			if (Word[0] == "color") {
				if ((Word[1] == "bg") || (Word[1] == "background")) {
					// ������ � ������
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

					AddInFile(file_out, "\nbackground-color: rgb(" + color_fin_vector[0] + ", " + color_fin_vector[1] + ", " + color_fin_vector[2] + ");");
				}

				if ((Word[1] == "fg") || (Word[1] == "forgeground")) {
					// ������ � ������
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

					AddInFile(file_out, "\ncolor: rgb(" + color_fin_vector[0] + ", " + color_fin_vector[1] + ", " + color_fin_vector[2] + ");");

				}
			}

			i++;
		}

	}
	cout << Read("print"); // ������� �����    } ��������� ��������� ���������� ��� ������� ����� 
	WriteInFile("print", ""); // ������� ����� ������ ������ ������ ������
	return 0;
}