#include "SmallSum.h"
#include <vector>
int SmallSum::small_sum(int arr[], int n)
{   
    if(n<2)
        return 0;
    int sum = 0;

    for(int i = 1; i<n ;i++)
    {
        for(int j = 0;j<i;j++)
        {
            
            if(arr[i]>arr[j])
            {
                sum += arr[j];
            }   
        }
    }
    return sum;
}

int SmallSum::merge_sort(int arr[],int l,int r)
{
    if(l == r)
        return 0 ;
    int m = l + ((r-l)>>1);
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    merge(arr,l,m,r);
    return 0;
}

int SmallSum::merge(int arr[],int l,int m,int r)
{
    std::vector<int> temp;
    int p_left = l;
    int p_right = m+1;
    while(p_left<=m && p_right <= r)
    {
        temp.push_back(arr[p_left]<arr[p_right]?arr[p_left++]:arr[p_right++]);
    }
    while (p_left<=m)
    {
        temp.push_back(arr[p_left++]);
    }
    while(p_right<=r)
    {
        temp.push_back(arr[p_right++]);
    }
    for(int i = l ;i<=r;i++)
    {
        arr[i] = temp[i-l];
    }
    return 0;
}