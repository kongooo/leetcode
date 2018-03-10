#include"stdafx.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

/*
2018 3 8
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
	int middleIndex = 0;
	int *bigger = nums1, *smaller = nums2;
	int fronter = nums2Size, backer = nums1Size;
	int totalLength = (nums1Size + nums2Size);
	int halfTotalLength = totalLength / 2;
	if (nums1[nums1Size - 1] < nums2[0])
	{
		smaller = nums1;
		bigger = nums2;
		fronter = nums1Size;
		backer = nums2Size;
	}
	//如果num1都比num2小或num2都比num1小
	if (nums1[nums1Size - 1] < nums2[0] || nums2[nums2Size - 1] < nums1[0])
	{
		if (fronter >= halfTotalLength)
		{
			if (totalLength % 2 == 0)
			{
				if (fronter == halfTotalLength)
					return (double)((smaller[fronter - 1] + bigger[0]) / 2);
				else
					return (double)((smaller[halfTotalLength - 1] + smaller[halfTotalLength]) / 2);
			}
			else
			{
				if (fronter == halfTotalLength)
					return (double)(bigger[0]);
				else
					return (double)(smaller[halfTotalLength]);
			}
		}
		else
		{
			if (totalLength % 2 == 0)
			{
				return (double)((bigger[halfTotalLength - fronter - 1] + bigger[halfTotalLength - fronter]) / 2);
			}
			else
			{
				return (double)bigger[halfTotalLength - fronter];
			}
		}
	}
	
	//用二分查找找到两个数组衔接的地方
	//如果num2的头在num1中间
	if (nums1[0] > nums2[0] && nums1[0] < nums2[nums2Size - 1])
		middleIndex = findContactNumber(smaller, 0, nums2Size - 1, nums1[0]);
	//如果num1的头在num2中间
	if (nums2[0] > nums1[0] && nums2[0] < nums1[nums2Size - 1])
	{
		smaller = nums1;
		bigger = nums2;
		middleIndex = findContactNumber(smaller, 0, nums1Size - 1, nums2[0]);
	}
	//用计算出的两数组长度之和/2作为边界值对两数组边“排序”边进行计数
	int currentSmaller = middleIndex, currentBigger = 0;
	for (int index = middleIndex; index < halfTotalLength - 1; index++)
	{

	}
	//达到边界值后，判断长度值之和的奇偶性，对相应值进行计算
}
/*返回连接两数组的序号*/
int findContactNumber(int *s, int start, int end, int firstNum) 
{
	int middle = (start + end) / 2;
	if (s[middle] == firstNum || (s[middle] < firstNum && s[middle + 1] > firstNum))
		return middle;
	else if (s[middle] > firstNum && s[middle - 1] < firstNum)
		return middle - 1;
	else
	{
		if (s[middle] > firstNum)
			return findContactNumber(s, start, middle - 1, firstNum);
		else 
			return findContactNumber(s, middle + 1, end, firstNum);
	}
}

