# 9x9 數獨解題器 - C++ + HTML 版本

## 📋 概述

這個專案結合了 C++ 高效的數獨解題演算法和美觀的網頁展示。

## 🔧 工作流程

1. **C++ 程式** (`sudoku.cpp`) - 使用回溯演算法和位元運算解題
2. **JSON 輸出** - 將解答輸出為 JSON 格式
3. **HTML 展示** - 在網頁中美觀地顯示數獨解答

## 🚀 快速開始

### 方法一：使用自動化腳本（推薦）

```bash
./update_sudoku.sh
```

### 方法二：手動執行

```bash
# 編譯 C++ 程式
g++ -std=c++20 -o sudoku sudoku.cpp

# 運行並生成 JSON
./sudoku > sudoku.json

# 啟動網頁服務器
python3 -m http.server 8000

# 開啟網址
http://localhost:8000/sudoku.html

```
## 製作專屬數獨題目
專門製造數獨題目的網站，設計好題目後，可以下載json格式
```
# 啟動網頁服務器
python3 -m http.server 8000

# 開啟網址
http://localhost:8000/make_sudoku.html

```


## 📁 檔案說明

- `sudoku.cpp` - C++ 數獨解題程式
- `sudoku.html` - 網頁界面
- `sudoku.json` - 數獨解答數據
- `update_sudoku.sh` - 自動化更新腳本
- `README.md` - 詳細說明文檔

## 🌐 技術棧

- **後端**：C++ 20 (位元運算 + 回溯演算法)
- **前端**：HTML5 + CSS3 + JavaScript
- **數據交換**：JSON 格式
- **服務器**：Python HTTP Server


## 🔍 演算法原理

- **回溯搜尋**：系統性嘗試所有可能解
- **位元優化**：使用 9 位元表示數字狀態
- **約束檢查**：行、列、3x3 區塊約束驗證

## to-do
- 新增更方便的介面可以新增題目，而不用再修改sudoku.cpp內部題目

---

**作者**：paulboul1013
