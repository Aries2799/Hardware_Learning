# 调试工具指南

本文档提供了一系列调试工具的使用方法和描述，帮助开发者在开发和维护过程中有效地调试硬件和软件问题。

## 目录

- [CAN 总线监控 - candump](#can-总线监控---candump)
- [网络数据抓取 - tcpdump](#网络数据抓取---tcpdump)
- [串行通信 - picocom](#串行通信---picocom)

## CAN 总线监控 - candump

`candump` 是用于监听和记录 CAN (Controller Area Network) 总线上数据的工具，非常适用于车载网络或工业自动化系统的调试。

### 使用方法

打开终端并输入以下命令来监听 `can0` 接口：

```bash
candump can0
