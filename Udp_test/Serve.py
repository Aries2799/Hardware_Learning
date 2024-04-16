import socket

def udp_server():
    # 创建 UDP 套接字
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # 绑定地址和端口
    host = '127.0.0.1'
    port = 9999
    server_socket.bind((host, port))
    print("UDP 服务器启动，等待接收数据...")

    while True:
        # 接收客户端数据
        data, addr = server_socket.recvfrom(1024)  # 1024是缓冲区大小
        print("从 {} 收到消息: {}".format(addr, data.decode()))

        # 发送响应数据
        server_socket.sendto("收到你的数据！".encode(), addr)

    server_socket.close()

if __name__ == "__main__":
    udp_server()
