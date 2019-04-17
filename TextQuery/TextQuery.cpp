//
// Created by feng on 19-4-17.
//

#include "TextQuery.h"



TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
    string text;
    while(getline(is, text)) { // 对于文件中的每一行
        file->push_back(text); // 保存此行文本
        int n = file->size() - 1; // 当前行号
        istringstream line(text); // 将行文本分解为单词
        string word;
        while (line >> word) { // 对行中的每个单词
            // 如果单词不在 wm 中，以此为下标在 wm 中添加一项
            auto &lines = wm[word]; // lines 是一个 shared——ptr
            if(!lines) { // 第一次遇到这个单词时，指针为空
                lines.reset(new set<line_no>); // 分配一个新的 set
            }
            lines->insert(n); // 将此行号插入到 set 中
        }

    }
}

QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no >> nodata(new set<line_no >);
    auto loc = wm.find(sought);
    if(loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    } else {
        return QueryResult(sought, loc->second, file);
    }
}


ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought
       << " occurs "
       << qr.lines->size()
       << " "
       << make_plursal(qr.lines->size(), "time", "s")
       << endl;
}