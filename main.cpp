#include <iostream>
#include <string>
using namespace std;

// The Cutie Interface provided
class Cutie {
public:
    virtual string description() = 0;  
    virtual int cuteness_rating() = 0; 
};

// Cuttie Classes to Demo the Queue
class Puppy : public Cutie {
public:
    string description() override {
        return "A little puppy with big, sad eyes";
    }

    int cuteness_rating() override {
        return 11;
    }
};

class Kitten : public Cutie {
public:
    string description() override {
        return "The fluffiest and softest kitten ever";
    }

    int cuteness_rating() override {
        return 11;
    }
};

/////////////// Queue Implementation ////////////////
class QueueTees {
private:
    Cutie* queue[100]; 
    int front;
    int rear;
    int current_size;

public:
    QueueTees() : front(0), rear(0), current_size(0) {}

    bool is_full() {
        return current_size == 100; 
    }

    bool is_empty() {
        return current_size == 0;
    }

    void enqueue(Cutie* cutie) {
        if (is_full()) {
            cout << "The queue is full! Cannot enqueue more items." << endl;
        } else {
            queue[rear] = cutie;
            rear = (rear + 1); 
            current_size++;
        }
    }

    Cutie* dequeue() {
        if (is_empty()) {
            cout << "The queue is empty! Cannot dequeue." << endl;
            return nullptr;
        } else {
            Cutie* dequeued_cutie = queue[front];
            front = (front + 1);
            current_size--;
            return dequeued_cutie;
        }
    }

    int size() {
        return current_size;
    }
};

////////////////////// Driver Program //////////////////////
int main() {

    Puppy puppy;
    Kitten kitten;

    QueueTees queue;

    // Testing queue functionalities
    cout << "Demonstration:" << endl;
    cout << "Initial queue size: " << queue.size() << endl;

    // Enqueue cuties
    cout << "Enqueuing: " << puppy.description() << endl;
    queue.enqueue(&puppy);
    cout << "Enqueuing: " << kitten.description() << endl;
    queue.enqueue(&kitten);

    cout << "Queue size after enqueue: " << queue.size() << endl;

    // Dequeue cutie demonstration
    Cutie* dequeued_cutie = queue.dequeue();

    if (dequeued_cutie) {
        cout << "Dequeued: " << dequeued_cutie->description() << endl;
    }

    cout << "Queue size after dequeue: " << queue.size() << endl;

    cout << "Note which cutie was dequeued first. This follows the FIFO principle. Program closing." << endl;

    return 0;
}