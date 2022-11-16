// ������ � �������� �������������. ADD_H � ��� ������������ ���������� ��� (������ ������������ ��� ������������� �����)
#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <string>
using namespace std;
#pragma once

// � ���� ����� ������� ��������� ������� ��� ������ ������ ��������������

vector<string> split(string str, string sep = " "); // �������� ������� split() (�� ��������� ����� � ������� � �����!)

void WriteInFile(string file_for_input, string string_for_input); // �������� ������� ���������� � ���� ������
string Read(string file_to_read);// ������� ������� �����
vector<string> SplitOnFild(string content); // �������� ������� ��� ���������� �� ���� �������� �����
void AddInFile(string file_for_input, string string_for_input); // ������� ���������� �����

string join(std::vector<string> vec);

void log(string log_text);// ���������� ������ �����
void printv(vector<string> arr);
string int_to_str(int num);// ������� ��� �������� �� int � str

template<typename T>
string toString(T val); // ������� �� ����� � ������
#endif