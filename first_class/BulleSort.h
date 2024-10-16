#ifndef __BULLE_SORT_H__
#define __BULLE_SORT_H__

class BulleSort
{
public:
    BulleSort();
    ~BulleSort();
    void sort(int* arr,int len);
private:
    void swap(int* arr,int i,int j);
};

#endif // __BULLE_SORT_H__

