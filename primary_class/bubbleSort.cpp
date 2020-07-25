# include <stdio.h>
# include <vector>
# include <array>
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

    void selectionSort(vector<int>& nums){
        if(nums.size()<2){
            return;
        }
        for(int i=0; i<nums.size()-1; ++i){
            int min_idx = i;
            for(int j=i+1; j < nums.size(); ++j){
                if(nums[j]<nums[min_idx]) 
                    min_idx = j;
            }
            swap(nums[i], nums[min_idx]);
        }
    }

    void insertionSort(vector<int>& nums){
        if(nums.size()<2){
            return;
        }
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j>0 && nums[j]<nums[j-1]; j--){
                swap(nums[j], nums[j-1]);
            }
        }
    }
 
    // void insertionSort(vector<int>& nums){
    //     if(nums.size()<2){
    //         return;
    //     }
    //     for(int i=1; i<nums.size(); i++){
    //         for(int j=i-1; j>=0 && nums[j+1]>nums[j]; j--){
    //             swap(nums[j], nums[j+1]);
    //         }
    //     }
    // }


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
        if(nums.size()<2){
            return;
        }
        quickSort_(nums, 0, nums.size()-1);
    }

    void quickSort_(vector<int>& nums, int l, int r){
        if(l<r){
            default_random_engine e(time(0));
            uniform_int_distribution<unsigned> u(l, r-1);
            swap(nums[u(e)], nums[r]);
            array<int, 2> p = partition(nums, l, r);
            quickSort_(nums, l, p[0]-1);
            quickSort_(nums, p[1]+1, r);
        }
    }
    array<int, 2> partition(vector<int>& nums, int l, int r){
        int less = l-1, more = r;
        while(l < more){
            if(nums[l] < nums[r]){
                swap(nums[++less], nums[l++]);
            }
            else if(nums[l]> nums[r]){
                swap(nums[l], nums[--more]);
            }
            else l++;
        }
        swap(nums[more], nums[r]);
        return array<int, 2> {less+1, more};
    }

    // heap sort
    void heapSort(vector<int>& nums){
        if(nums.size()<2){
            return;
        }
        for(int index=0; index < nums.size(); index++){
            heapInsert(nums, index);
        }

        int len = nums.size();
        swap(nums[0], nums[--len]);
        while(len>0){
            heapify(nums, 0, len);
            swap(nums[--len], nums[0]);
        }
    }

    void heapInsert(vector<int>& nums, int index){
        while(nums[index] > nums[(index-1)/2]){
            swap(nums[index], nums[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    void heapify(vector<int>& nums, int index, int len){
        int left = 2*index +1;
        while(left < len){
            int largest = (left+1 < len && nums[left+1]>nums[left])?(left+1):left;
            if(nums[largest] > nums[index]){
                swap(nums[largest], nums[index]);
                index = largest;
                left = index*2+1; 
            }
            else break;
        }

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
        // sorter.selectionSort(nums1);
        // sorter.insertionSort(nums1);
        // sorter.mergeSort(nums1, 0, nums1.size()-1);
        // sorter.quickSort(nums1);
        sorter.heapSort(nums1);
        sorter.comparator(nums2);
        if(!sorter.isEqual(nums1, nums2)){
            succeed = false;
            cout << "Died at time "<< i << endl;
            for(vector<int>::iterator v=nums1.begin(); v!=nums1.end(); v++){
                cout <<"nums1: "<<*v;
            }
            cout<<endl;
            for(vector<int>::iterator v=nums2.begin(); v!=nums2.end(); v++){
                cout <<"nums2: "<<*v;
            }
            break;
        }
    }
    succeed?(cout<<"Oh yes!"<<endl):(cout<<"Oh, fuck!" <<endl);
    
    cout<<endl;
    system("pause");
    return 0;
}

