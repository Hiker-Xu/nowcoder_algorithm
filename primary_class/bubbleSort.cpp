# include <stdio.h>
# include <vector>
# include <iostream>
# include <algorithm>
# include <random>
# include <ctime>

using namespace std;

class BubbleSort{
public:
    void bubbleSort(vector<int>& nums){
        if (nums.empty() || nums.size() <2){
            return;
        }
        for(int i=nums.size()-1; i>0; i--){
            for(int j=0; j<i; j++){
                if(nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }
    }

    // merge sort
    void mergeSort(vector<int>& nums, int L, int R){
        if(L==R){
            return;
        }
        int mid = (int)(L+ (R-L)/2);
        mergeSort(nums, L, mid); //
        mergeSort(nums, mid+1, R);
        merge(nums, L, R);
    }

    void merge(vector<int>& nums, int L, int R){
        int mid = (int)(L+ (R-L)/2);
        int liter=L, riter =mid+1;
        vector<int> temp;
        while(liter <= mid && riter <=R){
            if(nums[liter] > nums[riter]){
                temp.push_back(nums[riter++]);
            }
            else temp.push_back(nums[liter++]);
        }
        while(liter <= mid){
            temp.push_back(nums[liter++]);
        }
        while(riter <= R){
            temp.push_back(nums[riter++]);
        }
        for(size_t i=0; i < temp.size(); i++){
            nums[L+i] = temp[i];
        }
    }

    // quick sort
    void quickSort(vector<int>& nums){
        if(nums.size()<2 || nums==NULL){
            return;
        }
        quickSort_(nums, 0, nums.size()-1);
    }

    


    // for test
    void comparator(vector<int>& nums){
        sort(nums.begin(), nums.end());
    }

    // for test
    vector<int> generateRandomVector(int maxSize, int maxValue){
        default_random_engine e(time(0));
        uniform_int_distribution<unsigned> u1(0, maxValue);
        uniform_int_distribution<unsigned> u2(0, maxSize);
        vector<int> nums;
        for(size_t i=0; i<u2(e); i++){
            nums.push_back(u1(e));
        }
        return nums;
    }

    //for test
    bool isEqual(vector<int>& v1, vector<int>&v2){
        if ((v1.empty() && !v2.empty()) || (!v1.empty() && v2.empty())) {
			return false;
		}
		if (v1.empty() && v2.empty()) {
			return true;
		}
		if (v1.size() != v2.size()) {
			return false;
		}
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] != v2[i]) {
				return false;
			}
		}
		return true;
    }
};

int main(){
    int testTime = 50000;
    int maxSize = 100;
    int maxValue = 100;
    bool succeed = true;
    BubbleSort sorter;
    for(size_t i=0; i<testTime; i++){
        vector<int> nums1 = sorter.generateRandomVector(maxSize, maxValue);
        vector<int> nums2(nums1);
        // sorter.bubbleSort(nums1);
        sorter.mergeSort(nums1, 0, nums1.size()-1);
        sorter.comparator(nums2);
        if(!sorter.isEqual(nums1, nums2)){
            succeed = false;
            cout << "Died at time "<< i << endl;
            break;
        }
    }
    succeed?(cout<<"Oh yes!"<<endl):(cout<<"Oh, fuck!" <<endl);
    system("pause");
    return 0;
}

