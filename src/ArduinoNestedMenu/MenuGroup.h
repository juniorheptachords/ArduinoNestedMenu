// ArduinoNestedMenu
// Copyright Christophe Jourdan
// MIT License

#ifndef MenuGroup_h
#define MenuGroup_h

#include "Arduino.h"
#include "Menu.h"

namespace ArduinoNestedMenu {
    
/*
 * MenuGroup
 */
class MenuGroup{
  private:
    unsigned int itemsSize;
    unsigned int currentIndex=0;
    
  public:

    // Pointer to the Menu
    Menu<MenuGroup> * menuPointer;

    // A type that is function with an int as parameter
    typedef void (*functiontype)(int value);

    /**
     * Item
     */
    template <class T>
    struct Item{
      
      //text to be displayed for the item
      String text;
      
      // Function to call
      functiontype action;
      
      // Sub menu
      T * subMenuGroup;

      /**
       * Call the action of navigate to Sub menu
       */
      void doAction(int value){
        if(subMenuGroup != NULL){
          subMenuGroup->currentIndex=0;
          subMenuGroup->menuPointer->setCurrentMenuGroup(subMenuGroup);
        }else{
          action(value);
        }
      }
    };

    // List of items
    Item<MenuGroup> * items;

    template <size_t Size>
    MenuGroup(Item<MenuGroup> (&items)[Size]);

    unsigned int getCurrentIndex();
    
    String getCurrentItemText();

    String getPreviousItemText();
    
    String getNextItemText();

    unsigned int getItemsSize();

    void setItemsSize(unsigned int value);
    
    void navigatePrevious();
    
    void navigateNext();
    
    void doCurrentItemAction(int value);

    bool isCurrentItemHasSubMenu();

    void addBackItemToGroup(MenuGroup * backMenuGroup);
    
};

}

#include "MenuGroup.hpp"

#endif
