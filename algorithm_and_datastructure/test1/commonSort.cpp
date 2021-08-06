#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
using namespace std;
class solution {
 public:
  // 冒泡
  void Bubble(vector<int>& nums) {
    // 外层控制循环次数，其实外层最后一次循环已经是有序的，所以-1次
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = 0; j < nums.size() - i - 1; j++) {
        if (nums[j] > nums[j + 1])
          swap(nums[j], nums[j + 1]);
      }
    }
    return;
  }

  // 快排
  void QuickSort(vector<int>& nums) {
    QuickSort(nums, 0, nums.size() -1);
  }
  void QuickSort(vector<int>& nums, int st, int en) {
    // 说明此时
    if (st >= en)  return;
    int target = nums[st];
    int i = st, j = en + 1;
    while (i < j) {
      while (nums[++i] < target) {
        if (i > j)  break;
      }
      // 用于保证位置的相对一致
      while (nums[--j] >= target) {
        if (i > j)  break;
      }
      // 在循环过程中只有当i < j时才会进行置换
      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }
    // i >= j时退出最外层循环
    swap(nums[j], nums[st]);
    QuickSort(nums, st, j - 1);
    QuickSort(nums, j + 1, en);
    return;
  }
  void random_shuffle(vector<int>& nums) {
    random_device rd;
    mt19937 rng(rd());
    // 使用一个随机数产生器来打乱数组，推荐使用shuffle代替被删除的random_shuffle
    shuffle(nums.begin(), nums.end(), rng);
    return;
  }

  // 简单插入排序
  void insertSort(vector<int>& nums) {
    int len = nums.size();
    for (int i = 1; i < len; i++) {
      int key = nums[i];
      int j = 0;
      for (j = i - 1; j >= 0; j--) {
        if (nums[j] > key)  nums[j + 1] = nums[j];
        else break;
      }
      nums[j + 1] = key;
    }
    return;
  }

  // 希尔排序
  void shellSort(vector<int>& nums) {
    int len = nums.size();
    int gap = 1;
    // 先计算得到最大的步长
    while (gap < len / 3) {
      gap = gap * 3 + 1;
    }
    // 从当前步长gap开始，到下一个步长2gap为止，分成了gap组；并在每一组中从前往后进行插入排序
    while (gap >= 1) {
      for (int i = gap; i < len; i++) {
        // j从i开始保证了可以最少和第一个元素比较一次,每次循环中比较当前元素和它前一个步长位置元素
        // 类似于将较小元素的值冒泡到前面
        for (int j = i; j >= gap && (nums[j] < nums[j - gap]); j -= gap) {
          swap(nums[j], nums[j - gap]);
        }
      }
      gap /= 3;
    }
    return;
  }

  // 简单选择排序
  void selectionSort(vector<int>& nums) {
    int len = nums.size();
    // 由于在找到未排序元素中最小元素之后需要进行交换，所以需要保存下标
    int min = 0;
    // 每次排序最小元素的插入位置
    for (int i = 0; i < len; i++) {
      min = i;  // 每次默认最小的元素是开始位置的元素
      for (int j = i; j < len; j++) {
        if (nums[j] < nums[min])  min = j;
      }
      swap(nums[min], nums[i]);
    }
    return;
  }

  // 堆排序，利用一维数组进行存储
  void heapSort (vector<int>& arr) {
    // 首先将数组调整为大顶堆
    heapInsert(arr);
    int endIndex = arr.size() - 1;
    while (endIndex > 0) {
      swap(arr[0], arr[endIndex]);
      endIndex --;
      heapify(arr, endIndex);
    }
    return;
  }
  // 给定一个数组，在依次插入过程中将其调整为大顶堆
  void heapInsert(vector<int>& arr) {
    int len = arr.size();
    if (len == 1)  return;
    for (int i = 1; i < len; i++) {
      int currentIndex = i;
      int fatherIndex = (currentIndex - 1) / 2;
      while (arr[currentIndex] > arr[fatherIndex] && currentIndex > 0) {
        swap(arr[currentIndex], arr[fatherIndex]);
        currentIndex = fatherIndex;
        fatherIndex = (currentIndex - 1) / 2;
      }
    }
    return;
  }
  void heapify (vector<int>& arr, int end) {
    int currentIndex = 0;
    int leftIndex = currentIndex * 2 + 1;
    int rightIndex = currentIndex * 2 + 2;
    int maxValIndex = 0;
    while (leftIndex <= end) {
      if (rightIndex <= end)  maxValIndex = arr[leftIndex] > arr[rightIndex] ? leftIndex : rightIndex;
      else  maxValIndex = leftIndex;
      if (arr[currentIndex] < arr[maxValIndex])  swap(arr[currentIndex], arr[maxValIndex]);
      else  break;
      currentIndex = maxValIndex;
      leftIndex = currentIndex * 2 + 1;
      rightIndex = currentIndex * 2 + 2;
    }
    return;
  }

  // 2路归并排序，采用迭代的方式(自底向上)
  void twoPathMergeSort(vector<int>& arr) {
    int len = arr.size();
    vector<int> addition(len, 0);
    // seg表示每次迭代的子数组长度
    for (int seg = 1; seg < len; seg *= 2) {
      for (int start = 0; start < len; start += seg * 2) {
        int low = start, mid = min(start + seg - 1, len - 1), high = min(start + 2 * seg - 1, len - 1);
        merge(arr, addition, low, mid, high);
      }
    }
  }
  void merge(vector<int>& arr, vector<int>& addition, int low, int mid, int high) {
    // 此时归并到了边界
    if (mid >= high)  return;
    for (int k = low; k <= high; k++)
      addition[k] = arr[k];
    int k = low, i = low, j = mid + 1;
    while (i <= mid && j <= high)
      arr[k++] = addition[i] < addition[j] ? addition[i++] : addition[j++];
    while (i <= mid)  arr[k++] = addition[i++];
    while (j <= high)  arr[k++] = addition[j++];
    return;
  }

  // 采用递归的方式进行(自顶向下)
  void twoPathMergeSort_recur(vector<int>& arr) {
    vector<int> addition(arr.size(), 0);
    sort(arr, addition, 0, arr.size() - 1);
    return;
  }
  void sort(vector<int>& arr, vector<int>& addition, int low, int high) {
    if (low >= high)  return;
    int mid = (low + high) / 2;
    sort(arr, addition, low, mid);
    sort(arr, addition, mid + 1, high);
    merge(arr, addition, low, mid, high);
    return;
  }

};
int main() {
  vector<int> nums = {4,1,3,2,7,6,5,4,7,3,10};
  solution ss;
  ss.twoPathMergeSort_recur(nums);
  for (auto num : nums)
    cout << num << " ";
  return 0;
  //sort(nums.begin(), nums.end(), [](int x, int y){return x < y;});
}