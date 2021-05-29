#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

template<class ItemType>
Stack<ItemType>::Stack()
{
    maxStack = 500;
    top = -1;
    items = new ItemType[maxStack];
}

template<class ItemType>
Stack<ItemType>::Stack(int maximum)
{
    maxStack = maximum;
    top = -1;
    items = new ItemType[maxStack];
}

template<class ItemType>
bool Stack<ItemType>::IsEmpty() const
{
    return (top == -1);
}


template<class ItemType>
bool Stack<ItemType>::IsFull() const
{
    return (top == (maxStack-1) );
}


template<class ItemType>
void Stack<ItemType>::Push(ItemType newItem)
{
    if(IsFull())
        throw FullStack();

    items[++top] = newItem;
}


template<class ItemType>
void Stack<ItemType>::Pop()
{
    if(IsEmpty())
        throw EmptyStack();

    top--;
}


template<class ItemType>
ItemType Stack<ItemType>::Top()
{
    if(IsEmpty())
        throw EmptyStack();

    return items[top];
}

template<class ItemType>
bool Stack<ItemType>::LastItem() const
{
    return (items[top] == NULL);
}

template<class ItemType>
Stack<ItemType>::~Stack()
{
    delete [] items;
}

#endif // STACK_CPP
