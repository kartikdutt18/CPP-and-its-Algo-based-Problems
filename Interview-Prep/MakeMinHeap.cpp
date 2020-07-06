#include <vector>
using namespace std;

class MinHeap
{
  public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(&vector); }

  vector<int> buildHeap(vector<int> *vec)
  {
    int lastParent = vec->size() / 2;
    for (int i = lastParent; i >= 0; i--)
      siftDown(i, vec->size() - 1, vec);

    return *vec;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> *heap)
  {
    int childOneIdx = 2 * currentIdx + 1;
    while (childOneIdx <= endIdx)
    {
      int swapIdx = childOneIdx;
      int childTwoIdx = 2 * currentIdx + 2;
      if (childTwoIdx <= endIdx && heap->at(childTwoIdx) < heap->at(childOneIdx))
        swapIdx = childTwoIdx;
      if (heap->at(currentIdx) > heap->at(swapIdx))
      {
        swap(heap->at(currentIdx), heap->at(swapIdx));
        currentIdx = swapIdx;
        childOneIdx = 2 * currentIdx + 1;
      }
      else
        return;
    }
  }

  void siftUp(int currentIdx, vector<int> *heap)
  {
    int parentIdx = (currentIdx - 1) / 2;
    while (parentIdx >= 0)
    {
      if (heap->at(parentIdx) > heap->at(currentIdx))
      {
        swap(heap->at(parentIdx), heap->at(currentIdx));
        currentIdx = parentIdx;
        parentIdx = (currentIdx - 1) / 2;
        ;
      }
      else
        return;
    }
  }

  int peek()
  {
    if (!heap.empty())
      return heap[0];
    return -1;
  }

  int remove()
  {
    if (heap.empty())
      return -1;
    int min_val = heap[0];
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    if (!heap.empty())
      siftDown(0, heap.size() - 1, &heap);
    return min_val;
  }

  void insert(int value)
  {
    heap.push_back(value);
    siftUp(heap.size() - 1, &heap);
  }
};
