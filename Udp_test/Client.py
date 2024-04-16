import socket
import time

def udp_client():
    # 创建 UDP 套接字
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.settimeout(2)  # 设置接收超时时间为2秒

    # 服务器的 IP 地址和端口号
    host = '172.16.8.154'
    port = 9999

    # 发送数据的次数
    num_messages = 10
    received_count = 0

    for i in range(num_messages):
        # 发送数据
        message = f"消息 {i}"
        client_socket.sendto(message.encode(), (host, port))
        print(f"发送到服务器: {message}")

        # 尝试接收来自服务器的响应
        try:
            data, server = client_socket.recvfrom(1024)
            print("从服务器收到响应：", data.decode())
            received_count += 1
        except socket.timeout:
            print("响应超时，未收到服务器回复。")

        time.sleep(1)  # 暂停1秒再发送下一条消息

    print(f"\n总发送消息数: {num_messages}")
    print(f"收到响应的消息数: {received_count}")
    print(f"丢包率: {(1 - received_count / num_messages) * 100:.2f}%")

    client_socket.close()

if __name__ == "__main__":
    udp_client()
