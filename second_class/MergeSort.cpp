#include "MergeSort.h"
#include <vector>
#include <iostream>
using namespace std;

void printf_arr(int *arr,int L,int R)
{
    for(int i = L;i<=R;i++)
    {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}
void printf_arr(vector<int> vec)
{
    for(auto iter = vec.begin();iter != vec.end();iter++)
    {
        cout<< *iter <<" ";
    }
    cout<<endl;
}

void merge(int arr[],int L,int middle,int R)
{
    vector<int> temp;
    
    temp.reserve(R-L+1);
    int p_left = L;
    int p_right = middle+1;
    cout<<"左半部分:"<<endl;
    printf_arr(arr,L,middle);
    cout<<"右半部分:"<<endl;
    printf_arr(arr,middle+1,R);
    while(p_left<=middle && p_right <= R)
    {
        temp.push_back(arr[p_left]< arr[p_right]? arr[p_left++]:arr[p_right++]);
    }
    while(p_left<=middle)
    {
        temp.push_back(arr[p_left++]);
    }
    while(p_right<=R)
    {
        temp.push_back(arr[p_right++]);
    }
    
    for(int i = L;i<=R;i++)
    {
        arr[i] = temp[i];
    }

    cout<<"合并的temp:"<<endl;
    printf_arr(temp);
    cout<<"赋值:"<<endl;
    printf_arr(arr,L,R);
}



void merge_sort(int arr[], int L,int R)
{
    if(L == R)
        return;
    int middle = L + ((R - L)>>1);
    merge_sort(arr,L,middle);
    merge_sort(arr,middle+1,R);
    merge(arr,L,middle,R);
}


