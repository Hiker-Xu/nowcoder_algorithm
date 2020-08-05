// 实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返
// 回栈中最小元素的操作。
// 【要求】
// pop、push、getMin操作的时间复杂度都是O(1)。
// 设计的栈类型可以使用现成的栈结构

# include <stdio.h>
# include <iostream>
# include <stack>

using namespace std;

class myStack{

public:
  // void push(int n){
  //   nums.push(n);
  //   if(mins.empty() || min > n){
  //     min = n;
  //   }
  //   mins.push(min);
  // }

  // int pop(){
  //   if(nums.empty()){
  //     return NULL;
  //   }
  //   int t = nums.top();
  //   nums.pop();
  //   mins.pop();
  //   return t;
  // }

  void push(int n){
    nums.push(n);
    if(mins.empty() || min >= n){
      min = n;
      mins.push(min);
    }
  }

  int top(){
    if(nums.empty()){
      return NULL;
    }
    return nums.top();
  }

  void pop(){
    if(nums.empty()){
      return;
    }
    if(nums.top() == mins.top()){
      nums.pop();
      mins.pop();
    } 
    else nums.pop();

  }
  

  int getMin(){
    if(mins.empty()){
      return NULL;
    }
    return mins.top();
  }

private:
  stack<int> nums;
  stack<int> mins;
  int min;


};


int main(){
  myStack s1;
  s1.push(3);
  cout << s1.getMin() << endl;
  s1.push(4);
  cout << s1.getMin() << endl;
  s1.push(1);
  cout << s1.getMin() << endl;
  s1.pop();
  cout << s1.getMin() << endl;
  system("pause");
  return 0;
}