# include <stdio.h>
# include <iostream>
# include <vector>

using namespace std;

int main(){
  // vector<int> t1(10);
  // for(int i=0; i<10; i++){
  //   cout<< t1[i] << endl;
  // }
  unsigned int n1 = 4294967295;
  int n2 = -1;
  bool t = (n1 == n2);
  cout << "n1: " << n1 << endl;
  cout << t << endl;
  system("pause");
}