# 新增题目完整步骤总结（基于子目录管理）

---

## 1. 创建题目代码

- 使用已有脚本快速创建题目目录和文件，例如：

  ```bash
  ./add_problem.sh problem3

形成
src/problem3/
  problem3.cpp
  problem3.h
  main_problem3.cpp


2. 确认 CMakeLists.txt 支持自动生成目标


3. 编译生成可执行文件
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target problem3

构建完成后，生成的可执行文件位于：build/problem3

4. VSCode 调试配置
在 .vscode/launch.json 中添加对应调试配置：
{
  "name": "Debug problem3",
  "type": "cppdbg",
  "request": "launch",
  "program": "${workspaceFolder}/build/problem3",
  "args": [],
  "stopAtEntry": true,
  "cwd": "${workspaceFolder}",
  "externalConsole": false,
  "MIMode": "gdb",
  "miDebuggerPath": "/usr/bin/gdb",
  "setupCommands": [
    {
      "description": "Enable pretty-printing for gdb",
      "text": "-enable-pretty-printing",
      "ignoreFailures": true
    }
  ],
  "preLaunchTask": "Build problem3"
}

并在 .vscode/tasks.json 中添加对应构建任务：
{
  "label": "Build problem3",
  "type": "shell",
  "command": "cmake --build build --target problem3",
  "group": "build"
}

在 VSCode “运行和调试”面板选择 Debug problem3，按 F5 启动调试