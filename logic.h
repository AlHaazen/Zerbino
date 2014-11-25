#ifndef LOGIC_H
#define LOGIC_H
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

//J - НОМЕР У РЯДКУ

using namespace std;



vector<char> toVec(string s);

vector<char> transform(string num, int from, int to);

char toChar(int num);

int toInt(char c);

int preventOGul(string num, int from, int to);

string multipl(string s1,string s2);

void fig(vector<vector<int> > *matrix);

vector<char> toNegBin(string s);

string divide(string A, string B, int accuracy);

void addB(vector<vector<int> > *matrixAB, string B);
void figN(vector<vector<int> > *matrixAB);


#endif // LOGIC_H
/* Почистити Тетріс від Дебаг-виводу
 * Об'єднати усі варіанти в один великий ІФ
 * Загнати дію над комірками у загальний випадок. Тобто якщо вихід - додати стовпець, якщо не вихід до закинути
 *
 *
 */
