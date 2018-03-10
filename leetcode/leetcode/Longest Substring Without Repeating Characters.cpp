#include"stdafx.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

/*ÌâÄ¿ÃèÊö
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

char* checkIfSame(char *start, char *current);
int GetLength(char *s, char *e);

int lengthOfLongestSubstring(char* s)
{
	int currentLength = 0, maxLength = 0;
	char *start = s, *current = s, *mediumNode;
	while (*current != '\0')
	{
		/*the node same with the current node*/
		mediumNode = checkIfSame(start, current);
		/*update from mediumnode*/
		if (mediumNode != NULL)
		{
			if (currentLength > maxLength)
				maxLength = currentLength;
			start = mediumNode + 1;
			currentLength = GetLength(start, current);
		}
		current++;
		currentLength++;
	}
	if (currentLength > maxLength)
		maxLength = currentLength;
	return maxLength;
}
/*check same node from interruption to current node, If have, return true*/
char* checkIfSame(char *start, char *current)
{
	char *p = start, *q = current;
	while (p != q)
	{
		if (*p == *q)
			return p;
		p++;
	}
	return NULL;
}
/*get the length between the two node, not include both of the boundary*/
int GetLength(char *s, char *e)
{
	int n = 0;
	while (s != e)
	{
		n++;
		s++;
	}
	return n;
}
int main()
{
	char p[] = "abca";
	printf("%d", lengthOfLongestSubstring(p));
	system("pause");
}