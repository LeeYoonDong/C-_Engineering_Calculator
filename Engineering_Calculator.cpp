#include "pch.h"
#include <iostream>
#include <iostream>
#include <string>
#include "math.h"
using namespace std;

const int stackSize = 10; 
const float PI = 3.1415925;

class CInterface {

private:
unsigned int select;

public:
CInterface() {};
~CInterface() {};
void Manual();
int getSelect() { return select; } 
void setSelect(int tmp) { select = tmp }
};



void CInterface::Manual() {

cout << "" << endl;
cout << "" << endl;
cout << " --------------- Calculator Manual ----------------" << endl;
cout << "|                                                  |" << endl;
cout << "|        -----Trigonometric Function-----          |" << endl;
cout << "|       |                                |         |" << endl;
cout << "|       |       sin : s (ex: s45)        |         |" << endl;
cout << "|       |                                |         |" << endl;
cout << "|       |       cos : c (ex: c45)        |         |" << endl;
cout << "|       |                                |         |" << endl;
cout << "|       |       tan : t (ex: t45)        |         |" << endl;
cout << "|       |                                |         |" << endl;
cout << "|        --------------------------------          |" << endl;
cout << "|                                                  |" << endl;
cout << "|       ---Inverse Trigonometric Funtion---        |" << endl;
cout << "|      |                                  |        |" << endl;
cout << "|      |        asin : S (ex: S45)        |        |" << endl;
cout << "|      |                                  |        |" << endl;
cout << "|      |        acos : C (ex: C45)        |        |" << endl;
cout << "|      |                                  |        |" << endl;
cout << "|      |        atan : T (ex: T45)        |        |" << endl;
cout << "|      |                                  |        |" << endl;
cout << "|       -----------------------------------        |" << endl;
cout << "|                                                  |" << endl;
cout << "|        -------------Log & √------------         |" << endl;
cout << "|       |                                 |        |" << endl;
cout << "|       |         Log : l (ex: l2)        |        |" << endl;
cout << "|       |                                 |        |" << endl;
cout << "|       |         √: L (ex: L4)         |        |" << endl;
cout << "|       |                                 |        |" << endl;
cout << "|        ---------------------------------         |" << endl;
cout << "|                                                  |" << endl;
cout << "|        -----------Converter-------------         |" << endl;
cout << "|       |                                 |        |" << endl;
cout << "|       |          Binary Number          |        |" << endl;
cout << "|       |                                 |        |" << endl;
cout << "|       |          Octal Number           |        |" << endl;
cout << "|       |                                 |        |" << endl;
cout << "|       |              Hexin              |        |" << endl;
cout << "|       |                                 |        |" << endl;
cout << "|        ---------------------------------         |" << endl;
cout << "|                                                  |" << endl;
cout << " -------------------------------------------------- \n" << endl;

do {
select = 0;
cout << "  기능선택\n" << endl;
cout << " 1 : 수식계산\n 2 : 진수변환\n 3 : 종료\n" << endl;
cin >> select;

} while (select != 1 && select != 2 && select != 3);

}



class CCharStack {

private:
char stack[stackSize];
int index;

public:
CCharStack() { index = -1; }
~CCharStack() {}
void push(char ch) { stack[++index] = ch }
char pop() { return stack[index--]; }
char getElement() { return stack[index]; }
int getIndex() { return index; }

};

class CIntStack {

private:
float stack[stackSize];
int index;

public:
CIntStack() { index = -1; }
~CIntStack() {}
void push(float num) { stack[++index] = num }
float pop() { return stack[index--]; }
};


class CCalc {
private:
int result;
int num, antilo;
char reFormula[100];
string formula;
CCharStack chSt;
CIntStack inSt;
int Priority(char);
void Rearrange();
float CalcSqrt(float);
float CalcLog(float);
float CalcTri(char, float);
void CalcFormula();
void CalcAntilogarithm();

public:
CCalc() {};
~CCalc() {};
void setFormula(string str) { formula = str Rearrange(); } 
void setNum(int tmp) { num = tmp } 
void setAntilo(int tmp) { antilo = tmp CalcAntilogarithm(); } 
};


int CCalc::Priority(char ch) {
if (ch == 's' || ch == 'S' || ch == 'c' || ch == 'C' || ch == 't' || ch == 'T' ||
ch == 'l' || ch == 'L')
return 4;
if (ch == '*' || ch == '/')
return 3;
if (ch == '+' || ch == '-')
return 2;
return 1;
}


