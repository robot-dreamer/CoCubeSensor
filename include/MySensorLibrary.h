#ifndef MY_SENSOR_LIBRARY_H
#define MY_SENSOR_LIBRARY_H

class MySensor {
public:
    MySensor();
    void begin();
    int readValue();
private:
    // 私有成员变量和函数
};

#endif
