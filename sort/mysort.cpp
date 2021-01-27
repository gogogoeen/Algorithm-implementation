#include <iostream>
#include <vector>
using namespace std;
class mysort {
public:

    // implement quick sort
    // time complexity: O(n^2)
    // space complexity: O(1)

    void bubble (vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++ i) {
            for (int j = nums.size() - 1; j > i; -- j) {
                if (nums[j] < nums[j - 1]) swap(nums[j], nums[j - 1]);
            }
        }
    }

    // implement insert sort
    // time complexity: O(n^2)
    // space complexity: O(1)

    void insert (vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++ i) {
            int minval = nums[nums.size() - 1], ptr = nums.size() - 1;
            for (int j =  nums.size() - 1; j >= i; -- j) {
                if (minval > nums[j]) {
                    minval = nums[j];
                    ptr = j;
                }
            }
            swap(nums[i], nums[ptr]);
        }
    }

    // implement quicksort
    // time complexity: O(nlogn(n))
    // space complexity: O(1)

    void quick (vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pivot = nums[r], ptrl = l, ptrr = r;
        while (ptrl < ptrr) {
            while (ptrl < ptrr && nums[ptrl] < pivot) ++ ptrl;
            nums[ptrr] = nums[ptrl];
            while (ptrl < ptrr && nums[ptrr] > pivot) -- ptrr;
            nums[ptrl] = nums[ptrr];
        }
        nums[ptrl] = pivot;
        quick(nums, l, ptrl - 1);
        quick(nums, ptrl + 1, r);
        
    }

    // implement merge sort
    // time complexity: O(nlog(n))
    // space complexity: O(n)
    
    void merge (vector<int>& nums, int l, int r, vector<int>& dummy) {
        if(l >= r) return;
        int mid = l + (r - l) / 2;
    
        merge(nums, l, mid, dummy);
        merge(nums, mid + 1, r, dummy);
        int ptr = l, ptrl = l, ptrr = mid + 1;
        while (ptrl <= mid && ptrr <= r) {
            if (nums[ptrr] < nums[ptrl]) dummy[ptr++] = nums[ptrr++];
            else dummy[ptr++] = nums[ptrl++];
        }
        while (ptrl <= mid) {
            dummy[ptr++] = nums[ptrl++];
        }
        while (ptrr <= r) {
            dummy[ptr++] = nums[ptrr++];
        }
        for (int i = l; i <= r; ++ i) {
            nums[i] = dummy[i];
        }
    }
    

};

int main() {
    vector<int> myarray  {1,5,13,8,3,9,4,7,6,12};
    mysort Mysort;
    //Mysort.insert(myarray);
    //Mysort.bubble(myarray);
    //Mysort.quick(myarray, 0, myarray.size() - 1);
    vector<int> dummy (myarray.size(), 0);
    Mysort.merge(myarray, 0, myarray.size() - 1, dummy);
    for (int i = 0; i < myarray.size(); ++ i) {
        cout << myarray[i] << endl;
    }
}