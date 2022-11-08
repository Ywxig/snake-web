#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "helper.h"

using namespace std;

void get_text_in_fail_for_markdown(string file_input, string file_out) {

	vector<string> Content = split(Read(file_input), "\n");
	
	for (int i = 0; i < Content.size(); i++) {
		vector<string> Content_str = split(Content[i]);
		int score = 0;
		for (int q = 0; q < Content_str.size(); q++) {
			if ((Content_str[q] == "#") && (score == 0)) {
				Content_str.at(q) = "<h1 class=\"Header\">";
				score++;
			}

			if (Content_str[q] == "/img") {
				Content_str.at(q) = "<img src=\"" + Content_str[q + 1] + "\">";
			}

			if ((Content_str[q] == "#") && (score != 0)) {
				Content_str.at(q) = "</h1>";
				score = 0;
			}

			if ((Content_str[q] == "##") && (score == 0)) {
				Content_str.at(q) = "<h2 class=\"Header\">";
				score++;
			}

			if ((Content_str[q] == "##") && (score != 0)) {
				Content_str.at(q) = "</h2>";
				score = 0;
			}


			if ((Content_str[q] == "###") && (score == 0)) {
				Content_str.at(q) = "<h2 class=\"Header\">";
				score++;
			}

			if ((Content_str[q] == "###") && (score != 0)) {
				Content_str.at(q) = "</h3>";
				score = 0;
			}

			if ((Content_str[q] == "[")) {
				Content_str.at(q) = "<i class=\"Italic\">";
				score++;
			}

			if ((Content_str[q] == "]")) {
				Content_str.at(q) = "</i>";
				score = 0;
			}


			if ((Content_str[q] == "*") && (score == 0)) {
				Content_str.at(q) = "<b class=\"high-light\">";
				score++;
			}

			if ((Content_str[q] == "*") && (score != 0)) {
				Content_str.at(q) = "</b>";
				score = 0;
			}

			if ((Content_str[q] == "(note")) {
				Content_str.at(q) = "<div class=\"note\">";
				score++;
			}


			if ((Content_str[q] == "(block")) {
				Content_str.at(q) = "<div class=\"Block\">";
			}

			if ((Content_str[q] == "(corect")) {
				Content_str.at(q) = "<div id=\"corect\">";
			}

			if ((Content_str[q] == "(nocorect")) {
				Content_str.at(q) = "<div id=\"nocorect\">";
			}

			if ((Content_str[q] == "(")) {
				Content_str.at(q) = "<div class=\"text\">";
				score++;
			}

			if ((Content_str[q] == ")")) {
				Content_str.at(q) = "</div>\n<br>";
				score = 0;
			}

			if ((Content_str[q] == "|n") || (Content_str[q] == "|")) {
				Content_str.at(q) = "\n<br>";
				score = 0;
			}

		}
		
		for (int e = 0; e < Content_str.size(); e++) {
			AddInFile(file_out, " " + Content_str[e]);
		}
	}
}