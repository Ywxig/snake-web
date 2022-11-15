// Начнем с директив препроцессора. ADD_H – это произвольное уникальное имя (обычно используется имя заголовочного файла)
#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <string>
using namespace std;
#pragma once

// в этом файле описаны прототипы функций для работы нашего инторпритатора

vector<string> split(string str, string sep = " "); // прототип функции split() (не забывайте точку с запятой в конце!)

void WriteInFile(string file_for_input, string string_for_input); // прототип функции добавления в фаил строки
string Read(string file_to_read);// функция чьтения файла
vector<string> SplitOnFild(string content); // Прототип функции для разбивания на поля исходный текст
void AddInFile(string file_for_input, string string_for_input); // Функция перезаписи файла

string join(std::vector<string> vec);

void log(string log_text);// инструмент записи логов
void printv(vector<string> arr);
string int_to_str(int num);// функция для перевода иш int в str

template<typename T>
string toString(T val); // перевод из числа в сторку
#endif