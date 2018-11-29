#!/usr/bin/env python3
#-*- conding: utf-8 -*-
import sys

def reverse(arr, start, end):
	while (start < end):
		temp = arr[start]
		arr[start] = arr[end]
		arr[end] = temp
		start += 1
		end -= 1

def shift_right_by_k(arr, k):
	n = len(arr)
	reverse(arr, 0, n - k - 1)
	reverse(arr, n -k, n - 1)
	reverse(arr, 0, n - 1)

def main():
	arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
	k = input("please input the number of k: ")
	shift_right_by_k(arr, int(k))
	for a in arr:
		print(a)

if __name__=='__main__':
	main()
