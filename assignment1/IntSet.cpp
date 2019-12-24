// FILE: IntSet.cpp - header file for IntSet class

//       Implementation file for the IntStore class
//       (See IntSet.h for documentation.)
// INVARIANT for the IntSet class:
// (1) Distinct int values of the IntSet are stored in a 1-D,
//     compile-time array whose size is IntSet::MAX_SIZE;
//     the member variable data references the array.
// (2) The distinct int value with earliest membership is stored
//     in data[0], the distinct int value with the 2nd-earliest
//     membership is stored in data[1], and so on.
//     Note: No "prior membership" information is tracked; i.e.,
//           if an int value that was previously a member (but its
//           earlier membership ended due to removal) becomes a
//           member again, the timing of its membership (relative
//           to other existing members) is the same as if that int
//           value was never a member before.
//     Note: Re-introduction of an int value that is already an
//           existing member (such as through the add operation)
//           has no effect on the "membership timing" of that int
//           value.
// (4) The # of distinct int values the IntSet currently contains
//     is stored in the member variable used.
// (5) Except when the IntSet is empty (used == 0), ALL elements
//     of data from data[0] until data[used - 1] contain relevant
//     distinct int values; i.e., all relevant distinct int values
//     appear together (no "holes" among them) starting from the
//     beginning of the data array.
// (6) We DON'T care what is stored in any of the array elements
//     from data[used] through data[IntSet::MAX_SIZE - 1].
//     Note: This applies also when the IntSet is empry (used == 0)
//           in which case we DON'T care what is stored in any of
//           the data array elements.
//     Note: A distinct int value in the IntSet can be any of the
//           values an int can represent (from the most negative
//           through 0 to the most positive), so there is no
//           particular int value that can be used to indicate an
//           irrelevant value. But there's no need for such an
//           "indicator value" since all relevant distinct int
//           values appear together starting from the beginning of
//           the data array and used (if properly initialized and
//           maintained) should tell which elements of the data
//           array are actually relevant.

#include "IntSet.h"
#include <iostream>
#include <cassert>
using namespace std;

IntSet::IntSet()
{ //initialize the private members
    used = 0;
    for(int x=0; x < MAX_SIZE; x++)
    {
        data[x]=0;
    }
}

int IntSet::size() const
{
   return used;
}


bool IntSet::isEmpty() const
{ //if array contains anything other than zero, then
  //function returns false
   for(int x=0;x<MAX_SIZE;x++)
   {
       if(data[x]>0)
        return false;
        if(data[x]<0)
            return false;
   }



   return true;
}

bool IntSet::contains(int anInt) const
{//if array contains the number user inputs
 // then function returns true
   for(int x=0; x<MAX_SIZE; x++)
   {
       if(data[x] == anInt)
        return true;
   }

   return false;
}

bool IntSet::isSubsetOf(const IntSet& otherIntSet) const
{//if invoked array is empty or if invoked array
 // has a value that in not in otherIntSet
 // function returns false and is not a subset
        for(int y=0; y<MAX_SIZE;y++)
        {
            if(otherIntSet.contains(data[y])== false)
                return false;
        }
           if(data[0] == 0 &&
                data[MAX_SIZE-1] == 0 &&
                data[MAX_SIZE-2] == 0 &&
                data[MAX_SIZE-3] == 0 &&
                data[MAX_SIZE-4] == 0 &&
                data[MAX_SIZE-5] == 0 &&
                data[MAX_SIZE-6] == 0 &&
                data[MAX_SIZE-7] == 0 &&
                data[MAX_SIZE-8] == 0 &&
                data[MAX_SIZE-9] == 0 )
                return true;


   return true;
}

void IntSet::DumpData(ostream& out) const
{//displays array
   if (used > 0)
   {
      out << data[0];
      for (int i = 1; i < used; ++i)
         out << "  " << data[i];
   }
}

IntSet IntSet::unionWith(const IntSet& otherIntSet) const
{// copies invoked array to a new object's array
 // then if the otherIntSet array contains a
 // value that is not in that array it gets added
 // to it then returns that object
    IntSet unionW;
   for(int x=0; x<MAX_SIZE;x++)
            {
                unionW.data[x] = data[x];
                unionW.used = used;
            }
    int usize = 0; //to find the number of values the sets have in common
    int actsize = 0; //to hold

    for(int x=0; x<MAX_SIZE;x++)
    {
        if(contains(otherIntSet.data[x])== true)
        {
            ++usize;
        }
    }

     actsize = otherIntSet.used - usize;


     if((size() + actsize) <= MAX_SIZE)
          {


                  for(int z=0; z<MAX_SIZE;z++)

               {
                   if(contains(otherIntSet.data[z])== false)
                        {
                             unionW.add(otherIntSet.data[z]);

                        }

                }




          }

    else
    {
        cout<<endl<<"Not enough room to fit all elements from both sets into one single set!"<<endl;

    }

   return unionW;
}

IntSet IntSet::intersect(const IntSet& otherIntSet) const
{//if the otherIntSet's array contains the invoked value
 // in th array it is recored to a new object's array
 // providing a set with only the intersected values
    IntSet intersec;

    for(int x=0; x<MAX_SIZE;x++)
            {
                intersec.data[x] = data[x];
                intersec.used = used;
            }

        for(int x=0;x<MAX_SIZE;x++)
        {
            if(otherIntSet.contains(data[x])== false)
            {
                intersec.remove(data[x]);
            }

        }

   return intersec;
}

IntSet IntSet::subtract(const IntSet& otherIntSet) const
{//if the otherIntSet array does not contain the invoking value
 //questioned than it is recored in the new objects array and returned
    IntSet subT;

    for(int x=0; x<MAX_SIZE;x++)
            {
                subT.data[x] = data[x];
                subT.used = used;
            }

    for(int x=0;x<MAX_SIZE;x++)
        {
            if(contains(otherIntSet.data[x])== true)
            {
                subT.remove(otherIntSet.data[x]);
            }

        }

   return subT;
}

void IntSet::reset()
{//private members get re-initialized
    for(int x=0; x<MAX_SIZE;x++)
     {
         data[x]=0;

     }
    used = 0;
}

bool IntSet::add(int anInt)
{//if a space is opened then the user entered value gets added to
//the array and returns true
    for(int x=0; x < MAX_SIZE; x++)
    {
        if(data[x]==0)
        {
            data[x]= anInt;
            ++used;
            return true;
        }

    }

    return false;
}

bool IntSet::remove(int anInt)
{ //if the array has the value the user
 //entered then that value gets removed from
 //the array
    for(int x=0;x<MAX_SIZE;x++)
    {
        if(data[x]==anInt)
        {
         data[x]=0;


         return true;
        }
    }


   return false;
}

bool equal(const IntSet& is1, const IntSet& is2)
{//if the two sets are subsets of each other then they are equal
    if(is1.isSubsetOf(is2) == true && is2.isSubsetOf(is1)== true)
        return true;

    return false;

}

