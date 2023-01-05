
#ifndef INC_04_TRY_IT_OUT_QUEUE_QUEUE_H
#define INC_04_TRY_IT_OUT_QUEUE_QUEUE_H
#include <iostream>

//each node contains data and a pointer to the next node in the list
template <class Type>
struct Node
{
    Type data;
    Node<Type> *nextNode;
};

template <class Type>
class Queue;

template <class Type>
std::ostream& operator<<(std::ostream &out, Queue<Type> &q);

template <class Type>
class Queue {

private:
    int size_; //size of list
    Node<Type>* first_;
    Node<Type>* last_;

public:
    //Constructor, sets the front and back pointer to nullptr and initializes any other additional variables
    Queue();

    //Copy Constructor, creates a deep copy of the other stack
    Queue(const Queue &other);

    //Deallocates memory by deleting all the existing nodes in the Queue
    ~Queue();

    //Adds an item to the end of the queue
    void enqueue(Type item);

    //removes an item from the front of the queue
    void dequeue();

    //returns the value of the item at the front of the queue, but does not remove it
    Type peek();

    //returns the number of items in the queue
    int size();

    //returns true if the queue is empty
    bool empty();

    //deletes the items in the list and sets the size to 0 (don't forget to delete each node using the "delete" command.
    void clear();

    //Allows the user to output the queue formatted as... item1->item2->item3->item4.
    // For example, if the queue has values 1, 2, 3, 4 with 1 at the front and 4 at the end it would return 1->2->3->4
    // It is recommended that you use recursion to accomplish this function.
    // You may use a private recursive to code the logic, then the operator would just return the results of the
    // recursive function  such as...  string recursive_str(Node<Type> *curr);
    friend std::ostream &operator<< <>(std::ostream &out, Queue<Type> &q);
//    friend std::ostream &operator<< (std::ostream &out, Queue<Type> &q);
};

//Constructor, sets the front and back pointer to nullptr and initializes any other additional variables
template <class Type>
Queue<Type>::Queue(){
    first_ = nullptr;
    last_ = nullptr;
    size_ = 0;
}

//Copy Constructor, creates a deep copy of the other stack
template <class Type>
Queue<Type>::Queue(const Queue &other){

}

//Deallocates memory by deleting all the existing nodes in the Queue
template <class Type>
Queue<Type>::~Queue(){}

//Adds an item to the end of the queue
template <class Type>
void Queue<Type>::enqueue(Type item){
    //std::cout << "Attempting to add " << item << std::endl;
    Node<Type>*newNode = new Node<Type>();
    newNode->data = item;

    //if list is empty add item.
    //set first_ & last_ to new node
    if(!first_)
    {
        this->first_ = newNode;
        this->last_ = newNode;
    }
        //if list is not empty add new node to end of queue
    else
    {
        auto lastNode = this->last_;
        lastNode->nextNode = newNode;
        this->last_ = newNode;
    }
    size_++;
}

//removes an item from the front of the queue
template <class Type>
void Queue<Type>::dequeue(){
    if(size_ > 0){
        auto nodeToDelete = this->first_;
        this->first_ = nodeToDelete->nextNode;
        delete nodeToDelete;
        size_--;
    }
    else{
        std::cout << "Attempting to delete when size of queue is = " << size_ << std::endl;
    }
}

//returns the value of the item at the front of the queue, but does not remove it
template <class Type>
Type Queue<Type>::peek(){
    if(size_ > 0){
        return this->first_->data;
    }
    else{
        throw std::out_of_range("empty list");
    }

}

//returns the number of items in the queue
template <class Type>
int Queue<Type>::size(){
    return size_;
}

//returns true if the queue is empty
template <class Type>
bool Queue<Type>::empty(){
    if(size_ == 0){
        return true;
    }
    else{
        return false;
    }
}

//deletes the items in the list and sets the size to 0 (don't forget to delete each node using the "delete" command.
template <class Type>
void Queue<Type>::clear(){
    while(!empty()){
        dequeue();
    }
}

template <class Type>
std::ostream &operator<< (std::ostream &out, Queue<Type> &q)
{
    auto currentNode = q.first_;
    while(currentNode){
        out << currentNode->data;
        if(currentNode->nextNode){
            out << "->";
        }//end if
        currentNode = currentNode->nextNode;
    }//end while
    return out;
}

#endif //INC_04_TRY_IT_OUT_QUEUE_QUEUE_H
