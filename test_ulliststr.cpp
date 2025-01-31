#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  //ou should allocate one of your ULListStr items and make calls to 
  //push_back, push_front, pop_back, pop_front, back and front
  ULListStr list; 
  list.push_back("Bella"); 
  list.push_back("was"); 
  list.push_back("here"); 
  
  list.pop_back(); 
  list.pop_front(); 
  list.pop_front(); 

  list.front();
  list.push_back("hello there"); 
  list.back(); 
  list.push_front("new front"); 
  list.front(); 

  list.pop_back();
  list.pop_back();
  list.pop_front(); 
  list.push_back("all done."); 


}
