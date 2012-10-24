#include <iostream>

using namespace std;


void InsertSort (int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (array[i] < array[i + 1])
		{
			int insert = array[i];
			int j = i - 1;
		    while (j > 0 && array[j] > insert) j--;

		    for (int k = i - 1; k > j; k--)
		    {
		    	array[k + 1] = array[k];
		    }
		    array[j + 1] = insert;
		}
	}
}


void Bubbsort(int array[], int len)
{

}

int main()
{
	int array[10] = {10,1,3,8,5,7,6,4,9,0};
	for(int i = 0; i < 10; i++)cout<<array[i]<<' ';
	cout<<endl;
	InsertSort(array, 10);
	for(int i = 0; i < 10; i++)cout<<array[i]<<' ';
	cout<<endl;
}
