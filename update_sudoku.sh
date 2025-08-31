#!/bin/bash

echo "🔧 編譯數獨程式..."
g++ -std=c++20 -o sudoku sudoku.cpp

if [ $? -eq 0 ]; then
    echo "✅ 編譯成功！"
    echo ""
    echo "🚀 運行數獨解題程式..."
    ./sudoku > sudoku.json
    echo "📄 數獨解答已保存到 sudoku.json"
    echo ""
    echo "🌐 網頁服務器正在運行中..."
    python3 -m http.server 8000
    echo "   開啟瀏覽器訪問: http://localhost:8000/sudoku.html"

else
    echo "❌ 編譯失敗！"
    exit 1
fi
