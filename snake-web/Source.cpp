#include <iostream>
#include <fstream  >
#include <string> // ���������� ������

using namespace std;

// ������ ������������ ������� ����� ���� � ����� ReadMe ��� � about.html

void r(string file_input, string file_output) {
	ifstream file; // ������� ������ ������ ifstream
	file.open(file_input); // ��������� ����
	// ������ ���� �� �����
	int n = 0;
	float a;

	fstream F;
	string str;
	while (!F.eof())
	{
		//������ ���������� �������� �� ������ F � ���������� a
		F >> a;
		//����� �������� ���������� a �� �����
		cout << a << "\t";
		//���������� ���������� ��������� �����
		n++;
	}
	//�������� ������
	F.close();
	//����� �� ����� ���������� ��������� �����
	cout << "n = " << "Gata" << endl;
}

int File(string file_input, string file_output) {
	string s = "test-message"; // ���� ����� ������ ��������� ������
	ifstream file; // ������� ������ ������ ifstream
	file.open(file_input); // ��������� ����
	/* ���� ���� ��������� �������
	while(getline(file, s)){ // ���� �� ��������� ����� ����� ������ ��������� ������ � ���������� (s)
		cout << s << endl; // ������� �� �����
	}*/
	// ���� ������ ���������� ����� ���� ����� � ������
	getline(file, s);
	int n;
	n = atoi(s.c_str());//�����
	cout << s;
	file.close(); // ����������� ��������� ���� ��� �� �� ��������� ���

	return 0;
}

int Write(string input, string file_output) {
	ofstream fout(file_output);
	fout << input;
	return 0;
}

int Und(string input) {
		
	while (true)
	{

	}
	
	char* chars = &input[0];
	std::cout << chars << std::endl;
	
	return 0;
}




int main() {

	while (true)
	{
		// ��������� ���������� ������ �� ��������� ����������� �����!
		string command;
		cout << "\nInput command: " << endl;	cin >> command; // �������� ��� ������� ��� �������� ��� ����������� ����� (run, read, del, help ...)
		if (command == "run") {

			string file_input;
			string file_output;

			cout << "Input file adres for input data: ";	cin >> file_input; // �������� ��� ����� ��� ������ ����
			cout << "Input file adres for output data: ";	cin >> file_output; // ���� �������� ������������ ���������

			File(file_input, file_output);
		}

		if (command == "write") {

			string file_input;
			string file_output;

			cout << "Input data: ";	cin >> file_input; // �������� ����� ��� ������ 
			cout << "Input file adres for output data: ";	cin >> file_output; // ���� �������� ������������ ���������

			Write(file_input, file_output);
		}


		if (command == "help") {
			cout << "Snake-web version 1.1" << endl;
		}

		if (command == "read") {

			string file_input;

			cout << "Input data: ";	cin >> file_input; // �������� ����� ��� ������ 

			Und(file_input);
		}

	}
	return 0;
}
