# DeployMaster - PLC 部署和测试工具

DeployMaster 是一款基于 Qt 开发的工业级 PLC 部署和测试工具，专为批量设备管理和运维设计。它集成了 FTP 部署、Telnet 命令执行、日志查询、Modbus 测试和 OPC UA 客户端等多种功能，为工业自动化系统的维护和管理提供了全面的解决方案。

## 功能特性

### 1. 批量部署功能
- **文件和文件夹上传**：支持将文件和文件夹批量上传到多个设备
- **远程路径配置**：可自定义远程部署路径
- **部署后操作**：支持部署后自动重启设备
- **远程预览**：可查看目标设备上的文件结构，支持双击文件夹进入子目录
- **批量操作**：一次操作可部署到多个设备，提高工作效率

### 2. 批量命令功能
- **Telnet 命令执行**：在多个设备上并行执行 Telnet 命令
- **实时状态显示**：实时显示每个设备的执行状态、耗时和错误信息
- **命令输出管理**：收集和缓存每个设备的命令输出
- **详细信息查看**：双击设备查看详细的命令执行输出
- **结果导出**：支持导出所有执行结果到文件

### 3. 日志查询功能
- **日志文件浏览**：查看远程设备上的日志文件列表
- **文件信息显示**：显示文件名、大小、修改时间等信息
- **日志下载**：支持下载选中的日志文件或全部日志文件
- **查询条件配置**：可配置日志路径、关键字搜索等查询条件

### 4. Modbus 集群测试功能
- **批量寄存器读取**：同时读取多个设备的 Modbus 寄存器值
- **数据对比**：对比不同设备间的寄存器值，确保数据一致性
- **寄存器写入**：支持向选定设备写入相同值、随机值或特定值
- **定时刷新**：可设置定时自动刷新，实时监控设备状态
- **操作耗时统计**：显示设备操作的耗时，便于性能评估

### 5. OPC UA 客户端功能
- **服务器连接**：连接到 OPC UA 服务器
- **节点浏览**：浏览服务器中的 OPC UA 节点
- **数据读写**：读取和写入节点值
- **订阅功能**：支持订阅节点值的变化

## 技术架构

- **开发框架**：Qt 6.10.1
- **开发语言**：C++
- **网络协议**：FTP、Telnet、Modbus TCP、OPC UA
- **并发处理**：使用 QtConcurrent 实现多线程并发操作
- **界面设计**：基于 Qt Widgets 的现代化界面

## 系统要求

- **操作系统**：Windows 10/11 (64位)
- **Qt 运行时**：Qt 6.10.1 或更高版本
- **依赖库**：libcurl (用于 FTP 操作)

## 安装方法

### 方法一：使用预编译二进制文件
1. 从 GitHub Releases 页面下载最新的发布版本
2. 解压下载的压缩包到任意目录
3. 运行 `DeployMaster.exe` 启动应用程序

### 方法二：从源代码编译
1. **安装依赖**：
   - 安装 Qt 6.10.1 或更高版本（包含 SerialBus 模块）
   - 确保 Visual Studio 2022 已安装

2. **克隆代码**：
   ```bash
   git clone https://github.com/yourusername/DeployMaster.git
   cd DeployMaster
   ```

3. **编译项目**：
   ```bash
   mkdir build
   cd build
   cmake .. -DCMAKE_PREFIX_PATH="C:\Qt\6.10.1\msvc2022_64"
   cmake --build .
   ```

4. **运行应用**：
   编译完成后，在 `build/Debug` 目录中找到 `DeployMaster.exe` 并运行

## 使用指南

### 基本配置
1. **目标 IP 列表**：在主界面上方的文本框中输入要管理的设备 IP 地址，每行一个
2. **认证信息**：输入 FTP 和 Telnet 登录所需的用户名和密码
3. **默认路径**：设置默认的远程部署路径

### 批量部署
1. **添加文件**：点击"添加文件"或"添加文件夹"按钮，或直接拖拽文件/文件夹到上传列表
2. **配置部署选项**：设置远程路径、是否重启设备等选项
3. **开始部署**：点击"开始部署"按钮，系统将自动上传文件到所有目标设备
4. **查看结果**：部署过程和结果将在下方的日志窗口中显示

