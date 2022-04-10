#include <bits/stdc++.h>
using namespace std;
  
// Function to find an element in the queue as
// std::find does not work for a queue
bool findQueue(queue<int> q, int x)
{
    while (!q.empty()) {
        if (x == q.front())
            return true;
        q.pop();
    }
  
    // Element not found
    return false;
}
  
// Function to implement LRU Approximation
void LRU_Approximation(vector<int> t, int capacity)
{
    int n = t.size();
    queue<int> q;
  
    // Capacity is the size of the queue
    // hits is number of times page was
    // found in cache and faults is the number
    // of times the page was not found in the cache
    int hits = 0, faults = 0;
  
    // Array to keep track of bits set when a
    // certain value is already in the queue
    // Set bit --> 1, if its a hit
    // find the index and set bitref[index] = 1
    // Set bit --> 0, if its a fault, and the front
    // of the queue has bitref[front] = 1, send front
    // to back and set bitref[front] = 0
    bool bitref[capacity] = { false };
  
    // To find the first element that does not
    // have the bitref set to true
    int ptr = 0;
  
    // To check if the queue is filled up or not
    int count = 0;
    for (int i = 0; i < t.size(); i++) {
        if (!findQueue(q, t[i])) {
  
            // Queue is not filled up to capacity
            if (count < capacity) {
                q.push(t[i]);
                count++;
            }
  
            // Queue is filled up to capacity
            else {
                ptr = 0;
  
                // Find the first value that has its
                // bit set to 0
                while (!q.empty()) {
  
                    // If the value has bit set to 1
                    // Set it to 0
                    if (bitref[ptr % capacity])
                        bitref[ptr % capacity] = !bitref[ptr % capacity];
  
                    // Found the bit value 0
                    else
                        break;
                    ptr++;
                }
  
                // If the queue was empty
                if (q.empty()) {
                    q.pop();
                    q.push(t[i]);
                }
  
                // If queue was not empty
                else {
                    int j = 0;
  
                    // Rotate the queue and set the front's
                    // bit value to 0 until the value where
                    // the bitref = 0
                    while (j < (ptr % capacity)) {
                        int t1 = q.front();
                        q.pop();
                        q.push(t1);
                        bool temp = bitref[0];
  
                        // Rotate the bitref array
                        for (int counter = 0; counter < capacity - 1; counter++)
                            bitref[counter] = bitref[counter + 1];
                        bitref[capacity - 1] = temp;
                        j++;
                    }
  
                    // Remove front element
                    // (the element with the bitref = 0)
                    q.pop();
  
                    // Push the element from the
                    // page array (next input)
                    q.push(t[i]);
                }
            }
            faults++;
        }
  
        // If the input for the iteration was a hit
        else {
            queue<int> temp = q;
            int counter = 0;
            while (!q.empty()) {
                if (q.front() == t[i])
                    bitref[counter] = true;
                counter++;
                q.pop();
            }
            q = temp;
            hits++;
        }
    }
    cout << "Hits: " << hits << "\nFaults: " << faults << '\n';
}
  
// Driver code
int main()
{
    vector<int> t = { 2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2 };
    int capacity = 4;
    LRU_Approximation(t, capacity);
  
    return 0;
}
