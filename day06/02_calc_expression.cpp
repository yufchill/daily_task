#include <bits/stdc++.h>
using namespace std;

string expression;

int calc(int num1, int num2, char op) {
  if (op == '+') {
    return num1 + num2;
  } else if (op == '-') {
    return num1 - num2;
  } else if (op == '*') {
    return num1 * num2;
  } else {
    return num1 / num2;
  }
}

void take_st_calc(stack<char> &operation, stack<int> &digits) {
  char op = operation.top();
  operation.pop();
  int digit2 = digits.top();
  digits.pop();
  int digit1 = digits.top();
  digits.pop();
  digits.push(calc(digit1, digit2, op));
}

int main() {
  cin >> expression;
  stack<char> operation;
  stack<int> digits;
  unordered_map<char, int> level{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
  for (int i = 0; i < expression.size(); i++) {
    if (isdigit(expression[i])) {
      int num = 0;
      while (i < expression.size() && isdigit(expression[i])) {
        num = num * 10 + expression[i] - '0';
        i++;
      }
      digits.push(num);
      i--;
    } else {
      if (expression[i] == '(') {
        operation.push(expression[i]);
      } else if (expression[i] == ')') {
        while (operation.top() != '(') {
          take_st_calc(operation, digits);
        }
        operation.pop();
      } else {
        while (!operation.empty() && operation.top() != '(' &&
               level[operation.top()] >= level[expression[i]]) {
          take_st_calc(operation, digits);
        }
        operation.push(expression[i]);
      }
    }
  }
  while (!operation.empty()) {
    take_st_calc(operation, digits);
  }
  cout << digits.top() << endl;
}
