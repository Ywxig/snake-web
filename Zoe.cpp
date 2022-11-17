#include <iostream>
#include <fstream >
#include <string>
#include <sstream>
#include <vector>
#include "Helper.h"

using namespace std;

class Interview{

public:
	const string file_vacantion = "tests.txt";

public: // 0 индекс имя, 1 индекс тип, 2 индекс уровень, 3 индекс ссылка на фаил с вопросами 
	string find( string name_type, int lavel = 1  ) {
		vector<string> content = split(Read(file_vacantion), "\n");

		for (int i = 0; i < content.size(); i++) {
			vector<string> content_str = split(content[i], "::");
			if ((name_type == content_str[1]) && (lavel == stoi(content_str[2]))) { return content_str[i] + "\n"; }
		}

	}
};


class Zoe {

public:
	const string data_set = "DataSet.txt";
	const string replic_set = "Replic.txt";

public:
	void Say ( string name_replic ) {
		cout << get(replic_set, name_replic, 2);
	}

public:
	float Match_word( string Word, vector<string> data_set_list) { 
		int replaceScore = 0;
		vector<char> Word_chgaer = list(Word);
		for (int i = 0; i < data_set_list.size(); i++) {

			vector<char> data_set_list_chgaer = list(data_set_list[i]);
			for (int q = 0; q < Word_chgaer.size(); q++ ) {
				if ( line_serchCHAR(data_set_list_chgaer, Word_chgaer[q]) == true) {
					replaceScore++;
				}
			}

			return (replaceScore / data_set_list_chgaer.size()) * 100;
		}
	}

};