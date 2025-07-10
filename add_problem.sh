#!/bin/bash

if [ -z "$1" ]; then
  echo "用法: ./add_problem.sh problem2"
  exit 1
fi

NAME=$1
DIR="src/${NAME}"
CPP_FILE="${DIR}/${NAME}.cpp"
H_FILE="${DIR}/${NAME}.h"
MAIN_FILE="${DIR}/main_${NAME}.cpp"

# 判断目录和文件是否已存在
if [ -d "$DIR" ]; then
  echo "目录 $DIR 已存在，文件可能已存在，停止创建"
  exit 1
fi

# 创建目录
mkdir -p "$DIR"

# 创建 cpp 文件
cat > "$CPP_FILE" <<EOF
#include "${NAME}.h"

int ${NAME}(int x) {
    // TODO: 实现函数逻辑
    return x;
}
EOF

# 创建头文件
cat > "$H_FILE" <<EOF
#pragma once
int ${NAME}(int x);
EOF

# 创建 main 文件
cat > "$MAIN_FILE" <<EOF
#include <iostream>
#include "${NAME}.h"

int main() {
    std::cout << "${NAME}(5) = " << ${NAME}(5) << std::endl;
    return 0;
}
EOF

echo "已创建目录和文件:"
echo "  $CPP_FILE"
echo "  $H_FILE"
echo "  $MAIN_FILE"
echo
echo "请运行以下命令生成并编译对应题目："
echo "  cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug"
echo "  cmake --build build --target ${NAME}"
