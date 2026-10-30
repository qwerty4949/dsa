#include <iostream>
using namespace std;

const int n = 5;
int q[n], front = -1, rear = -1;

void enqueue(int x) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        cout << "Queue is full\n";
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (rear == n - 1)
        rear = 0;
    else
        rear++;

    q[rear] = x;
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Removed: " << q[front] << "\n";

    if (front == rear)
        front = rear = -1;
    else if (front == n - 1)
        front = 0;
    else
        front++;
}

void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    int i = front;

    while (true) {
        cout << q[i] << " ";

        if (i == rear)
            break;

        if (i == n - 1)
            i = 0;
        else
            i++;
    }

    cout << "\n";
}

int main() {
    int choice, x;

    do {
        cout << "1.Enqueue 2.Dequeue 3.Display 0.Exit: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Value: ";
            cin >> x;
            enqueue(x);
        }
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();

    } while (choice != 0);

    return 0;
}
