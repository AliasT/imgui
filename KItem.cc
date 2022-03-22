#include <chrono>
#include <stdio.h>
#include <string>
#include <vector>
// using namespace date;

using namespace std;

// 状态
enum KStatus {
    PENDING,
    RUNNING,
    DONE
};

//
struct KItem {
    string content;
    KStatus status;
    chrono::system_clock::time_point create_time;

    KItem(string c)
        : content(c)
        , status(KStatus::PENDING)
        , create_time(chrono::system_clock::now()) {
        //
    }
};

struct Kanban {
    vector<vector<KItem*>> kItems;

    Kanban() {
        kItems = vector<vector<KItem*>>(3);
    };

    void moveTo(KStatus status, int from, int to) {
        // vector remove, add insert
        vector<KItem*>& list = kItems[status];
        auto item = list[from];
        list[from] = list[to];
        list[to] = item;
    }

    void insert(KItem* item) {
        vector<KItem*>& list = kItems[KStatus::PENDING];
        list.push_back(item);
    }

    void remove(KStatus status, int at) {
        auto list = &kItems[status];
        list->erase(list->begin() + at);
    }

    void moveTo(KStatus fromStatus, KStatus toStatus, int from, int to) {
        vector<KItem*>& fromList = kItems[fromStatus];
        vector<KItem*>& toList = kItems[toStatus];

        auto item = fromList[0];

        toList.emplace(toList.begin() + to, item);
        fromList.erase(fromList.begin() + from);
    }
};