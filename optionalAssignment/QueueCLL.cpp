// FILE: QueueCLL.cpp
// IMPLEMENTS: QueueCLL (see QueueCLL.h for documentation.)
//
// INVARIANT for the QueueCLL class:
//   1. The number of items in the QueueCLL is stored in the member
//      variable numItems.
//   2. The items themselves are stored in a circular linked list
//      of Nodes.
//      2.1 The member variable rear_ptr points to the rear of the
//          QueueCLL (tail node of the circular linked list).
//          heap[0] through heap[used - 1].
//      2.2 The rear_ptr is set to the null address if the circular
//          linked list (thus queue) is empty.

#include <iostream>
#include <cassert>  // provides assert
#include <cstdlib>  // provides size_t
using namespace std;

#include "QueueCLL.h"

QueueCLL::QueueCLL():numItems(0)
{
    rear_ptr = new Node;
    rear_ptr = 0;
}

QueueCLL::QueueCLL(const QueueCLL& src) : numItems(src.numItems)
{
    rear_ptr = new Node;
    rear_ptr = 0;
    numItems = 0;

    if(src.rear_ptr==0)
        rear_ptr=0;
    else
    {
        Node *temp = new Node;
            temp = src.rear_ptr->link;
        while (temp != src.rear_ptr)
        {
            push(temp->data);
            temp = temp->link;
        }

            rear_ptr = temp;
            delete temp;



}
}

QueueCLL::~QueueCLL()
{
   delete rear_ptr;
}

QueueCLL& QueueCLL::operator=(const QueueCLL& rhs)
{
    rear_ptr=new Node;
   if(this != &rhs)
    {
        Node *temp = new Node;


            temp = rhs.rear_ptr->link;
        while (temp != rhs.rear_ptr)
        {
            push(temp->data);
            temp = temp->link;
        }


            delete rear_ptr;

            rear_ptr = temp;

            numItems = rhs.numItems;
            delete temp;


    }
   return *this;
}

void QueueCLL::push(const value_type& entry)
{
   Node *newPtrNode = new Node;
   newPtrNode->data=entry;
   newPtrNode->link=newPtrNode;

   if(rear_ptr==0)
   {
       rear_ptr=newPtrNode;
       rear_ptr->link=newPtrNode;
       ++numItems;

   }
   else
   {
       newPtrNode->link=rear_ptr->link;
       rear_ptr->link=newPtrNode;
       rear_ptr=newPtrNode;
       ++numItems;

   }
}

QueueCLL::value_type QueueCLL::front( ) const
{
   assert(size() > 0);

   return rear_ptr->link->data;
}

void QueueCLL::pop( )
{
    assert(size() > 0);

    Node *temp = new Node;

    if(numItems==1)
    {
        temp=rear_ptr->link;
        rear_ptr=0;
        delete temp;
        --numItems;
    }
    else
    {
        temp = rear_ptr->link;
        rear_ptr->link = rear_ptr->link->link;
        delete temp;
        --numItems;
    }

}

QueueCLL::size_type QueueCLL::size() const
{
   return numItems;
}

bool QueueCLL::empty() const
{
   if(numItems==0)
    return true;
   else
    return false;
}

QueueCLL::value_type QueueCLL::peek(size_type n) const
{
    assert(size() > 0);
    assert(n>0);

    Node *cursor = new Node;

    for(size_type i=1; i<=n; ++i)
    {
        cursor=rear_ptr->link;
        cursor->data= rear_ptr->link->data;
        rear_ptr->link=rear_ptr->link->link;
    }
    int data = cursor->data;

    delete cursor;

    return data;
}
