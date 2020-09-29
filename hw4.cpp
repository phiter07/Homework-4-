/****
* PSEUDOCODE:
***** -------------------------------------- *****
* static int sumHelper(list, sum)
*  if (list is Empty)
*    return sum
*  else
*    sum = sum + list first
*    return sumHelper
* 
* int sum (list)
*  if (list is Empty)
*    return 0
*  else 
*    return sumHelper
***** -------------------------------------- *****
* static int productHelper (list, product)
*  if (list is Empty)
*    return product;
*  else 
*    product = product * list first
*    return productHelper
*
* int product (list)
*  if (list is Empty)
*    return 1
*  else
*    return productHelper (list, 1)
***** -------------------------------------- *****
* int accumulate (list, *function, int, base)
*  if (list is Empty)
*    return base
*  else
*    return accumulate
***** -------------------------------------- *****
* list_t reverseHelper(list, newlist)
*  if(if list is Empty)
*    return newlist
*  else
*  return reverseHelper
*
* list_t reverse (list)
*  if (list is Empty)
*    return list
*  else
*    return reverseHelper
***** -------------------------------------- *****
* list_t appendHelper (list, secondList)
*  if (list is Empty)
*    return secondList
*  else
*    return appendHelper
* 
* list_t append (first, second)
*  if (list is Empty(first) ** list is Empty(second))
*    return first
*  else
*    return appendHelper
***** -------------------------------------- *****
* list fiter_oddHelper(list, newlist)
*  if (list is Empty)
*    newlist = reverse(newlist)
*    return newlist
*  else if
*    return filter_oddrHelper (list, make(list, newlist)
*  else
*    return filter_oddHelper (list, newlist)
* 
* list_t filter_odd (list)
*  if (list is Empty)
*    return list
*  else
*    return filter_oddHelper(list, make)
***** -------------------------------------- *****
* list fiter_evenHelper(list, newlist)
*  if (list is Empty)
*    newlist = reverse(newlist)
*    return newlist
*  else if
*    return filter_evenHelper (list, make(list, newlist)
*  else
*    return filter_evenHelper (list, newlist)
* 
* list_t filter_even (list)
*  if (list is Empty)
*    return list
*  else
*    return filter_evenHelper(list, make)
***** -------------------------------------- *****
* list_t filter(list, bool *fn int)
*  returns a list = to original for which evaluates
*  to true
***** -------------------------------------- *****
* list_t rotate(list, n)
*  returns a list = to original with first element
*  moved to end of list n times
***** -------------------------------------- *****
* list_t insert_list(first, second, n)
*  n <= number of elements in first
*  returns list comprising first n elements
***** -------------------------------------- *****
* list_t chop(l, n)
*  l has least elements
*  returns list equal to l without last n elements
***** -------------------------------------- *****
* int fib (n)
*  if (n <= 1)
*    return n
*    return fib(n-1) + fib(n-2)
*
* fib_tailHelper(a, b, n)
*  if (n > 0)
*   return fib_tailHelper(b, a+b, n-1)
*  else
*   return a
*
* fib_tail (n)
*  return fib_tailHelper(0, 1, n)
*
***** -------------------------------------- *****
****/

#include <iostream>
#include <string> 
#include "hw4.h"
#include "recursive.h"

using namespace std;

static int sumHelper (list_t list, int sum) {
  if (list_isEmpty(list))
    return sum;
  else {
    sum += list_first(list);
    return sumHelper(list_rest(list), sum);
  }   
}

int sum(list_t list) {
  if (list_isEmpty(list))
    return 0;
  else 
  return sumHelper(list, 0);
    /*
    // EFFECTS: returns the sum of each element in list
    //     zero if the list is empty.
    */
}

static int productHelper(list_t list, int product) {
  if(list_isEmpty(list))
    return product;
  else {
    product *= list_first(list);
    return productHelper(list_rest(list), product);
  }
}

int product (list_t list) {
  if(list_isEmpty(list))
    return 1;
  else 
    return productHelper(list, 1);
}

int accumulate(list_t list, int (*fn) (int, int), int base) {
  if (list_isEmpty(list)) 
    return base;
  else 
    return accumulate(list_rest(list), fn, fn(base, list_first(list)));
}

list_t reverseHelper(list_t list, list_t newlist) {
  if(list_isEmpty(list))
    return newlist;
  else
    return reverseHelper(list_rest(list), list_make(list_first(list), newlist));
}

list_t reverse(list_t list) {
  if(list_isEmpty(list)) 
    return list;
  else
    return reverseHelper(list, list_make());
}

list_t appendHelper(list_t list, list_t secondList) {
  if (list_isEmpty(list)){
    return secondList;
  }else{
    return  appendHelper(list_rest(list), list_make(list_first(list), secondList));
  }
}

list_t append(list_t first, list_t second) {
  if (list_isEmpty(first) && list_isEmpty(second)) {
    return first;
  } else{
    return appendHelper(reverse(first), second);
  }
}

 list_t filter_oddHelper(list_t list, list_t newlist) {
  if(list_isEmpty(list)){
    newlist = reverse(newlist);
    return newlist;
  } 
  else if(list_first(list) % 2 != 0) {
    return filter_oddHelper(list_rest(list), list_make(list_first(list), newlist));
  }
  else{
   return filter_oddHelper(list_rest(list), newlist);
  }
}

list_t filter_odd(list_t list) {
  if(list_isEmpty(list)){
    return list;
  } else{
    return filter_oddHelper(list, list_make());
  }
}

 list_t filter_evenHelper(list_t list, list_t newlist){
  if(list_isEmpty(list)){
    newlist = reverse(newlist);
    return newlist;
  } 
  else if(list_first(list) % 2 == 0) {
    return filter_evenHelper(list_rest(list), list_make(list_first(list), newlist));
  }
  else{
   return filter_evenHelper(list_rest(list), newlist);
  }
}

list_t filter_even(list_t list) {
  if(list_isEmpty(list)){
    return list;
  } else{
    return filter_evenHelper(list, list_make());
  }
}


int fib(int n) {
  if (n <= 1) 
    return n; 
    return fib(n-1) + fib(n-2);
}

int FibTailHelper(int a, int b, int n) {
  if(n > 0)
    return FibTailHelper(b, a+b, n-1);
  else
    return a;
}

int fib_tail(int n) {
  return FibTailHelper(0, 1, n);
}

