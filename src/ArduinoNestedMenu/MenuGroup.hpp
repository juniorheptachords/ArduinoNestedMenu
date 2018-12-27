// ArduinoNestedMenu
// Copyright Christophe Jourdan
// MIT License


namespace ArduinoNestedMenu {
    
/**
 * Constructor
 */
template <size_t Size>
MenuGroup::MenuGroup(Item<MenuGroup> (&items)[Size]){
  this->items = items;
  this->itemsSize = (Size);
}

}