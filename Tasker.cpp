#include <iostream>
#include <fstream >
#include <string>
#include <sstream>
#include <vector>
#include "Helper.h"

using namespace std;

class achievement {

private:
	string user_file = "user";
	vector<string> none_list = {"none", "none", "none", "img/none.png"};
public:
	string get_name( string name ) {
		vector<string> content = split(Read(user_file), "\n");
		for (int i = 0; i < content.size(); i++) {
			vector<string>	content_list = split(content[i], "::");
			if (content_list[0] == "achievement") {
				if (content_list[1] == name) {
					return content_list[1];
				}
				else {
					return "None";
				}
			}
		}
	}

public:
	string get_description(string name) {
		vector<string> content = split(Read(user_file), "\n");
		for (int i = 0; i < content.size(); i++) {
			vector<string>	content_list = split(content[i], "::");
			if (content_list[0] == "achievement") {
				if (content_list[1] == name) {
					return content_list[2];
				}
				else {
					return "None";
				}
			}
		}
	}

public:
	string get_description_long(string name) {
		vector<string> content = split(Read(user_file), "\n");
		for (int i = 0; i < content.size(); i++) {
			vector<string>	content_list = split(content[i], "::");
			if (content_list[0] == "achievement") {
				if (content_list[1] == name) {
					if (content_list[3] == "none") {
						return content_list[2];
					}
					else {
						return content_list[3];
					}
				}
				else {
					return "None";
				}
			}
		}
	}

public:
	string get_img(string name) {
		vector<string> content = split(Read(user_file), "\n");
		for (int i = 0; i < content.size(); i++) {
			vector<string>	content_list = split(content[i], "::");
			if (content_list[0] == "achievement") {
				if (content_list[1] == name) {
					if (content_list[3] == "none") {
						return "img/none.png";
					}
					else {
						return content_list[4];
					}
				}
				else {
					return "img/none.png";
				}
			}
		}
	}

public:
	string get(int index_str, int index_col) {
		vector<string> content = split(Read(user_file), "\n");
		for (int i = 0; i < content.size(); i++) {

			vector<string>	content_list = split(content[i], "::");

			if (content_list[0] == "achievement") {
				if ((i == index_str) && (index_col <= content_list.size())) {
					return content_list[index_col];
				}
				else {
					return "None";
				}
			}
		}
	}

public:
	vector<string> find(string name) {
		vector<string> content = split(Read(user_file), "\n");
		for (int i = 0; i < content.size(); i++) {
			vector<string>	content_list = split(content[i], "::");
			if (content_list[0] == "achievement") {
				if (content_list[1] == name) {
					return content_list;
				}
				else {
					return none_list;
				}
			}
		}
	}

};

