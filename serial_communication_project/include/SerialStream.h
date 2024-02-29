#ifndef SERIAL_STREAM_H
#define SERIAL_STREAM_H

namespace LibSerial {
    class SerialStream {
    public:
        // 构造函数
        SerialStream();

        // 打开串口
        bool Open(const char* device);

        // 设置波特率
        void SetBaudRate(int baudRate);

        // 设置字符大小
        void SetCharSize(int charSize);

        // 设置停止位数
        void SetNumOfStopBits(int numOfStopBits);

        // 设置奇偶校验
        void SetParity(int parity);

        // 设置流控制
        void SetFlowControl(int flowControl);

        // 发送数据
        void Send(const char* data);

        // 读取数据
        void Read(char* buffer, int bufferSize);

        // 关闭串口
        void Close();
    };
}

#endif // SERIAL_STREAM_H
