/*冒泡排序算法的原理如下： 
比较相邻的元素。如果第一个比第二个大，就交换他们两个。 
对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。 
针对所有的元素重复以上的步骤，除了最后一个。
持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。*/

#include <stdio.h>

#define ARR_LEN 255 /*数组长度上限*/

/* 冒泡排序 */
/* 1. 从当前元素起，向后依次比较每一对相邻元素，若逆序则交换 */
/* 2. 对所有元素均重复以上步骤，直至最后一个元素 */
/* int arr[]: 排序目标数组; int len: 元素个数 */
void bubbleSort(int arr[], int len)
{
    int temp, i, j;
    for (i = 0; i < len - 1; i++) /* 外循环为排序趟数，len个数进行len-1趟 */
        for (j = 0; j < len - 1 - i; j++)
        { /* 内循环为每趟比较的次数，第i趟比较len-i次 */
            if (arr[j] > arr[j + 1])
            { /* 相邻元素比较，若逆序则交换（升序为左大于右，降序反之） */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}

int main(void)
{
    int arr[ARR_LEN] = {3, 5, 1, -7, 4, 9, -6, 8, 10, 4};
    int len = 10;
    int i;

    bubbleSort(arr, len);
    for (i = 0; i < len; i++)
        printf("%d\t", arr[i]);
    putchar('\n');

    return 0;
}