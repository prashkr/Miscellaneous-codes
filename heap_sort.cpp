#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int heapSize;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int Heap[], int idx)
{
    int left = 2*idx+1;
    int right = 2*idx+2;
    int min = idx;
    if(left<heapSize && Heap[left]<Heap[idx])
        min = left;
    if(right<heapSize && Heap[right]<Heap[min])
        min = right;

    if(min!=idx)
    {
        swap(&Heap[idx], &Heap[min]);
        heapify(Heap, min);
    }

}

/*
Time complexity analysis
Number of nodes at height h = n/(2^(h+1)). lets call it 'num'.
time to heapify at a node at height h is O(h);
so total time to build a head is sum(h=1 to logn) O(h)*num  = O(n)

*/
void buildHeap(int Heap[])  
{
    int idx = heapSize-1;
    idx = (idx-1)/2;
    while(idx>=0)
    {
        heapify(Heap, idx);
        idx--;
    }
}

int ExtractMin(int Heap[])
{
    int min = Heap[0];
    swap(Heap[0], Heap[heapSize-1]);
    heapSize--;
    heapify(Heap, 0);
    return min;
}

int HeapMin(int Heap[])
{
    return Heap[0];
}

void Insert(int Heap[], int val)
{
    Heap[heapSize] = val;
    int idx = (heapSize-1)/2;
    int node = heapSize-1;
    bool flag = true;
    while(idx>=0 && flag)
    {
        if(Heap[idx]>Heap[node])
        {
            swap(Heap[idx], Heap[node]);
            node = idx;
        }
        else
            flag = false;
        idx = (idx-1)/2;
    }
    heapSize++;
}

int main()
{
    int Heap[MAX] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    heapSize = 10;
    buildHeap(Heap);
    Insert(Heap, 0);
    Insert(Heap, 20);
    Insert(Heap, -1);
    // cout<<HeapMin(Heap)<<endl;;
    while(heapSize)
    {
        cout<<ExtractMin(Heap)<<" ";  //basically heap sort
    }
    int i;
    // for(i=0; i<10; i++)
    //     cout<<Heap[i]<<" ";
    cout<<endl;
    return 0;
}
