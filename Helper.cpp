
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

	string join(std::vector<string> vec) {
		

		std::ostringstream oss;
		if (!vec.empty()) {
			std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<string>(oss, "\n"));
			oss << vec.back();
		}
		return oss.str();
	}

	string Read(string file_to_read) {
		std::string line;
		vector<string> return_string;

		std::ifstream in(file_to_read); // �������� ���� ��� ������
		if (in.is_open())
		{
			while (getline(in, line))
			{
				return_string.push_back( line );
			}
		}
		else {
			return_string.push_back( "" );
		}
		in.close();     // ��������� ����
		return join(return_string);
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

	string int_to_str(int num) {
		std::ostringstream ost;
		ost << num;
		return ost.str();
	}

	
	void printv(vector<string> arr) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
	}


	class Vec {


	public:
		vector<int> Creat2D(int VecX, int VecY) {
			vector<int> Fin_Vector;
			Fin_Vector.push_back(VecX);
			Fin_Vector.push_back(VecY);
			return Fin_Vector;
		}

	public:
		vector<int> Creat3D(int VecX, int VecY) {
			vector<int> Fin_Vector;
			Fin_Vector.push_back(VecX);
			Fin_Vector.push_back(VecY);
			return Fin_Vector;
		}



	};

string GetFunctionInJsScript(string file_input, string file_out, int index) {
	
	vector<string> content_list = split(Read(file_input), "//cut");
	return content_list[index];

}