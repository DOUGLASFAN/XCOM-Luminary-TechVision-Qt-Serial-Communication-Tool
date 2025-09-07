# Qt Serial Communication Tool (XCOM)  

A lightweight serial communication tool developed based on the Qt framework, supporting core features such as serial port scanning, opening/closing, data transmission/reception, file sending (with interrupt functionality), and dynamic serial port list updates. It has a clean and user-friendly interface, suitable for scenarios like embedded debugging and hardware communication.  


## Project Overview  

### Core Features  
- **Serial Port Management**: Automatically scans available serial ports in the system and supports dynamic updates (auto-refreshes the list when devices are plugged in/out).  
- **Data Transmit/Receive**: Real-time receives serial data and displays it; supports manual text data sending.  
- **File Transfer**: Allows selecting local files for sending, with mid-transfer stop functionality to avoid blocking from large files.  
- **Status Feedback**: Clearly shows serial port connection status and transmit/receive results; pops up prompts for errors.  
- **Custom Configuration**: Supports setting window icons and titles to adapt to different usage scenarios.  

### Tech Stack  
- Framework: Qt 6.x (compatible with Qt 5.x; project configuration adjustments required).  
- Compiler: MSVC 2022 (64-bit) / MinGW 8.1 (selected based on the operating system).  
- Core Classes: `QSerialPort` (serial communication), `QTimer` (periodic scanning/chunked sending), `QFile` (file operations).  


## Project Structure  

```
XCOM/
├── .gitignore                # Git ignore file (filters build artifacts, IDE configs, etc.)
├── README.md                 # Project documentation (this file)
├── XCOM.pro                  # Qt project configuration file
├── XCOM_resource.rc          # Resource file (optional, for window icon)
├── resources.qrc             # Qt resource file (manages icons, configurations, etc.)
├── logo.ico                  # Project icon (for window and executable)
├── main.cpp                  # Program entry (initializes the window)
├── mainwindow.h              # Main window class header (declares member variables and slots)
├── mainwindow.cpp            # Main window class implementation (core logic: serial control, data processing)
├── mainwindow.ui             # UI layout file (designed with Qt Designer)
└── debug/                    # Build artifacts (filtered in .gitignore, no need to upload)
```


## Quick Start  

### 1. Environment Preparation  
- Install Qt 6.x or Qt 5.x (must include the `Qt SerialPort` module and `Qt Widgets` module).  
- Install a compiler:  
  - Windows: MSVC 2022 (requires installing Visual Studio 2022 and the corresponding MSVC version of Qt) or MinGW 8.1.  
  - Linux/macOS: GCC 9.4+ (usually pre-installed or installable via package managers).  

### 2. Clone the Project  
```bash
git clone https://github.com/DOUGLASFAN/XCOM-Luminary-TechVision-Qt-Serial-Communication-Tool.git
cd XCOM
```

### 3. Compile and Run  
1. Open the `XCOM.pro` file with Qt Creator.  
2. Select a compatible build kit (e.g., `Desktop Qt 6.8.2 MSVC2022 64bit`).  
3. Click **Build** → **Rebuild Project**; after compilation, click **Run** to launch the program.  


## User Guide  

### 1. Serial Port Connection  
1. After launching the program, the dropdown list `comboBoxPort` automatically loads available serial ports in the system.  
2. Select the target serial port and click the **Open Serial Port** button (the button text will change to **Close Serial Port**).  
3. If opening fails, a prompt will pop up (common causes: serial port occupied, device not connected).  

### 2. Data Sending  
- **Manual Sending**: Enter content in the send-area text box (`textEditSend`) and click the **Send** button.  
- **File Sending**:  
  1. Click the **Open File** button to select a local file for sending.  
  2. Click the **Send File** button to start transmission (supports clicking **Stop Sending** to interrupt mid-transfer).  

### 3. Data Receiving  
- When the serial port receives data, it will be automatically displayed in the receive-area text box (`textBrowser`)—no manual operation required.  
- Received data refreshes in real time, allowing intuitive viewing of content sent by the device.  


## Frequently Asked Questions (FAQs)  

