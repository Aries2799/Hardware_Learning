import socket

def tcp_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = '172.16.8.154'  # 使用服务器的实际 IP 地址
    port = 9999
    server_socket.bind((host, port))
    server_socket.listen(5)
    print("服务器启动，等待连接...")

    while True:  # 无限循环以接受新的连接
        client_socket, addr = server_socket.accept()
        print('连接地址：', addr)
        
        while True:  # 这个循环用来不断接收和发送数据
            data = client_socket.recv(1024)
            if not data:
                break
            print("收到消息：", data.decode())
            client_socket.send('服务器收到你的消息了'.encode())
        
        client_socket.close()

    server_socket.close()

if __name__ == "__main__":
    tcp_server()