### 批量命令执行
1. **输入命令**：在命令编辑区输入要执行的命令，每行一条
2. **配置执行选项**：设置命令超时时间等选项
3. **执行命令**：点击"执行命令"按钮，系统将在所有目标设备上并行执行命令
4. **查看结果**：执行状态将在右侧的设备执行状态窗口中显示，双击设备可查看详细输出

### 日志查询
1. **配置查询条件**：设置日志路径、关键字等查询条件
2. **查询日志**：点击"查询日志"按钮，系统将列出匹配的日志文件
3. **下载日志**：选择要下载的日志文件，点击"下载选中日志"或"下载全部日志"按钮

### Modbus 测试
1. **配置 Modbus 参数**：设置端口、从站 ID、起始地址、长度等参数
2. **读取寄存器**：点击"读取并对比"按钮，读取所有设备的寄存器值并进行对比
3. **写入寄存器**：选择要写入的设备和写入方式，点击"写入选定设备"按钮
4. **定时刷新**：可开启定时刷新功能，实时监控设备状态

### OPC UA 客户端
1. **配置连接参数**：输入 OPC UA 服务器的 endpoint URL
2. **连接服务器**：点击"Connect/Disconnect"按钮连接到服务器
3. **浏览节点**：点击"Browse Nodes"按钮浏览服务器中的节点
4. **读写数据**：选择节点后，可点击"Read Value"读取值，或点击"Write Value"写入新值
5. **订阅节点**：选择节点后，点击"Subscribe/Unsubscribe"按钮订阅节点值的变化

## 界面预览

### 主界面
![主界面](https://trae-api-cn.mchost.guru/api/ide/v1/text_to_image?prompt=Qt%20application%20main%20window%20for%20industrial%20device%20management%20with%20tabs%20for%20deployment%2C%20commands%2C%20logs%2C%20and%20testing%2C%20professional%20industrial%20UI%20design%2C%20clean%20layout%2C%20dark%20theme%20with%20green%20text%20for%20logs&image_size=landscape_16_9)

### 批量命令执行
![批量命令执行](https://trae-api-cn.mchost.guru/api/ide/v1/text_to_image?prompt=Qt%20application%20tab%20for%20batch%20command%20execution%20via%20Telnet%2C%20showing%20command%20editor%20on%20left%20and%20device%20status%20tree%20on%20right%2C%20professional%20industrial%20UI%20design&image_size=landscape_16_9)

### Modbus 测试
![Modbus 测试](https://trae-api-cn.mchost.guru/api/ide/v1/text_to_image?prompt=Qt%20application%20tab%20for%20Modbus%20cluster%20testing%2C%20showing%20register%20matrix%20table%20and%20configuration%20panel%2C%20professional%20industrial%20UI%20design&image_size=landscape_16_9)

## 常见问题

### 1. 部署失败怎么办？
- 检查目标 IP 地址是否正确
- 确认用户名和密码是否正确
- 检查网络连接是否正常
- 查看日志窗口中的详细错误信息

### 2. 命令执行超时怎么办？
- 在批量命令界面增加命令超时时间
- 检查网络连接质量
- 确认设备是否正常运行

### 3. 无法连接到 Modbus 设备怎么办？
- 检查 Modbus 端口和从站 ID 是否正确
- 确认设备是否支持 Modbus TCP 协议
- 检查网络连接是否正常

### 4. OPC UA 连接失败怎么办？
- 检查 endpoint URL 是否正确
- 确认 OPC UA 服务器是否运行
- 检查网络连接和防火墙设置

## 贡献指南

我们欢迎社区贡献！如果您想为 DeployMaster 做出贡献，请按照以下步骤进行：

1. Fork 本仓库
2. 创建您的特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交您的更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 打开一个 Pull Request

## 许可证

本项目采用 MIT 许可证 - 详情请参阅 [LICENSE](LICENSE) 文件

## 联系方式

- **项目地址**：https://github.com/yourusername/DeployMaster
- **问题反馈**：https://github.com/yourusername/DeployMaster/issues

---

**DeployMaster - 让工业设备管理更简单、更高效！**