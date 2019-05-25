#include <bits/stdc++.h>

using namespace std;

void pt() {
  printf("test\n");
}

class Token {
  char oper;
  int val;
public:
  Token() {

  }

  Token(int v) {
    setInt(v);
  }

  bool isNumber() {
    return oper == '0';
  }

  int getNumber() {
    return val;
  }

  int getOperator() {
    return oper;
  }

  void set(char op) {
    if (op >= '0' && op <= '9') {
      oper = '0';
      val = op - '0';
    } else {
      oper = op;
    }
  }

  void setInt(int v) {
    oper = '0';
    val = v;
  }

  int getPriority() {
    switch(oper) {
      case '+':
      case '-':
        return 1;
      case '*':
      case '/':
        return 2;
      case '(':
      case ')':
        return -1;
    }
  }

  Token operate(char op, Token b) {
    switch (op) {
      case '+':
        return Token(val + b.getNumber());
      case '-':
        return Token(val - b.getNumber());
      case '*':
        return Token(val * b.getNumber());
      case '/':
        return Token(val / b.getNumber());
    }
  }
};

int main() {
  char str[129];
  scanf("%s", str);
  int i;
  Token t, a, b;
  queue<Token> q;
  stack<Token> s;
  // Shunting yard
  for (i = 0; str[i]; ++i) {
    t.set(str[i]);
    if (t.isNumber()) q.push(t);
    else if (t.getOperator() == '(') s.push(t);
    else if (t.getOperator() == ')') {
      while (s.top().getOperator() != '(') {
        q.push(s.top());
        s.pop();
      }
      s.pop();
    } else {
      while (!s.empty() && s.top().getPriority() >= t.getPriority()) {
        q.push(s.top());
        s.pop();
      }
      s.push(t);
    }
  }
  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  }
  // Reverse polish notation
  while (!q.empty()) {
    t = q.front();
    q.pop();
    if (t.isNumber()) {
      printf("%d", t.getNumber());
    } else {
      printf("%c", t.getOperator());
    }
    if (t.isNumber()) s.push(t);
    else {
      b = s.top();
      s.pop();
      a = s.top();
      s.pop();
      s.push(a.operate(t.getOperator(), b));
    }
  }
  // Print result
  printf("\n%d\n", s.top().getNumber());
  return 0;
}
