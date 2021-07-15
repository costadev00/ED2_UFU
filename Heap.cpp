// A C++ program to demonstrate common Binary Heap Operations
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);

    // to heapify a subtree with the root at given index
    void MinHeapify(int);

    int parent(int i) { return (i - 1) / 2; }

    // to get index of left child of node at index i
    int left(int i) { return (2 * i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2 * i + 2); }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);

    //prints all the elements of the heap
    void printAll();
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void MinHeap::printAll()
{
    for (int i = 0; i < heap_size; i++)
        cout << harr[i] << " ";
    cout << endl;
}
// ---------------------------------------------------------------
//MAX Heap implementations
vector<int> vet = {1, 5, 7, 2, 9, 7, 8, 2, 34};
// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapifyMax(int i)
{
    int n = vet.size();
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && vet[l] > vet[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && vet[r] > vet[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(vet[i], vet[largest]);

        // Recursively heapify the affected sub-tree
        heapifyMax(largest);
    }
}

// Function to build a Max-Heap from the given array
void buildMaxHeap()
{
    // Index of last non-leaf node
    int startIdx = (vet.size() / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--)
    {
        heapifyMax(i);
    }
}

// A utility function to print the array
// representation of Heap
void printMaxHeap()
{
    cout << "Array representation of Max Heap is:\n";

    for (int i = 0; i < vet.size(); ++i)
        cout << vet[i] << " ";
    cout << "\n";
}
//-----------------------------------------------------------

// Driver program to test above functions
int main()
{
    vector<int> arr = {3, 2, 1, 15, 5, 4, 45};
    MinHeap hmin(arr.size());
    cout << "Original Max Array:\n";
    for (auto i : vet)
        cout << i << " ";
    cout << endl;
    //insert the elements at the min heap
    for (int i = 0; i < arr.size(); i++)
        hmin.insertKey(arr[i]);
    //insert the elements on max heap
    buildMaxHeap();
    cout << "Printing the Max Heap\n";
    printMaxHeap();
    cout << "\n\n";
    cout << "Original "
            "Min"
            " Array:\n";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    cout << "MinHeap:\n";
    hmin.printAll();
    cout << "Extracting the minimum element(root), and heapfying the tree\n";
    hmin.extractMin();
    hmin.printAll();
    cout << "Minimum element of the MinHeap(root):\n";
    cout << hmin.getMin() << "\n";
    cout << "Changing the position 2 and adding the element 1 in place:\n";
    hmin.decreaseKey(2, 1);
    cout << hmin.getMin() << "\n";
    cout << "Deleting the position 0 of the MinHeap\n";
    hmin.deleteKey(0);
    cout << endl;
    cout << "Min Heap:\n";
    hmin.printAll();
    return 0;
}
