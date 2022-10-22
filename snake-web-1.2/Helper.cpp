
#include <iostream>
#include <fstream >
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, string sep = " ") {// ������� ��� ���������� ������ �� ����� ��� �� ������� ������������
	int idx = 0, lidx = 0,// ��������� ��������
		sep_len = sep.size();// ���������� ����� ������
	vector<string> ret_list; // ��������� ������� ��� ������

	while (true) { // ������������ �����
		lidx = str.find(sep, idx);// ���������� ������� � ������

		ret_list.push_back(str.substr(idx, lidx - idx));

		if (lidx == string::npos) // �������� �������
			break;

		idx = lidx + sep.size(); // ���������� ������ �������
	}

	return ret_list;// ������� ��������� ����������
}


	void AddInFile(string file_for_input, string string_for_input) {// ��������� ������ WriteInFile
		ofstream out(file_for_input, std::ios::app);// �������� ������ ��� ������
		out << string_for_input;// ������ ����������
		out.close();// �������� ������
	}

	void WriteInFile(string file_for_input, string string_for_input) {// ��������� ������ WriteInFile
		ofstream out(file_for_input);// �������� ������ ��� ������
		out << string_for_input;// ������ ����������
		out.close();// �������� ������
	}

	string Read(string file_to_read) {
		std::string line;

		std::ifstream in(file_to_read); // �������� ���� ��� ������
		if (in.is_open())
		{
			while (getline(in, line))
			{
				return line;
			}
		}
		else {
			return "";
		}
		in.close();     // ��������� ����
	}

	vector<string> SplitOnFild(string content) {// ������� ���������� ��������� ������ �� ���� ��� ������� �������
		vector<string> Filds = split(content, "<cut>");// ���� ���������� �� ���� <cut>

		return Filds;// ���������� ����� � ������!
	}

	void log(string log_text) {// ����� ��� ����������� � ������� ����������

		std::string line;

		std::ifstream in("logs.txt"); // �������� ���� ��� ������
		if (in.is_open()) {

			if (log_text == "") {
				cout << "Log is empty" << endl;
			}

			else {
				AddInFile("logs.txt", "\n" + log_text);
			}
		}

		else {
			cout << "Logs con't write in file!" << endl;
		}
	}

	void log_sleep(string log_text){AddInFile("logs.txt", "\n" + log_text);} // ��� ����������� ��� ������ � ��������
	