### 1. Compilation Error: "RC2175: resource file is not in 3.00 format"  
- Cause: The icon file `logo.ico` does not meet the format requirements of the Windows Resource Compiler.  
- Solution:  
  1. Use an online tool (e.g., [ConvertICO](https://convertico.com/)) to convert the icon to a Windows-compatible format (recommended to include sizes: 16x16, 32x32, 48x48 pixels).  
  2. Use the Qt Resource System (`resources.qrc`) to load the icon instead of relying on the `.rc` file (see resource configuration in "Project Structure").  

### 2. Serial Port Not Showing in the List  
- Cause: Device not connected properly, driver not installed, or Qt failing to scan the serial port.  
- Solution:  
  1. Check if the USB-to-serial device is recognized correctly (Windows Device Manager, Linux `ls /dev/ttyUSB*`).  
  2. Restart the program (automatically rescans serial ports) or wait 1 second (periodic scanning logic will refresh the list).  

### 3. File Sending Freezes Mid-Transfer  
- Cause: Loading large files at once leads to high memory usage, or serial port baud rate mismatch.  
- Solution:  
  1. Ensure the code uses "chunked sending" logic (refer to the `onFileSendTimerTimeout` function).  
  2. Verify that serial port parameters (baud rate, data bits, parity, stop bits) match the device (you can extend the code to add parameter configuration).  


## Extension Suggestions  
- **Parameter Configuration**: Add dropdowns for baud rate, data bits, parity, and stop bits to adapt to different devices.  
- **Data Format**: Support hexadecimal (Hex) transmit/receive for debugging binary data.  
- **Log Saving**: Add "Save Receive Log" functionality to export received data as a local text file.  
- **Cross-Platform Adaptation**: The current code is compatible with Windows/Linux/macOS; optimize the UI layout to fit window styles of different systems.  


## License  
This project is open-source under the MIT License. It can be freely used for personal learning and commercial projects. When modifying or secondary developing, please retain the original author information.  

```
MIT License

Copyright (c) 2024 Your Name

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```


## Contact  
- Project URL: [https://github.com/DOUGLASFAN/XCOM-Luminary-TechVision-Qt-Serial-Communication-Tool](https://github.com/DOUGLASFAN/XCOM-Luminary-TechVision-Qt-Serial-Communication-Tool)  
- Feedback: Submit bugs or suggestions via GitHub Issues, or contact via email: 3478216458@qq.com

# Qt 串口通信工具（XCOM）

一个基于 Qt 框架开发的轻量级串口通信工具，支持串口扫描、打开/关闭、数据收发、文件发送（含中断功能）、动态更新串口列表等核心功能，界面简洁易用，适合嵌入式调试、硬件通信等场景。


## 项目介绍

### 核心功能
- **串口管理**：自动扫描系统可用串口，支持动态更新（插拔设备后自动刷新列表）；
- **数据收发**：实时接收串口数据并显示，支持手动发送文本数据；
- **文件传输**：支持选择本地文件发送，可中途停止发送，避免大文件阻塞；
- **状态反馈**：清晰显示串口连接状态、发送/接收结果，错误时弹出提示；
- **自定义配置**：可设置窗口图标和标题，适配不同使用场景。

### 技术栈
- 框架：Qt 6.x（兼容 Qt 5.x，需调整项目配置）
- 编译器：MSVC 2022（64位）/ MinGW 8.1（根据系统选择）
- 核心类：`QSerialPort`（串口通信）、`QTimer`（定时扫描/分块发送）、`QFile`（文件操作）


## 项目结构

```
XCOM/
├── .gitignore                # Git 忽略文件（过滤编译产物、IDE配置等）
├── README.md                 # 项目说明文档（本文档）
├── XCOM.pro                  # Qt 项目配置文件
├── XCOM_resource.rc          # 资源文件（可选，用于窗口图标）
├── resources.qrc             # Qt 资源文件（管理图标、配置等）
├── logo.ico                  # 项目图标（用于窗口和可执行文件）
├── main.cpp                  # 程序入口（初始化窗口）
├── mainwindow.h              # 主窗口类头文件（声明成员变量和槽函数）
├── mainwindow.cpp            # 主窗口类实现（核心逻辑：串口控制、数据处理）
├── mainwindow.ui             # UI 布局文件（用 Qt Designer 设计）
└── debug/                    # 编译产物（已在 .gitignore 中过滤，无需上传）
```


## 快速开始

### 1. 环境准备
- 安装 Qt 6.x 或 Qt 5.x（需包含 `Qt SerialPort` 模块和 `Qt Widgets` 模块）；
- 安装编译器：
  - Windows：MSVC 2022（需安装 Visual Studio 2022 及 Qt 对应的 MSVC 版本）或 MinGW 8.1；
  - Linux/macOS：GCC 9.4+（通常系统自带或通过包管理器安装）。

### 2. 克隆项目
```bash
git clone https://github.com/DOUGLASFAN/XCOM-Luminary-TechVision-Qt-Serial-Communication-Tool.git
cd XCOM
```

### 3. 编译运行
1. 用 Qt Creator 打开 `XCOM.pro` 文件；
2. 选择适配的编译套件（如 `Desktop Qt 6.8.2 MSVC2022 64bit`）；
3. 点击「构建」→「重新构建项目」，编译完成后点击「运行」即可启动程序。


## 使用指南

### 1. 串口连接
1. 启动程序后，下拉列表 `comboBoxPort` 会自动加载系统可用串口；
2. 选择目标串口，点击「打开串口」按钮（按钮文本会变为「关闭串口」）；
3. 若打开失败，会弹出提示（常见原因：串口被占用、设备未连接）。

### 2. 数据发送
- **手动发送**：在发送区文本框（`textEditSend`）输入内容，点击「发送」按钮即可；
- **文件发送**：
  1. 点击「打开文件」按钮，选择待发送的本地文件；
  2. 点击「发送文件」按钮，开始传输（支持中途点击「停止发送」中断）。

### 3. 数据接收
- 串口接收到数据后，会自动显示在接收区文本框（`textBrowser`），无需手动操作；
- 接收数据会实时刷新，可直观查看设备发送的内容。


## 常见问题

### 1. 编译报错「RC2175: resource file is not in 3.00 format」
- 原因：图标文件 `logo.ico` 格式不符合 Windows 资源编译器要求；
- 解决方案：
  1. 使用在线工具（如 [ConvertICO](https://convertico.com/)）将图标转换为 Windows 兼容格式（推荐包含 16x16、32x32、48x48 像素尺寸）；
  2. 改用 Qt 资源系统（`resources.qrc`）加载图标，避免依赖 `.rc` 文件（见「项目结构」中的资源配置）。

### 2. 串口列表不显示设备
- 原因：设备未正确连接、驱动未安装，或 Qt 未扫描到串口；
- 解决方案：
  1. 检查 USB 转串口设备是否正常识别（Windows 设备管理器、Linux `ls /dev/ttyUSB*`）；
  2. 重启程序（自动重新扫描串口），或等待 1 秒（定时扫描逻辑会刷新列表）。

### 3. 文件发送中途卡死
- 原因：一次性读取大文件导致内存占用过高，或串口波特率不匹配；
- 解决方案：
  1. 确保代码中使用「分块发送」逻辑（参考 `onFileSendTimerTimeout` 函数）；
  2. 检查串口波特率、数据位、停止位等参数是否与设备一致（可在代码中添加参数配置功能扩展）。


## 扩展建议
- **参数配置**：增加波特率、数据位、校验位、停止位的下拉选择，适配不同设备；
- **数据格式**：支持十六进制（Hex）发送/接收，方便调试二进制数据；
- **日志保存**：添加「保存接收日志」功能，将接收数据导出为本地文本文件；
- **跨平台适配**：当前代码已兼容 Windows/Linux/macOS，可优化界面布局以适配不同系统的窗口风格。


## 许可证
本项目基于 MIT 许可证开源，可自由用于个人学习、商业项目，修改或二次开发时需保留原作者信息。

```
MIT License

Copyright (c) 2024 你的名字

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```


## 联系方式
- 项目地址：[https://github.com/DOUGLASFAN/XCOM-Luminary-TechVision-Qt-Serial-Communication-Tool](https://github.com/DOUGLASFAN/XCOM-Luminary-TechVision-Qt-Serial-Communication-Tool)  
- 问题反馈：可通过 GitHub Issues 提交 bug 或建议，也可邮件联系：你的邮箱3478216458@qq.com
