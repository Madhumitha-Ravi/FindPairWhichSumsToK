/*Given a sorted array - Find a pair which will sum to K
If found return the tuple else give none found 
The paired elements should not be of the same inde*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Pair
{
  int Element1;
  int Element2;
  bool bFoundPair;
  Pair()
  {
    Element1 =0;
    Element2 = 0;
    bFoundPair = false;
  }
};
// First will be the brute force technique
int FindPair(int InputArray[],int nSize,int sum,Pair &pairedElements)
{
  // For a given array - iterate each element through the entire array and sum it with each other element , if the elements paired matches the sum add it to the structure and return the pair
  for (int i=0;i<nSize;i++)
  {
    for(int j=0;j<nSize;j++)
    {
      if(i == j)
      {
        continue;
      }
      if((InputArray[i]+InputArray[j]) == sum)
      {
        pairedElements.Element1 = InputArray[i];
        pairedElements.Element2 = InputArray[j];
        pairedElements.bFoundPair = true;
        return 1;
      }
    }
  }
  return 0;
  // This of TimeComplexity of O(n^2)
  // I think this is a space complexity of O(1) bcoz we are doing an assignment thrice - 2 for elements 1 for bool - O(3) - Since it is constant - we get O(1)
}
// What might be the optimized method
// We can avoid 2 nested loops
int OptimizedFindPair(int InputArray[],int nSize,int nSum,Pair &stPairedElements)
{
  map<int,int> ComplementElement;
  map<int,int>::iterator itr;
  for(int i =0; i<nSize;i++)
  {
    
    if ( (itr =ComplementElement.find(InputArray[i])) != ComplementElement.end())
    {
        stPairedElements.Element1 = InputArray[i];
        stPairedElements.Element2 = itr->second;
        stPairedElements.bFoundPair = true;
        return 1;
    }
    ComplementElement.insert({(nSum-InputArray[i]),InputArray[i]});
     
  }

  return 0;
  // Time Complexity O(n).
  // Space Complexity O(n).
}

int OptimizedFindPairUsingSet(int InputArray[],int nSize,int nSum,Pair &stPairedElements)
{
  unordered_set<int> ComplementElement;
  int nComp = 0;
  for(int i =0; i<nSize;i++)
  {
    nComp = nSum - InputArray[i];
    if ( (ComplementElement.find(InputArray[i])) != ComplementElement.end())
    {
        stPairedElements.Element1 = InputArray[i];
        stPairedElements.Element2 = nComp;
        stPairedElements.bFoundPair = true;
        return 1;
    }
    ComplementElement.insert(nComp);
     
  }

  return 0;
  // Time Complexity O(n).
  // Space Complexity O(n).
}

int main() {
  int Array[] = {1,4,3,5};
  int nSum = 8;
  int nSize = sizeof(Array)/sizeof(Array[0]);
  Pair stPair;
  //FindPair(Array,nSize,nSum,stPair);
 // OptimizedFindPair(Array,nSize,nSum ,stPair);
 OptimizedFindPairUsingSet(Array,nSize,nSum,stPair);
  if(stPair.bFoundPair)
  {
    cout<<"Paired Element : ( "<<stPair.Element1<<" , "<<stPair.Element2<<" )"<<endl;
  }
  else
  {
    cout<<"Unable to find a pair which sums to "<<nSum<<endl;
  }

}
