# include <stdio.h>
# include <iostream>
# include <unordered_map>
# include <random>
using namespace std;

template <class Key>
class MaxPool{
public:
  MaxPool(): size(0);

  pair<Key, int>::const_iterator insert(Key k){
    pair<Key, int>::const_iterator it = keyIndex.insert(pair<Key, int>(k, index);
    if (*it.second == true){
      indexKey.insert(pair<int, Key>(++size, k);
    }
    return it;
  }

  void erase(Key k){
    pair<Key, int>::const_iterator it = keyIndex.find(k);
    if(it != keyIndex.end()){
      int eraseIndex = *it.second;
      int lastIndex = size--;
      Key lastKey = indexKey[lastIndex];
      indexKey.erase(eraseIndex);
      keyIndex.erase(it);
      keyIndex.insert(pair<Key, int>(lastKey, eraseIndex));
      indexKey.insert(pair<int, Key>(eraseIndex, lastKey));
    }
  }

  Key getRandom(){
    default_random_engine e;
    uniform_int_distribution<unsigned int> u(1, size);
    return indexKey[u(e)];
  }

private:
  unordered_map<Key, int> keyIndex;
  unordered_map<int, Key> indexKey;
  int size;

};