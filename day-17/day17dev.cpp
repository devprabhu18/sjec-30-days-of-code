#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of frames: ";
    cin >> n;

    stack<int> frames;
    cout << "Enter the frames: ";
    for (int i = 0; i < n; i++) {
        int frame;
        cin >> frame;

        if (frames.empty() || frames.top() != frame) {
            // Push the frame onto the stack if the stack is empty or the top of the stack is not a duplicate
            frames.push(frame);
        }
    }

    cout << "Frames: ";
    // Create a temporary stack to store the frames in the correct order
    stack<int> temp;
    while (!frames.empty()) {
        temp.push(frames.top());
        frames.pop();
    }
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
