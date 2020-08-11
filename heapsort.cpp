#include <iostream> 

using namespace std;

// To makeHeap a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void makeHeap(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int left = 2 * i + 1; // left child 
	int right = 2 * i + 2; // right child

					   // If left child is larger than root 
	if (left < n && arr[left] > arr[largest])
		largest = left;

	// If right child is larger than largest so far 
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);


		makeHeap(arr, n, largest);
	}
}

// do heap sort 
void sortHeap(int arr[], int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		makeHeap(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i>0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max makeHeap on the reduced heap 
		makeHeap(arr, i, 0);
	}
}


// main program 
int main()
{

	int arr[10];
	cout << "Input the 10 values: ";
	int i = 0;
	while (i < 10 )
	{
		cin >> arr[i];
		i++;
	}

	
	int n = sizeof(arr) / sizeof(arr[0]);

	sortHeap(arr, n);

	cout << "\nSorted array is \n";
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}