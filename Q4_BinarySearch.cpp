#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[100], key;
    cout << "Number of student IDs: ";
    cin >> n;
    cout << "Enter IDs: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cout << "Sorted IDs: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nEnter ID to find: ";
    cin >> key;
    int low = 0, high = n - 1, found = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) { found = mid; break; }
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    if (found >= 0) cout << "\nStudent ID found\n";
    else cout << "\nStudent ID not found\n";
    return 0;
}
