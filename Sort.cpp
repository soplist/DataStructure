#include "stdafx.h"
#include<stdlib.h>
#include <string>
using namespace std;

#define MAXSIZE 20
typedef int KeyType;

typedef struct{
	KeyType key;
	string otherinfo;
}RedType;

typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

void InsertSort(SqList &L){
	for (int i = 2; i <= L.length;++i)
		if (L.r[i].key<L.r[i-1].key){
			L.r[0] = L.r[i];
			L.r[i] = L.r[i - 1];
			int j;
			for (j = i - 2; L.r[0].key < L.r[j].key; --j)
				L.r[j + 1] = L.r[j];
			L.r[j + 1] = L.r[0];
		}
}

void ShellInsert(SqList &L,int dk){
	for (int i = dk + 1; i <= L.length;++i)
		if (L.r[i].key<L.r[i - dk].key){
			L.r[0] = L.r[i];
			int j;
			for (j = i - dk; j>0 && L.r[0].key < L.r[j].key;j-=dk)
				L.r[j + dk] = L.r[j];
			L.r[j + dk] = L.r[0];
		}
}

void ShellSort(SqList &L, int dlta[],int t){
	for (int k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]);
}

void BInsertSort(SqList &L){
	for (int i = 2; i <= L.length; ++i){
		L.r[0] = L.r[i];
		int low = 1;
		int high = i - 1;
		while (low <= high){
			int m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key)
				high = m - 1;
			else
				low = m + 1;
		}
		for (int j = i - 1; j >= high + 1; --j)
			L.r[j + 1] = L.r[j];
		L.r[high + 1] = L.r[0];
	}
}

int Partition(SqList &L,int low,int high){
	//L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while (low<high){
		while (low < high&&L.r[high].key >= pivotkey) --high;
		//RedType tmp1 = L.r[low];
		//L.r[low] = L.r[high];
		//L.r[high] = tmp1;
		while (low < high&&L.r[low].key <= pivotkey) --low;
		//RedType tmp2 = L.r[low];
		//L.r[low] = L.r[high];
		//L.r[high] = tmp2;
	}
	return low;
}

void QSort(SqList &L, int low, int high){
	if (low < high){
		int pivotlov = Partition(L,low,high);
		QSort(L, low, pivotlov-1);
		QSort(L, pivotlov+1, high);
	}
}

int _tmain()
{
	SqList sqList;
	sqList.length = 8;
	RedType redType1;
	redType1.key = 49;
	sqList.r[1] = redType1;
	RedType redType2;
	redType2.key = 38;
	sqList.r[2] = redType2;
	RedType redType3;
	redType3.key = 65;
	sqList.r[3] = redType3;
	RedType redType4;
	redType4.key = 97;
	sqList.r[4] = redType4;
	RedType redType5;
	redType5.key = 76;
	sqList.r[5] = redType5;
	RedType redType6;
	redType6.key = 13;
	sqList.r[6] = redType6;
	RedType redType7;
	redType7.key = 27;
	sqList.r[7] = redType7;
	RedType redType8;
	redType8.key = 49;
	sqList.r[8] = redType8;
	//InsertSort(sqList);
	//BInsertSort(sqList);
	//dlta[k] = 2 ^ (t-k+1)-1
	//int dlta[3] = {7,3,1};
	//ShellSort(sqList, dlta, 3);
	QSort(sqList, 1, sqList.length);
	for (int i = 1; i <= sqList.length; ++i)
		printf("%d ", sqList.r[i]);
	system("pause");
	return 0;
}