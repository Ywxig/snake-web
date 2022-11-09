
#include <iostream>
#include <fstream >
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, string sep = " ") {// Функция для разбивания строки на слова или по другому определителю
	int idx = 0, lidx = 0,// обявление индексов
		sep_len = sep.size();// порлучение длины строки
	vector<string> ret_list; // обявление вектора для записи

	while (true) { // бесконечьный цикол
		lidx = str.find(sep, idx);// нахождение индекса в строке

		ret_list.push_back(str.substr(idx, lidx - idx));

		if (lidx == string::npos) // проверка позиции
			break;

		idx = lidx + sep.size(); // пресвоение нового индекса
	}

	return ret_list;// вернуть результат разделения
}


	void AddInFile(string file_for_input, string string_for_input) {// обявления метода WriteInFile
		ofstream out(file_for_input, std::ios::app);// создание потока для записи
		out << string_for_input;// запись результата
		out.close();// закрытие потока
	}

	void WriteInFile(string file_for_input, string string_for_input) {// обявления метода WriteInFile
		ofstream out(file_for_input);// создание потока для записи
		out << string_for_input;// запись результата
		out.close();// закрытие потока
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

		std::ifstream in(file_to_read); // окрываем файл для чтения
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
		in.close();     // закрываем файл
		return join(return_string);
	}

	vector<string> SplitOnFild(string content) {// функция разделения исходного текста на поля или рабочии области
		vector<string> Filds = split(content, "<cut>");// само разделение по тегу <cut>

		return Filds;// возвращяем масив с полями!
	}

	void log(string log_text) {// любой лог проверяется и выводит информацию

		std::string line;

		std::ifstream in("logs.txt"); // окрываем файл для чтения
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

	void log_sleep(string log_text){AddInFile("logs.txt", "\n" + log_text);} // Лог сохраняется без вывода и проверок

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