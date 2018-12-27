ArduinoNestedMenu is a C++ library for Arduino.

## Features

* Multi-level menus
* Action callback on each item
* Self-contained (no external dependency)
* [MIT License](https://en.wikipedia.org/wiki/MIT_License)

## Compatibility

Currently tested only on Teensy but should work with any Arduino or C++ hardware.

## Quickstart

Here is an example of a 3 level menu.

```c++
// Livingroom lamps Menu
MenuGroup::Item<MenuGroup> livingroomLampsItems[3] = {
  {"Big lamp", LivingroomController::updateBrighthnessBigLamp},
  {"Sofa lamp", LivingroomController::updateBrighthnessSofaLamp},
};
MenuGroup livingroomLampsMenuGroup(livingroomLampsItems);

// Livingroom menu
MenuGroup::Item<MenuGroup> livingroomItems[3] = {
  {"Lamps", {}, &livingroomLampsMenuGroup},
  {"Temperature", LivingroomController::updateTemperature},
  {"Music", LivingroomController::updateMusic},
};
MenuGroup livingroomMenuGroup(livingroomItems);

// Bedroom menu
MenuGroup::Item<MenuGroup> bedroomMenuItems[2] = {
  {"Big lamp", {BedroomController::updateBrigthnessBigLamp}},
  {"Bed lamp", {BedroomController::updateBrigthnessBedLamp},
};

MenuGroup bedroomMenuGroup(bedroomMenuItems);

// Main menu
MenuGroup::Item<MenuGroup> mainItems[3] = {
  {"Bedroom", {}, &bedroomMenuGroup},
  {"Livingroom", {}, &livingroomMenuGroup},
};
       
MenuGroup mainMenuGroup(mainItems);
                                                  
Menu<MenuGroup> mainMenu(&mainMenuGroup);
```

The logic using this menu to navigate is not part of the library and is intended to be in the project itself because it all depends on the type of inputs and outputs used (rotary encoder, potentiometer, buttons, oled display, lcd display, serial logging, ...).

## How to use

Here are the methods provided by the Menu object.

### getCurrentIndex()
Get the current item's index.

### getPreviousItemText()
Get the previous item's text.

### getCurrentItemText()
Get the current item's text.  

### getNextItemText()
Get the next item's text.  

### navigatePrevious()
Navigate to previous item.  

### navigateNext()
Navigate to next item.  

### doCurrentItemAction(int value)
Call the action of the current item.

### isCurrentItemHasSubMenu()
Check wether the current Item has a sub menu.



---

Do you like this library? Please [star this project on GitHub](https://github.com/juniorheptachords/ArduinoNestedMenu/stargazers)!