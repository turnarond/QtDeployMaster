/*
 * Copyright (c) 2024 ACOINFO CloudNative Team.
 * All rights reserved.
 *
 * File: DeviceInfo.h
 *
 * Date: 2026-07-04
 *
 * Author: Yan.chaodong <yanchaodong@acoinfo.com>
 *
 * Description: 设备信息与认证信息数据结构（framework 层统一定义）
 *
 * 与 adapter 层的同名结构体兼容。后续所有模块使用 framework 层的定义。
 */

#pragma once
#include <string>
#include <vector>

// 设备信息（framework 层的统一定义，与 adapter 层的同名结构体兼容）
struct DeviceInfo {
    std::string ip;
    int port = 0;
    std::string protocol; // "ftp", "telnet", "modbus"...
    std::string alias;    // 用户自定义别名
};

struct AuthInfo {
    std::string user;
    std::string password;
};
