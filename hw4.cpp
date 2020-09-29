
#include <iostream>
#include <string> 
#include "hw4.h"
//#include "recursive.h"
//using namespace std;

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

list_t appendHelper(list_t list, list_t secondList){
  if (list_isEmpty(list)){
    return secondList;
  }else{
    return  appendHelper(list_rest(list), list_make(list_first(list), secondList));
  }
}

list_t append(list_t first, list_t second){
  if (list_isEmpty(first) && list_isEmpty(second)) {
    return first;
  } else{
    return appendHelper(reverse(first), second);
  }
}