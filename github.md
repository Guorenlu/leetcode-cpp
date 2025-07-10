# GitHub HTTPS + 代理 + PAT 完整配置教程

## 一、生成 GitHub Personal Access Token（PAT）

1. 登录你的 GitHub 账户，打开：https://github.com/settings/tokens  
2. 点击 **Generate new token**（生成新令牌）  
3. 输入 Token 描述，例如 `WSL git token`  
4. 选择作用域（权限），一般选择：  
   - `repo`（完全控制仓库）  
   - `workflow`（如果你用 GitHub Actions）  
   - 其他按需选择  
5. 点击 **Generate token**，生成后立即复制保存（页面关闭后无法再次查看）

---

## 二、配置 Git 使用代理

在 WSL 终端执行（假设代理地址和端口是 `127.0.0.1:7890`）：

```bash
git config --global http.proxy http://127.0.0.1:7890
git config --global https.proxy http://127.0.0.1:7890


三、设置远程仓库 HTTPS 地址
bash
复制
编辑
git remote set-url origin https://github.com/你的用户名/你的仓库名.git
四、日常操作
拉取最新代码

bash
复制
编辑
git pull origin master
提交代码

bash
复制
编辑
git add .
git commit -m "你的提交说明"
推送代码

bash
复制
编辑
git push origin master
第一次推送时，Git 会要求输入用户名和密码：

用户名填你的 GitHub 账号名

密码填刚才生成的 Personal Access Token（PAT）

五、使用 Git Credential Manager 缓存凭证（推荐）
安装方法（Ubuntu WSL）：

bash
复制
编辑
sudo apt install git-credential-manager-core
git-credential-manager-core configure
后续推送会提示是否保存凭证，保存后不用每次输入密码。

这样配置后，你的 HTTPS + 代理 + PAT 环境就完整了，日常推拉都很顺畅。

需要我帮你写更详细的操作脚本或者其他说明随时告诉我！

复制
编辑

你看这样可以吗？需要我帮你导出成文件也可以。








