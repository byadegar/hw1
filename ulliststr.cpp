#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val) {
    if (tail_ == nullptr || tail_->last == ARRSIZE){//tail node null means empty list or last == arrsize means full list
      Item *itemToPush = new Item(); //creating new node to push if there isn't a place to put the value
      
      if (tail_ != nullptr){
        tail_->next = itemToPush; //link new node to cur tail 
        itemToPush->prev = tail_; // linked to old tail
      }
    else 
      {
        head_ = itemToPush; //head points to new node if was empty before (becomes new head)
      }
      tail_ = itemToPush; //new tail is the one being pushed
      tail_->val[0] = val; //value coming into function
      tail_->first = 0; //set first 
      tail_->last = 1; //shows last item occupied
    } 
    else{ //this is if the tail has space anyway you can just put the value
      tail_->val[tail_->last] =val; 
      tail_->last++; 
    }
    size_++; //size increased by 1
  }

  //push front  - copy style of push back and go from there
    /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val) {
    if (head_ == nullptr || head_->first ==0){
      //you need a new node to put 
      Item *itemToPush = new Item(); 
      itemToPush -> next = head_; // link the new node 
      if (head_ != nullptr){
        head_->prev = itemToPush; 
      }
      else {
        tail_ = itemToPush; //do i need
      }
      head_= itemToPush; 
      head_->first = ARRSIZE -1; 
      head_->last = ARRSIZE;  // need to make sure that you have the space when new nodes are added
      head_->val[head_->first] = val; //add new value to array
    }
    else {
      head_->first--; //first index change
      head_->val[head_->first] = val; //new value onto array
    }
    size_++; //adding on to size 
  }

  //pop back 
    /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back() {
    if (tail_ == nullptr){ //empty
      return; //nothing to pop 
    }
    tail_->last = tail_->last-1; // 
    size_--; //decremernt size bc first is kinda gone now, its smaller
    if (tail_->last == tail_->first){ //empty tail node - deallocate
      Item* temp = tail_; //temp to be deleted 
      tail_ = tail_->prev; //go to previous
      if (tail_ != nullptr){ //exists
        tail_->next = nullptr; //so keep going
      }
      else {
        head_ = nullptr; //empty list now
      }
      delete temp; //deallocate 
    }
    
  }

  //pop front 
    /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front() {
    if (head_ == nullptr){ //empty
      return; 
    }
    head_->first = head_->first+1; // change first to second hypothetically
    size_--; //decremernt size bc first is kinda gone now, its smaller
    if (head_->first == head_->last){ //empty head node/empty list
      Item* temp = head_; //temp to store it
      head_ = head_->next; //go to next 
      if (head_ != nullptr){ //new head node exists?
        head_->prev = nullptr; //new first node
      }
      else {
        tail_ = nullptr; //empty list now
      }
      delete temp; //deallocate 
    }
  }

    /**video said don't need to check for null/weird ones
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const {
    return tail_->val[tail_->last-1]; 
  }

    /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const {
    return head_->val[head_->first]; 
  }

    /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const {
    if (loc >= size_ || head_ == nullptr){
      return nullptr; //doesn't exist (not valid)
    }
    Item* current = head_; //starting at head node
    while (current != nullptr){
      size_t items = current->last - current->first; //# elements in node

      if (loc < items){
        return &current->val[current->first + loc]; // current index
      }
      loc -= items; // if not in there, move on to look at remaining
      current = current->next; //move to next node 
    }
    return nullptr; //function needs to return value regardless 
    //whenever you have a return type, you can't only have returns in ifs
  }

