#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[100], key;
    cout << "Number of students: ";
    cin >> n;
    cout << "Enter student IDs: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cout << "Sorted IDs: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nEnter ID to search: ";
    cin >> key;
    int low = 0, high = n - 1, pos = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) { pos = mid; break; }
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    if (pos != -1) cout << "ID found at sorted index " << pos << "\n";
    else cout << "ID not found\n";
    return 0;
}
