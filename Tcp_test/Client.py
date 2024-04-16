import socket
import time

def tcp_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = '172.16.8.154'
    port = 9999
    client_socket.connect((host, port))
    print("连接到服务器")

    try:
        while True:  # 循环发送数据
            message = '你好，服务器！'
            client_socket.send(message.encode())
            response = client_socket.recv(1024)
            print("服务器响应：", response.decode())
            time.sleep(0)  # 等待2秒再发送下一条消息
    except KeyboardInterrupt:
        print("客户端关闭")
    finally:
        client_socket.close()

if __name__ == "__main__":
    tcp_client()