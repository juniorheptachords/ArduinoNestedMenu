// ArduinoNestedMenu
// Copyright Christophe Jourdan
// MIT License

#include "MenuGroup.h"

namespace ArduinoNestedMenu {
    
/**
 * Get the current item's index
 * @return int The index
 */
unsigned int MenuGroup::getCurrentIndex(){
  return this->currentIndex;
}
    
/**
 * Get the current item's text
 * @return String The text
 */
String MenuGroup::getCurrentItemText(){
  return this->items[this->currentIndex].text;
}

/**
 * Get the previous item's text
 * @return String The text
 */
String MenuGroup::getPreviousItemText(){
  if(this->currentIndex > 0){
    return this->items[this->currentIndex - 1].text;
  }
  else{
    return this->items[this->itemsSize - 1].text;
  }
}

/**
 * Get the next item's text
 * @return String The text
 */
String MenuGroup::getNextItemText(){
  if(this->currentIndex < this->itemsSize-1){
    return this->items[this->currentIndex + 1].text;
  }
  else{
    return this->items[0].text;
  }
}

/**
 * Get the items array size
 * @return Unsigned int The size
 */
unsigned int MenuGroup::getItemsSize(){
  return this->itemsSize;
}

/**
 * Set the items array size
 * @param Unsigned int The size
 */
void MenuGroup::setItemsSize(unsigned int value){
  this->itemsSize = value;
}
    
/**
 * Navigate to previous item
 */
void MenuGroup::navigatePrevious(){
  if(this->currentIndex > 0){
    this->currentIndex--;
  }else{
    this->currentIndex = this->itemsSize - 1;
  }
}

/**
 * Navigate to next item
 */
void MenuGroup::navigateNext(){
  if(this->currentIndex < this->itemsSize - 1){
    this->currentIndex++;
  }
  else{
    this->currentIndex = 0;
  }
}

/**
 * Call the action of the current item
 * @param int The direction for the value's change
 */
void MenuGroup::doCurrentItemAction(int value){ 
  this->items[this->currentIndex].doAction(value);
}

/**
 * Check wether the current item has a sub menu
 * @return bool True if has sub menu
 */
bool MenuGroup::isCurrentItemHasSubMenu(){
  if(this->items[this->currentIndex].subMenuGroup != NULL){
    return true;
  }else{
    return false;
  }
}

/**
 * Add a "Back" item to the MenuGroup at the end
 */
void MenuGroup::addBackItemToGroup(MenuGroup * backMenuGroup){
  // Put the items from the argument to the items of the menu + 1 element
  Item<MenuGroup> * tempItems = new Item<MenuGroup>[this->getItemsSize()+1];
  for(unsigned int i = 0; i < this->getItemsSize(); i++){
    tempItems[i] = this->items[i];
  }
  this->setItemsSize(this->getItemsSize()+1);

  // Set the new element to go back
  tempItems[this->getItemsSize()-1] = {"Back", {}, backMenuGroup};
  this->items = tempItems;
}

}
