class MyQueue {
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {
    }

    void push(int x) {
        input.push(x);
    }

    int pop() {

        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        int front = output.top();
        output.pop();

        return front;
    }

    int peek() {

        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};
// Dry Run

// Operations:

// push(1)
// push(2)

// input  = [1,2]
// output = []

// peek()

// Move elements:

// output = [2,1]
// input  = []

// Result:

// peek() = 1

// Next:

// pop() = 1
// queue = [2]
// Complexity
// Operation	Time
// push()	O(1)
// pop()	O(1) amortized
// peek()	O(1) amortized
// empty()	O(1)

// Space Complexity:

// O(n)
