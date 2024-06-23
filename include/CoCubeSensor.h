/**
 * @file CoCubeSensor.h
 * @author Liang Shuai (sliang23@m.fudan.edu.com)
 * @brief CoCube Position Sensor Library for MicroBlocks
 * @version 0.1
 * @date 2024-06-23
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
};