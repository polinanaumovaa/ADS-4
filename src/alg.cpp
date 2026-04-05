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
      while (left < len && arr[left] == leftVal) {
        leftCount++;
        left++;
      }
      int rightCount = 0;
      while (right >= 0 && arr[right] == rightVal) {
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
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    int target = value - arr[i];
    if (target < arr[i]) {
      break;
    }
    int left = i + 1;
    int right = i - 1;
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
      continue;
    }
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
    if (arr[i] == target) {
      int lenRange = lastPos - i + 1;
      count += lenRange * (lenRange - 1) / 2;
      break;
    }
    int leftCount = 1;
    while (i + leftCount < len && arr[i + leftCount] == arr[i]) {
      leftCount++;
    }
    count += leftCount * (lastPos - firstPos + 1);
  }
  return count;
}
