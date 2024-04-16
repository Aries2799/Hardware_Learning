
## 目录

- [CAN 总线监控 - `candump`](#can-总线监控---candump)
- [网络数据抓取 - `tcpdump`](#网络数据抓取---tcpdump)
- [串行通信 - `picocom`](#串行通信---picocom)

## CAN 总线监控 - `candump`

`candump` 是用于监听和记录 CAN (Controller Area Network) 总线上的数据。它是车载网络和工业自动化系统调试的理想工具。

### 使用方法

要开始监听 CAN 总线上的数据，你可以使用如下命令：

```bash
candump can0
```

此命令将捕获并显示通过 `can0` 接口传输的所有 CAN 帧。

## 网络数据抓取 - `tcpdump`

`tcpdump` 是一个功能强大的网络层数据包分析工具，用于捕获和显示通过网络接口传送的数据包。

### 使用方法

要捕捉特定网络接口（例如 `eth0`）上的数据包，使用如下命令：

```bash
tcpdump -i eth0
```

此命令将监控并记录通过 `eth0` 网络接口的所有数据包。

## 串行通信 - `picocom`

`picocom` 是一个用户友好的串行通信程序，通常用于串行端口的数据通信测试和设备配置。

### 使用方法

要与串行设备进行通信，并设置合适的波特率，可以使用以下命令：

```bash
picocom -b 115200 /dev/ttyUSB0
```

此命令打开 `/dev/ttyUSB0` 设备，并设置波特率为 115200，适用于多种测试和配置场景。

---
