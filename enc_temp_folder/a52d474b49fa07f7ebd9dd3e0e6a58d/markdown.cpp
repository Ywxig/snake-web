#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "helper.h"

using namespace std;

vector<string> get_text_in_fail_for_markdown(string file_input) {

	vector<string> Content = split(Read(file_input), "\n");
	
	for (int i = 0; i < Content.size(); i++) {
		vector<string> Content_str = split(Content[i]);
		int score = 0;
		for (int q = 0; q < Content_str.size(); q++) {
			if ((Content_str[q] == "#") && (score == 0)) {
				Content_str.at(q) = "<h1>";
				score++;
			}

			if ((Content_str[q] == "#") && (score != 0)) {
				Content_str.at(q) = "</h1>";
				score = 0;
			}
		}
		cout << join(Content_str);
		vector<string> vec;
		return vec;
	}
}