void CCalc::Rearrange()
{
string temp(formula); 

int i = 0, j = 0;
char ch;

while (temp[i] != '\0') {
if (temp[i] == ' ') 
i++;
else if (isdigit(temp[i]) || temp[i] == '.') { 
while (isdigit(temp[i]) || temp[i] == '.')
reFormula[j++] = temp[i++]
reFormula[j++] = ' ' 
}
else if (temp[i] == '(') { 
chSt.push(temp[i]);
i++;
}
else if (temp[i] == ')') { 
ch = chSt.pop();
while (ch != '(') { 
reFormula[j++] = ch; 
reFormula[j++] = ' ' 
ch = chSt.pop();
}
i++;
}
else { 
if (chSt.getIndex() == -1) 
chSt.push(temp[i++]);
else {

while (!(chSt.getIndex() == -1) && (Priority(chSt.getElement()) >= Priority(temp[i]))) {
ch = chSt.pop();
reFormula[j++] = ch;
reFormula[j++] = ' '
}
chSt.push(temp[i]);
i++;
}
}
}           

while (!(chSt.getIndex() == -1)) { 
ch = chSt.pop();
reFormula[j++] = ch;
reFormula[j++] = ' '
}
reFormula[j] = '\0'
cout << "reFormula : " << reFormula << endl;
CalcFormula();
}



void CCalc::CalcFormula()
{
int i = 0, k;
float num, result, num1, num2;
char ch;
char token[20];

while (reFormula[i] != '\0') {
if (isdigit(reFormula[i]) || reFormula[i] == '.') {
k = 0;
while (isdigit(reFormula[i]) || reFormula[i] == '.')
token[k++] = reFormula[i++]; 
token[k] = '\0'
num = atof(token);
inSt.push(num); 
}
else if (reFormula[i] == ' ')
i++;

else if (reFormula[i] == 's' || reFormula[i] == 'S' || reFormula[i] == 'c' || reFormula[i] == 'C' || reFormula[i] == 't' || reFormula[i] == 'T') {
result = CalcTri(reFormula[i], inSt.pop());
inSt.push(result);
i++;
}
else if (reFormula[i] == 'l') {
result = CalcLog(inSt.pop());
inSt.push(result);
i++;
}
else if (reFormula[i] == 'L') { 
result = CalcSqrt(inSt.pop());
inSt.push(result);
i++;
}
else { 
ch = reFormula[i++];
num1 = inSt.pop(); 
num2 = inSt.pop();
if (ch == '+')
result = num2 + num1;
else if (ch == '-')
result = num2 - num1;
else if (ch == '*')
result = num2 * num1;
else if (ch == '/')
result = num2 / num1;
inSt.push(result);
}
i++;
}           
printf("Answer : %0.12f\n", inSt.pop());
}


float CCalc::CalcSqrt(float tmp) {
return sqrt(tmp);
}


float CCalc::CalcLog(float tmp) {
return log10(tmp);
}


float CCalc::CalcTri(char ch, float tmp) {
switch (ch) {
case 's': 
return sin(PI*tmp / 180);
case 'c':
return cos(PI*tmp / 180);
case 't': 
return tan(PI*tmp / 180);
case 'S':
return asin(PI*tmp / 180);
case 'C':
return acos(PI*tmp / 180);
case 'T': 
return atan(PI*tmp / 180);
}
return 1;
}


void CCalc::CalcAntilogarithm() {
int bin[16];
int i, count = 0;

switch (antilo) {
case 2:
while (num > 0) {
bin[count++] = num % 2;
num /= 2;
}
bin[count] = '\0'
cout << "answer: "
for (i = 0; i < count; i++) {
cout << bin[i];
}
cout << endl;
break
case 8: 
printf("answer: %o\n", num);
break
case 16: 
printf("answer: %x\n", num);
break
default:
cout << "Error!" << endl;
exit(0);
}
}


void main()
{
string str;
int num = 0;

CInterface cInterface;
CCalc cCalc;

cInterface.Manual();

switch (cInterface.getSelect()) {
case 1:
cout << "  수식입력: "
cin >> str;
cCalc.setFormula(str);
break
case 2:
cout << "  숫자입력: "
cin >> num;
cCalc.setNum(num);
cout << "  진수입력(10진수-> 2,8,16진수): "
cin >> num;
cCalc.setAntilo(num);
break
case 3:
cout << "\n -- 종료됩니다--" << endl;
exit(3);
}
}