/**
 * @file CoCubeSensor.h
 * @author Liang Shuai (sliang23@m.fudan.edu.com)
 * @brief CoCube Position Sensor Library for MicroBlocks
 * @version 0.2
 * @date 2024-07-15
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <Arduino.h>
#include <pthread.h>

class CoCubeSensor {
   public:
    CoCubeSensor();

    void Init();
    void Update();
    void Release();
    int GetX();
    int GetY();
    int GetAngle();

   private:
    unsigned char PowerOn();
    unsigned char DecoderInit();
    unsigned char CheckReadData();
    unsigned char ReceiveData(unsigned short *rec_data);
    void ReceiveData();

    unsigned char TransmitCmd(unsigned short cmd);
    void TransmitData();
    void ReceiveRespond();

    unsigned char ReadDecInfo(unsigned short cmd, unsigned short *data1, unsigned short *data2);
    unsigned char WriteDecInfo(unsigned short cmd, unsigned short *data1, unsigned short *data2);

    unsigned char EnterSuspend();
    unsigned char ExitSuspend();

   private:
    struct PositionInfo {
        unsigned short x;
        unsigned short y;
        unsigned short angle;
    };

    PositionInfo position_info_;

    unsigned short rec_buffer_[4];
    unsigned short trans_cmd_;

    unsigned char write_muti_;
    unsigned short trans_muti_data_[6];

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