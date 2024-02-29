#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

// CAN接口名称
const std::string CAN_INTERFACE_NAME = "can0"; // 根据你的系统配置修改

// 创建CAN套接字的函数
int create_can_socket() {
    int s = socket(PF_CAN, SOCK_RAW, CAN_RAW); // 创建套接字
    if (s < 0) {
        perror("Error while opening socket");
        return -1;
    }

    struct ifreq ifr;
    std::strncpy(ifr.ifr_name, CAN_INTERFACE_NAME.c_str(), IFNAMSIZ - 1);
    ifr.ifr_name[IFNAMSIZ - 1] = '\0';
    ioctl(s, SIOCGIFINDEX, &ifr); // 指定CAN设备

    struct sockaddr_can addr;
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) { // 绑定套接字
        perror("Error in socket bind");
        return -2;
    }

    return s;
}

// 发送CAN消息的函数
void send_can_message(int socket, int can_id, const std::string &data) {
    struct can_frame frame;
    frame.can_id = can_id;
    frame.can_dlc = data.size();
    std::memcpy(frame.data, data.c_str(), frame.can_dlc);

    if (write(socket, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        perror("Error writing to CAN");
    }
}

// 接收CAN消息的函数
void receive_can_message(int socket) {
    struct can_frame frame;
    int nbytes = read(socket, &frame, sizeof(struct can_frame));

    if (nbytes < 0) {
        perror("Error reading from CAN");
        return;
    }

    std::cout << "Received a message with ID 0x" << std::hex << frame.can_id << std::dec 
              << " and data: " << std::string(reinterpret_cast<char *>(frame.data), frame.can_dlc) << std::endl;
}

// 主函数
int main() {
    int socket = create_can_socket();
    if (socket < 0) {
        return 1;
    }

    // 发送消息
    send_can_message(socket, 0x123, "Hello CAN");

    // 接收消息
    receive_can_message(socket);

    // 关闭套接字
    close(socket);
    return 0;
}

