ArduinoNestedMenu is a C++ library for Arduino.

## Features

* Multi-level menus
* Action callback on each item
* Self-contained (no external dependency)
* [MIT License](https://en.wikipedia.org/wiki/MIT_License)

## Compatibility

Currently tested only on Teensy but should work with any Arduino or C++ hardware.

## Quickstart

### Deserialization

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
```

---

Do you like this library? Please [star this project on GitHub](https://github.com/juniorheptachords/ArduinoNestedMenu/stargazers)!