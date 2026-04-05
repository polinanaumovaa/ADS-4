// Copyright 2021 NNTU-CS
#include "alg.h"
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int leftVal = arr[left];
      int rightVal = arr[right];
      int leftCount = 0;
      int rightCount = 0;
      while (left <= right && arr[left] == leftVal) {
        leftCount++;
        left++;
      }
      while (right >= left && arr[right] == rightVal) {
        rightCount++;
        right--;
      }
      count += leftCount * rightCount;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    int firstPos = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        firstPos = mid;
        right = mid - 1;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (firstPos != -1) {
      left = firstPos;
      right = len - 1;
      int lastPos = firstPos;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
          lastPos = mid;
          left = mid + 1;
        } else if (arr[mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      count += (lastPos - firstPos + 1);
    }
  }
  return count;
}
