#include "cnPtrQueue.h"
#include <cassert>
#include "nodes_LLoLL.h"
using namespace std;

namespace CS3358_SSII2019_A5P1
{

cnPtrQueue::cnPtrQueue():numItems(0){}

bool cnPtrQueue::empty() const
      {
        return outStack.empty()&&inStack.empty();
      }
   // returns # of items in queue
size_t cnPtrQueue::size() const
      {
         return numItems;
      }
CNode* cnPtrQueue::front()
      {
        assert(!inStack.empty()||!outStack.empty());
        if(outStack.empty())
        {
            while(!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
      }
void cnPtrQueue::push(CNode* cnPtr)
      {
        inStack.push(cnPtr);
      }
void cnPtrQueue::pop()
      {
        assert(!inStack.empty() || !outStack.empty());
        if(outStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
        outStack.pop();
      }


}

