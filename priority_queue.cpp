#include <iostream>
#include <vector>
template <typename T>
class priority_queue
{
    std::vector<T> heap;
private: void heapify(int n, int i)
    {
        int smallest = i;
        int l = (i << 1) + 1;
        int r = l + 1;
        if(l < n && heap[l] < heap[smallest])
            smallest = l;
        if(r < n && heap[r] < heap[smallest])
            smallest = r;
        if(smallest != i)
        {
            std::swap(heap[i], heap[smallest]);
            heapify(n, smallest);
        }
    }
public: void push(T val)
    {
        heap.push_back(val);
        int i = heap.size() - 1;
        while(i > 0)
        {
            int p = (i - 1) >> 1;
            if(!(heap[i] < heap[p]))
                break;
            std::swap(heap[p], heap[i]);
            i = p;
        }
    }
    void pop()
    {
        heap[0] = heap.back();
        heap.pop_back();
        heapify(heap.size(), 0);
    }
    T top()
    {
        return heap[0];
    }
    bool empty()
    {
        return heap.empty();
    }
};
struct Element
{
    int val, idx, time;
    Element(int val, int idx, int time) : val(val), idx(idx), time(time) {}
    bool operator<(const Element &other) const
    {
        if(val != other.val)
            return val < other.val;
        return time < other.time;
    }
};
int main()
{
    priority_queue<Element> p;
    int time = 0;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int val;
        std::cin >> val;
        p.push(Element(val, i, time++));
    }
    p.pop();
    p.pop();
    p.push(Element(1, 1, time++));
    while(!p.empty())
    {
        Element e = p.top();
        std::cout << e.val << ' ';
        p.pop();
    }
}