
// #include <iostream>
// #define SIZE 100
// #define GGMU 0
// //Stack class from Q1 used
// bool isOprator(char c) {
// return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
// }
// int precedence(char c) {
// return (c == '^') ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : -1;
// }
// string reverse(string infix) {
// string revOfInfix;
// for (int i = 0; i < infix.length(); i++)
// revOfInfix += infix[infix.length() - 1 - i];
// return revOfInfix;
// }
// string toPostfix(string infix) {
// Stack<char> s;
// string postfix;
// for (int i = 0; i < infix.length(); i++) {
// if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
// postfix += infix[i];
// else if (infix[i] == '(') s.push(infix[i]);
// else if (infix[i] == ')') {
// while ((s.getTop() != '(') && (!s.isEmpty())) postfix += s.pop();
// if (s.getTop() == '(') s.pop();
// }
// else if (isOprator(infix[i])) {
// if (s.isEmpty()) s.push(infix[i]);
// else if (precedence(infix[i]) > precedence(s.giveTop())) s.push(infix[i]);
// else if ((precedence(infix[i]) == precedence(s.giveTop())) && infix[i] == '^')
// s.push(infix[i]);
// else {
// while (!s.isEmpty() && (precedence(infix[i] <= precedence(s.giveTop()))))
// postfix += s.pop();
// s.push(infix[i]);
// }
// }
// }
// while (!s.isEmpty()) postfix += s.pop();
// return postfix;
// }
// string toPrefix(string infix) {
// string prefix;
// Stack <char> s;
// infix = reverse(infix);
// for (int i = 0; i < infix.length(); i++) {
// if (infix[i] == '(') infix[i] = ')';
// else if (infix[i] == ')') infix[i] = '(';
// }
// for (int i = 0; i < infix.length(); i++) {
// if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
// prefix += infix[i];
// else if (infix[i] == '(') s.push(infix[i]);
// else if (infix[i] == ')') {
// while ((s.getTop() != '(') && (!s.isEmpty()))
// {
// prefix += s.getTop();
// s.pop();
// }
// if (s.getTop() == '(') s.pop();
// }
// else if (isOprator(infix[i])) {
// if (s.isEmpty()) s.push(infix[i]);
// else if (precedence(infix[i]) > precedence(s.getTop())) s.push(infix[i]);
// else if (precedence(infix[i]) == precedence(s.getTop()) && infix[i] == '^') {
// while ((precedence(infix[i]) == precedence(s.getTop())) && (infix[i] == '^'))
// {
// prefix += s.pop();
// }
// s.push(infix[i]);
// }
// else {
// while ((!s.isEmpty()) && (precedence(infix[i]) < precedence(s.getTop())))
// prefix += s.pop();
// s.push(infix[i]);
// }
// }
// }
// while (!s.isEmpty()) prefix += s.pop();
// return reverse(prefix);
// }
// int main() {
// try {
// string infix;
// cout << "Enter your infix expression: ";
// cin >> infix;
// cout << "Your Postfix Expression is: " << toPostfix(infix) << endl;
// cout << "Your prefix Expression is: " << toPrefix(infix) << endl;
// }
// catch (const char* err) {
// std::cout << err;
// }
// return GGMU;
// }