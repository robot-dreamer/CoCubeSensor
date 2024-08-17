/**
 * @file CoCubeSensor.h
 * @author Liang Shuai (sliang23@m.fudan.edu.com)
 * @brief CoCube Sensor Library for MicroBlocks
 * @version 0.3
 * @date 2024-08-17
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <Arduino.h>

class CoCubeSensor {
   public:
    CoCubeSensor();

// Sensor
    void Init();
    void Update();
    int GetX();
    int GetY();
    int GetAngle();
    int GetIndex();
    bool GetState();

// Encoder
   public:
    void EncoderUpdate();
    static void LeftEncoderCountCallback();
    static void RightEncoderCountCallback();
    float GetSpeedLeft();
    float GetSpeedRight();

   private:
    unsigned short left_speed_;
    unsigned short right_speed_;

    float encoder_to_dis_;
    unsigned long curr_time_;
    unsigned long last_time_;
    unsigned long last_left_encoder_;
    unsigned long last_right_encoder_;

    static unsigned long curr_left_encoder_;
    static unsigned long curr_right_encoder_;

// Speed Correcting
   public:
    void SpeedCorrecting(unsigned char start_x, unsigned char start_y, unsigned char end_x, unsigned char end_y);
    unsigned short GetLeftCorrecting();
    unsigned short GetRightCorrecting();
   
   private:
    float velocity_left;
    float velocity_right;
};