#pragma once
 
#include <SFML/Window/Joystick.hpp>
 
enum class GamepadType {
    Xbox,
    PlayStation,
    Unknown
};
 
struct AxisMapping {
    sf::Joystick::Axis leftStickX;
    sf::Joystick::Axis leftStickY;
    sf::Joystick::Axis rightStickX;
    sf::Joystick::Axis rightStickY;
    sf::Joystick::Axis leftTriggerAxis;
    sf::Joystick::Axis rightTriggerAxis;
    
    bool triggersShareAxis;
    
    int LeftBumper;
    int RightBumper;
    
    int start;
    
    int A;
    int B;
    int Y;
    int X;
};
 
class GamepadUtils {
public:
    static GamepadType detectGamepadType(unsigned int joystickId = 0);

    static AxisMapping getMapping(unsigned int joystickId = 0);

    static AxisMapping getMappingFor(GamepadType type);
    
    static float getTriggerValue(unsigned int joystickId, const AxisMapping& mapping, bool isLeftTrigger);
};