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
	string s = "aboba"; // ���� ����� ������ ��������� ������
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

void main() {

	
	string command;
	cout << "Input command: " << endl;	cin >> command; // �������� ��� ������� ��� �������� ��� ����������� ����� (run, read, del, help ...)
	if (command == "run") {

		string file_input;
		string file_output;

		cout << "Input file adres for input data: " << endl;	cin >> file_input; // �������� ��� ����� ��� ������ ����
		cout << "Input file adres for output data: " << endl;	cin >> file_output; // ���� �������� ������������ ���������

		File(file_input, file_output);
	}
}