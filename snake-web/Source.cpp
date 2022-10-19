#include <iostream>
#include <fstream  >
#include <string> // подключаем строки

using namespace std;

// Полную документацию проекта можно найи в файле ReadMe или в about.html

void r(string file_input, string file_output) {
	ifstream file; // создаем объект класса ifstream
	file.open(file_input); // открываем файл
	// Считка слов из файла
	int n = 0;
	float a;

	fstream F;
	string str;
	while (!F.eof())
	{
		//чтение очередного значения из потока F в переменную a
		F >> a;
		//вывод значения переменной a на экран
		cout << a << "\t";
		//увеличение количества считанных чисел
		n++;
	}
	//закрытие потока
	F.close();
	//вовод на экран количества считанных чисел
	cout << "n = " << "Gata" << endl;
}

int File(string file_input, string file_output) {
	string s = "test-message"; // сюда будем класть считанные строки
	ifstream file; // создаем объект класса ifstream
	file.open(file_input); // открываем файл
	/* если надо несколько считать
	while(getline(file, s)){ // пока не достигнут конец файла класть очередную строку в переменную (s)
		cout << s << endl; // выводим на экран
	}*/
	// если просто считывание число одно число в строке
	getline(file, s);
	int n;
	n = atoi(s.c_str());//число
	cout << s;
	file.close(); // обязательно закрываем файл что бы не повредить его

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
		// Используя перегрузку метода мы реолизуем ветвистость среды!
		string command;
		cout << "\nInput command: " << endl;	cin >> command; // Получяем имя функции или операции для исполняемой среды (run, read, del, help ...)
		if (command == "run") {

			string file_input;
			string file_output;

			cout << "Input file adres for input data: ";	cin >> file_input; // Получяем имя файла для чтения кода
			cout << "Input file adres for output data: ";	cin >> file_output; // Куда записать получивщийся результат

			File(file_input, file_output);
		}

		if (command == "write") {

			string file_input;
			string file_output;

			cout << "Input data: ";	cin >> file_input; // Получяем текст для записи 
			cout << "Input file adres for output data: ";	cin >> file_output; // Куда записать получивщийся результат

			Write(file_input, file_output);
		}


		if (command == "help") {
			cout << "Snake-web version 1.1" << endl;
		}

		if (command == "read") {

			string file_input;

			cout << "Input data: ";	cin >> file_input; // Получяем текст для записи 

			Und(file_input);
		}

	}
	return 0;
}
