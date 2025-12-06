#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. 通用工具函数 (Utilities)
// ==========================================

// 交换两个整数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 复制数组 (用于在测试不同算法时重置数据)
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// ==========================================
// 2. 冒泡排序 (Bubble Sort)
// ==========================================
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

// ==========================================
// 3. 选择排序 (Selection Sort)
// ==========================================
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

// ==========================================
// 4. 插入排序 (Insertion Sort) [新增]
// ==========================================
// 原理：像打扑克牌理牌一样，将新抓的牌插入到已排好的序列中合适的位置
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // 当前待插入的元素
        int j = i - 1;

        // 将大于 key 的元素向后移一位
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // 找到位置，插入 key
        arr[j + 1] = key;
    }
}

// ==========================================
// 5. 归并排序 (Merge Sort)
// ==========================================

// 归并排序的辅助合并函数
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // 动态分配临时数组
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    if (!L || !R) { printf("Memory Error\n"); exit(1); }

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arr[k++] = L[i++]; }
    while (j < n2) { arr[k++] = R[j++]; }

    free(L);
    free(R);
}

// 归并排序主函数
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ==========================================
// 6. 主函数测试 (Main)
// ==========================================
int main() {
    // 原始数据
    int original[] = {64, 34, 25, 12, 22, 11, 90, 5, 78};
    int n = sizeof(original) / sizeof(original[0]);
    
    // 临时测试数组
    int *testArr = (int*)malloc(n * sizeof(int));

    printf("========= 排序算法全家桶 =========\n");
    printf("原始数组: ");
    printArray(original, n);
    printf("\n");

    // --- 1. 冒泡排序 ---
    copyArray(original, testArr, n); 
    bubbleSort(testArr, n);
    printf("[冒泡排序] 结果: ");
    printArray(testArr, n);

    // --- 2. 选择排序 ---
    copyArray(original, testArr, n); 
    selectionSort(testArr, n);
    printf("[选择排序] 结果: ");
    printArray(testArr, n);

    // --- 3. 插入排序 (新增) ---
    copyArray(original, testArr, n); 
    insertionSort(testArr, n);
    printf("[插入排序] 结果: ");
    printArray(testArr, n);

    // --- 4. 归并排序 ---
    copyArray(original, testArr, n); 
    mergeSort(testArr, 0, n - 1);
    printf("[归并排序] 结果: ");
    printArray(testArr, n);

    // 释放主函数内存
    free(testArr);

    return 0;
}