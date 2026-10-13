#include <iostream>
#include <string>
using namespace std;

// =============================
// STRUCTURES
// =============================

struct Operation {
    int id;
    string name;
    int priority;
    int time;
    int dependency;
    bool completed;
};

struct Machine {
    int id;
    string name;
    bool available;
};

// =============================
// QUEUE
// =============================

class Queue {
    int data[20];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (rear == 19) {
            cout << "Queue is full!\n";
            return;
        }

        if (front == -1)
            front = 0;

        data[++rear] = x;
    }

    int dequeue() {
        if (isEmpty())
            return -1;

        return data[front++];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Ready Operations: ";

        for (int i = front; i <= rear; i++)
            cout << data[i] << " ";

        cout << endl;
    }
};

// =============================
// STACK
// =============================

class Stack {
    int data[20];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 19) {
            cout << "Stack is full!\n";
            return;
        }

        data[++top] = x;
    }

    int pop() {
        if (top == -1)
            return -1;

        return data[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// =============================
// LINKED LIST
// Machine Schedule
// =============================

struct Node {
    int operationID;
    Node* next;
};

void addToSchedule(Node*& head, int operationID) {

    Node* newNode = new Node;

    newNode->operationID = operationID;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

void displaySchedule(Node* head) {

    if (head == NULL) {
        cout << "No operations scheduled.";
        return;
    }

    while (head != NULL) {
        cout << "Operation " << head->operationID;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }
}

// =============================
// LINEAR SEARCH
// =============================

int linearSearchMachine(Machine machines[], int n, int id) {

    for (int i = 0; i < n; i++) {

        if (machines[i].id == id)
            return i;
    }

    return -1;
}

// =============================
// MERGE SORT
// Sort operations by priority
// =============================

void merge(Operation arr[], int left, int mid, int right) {

    Operation temp[20];

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {

        if (arr[i].priority >= arr[j].priority)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(Operation arr[], int left, int right) {

    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

// =============================
// BINARY SEARCH
// Search operation by ID
// =============================

int binarySearch(Operation arr[], int n, int id) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid].id == id)
            return mid;

        else if (arr[mid].id < id)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

// =============================
// DISPLAY OPERATIONS
// =============================

void displayOperations(Operation operations[], int n) {

    cout << "\n---------------------------------\n";
    cout << "OPERATIONS\n";
    cout << "---------------------------------\n";

    for (int i = 0; i < n; i++) {

        cout << "ID: " << operations[i].id
             << " | " << operations[i].name
             << " | Priority: " << operations[i].priority
             << " | Time: " << operations[i].time
             << " | Dependency: " << operations[i].dependency
             << endl;
    }
}

// =============================
// MAIN
// =============================

int main() {

    // -------------------------
    // MACHINES
    // -------------------------

    Machine machines[3] = {
        {1, "Assembly Machine", true},
        {2, "Soldering Machine", true},
        {3, "Testing Machine", true}
    };

    // -------------------------
    // OPERATIONS
    // -------------------------

    Operation operations[10] = {

        {1, "Assembly", 3, 20, 0, false},

        {2, "Soldering", 2, 15, 1, false},

        {3, "Testing", 4, 10, 2, false},

        {4, "Quality Check", 5, 8, 3, false},

        {5, "Packaging", 1, 12, 4, false}
    };

    int n = 5;

    // -------------------------
    // LINKED LISTS
    // One schedule for each machine
    // -------------------------

    Node* machineSchedule[3] = {
        NULL,
        NULL,
        NULL
    };

    Queue readyQueue;
    Stack dependencyStack;

    int choice;

    do {

        cout << "\n\n====================================";
        cout << "\n PRODUCTION SCHEDULING SYSTEM";
        cout << "\n====================================";

        cout << "\n1. Display Operations";
        cout << "\n2. Sort Operations by Priority";
        cout << "\n3. Check Dependencies";
        cout << "\n4. Add Ready Operations to Queue";
        cout << "\n5. Schedule Operations";
        cout << "\n6. Search Operation";
        cout << "\n7. Display Machine Schedules";
        cout << "\n8. Simulate Machine Failure";
        cout << "\n9. Add Urgent Order";
        cout << "\n10. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        // =========================================
        // 1. DISPLAY
        // =========================================

        if (choice == 1) {

            displayOperations(operations, n);
        }

        // =========================================
        // 2. MERGE SORT
        // =========================================

        else if (choice == 2) {

            mergeSort(operations, 0, n - 1);

            cout << "\nOperations sorted by priority.\n";

            displayOperations(operations, n);
        }

        // =========================================
        // 3. STACK - DEPENDENCY CHECK
        // =========================================

        else if (choice == 3) {

            cout << "\nChecking dependencies using STACK...\n";

            for (int i = 0; i < n; i++) {

                if (operations[i].dependency != 0) {

                    dependencyStack.push(
                        operations[i].dependency
                    );
                }
            }

            while (!dependencyStack.isEmpty()) {

                int dependency = dependencyStack.pop();

                cout << "Dependency Operation: "
                     << dependency << endl;
            }
        }

        // =========================================
        // 4. QUEUE
        // =========================================

        else if (choice == 4) {

            cout << "\nAdding ready operations to QUEUE...\n";

            for (int i = 0; i < n; i++) {

                if (operations[i].dependency == 0 &&
                    !operations[i].completed) {

                    readyQueue.enqueue(
                        operations[i].id
                    );
                }
            }

            readyQueue.display();
        }

        // =========================================
        // 5. SCHEDULING
        // =========================================

        else if (choice == 5) {

            cout << "\nScheduling operations...\n";

            int operationID;

            while (!readyQueue.isEmpty()) {

                operationID = readyQueue.dequeue();

                int index = binarySearch(
                    operations,
                    n,
                    operationID
                );

                if (index == -1)
                    continue;

                // Find available machine
                bool assigned = false;

                for (int i = 0; i < 3; i++) {

                    if (machines[i].available) {

                        cout << "\nOperation "
                             << operationID
                             << " assigned to "
                             << machines[i].name;

                        addToSchedule(
                            machineSchedule[i],
                            operationID
                        );

                        operations[index].completed = true;

                        machines[i].available = false;

                        assigned = true;

                        break;
                    }
                }

                if (!assigned) {

                    cout << "\nNo machine available for Operation "
                         << operationID;
                }
            }

            cout << "\n\nScheduling completed.\n";
        }

        // =========================================
        // 6. BINARY SEARCH
        // =========================================

        else if (choice == 6) {

            int id;

            cout << "\nEnter operation ID: ";
            cin >> id;

            // Sort by ID first for binary search
            // Simple bubble sort for demonstration
            for (int i = 0; i < n - 1; i++) {

                for (int j = 0; j < n - i - 1; j++) {

                    if (operations[j].id >
                        operations[j + 1].id) {

                        Operation temp = operations[j];

                        operations[j] =
                            operations[j + 1];

                        operations[j + 1] = temp;
                    }
                }
            }

            int result =
                binarySearch(operations, n, id);

            if (result != -1) {

                cout << "\nOperation found: "
                     << operations[result].name;
            }
            else {

                cout << "\nOperation not found.";
            }
        }

        // =========================================
        // 7. LINKED LIST
        // =========================================

        else if (choice == 7) {

            cout << "\n\nMACHINE SCHEDULES\n";

            for (int i = 0; i < 3; i++) {

                cout << "\n"
                     << machines[i].name
                     << ": ";

                displaySchedule(
                    machineSchedule[i]
                );

                cout << endl;
            }
        }

        // =========================================
        // 8. MACHINE FAILURE
        // =========================================

        else if (choice == 8) {

            int id;

            cout << "\nEnter machine ID that failed: ";
            cin >> id;

            int index =
                linearSearchMachine(
                    machines,
                    3,
                    id
                );

            if (index != -1) {

                machines[index].available = false;

                cout << "\nMachine "
                     << machines[index].name
                     << " has failed.";

                cout << "\nRescheduling will use another "
                        "available machine.";
            }
            else {

                cout << "\nMachine not found.";
            }
        }

        // =========================================
        // 9. URGENT ORDER
        // =========================================

        else if (choice == 9) {

            if (n < 10) {

                operations[n].id = n + 1;

                operations[n].name =
                    "URGENT ORDER";

                operations[n].priority = 10;

                operations[n].time = 5;

                operations[n].dependency = 0;

                operations[n].completed = false;

                n++;

                cout << "\nUrgent order added!";
                cout << "\nPriority = 10";

                readyQueue.enqueue(
                    operations[n - 1].id
                );
            }
        }

        else if (choice == 10) {

            cout << "\nExiting system...\n";
        }

        else {

            cout << "\nInvalid choice!";
        }

    } while (choice != 10);

    return 0;
}