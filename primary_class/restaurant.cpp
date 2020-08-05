# include <stdio.h>
# include <iostream>
# include <map>
# include <vector>
# include <algorithm>

using namespace std;

int findDesk(vector<int>& desks, int num){
  
  int s = 0, e = desks.size()-1;

  while(s <= e){
    int mid = s+((e-s)/2);
    if(desks[mid] == num){
      return mid;
    }
    if(desks[mid] < num){
      s = mid+1;
    }
    else{
      e = mid - 1;
    }
  }
  return s;
}



int main(){
  int n, m;
  int capacity, num, money; 
  cin >> n >> m;
  vector<int> desks;
  vector<pair<int, int>> customers;
  // get desk data
  while(n){
    cin >> capacity;
    desks.push_back(capacity);
    n--;
  }
  // get customers data
  while(m){
    cin >> num >> money;
    customers.push_back(make_pair(money, num));
    m--;
  }
  // sort desk & customer
  sort(desks.begin(), desks.end());
  sort(customers.begin(), customers.end());
  m = customers.size();
  n = desks.size();
  long long count = 0;
  while(m && n){
    if (customers[--m].second > desks.back())
      continue;
    int location = findDesk(desks, customers[m].second);
    desks.erase(desks.begin() + location);
    count += customers[m].first;
    n--;
  }
  cout << count;

}