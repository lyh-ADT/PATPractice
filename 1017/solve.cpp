#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
using namespace std;


struct Time
{
    int hour;
    int minute;
    int second;
    Time()
    {
        hour=0;
        minute =0 ;
        second = 0;
    }
    Time(string str)
    {
        hour = stod(str.substr(0,2));
        minute = stod(str.substr(3,2));
        second = stod(str.substr(6,2));
    }
    Time operator+=(int min)
    {
        minute += min;
        hour += minute/60;
        minute %= 60;
        return *this;
    }
    bool operator<(const Time& rhs)
    {
        return hour < rhs.hour 
        || (hour == rhs.hour && minute < rhs.minute)
        || (hour == rhs.hour && minute == rhs.minute && second < rhs.second);
    }
    // 返回分钟为单位的时间差
    double operator-(const Time& rhs)
    {
        return this->timestamp() - rhs.timestamp();
    }
    // 从0点开始以分钟为单位的时间戳
    double timestamp() const
    {
        double stamp = 0;
        stamp += hour * 60;
        stamp += minute;
        stamp += second / 60.;
        return stamp;
    }
};

struct Customer
{
    Time arrive;
    Time start_process;
    int process_time=0;
    bool operator<(const Customer& rhs)
    {
        return arrive < rhs.arrive;
    }
};

vector<int> find_lowest_process_time(const vector<Customer>& v, int low)
{
    vector<int> picked;
    int time = 0x7fffffff;
    for(int i=0; i < v.size(); ++i)
    {
        if(v[i].process_time < time && low < v[i].process_time)
        {
            picked = {i};
            time = v[i].process_time;
        }
        else if(v[i].process_time == time)
        {
            picked.push_back(i);
        }
    }
    return picked;
}

int main()
{
    int N=0, K=0;
    cin >> N >> K;
    vector<Customer> customers;
    for(int _=0; _ < N; ++_)
    {
        string arrive_time;
        int proces = 0;
        cin >> arrive_time >> proces;
        if(Time(arrive_time) < Time("17:00:00"))
        {
            customers.push_back(Customer{Time(arrive_time), Time("00:00:00"), proces});
        }
    }
    sort(customers.begin(), customers.end());

    // 开始处理
    int process_count = 0;
    double total_waiting_time = 0;
    vector<Customer> inside_yellow(K);  // 存的是处理时间
    Time curTime("08:00:00");
    do{
        // 选择窗口
        if(!customers.empty())
        {
            // 找最短的队伍
            vector<int> pickeds = find_lowest_process_time(inside_yellow, -1);
            if(!pickeds.empty() && inside_yellow[pickeds[0]].process_time == 0)
            {
                if(pickeds.size() == K && curTime < customers[0].arrive)
                {
                    curTime = customers[0].arrive;
                }
                
                for(int picked : pickeds)
                {   
                    if(curTime < customers[0].arrive)
                    {
                        break;
                    }
                    inside_yellow[picked] = customers[0];
                    inside_yellow[picked].start_process = curTime;
                    total_waiting_time += curTime - inside_yellow[picked].arrive;
                    customers.erase(customers.begin());
                }
            }
        }
        // 窗口处理客户
        vector<int> lowest_windows = find_lowest_process_time(inside_yellow, 0);
        if(lowest_windows.empty())
        {
            // 所有客户都处理完毕
            break;
        }
        int used_time = inside_yellow[lowest_windows[0]].process_time;
        curTime += used_time;
        process_count += lowest_windows.size();
        for(Customer& c : inside_yellow)
        {
            c.process_time -= used_time;
        }
    }while(curTime < Time("17:00:00"));
    cout << setiosflags(ios::fixed) << setprecision(1) << total_waiting_time / process_count;
    return 0;
}

/*
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
*/