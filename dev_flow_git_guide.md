# 🧑‍💻 开发流程 & Git 常用命令（WSL + VSCode + GitHub）

适用于刷题或功能开发项目：每个题目/模块一个分支，统一管理，便于调试与提交。

---

## 🧱 1. 创建新题目 / 模块的开发分支

从主分支 `main` 创建一个新分支开始开发：

```bash
git checkout main
git pull origin main
git checkout -b feature-xxx  # 例如 feature-water-warmer
```

---

## 🛠️ 2. 编写代码 + 编译调试

使用 VSCode 编辑文件，比如：

```
src/water_warmer/water_warmer.cpp
src/water_warmer/main_water_warmer.cpp
```

然后用 CMake 编译：

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target MST
./build/String_Chain  # 运行程序
```

---

## ✅ 3. 本地提交代码

查看修改状态：

```bash
git status
```

添加 & 提交改动：

```bash
git add .
git commit -m "功能说明，如：水壶和小鼠"
```

---

## ☁️ 4. 推送到远程 GitHub

首次推送分支：

```bash
git push -u origin feature-xxx
```

之后直接：

```bash
git push
```

---

## 🔁 5. 合并分支到 main（功能开发完成）

```bash
git checkout main
git pull origin main
git merge feature-xxx
git push origin main
```

---

## 🧹 6. 删除旧分支（可选）

```bash
# 删除本地分支
git branch -d feature-xxx

# 删除远程分支
git push origin --delete feature-xxx
```

---

## 🧭 分支命名建议

| 类型       | 分支命名           | 示例                     |
|------------|--------------------|--------------------------|
| 新功能题目 | `feature-xxx`      | `feature-water-warmer`  |
| Bug 修复   | `fix-xxx`          | `fix-path-error`        |
| 重构优化   | `refactor-xxx`     | `refactor-io-module`    |

---

## 🧰 常用 Git 命令速查

| 操作                  | 命令                                  |
|-----------------------|---------------------------------------|
| 查看当前分支          | `git branch`                          |
| 查看历史提交          | `git log --oneline --graph --all`     |
| 添加文件              | `git add .`                           |
| 提交修改              | `git commit -m "备注"`                |
| 推送代码              | `git push`                            |
| 拉取远程更新          | `git pull`                            |
| 创建新分支            | `git checkout -b feature-xxx`         |
| 切换分支              | `git checkout main`                   |
| 合并分支              | `git merge feature-xxx`               |
| 删除本地分支          | `git branch -d feature-xxx`           |
| 删除远程分支          | `git push origin --delete feature-xxx`|

---

## 📌 提示

- 每个题目/功能模块一个分支，便于管理和定位问题
- 主分支 `main` 保持干净，只合并稳定功能
- 使用 GitHub Pull Request 合并也更安全可回溯