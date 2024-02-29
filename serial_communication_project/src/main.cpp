#include "SerialStream.h"
#include <iostream>

using namespace std;

int main() {
    LibSerial::SerialStream serialPort;
    const char* device = "/dev/ttyUSB0"; // 根据你的串口设备更改路径

    if (!serialPort.Open(device)) {
        cerr << "无法打开串口设备: " << device << endl;
        return 1;
    }

    // 设置串口参数
    serialPort.SetBaudRate(9600);
    serialPort.SetCharSize(8);
    serialPort.SetNumOfStopBits(1);
    serialPort.SetParity(0);
    serialPort.SetFlowControl(0);

    // 发送数据
    const char* data = "Hello, Serial Port!\n";
    serialPort.Send(data);

    // 读取并显示来自串口的数据
    char buffer[256];
    serialPort.Read(buffer, sizeof(buffer));
    cout << "Received data: " << buffer << endl;

    serialPort.Close();

    return 0;
}
