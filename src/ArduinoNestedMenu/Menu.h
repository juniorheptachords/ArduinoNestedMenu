// ArduinoNestedMenu
// Copyright Christophe Jourdan
// MIT License

#ifndef Menu_h
#define Menu_h

#include "Arduino.h"

namespace ArduinoNestedMenu {
    
/*
 * Menu
 */
template <class T>
class Menu{
  private:
    T * currentMenuGroup;
    bool currentlyEditing;

    /**
     * Set the Menu pointer in all the MenuGroup to this menu recursively
     * @param Menugroup The first MenuGroup to start from
     */
    void setAllMenuGroupMenuPointer(T * menuGroup){
      menuGroup->menuPointer = this;
      for(unsigned int i = 0; i < menuGroup->getItemsSize(); i++){
        if(menuGroup->items[i].subMenuGroup != NULL){
          setAllMenuGroupMenuPointer(menuGroup->items[i].subMenuGroup);
        }
      }
    }
    
    /**
     * Add a Back item to every nested MenuGroup
     * @param Menugroup The first MenuGroup to start from
     */
    void setAllBackItems(T * menuGroup, T * backMenuGroup){
      bool addBackItem = true;
      
      if(menuGroup == NULL){
        menuGroup = this->currentMenuGroup;
        addBackItem = false;
      }
      
      for(unsigned int i = 0; i < menuGroup->getItemsSize(); i++){
        if(menuGroup->items[i].subMenuGroup != NULL){
          setAllBackItems(menuGroup->items[i].subMenuGroup, menuGroup);
        }
      }
      
      if(addBackItem && backMenuGroup != NULL){
        menuGroup->addBackItemToGroup(backMenuGroup);
      }
    }
    
  public:

    /**
     * Constructor
     */
    Menu(T * menuGroup){
      this->currentMenuGroup = menuGroup;

      // Set the Menu pointer in all the MenuGroup to this menu recursively
      setAllMenuGroupMenuPointer(this->currentMenuGroup);

      setAllBackItems(NULL, NULL);
    }

    unsigned int getCurrentIndex(){
      return this->currentMenuGroup->getCurrentIndex();
    }
    
    /**
     * Get the current item's text
     * @return String The text
     */
    String getCurrentItemText(){
      return this->currentMenuGroup->getCurrentItemText();
    }
    
    /**
     * Get the previous item's text
     * @return String The text
     */
    String getPreviousItemText(){
      return this->currentMenuGroup->getPreviousItemText();
    }
    
    /**
     * Get the next item's text
     * @return String The text
     */
    String getNextItemText(){
      return this->currentMenuGroup->getNextItemText();
    }

    /**
     * Set the current MenuGroup
     * @param MenuGroup The MenuGroup
     */
    void setCurrentMenuGroup(T * menuGroup){
      this->currentMenuGroup = menuGroup;
    }
    
    /**
     * Navigate to previous item
     */
    void navigatePrevious(){
      this->currentMenuGroup->navigatePrevious();
    }

    /**
     * Navigate to next item
     */
    void navigateNext(){
      this->currentMenuGroup->navigateNext();
    }
    
    /**
     * Call the action of the current item
     * @param int The direction for the value's change
     */
    void doCurrentItemAction(int value){ 
      this->currentMenuGroup->doCurrentItemAction(value);
    }

    /*void setCurrentlyEditing(bool currentlyEditing){
      this->currentlyEditing = currentlyEditing;
    }
    
    bool isCurrentlyEditing(){
      return this->currentlyEditing;
    }
*/

    /**
     * Check wether the current Item has a sub menu
     * @return bool True if the current Item has a sub menu
     */
    bool isCurrentItemHasSubMenu(){
      return this->currentMenuGroup->isCurrentItemHasSubMenu();
    }


    
};

}

#endif
