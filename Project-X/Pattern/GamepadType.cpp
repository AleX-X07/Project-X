#include "GamepadType.h"

#include <SFML/Audio/Listener.hpp>

GamepadType GamepadUtils::detectGamepadType(unsigned int joystickId) {
    if (!sf::Joystick::isConnected(joystickId)) {
        return GamepadType::Unknown;
    }
 
    sf::Joystick::Identification id = sf::Joystick::getIdentification(joystickId);
    
    if (id.vendorId == 0x045E) {
        return GamepadType::Xbox;
    }
    
    if (id.vendorId == 0x054C) {
        return GamepadType::PlayStation;
    }
 
    return GamepadType::Unknown;
}
 

AxisMapping GamepadUtils::getMappingFor(GamepadType type) {
    switch (type)
    {
    case GamepadType::Xbox:
        return AxisMapping{
            sf::Joystick::Axis::X, sf::Joystick::Axis::Y,
            sf::Joystick::Axis::U, sf::Joystick::Axis::V,
            sf::Joystick::Axis::Z, sf::Joystick::Axis::Z,
            true, 4, 5, 7
        };
 
    case GamepadType::PlayStation:
        return AxisMapping{
            sf::Joystick::Axis::X, sf::Joystick::Axis::Y,
            sf::Joystick::Axis::Z, sf::Joystick::Axis::R,
            sf::Joystick::Axis::U, sf::Joystick::Axis::V,
            false, 4, 5, 8
        };
 
    case GamepadType::Unknown:
    default:
        return AxisMapping{
            sf::Joystick::Axis::X, sf::Joystick::Axis::Y,
            sf::Joystick::Axis::U, sf::Joystick::Axis::V,
            sf::Joystick::Axis::Z, sf::Joystick::Axis::Z,
            true, 4, 5, 7
        };
    }
}

AxisMapping GamepadUtils::getMapping(unsigned int joystickId) {
    return getMappingFor(detectGamepadType(joystickId));
}

float GamepadUtils::getTriggerValue(unsigned int joystickId, const AxisMapping& mapping, bool isLeftTrigger) {
    if (mapping.triggersShareAxis)
    {
        float raw = sf::Joystick::getAxisPosition(joystickId, mapping.leftTriggerAxis);
        
        if (isLeftTrigger)
        {
            return raw > 0.f ? raw : 0.f;
        }
        return raw < 0.f ? -raw : 0.f;
    }

    sf::Joystick::Axis axis = isLeftTrigger ? mapping.leftTriggerAxis : mapping.rightTriggerAxis;
    float raw = sf::Joystick::getAxisPosition(joystickId, axis);
    
    return (raw + 100.f) / 2.f;
}