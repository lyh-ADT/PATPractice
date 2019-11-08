#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<iomanip>
using namespace std;

struct Time
{
    int hour;
    int minute;
    Time operator+=(int min)
    {
        minute = min + minute;
        if(minute >= 60)
        {
            hour += minute / 60;
            minute = minute % 60;
        }
        return *this;
    }
    bool operator<=(const Time& rhs)
    {
        return hour < rhs.hour || (hour == rhs.hour && minute <= rhs.minute);
    }
    bool operator>(const Time& rhs)
    {
        return !(*this <= rhs);
    }
    bool operator==(const Time& rhs)
    {
        return hour == rhs.hour && minute == rhs.minute;
    }
};

int pick_queue(vector<queue<int>> queues, int M)
{
    int picked_queue = 0;
    int number = 2001;
    for(int i=1; i < queues.size(); ++i)
    {
        if(queues[i].size() < number && queues[i].size() < M)
        {
            number = queues[i].size();
            picked_queue = i;
        }
    }
    return picked_queue;
}

unordered_map<int, Time> process(const vector<int>& transaction_time, int N, int M)
{
    int queue_head = 1;
    vector<queue<int>> inside_yellow(N+1, queue<int>());
    vector<int> window_remain(N+1,0);
    unordered_map<int, Time> finished;
    Time curTime = {8, 0};
    while(curTime <= Time{17,0})
    {
        // 进入黄色
        while(queue_head < transaction_time.size())
        {
            int picked = pick_queue(inside_yellow, M);
            if(picked == 0)break;
            inside_yellow[picked].push(queue_head++);
        }

        // 计算窗口用时
        // 找出剩余时间最短的窗口
        vector<int> finish_window(0);
        for(int i=1; i <= N; ++i)
        {
            if(window_remain[i] == 0 && inside_yellow[i].size() > 0)// 处理新的客户
            {
                window_remain[i] = transaction_time[inside_yellow[i].front()];
            }
            if(window_remain[i] > 0 // 跳过没有用户的窗口
                && (finish_window.size() == 0 || window_remain[i] <= window_remain[finish_window[0]]))
            {
                if(finish_window.size() == 0 || window_remain[i] < window_remain[finish_window[0]])
                {
                    finish_window = {i};
                }
                else
                {
                    finish_window.push_back(i);
                }
            }
        }
        if(finish_window.size() == 0)
        {
            break;
        }
        int useTime = window_remain[finish_window[0]];
        curTime += useTime;
        if(curTime > Time{17,0})
        {
            break;
        }
        for(int i : finish_window)
        {
            int finish_client = inside_yellow[i].front();
            finished[finish_client] = curTime;
            inside_yellow[i].pop();
        }
        for(int i=1; i <= N; ++i)
        {
            window_remain[i] -= useTime;
        }
    }
    return finished;
}

int main()
{
    int N=0, M=0, K=0, Q=0;
    cin >> N >> M >> K >> Q;
    vector<int> transaction_time={0};
    for(int _=0; _ < K; ++_)
    {
        int t=0;
        cin >> t;
        transaction_time.push_back(t);
    }

    unordered_map<int, Time> finished = process(transaction_time, N, M);
    for(int _=0; _ < Q; ++_)
    {
        int client=0;
        cin >> client;
        Time t = finished[client];
        if(t == Time{0,0})
        {
            cout << "Sorry";
        }
        else
        {
            cout << setw(2) << setfill('0') << t.hour << ":" << setw(2) << setfill('0') << t.minute;
        }
        if(_ < Q-1)
        {
            cout << endl;
        }
    }
    return 0;
}