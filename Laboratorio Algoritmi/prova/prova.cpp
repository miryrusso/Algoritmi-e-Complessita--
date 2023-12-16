#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void heapify(vector<pair<int, int>> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && (arr[l].first > arr[largest].first ||
                  (arr[l].first == arr[largest].first && arr[l].second > arr[largest].second)))
        largest = l;

    if (r < n && (arr[r].first > arr[largest].first ||
                  (arr[r].first == arr[largest].first && arr[r].second > arr[largest].second)))
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<pair<int, int>> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n, heapify_count = 0;
    string type;
    vector<pair<int, int>> arr;
    pair<int, int> p;

    while (cin >> type >> n)
    {
        arr.clear();
        heapify_count = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> p.first >> p.second;
            arr.push_back(p);
        }

        heapSort(arr, n);

        cout << heapify_count << " ";
        for (int i = 0; i < n; i++)
            cout << "(" << arr[i].first << "," << arr[i].second << ") ";
        cout << endl;
    }

    return 0;
}
