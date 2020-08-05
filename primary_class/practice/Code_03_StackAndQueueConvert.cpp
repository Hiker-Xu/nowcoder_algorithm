// 如何仅用队列结构实现栈结构？
// 如何仅用栈结构实现队列结构？


# include <stdio.h>
# include <iostream>
# include <stack>
# include <queue>

using namespace std;

class twoStackQueue{
  public:
    void push(int num){
      stackPush.push(num);
    }

    bool empty(){
      return (stackPop.empty() && stackPush.empty())?true:false;
    }

    void pop(){
      if(empty()){
        return;
      }
      if(stackPop.empty()){
        decant();
      }
      stackPop.pop();
    }

    int front(){
      if(empty()){
        return NULL;
      }
      if(stackPop.empty()){
        decant();
      }
      stackPop.top();
    }

    int back(){
      if(empty()){
        return NULL;
      }
      if(!stackPush.empty()){
        return stackPush.top();
      }
      else{
        swap(stackPush, stackPop);
        decant();
        int t = stackPop.top();
        swap(stackPush, stackPop);
      }
    }

    void decant(){
      while(!stackPush.empty()){
        stackPop.push(stackPush.top());
        stackPush.pop();
      }
    }
  private:
    stack<int> stackPush;
    stack<int> stackPop;
};

class myStack{
  public:
    bool empty(){
      return major.empty();
    }

    void push(int num){
      major.push(num);
    }

    void pop(){
      if(empty())
        return;
      while(major.size()!=1){
        help.push(major.front());
        major.pop();
      }
      major.pop();
      major.swap(help);
    }

    int top(){
      if(empty())
        return;
      return major.back();
    }

  private:
    queue<int> major;
    queue<int> help;
};