#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Stack;


template <class T>
class StackNode{
private:
    StackNode<T>* next;
    T data;
public:
    friend class Stack<T>;
};

template <class T>
class Stack{
private:
    queue<T> a;
    queue<T> b;
public:
    void pop();
    T peek();
    void push(T data);
    bool isEmpty();

};

template <class T>
bool Stack<T>::isEmpty() {
    return (a.empty()&&b.empty())?: true, false;

}

template <class T>
T Stack<T>::peek(){
    if(isEmpty())
        return NULL;
    T result;
    if(b.empty()){
        while(a.size()!=1){
            b.push(a.front());
            b.pop();
        }
        result = a.front();
        b.push(a.front());
        a.pop();
    }else if(a.empty()){
        while(b.size()!=1){
            a.push(b.front());
            b.pop();
        }
        result = b.front();
        a.push(b.front());
        b.pop();
    }
    return result;
}

template <class T>
void Stack<T>::pop(){
    if(b.empty()){
        while(a.size()!=1){
            b.push(a.front());
            a.pop();
        }
        a.pop();

    }else if(a.empty()){
        while(b.size()!=1){
            b.push(a.front());
            b.pop();
        }
        b.pop();
    }
}

template <class T>
void Stack<T>::push(T data){
    if(a.empty()){
        b.push(data);
    }else if(b.empty()){
        a.push(data);
    }
}

int main() {

    Stack<int> a;
    a.push(3);
    a.push(4);
    cout<<a.peek()<<endl;//expecting 4
    a.pop();
    cout<<a.peek()<<endl;//expecting 3
    return 0;
}
