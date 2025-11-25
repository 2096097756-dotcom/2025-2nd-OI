#include <stdio.h>

#define N 5

// 指针法二分查找
// p: 数组首地址
// low: 起始下标 (本代码中逻辑其实忽略了这个参数，默认从 p 开始)
// high: 结束下标 (对应指针 n)
// v: 要查找的值
int binarySearch(double *p, int low, int high, double v) {//传入指针
    // mid 变量声明了但没用，可以直接删掉
    // m 相当于 left 指针
    // n 相当于 right 指针
    // h 相当于 mid 指针
    double *m = p + low;    // 修正：应该加上 low，虽然 PPT 写的是 *m=p
    double *n = p + high;   
    double *h;

    // 当左指针在右指针左边或重合时
    while (m <= n) {
        // 指针运算计算中间地址
        // (n-m) 得到中间差几个元素
        h = m + (n - m) / 2;

        if (*h == v) {
            // 找到了，返回下标 (地址差)
            return h - p;
        }
        else if (*h > v) {
            // 数组是【降序】的：100, 90, 87...
            // 如果中间值(例如90) 大于 目标(例如65)
            // 说明目标在右边（更小的方向）
            m = h + 1;
        }
        else {
            // 中间值 小于 目标
            // 说明目标在左边（更大的方向）
            n = h - 1;
        }
    }

    return -1; // 没找到
}

int main() {
    // 定义一个【降序】排列的数组
    double a[N] = {100.00, 90.50, 87.00, 83.00, 65.50};
    double *pa = a;
    double v = 65.50; // 要查找的目标值

    // 调用查找
    // 注意：这里传入 N-1 (即下标 4)，因为我们的算法是闭区间 [low, high]
    // 如果传入 N，指针 n 会指向数组外面，存在越界风险
    int result = binarySearch(pa, 0, N - 1, v);

    if (result != -1) {
        printf("Found! index=%d\n", result);
        // 验证一下
        printf("Value at index %d is %.2f\n", result, a[result]);
    } else {
        printf("Not found!\n");
    }

    return 0;
}