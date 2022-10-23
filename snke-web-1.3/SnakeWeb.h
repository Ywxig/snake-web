// Начнем с директив препроцессора. ADD_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef SNAKEWEB_H
#define SNAKEWEB_H

#include <vector>
#include <string>
using namespace std;
#pragma once

// одинокая функция для интерпритации файла
int SnakeWeb(string file_input, string file_out); // собственно сам интерпритатор!

#endif