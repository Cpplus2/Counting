#ifndef STACK_H
#define STACK_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class FullStack
{
    private: string message;

    public:
        FullStack()
        {
            message = "Stack Full!";
        }
        string getMessage()
        {
            return message;
        }
};

class EmptyStack
{
    private: string message;

    public:
        EmptyStack()
        {
            message = "Stack Empty!";
        }
        string getMessage()
        {
            return message;
        }
};

template<class ItemType>
class Stack
{
    private:
        int maxStack;
        int top;
        ItemType* items;

    public:
        Stack(int);
        Stack();
        ~Stack();
        bool IsEmpty() const;
        bool IsFull() const;
        bool LastItem() const;
        void Push(ItemType);
        void Pop();
        ItemType Top();
};

#include "Stack.cpp"

#endif // STACK_H

