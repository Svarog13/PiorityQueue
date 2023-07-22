#include <iostream>

template <typename T>
class Queue
{
private:
    class Node
    {
    public:
        T value;
        Node* ptr;
        Node(T value, Node* ptr = nullptr) : value{ value }, ptr{ ptr } {}
    };

    int size;
    Node* first;
    Node* last;

public:
    Queue() : size{ 0 }, first{ nullptr }, last{ nullptr } {}

    int getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return (size == 0);
    }

    bool isFull() const
    {
     
        return (size >= 100);
    }

    T top() const
    {
        if (size > 0)
        {
            return first->value;
        }
        throw std::out_of_range("Queue out of range");
    }

    void InsertWithPriority(T value)
    {
        Node* newNode = new Node(value);

        if (isEmpty() || value > first->value)
        {
            newNode->ptr = first;
            first = newNode;
        }
        else
        {
            Node* current = first;
            while (current->ptr && value <= current->ptr->value)
            {
                current = current->ptr;
            }
            newNode->ptr = current->ptr;
            current->ptr = newNode;
        }
        size++;
    }

    T PullHighestPriorityElement()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }

        T highestPriorityValue = first->value;
        Node* temp = first;
        first = first->ptr;
        delete temp;
        size--;
        return highestPriorityValue;
    }

    T Peek() const
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty");
        }

        return first->value;
    }

    void Show() const
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }

        std::cout << "Elements of the queue with priorities:" << std::endl;
        Node* current = first;
        while (current)
        {
            std::cout << "Value: " << current->value << ", Priority: " << current->value << std::endl;
            current = current->ptr;
        }
    }
};

int main()
{
    Queue<int> priorityQueue;

    priorityQueue.InsertWithPriority(30);
    priorityQueue.InsertWithPriority(10);
    priorityQueue.InsertWithPriority(50);
    priorityQueue.InsertWithPriority(20);

    priorityQueue.Show();

    int highestPriorityValue = priorityQueue.PullHighestPriorityElement();
    std::cout << "Pulled highest priority element: " << highestPriorityValue << std::endl;

    int topPriorityValue = priorityQueue.Peek();
    std::cout << "Top priority element: " << topPriorityValue << std::endl;

    return 0;
}