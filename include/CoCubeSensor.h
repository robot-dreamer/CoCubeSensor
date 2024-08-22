/**
 * @file CoCubeSensor.h
 * @author Liang Shuai (sliang23@m.fudan.edu.com)
 * @brief CoCube Sensor Library for MicroBlocks
 * @version 0.4
 * @date 2024-08-22
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <Arduino.h>

class CoCubeSensor {
   public:
// Sensor Init and Update
    void Init();

// Position Sensor
    void Update();
    int GetX();
    int GetY();
    int GetAngle();
    int GetIndex();
    bool GetState();

// Encoder
    void EncoderUpdate();
    float GetSpeedLeft();
    float GetSpeedRight();
};