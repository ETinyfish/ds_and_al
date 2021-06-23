/*
快速排序  
平均时间复杂度：O(logn)
稳定性：不稳定


*/

#include<iostream>
#include<ctime>
#include<algorithm>
#include<vector>
using namespace std;
//void swap(int index1, int index2, int* array)
//{
//	int temp = array[index1];
//	array[index1] = array[index2];
//	array[index2] = temp;
//}
int pivotIndex(int begin, int end, vector<int> &array)
{
	//默认让第一个元素成为节点元素
	int pivot = array[begin];
	end--;
	//快速排序
	while (begin < end)
	{
		//从右向左扫描
		while (begin < end)
		{
			//右边元素大于轴点元素
			if (array[end] > pivot)
			{
				//右边元素索引左移
				end--;
				cout << end << endl;
			}
			//右边元素小于轴点元素
			else
			{
				array[begin++] = array[end];
				break;
			}
		}
		//从左向右扫描
		while (begin < end)
		{
			//左边元素小于轴点元素
			if (array[begin] < pivot)
			{
				begin++;
			}
			//左边元素>轴点元素
			else
			{
				array[end--] = array[begin];
				break;
			}
		}
	}
	//将备份元素放入原来的位置
	array[begin] = pivot;
	return begin;
}
void sort(int begin, int end, vector<int> &array)
{
	//如果元素小于2，将中止快排
	if (end - begin < 2)
	{
		return;
	}
	//确定轴点的位置
	int mid = pivotIndex(begin, end, array);
	sort(begin, mid, array);
	sort(mid + 1, end, array);
}
int main()
{

	vector<int> array2= { 1,3,2,4,5,2 };
	int n = array2.size();


	cout << "the length of array2 is " << n << endl;
	//快速排序
	sort(0, n, array2);
	for (int index = 0; index < n; index++)
	{
		cout << array2[index] << " ";
	}
}
