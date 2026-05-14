#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortREC(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSortREC(arr, left, mid);
    mergeSortREC(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSortNONREC(vector<int>& arr) {
    int n = arr.size();
    for (int currSize = 1; currSize < n; currSize *= 2) {
        for (int left = 0; left < n - 1; left += 2 * currSize) {
            int mid = min(left + currSize - 1, n - 1);
            int right = min(left + 2 * currSize - 1, n - 1);
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}
void wiggleSortNONREC(vector<int>& nums) {
    vector<int> sorted = nums;
    mergeSortNONREC(sorted);

    int n = nums.size();

    int left = (n - 1) / 2;
    int right = n - 1;

    for (int i = 0; i < n; i++) {

        if (i % 2 == 0) {
            nums[i] = sorted[left];
            left--;
        }
        else {
            nums[i] = sorted[right];
            right--;
        }
    }
}

void recWiggleSort(vector<int>& nums, vector<int>& sorted,int& left,int& right,int i) {

    if (i == nums.size())
        return;
    if (i % 2 == 0) {
        nums[i] = sorted[left];
        left--;
    }
    else {
        nums[i] = sorted[right];
        right--;
    }
    recWiggleSort(nums, sorted, left, right, i + 1);
}

void wiggleSortREC(vector<int>& nums) {
    vector<int> sorted = nums;
    mergeSortREC(sorted, 0, sorted.size() - 1);
    int n = nums.size();
    int left = (n - 1) / 2;
    int right = n - 1;
    recWiggleSort(nums, sorted, left, right, 0);
}


int main() {
    vector<int> nums;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n < 1 || n > 50000) {
        cout << "Invalid input! Number of elements must be between 1 and 50000.";
        return 0;
    }
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num < 0 || num > 5000) {
            cout << "Invalid input! Elements must be between 0 and 5000.";
            return 0;
        }
        nums.push_back(num);
    }
    vector<int> nums2 = nums;
    wiggleSortNONREC(nums);
    cout << "Wiggle Sorted Array (Non-Recursive): ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    wiggleSortREC(nums2);
    cout << "Wiggle Sorted Array (Recursive): ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
