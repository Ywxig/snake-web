#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Helper.h"

using namespace std;

// rule is SWS
//ѕроверка на использование переменных в коде
float sum_proc_word(string set) {
	int score = 0;
	vector<string> str = split(set, "\n");
	for (int i = 0; i < str.size(); i++) {
		vector<string> words = split(str[i], "::");
		for (int q = 0; q < words.size(); q++) {
			if (words[q] == "var") {
				score++;
			}
		}
	}

	return (score / set.size()) * 100;

}