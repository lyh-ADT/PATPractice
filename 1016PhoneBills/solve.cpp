#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Time
{
    int day;
    int hour;
    int minute;
    Time(string str)
    {
        day = stod(str.substr(0,2));
        hour = stod(str.substr(3,2));
        minute = stod(str.substr(6,2));
    }
    Time operator++()
    {
        minute++;
        if(minute >= 60)
        {
            minute %= 60;
            hour++;
        }
        if(hour >= 24)
        {
            hour %= 24;
            day++;
        }
        return *this;
    }
    bool operator<(const Time& rhs)
    {
        return day < rhs.day 
        || (day == rhs.day && hour < rhs.hour)
        || (day == rhs.day && hour == rhs.hour && minute < rhs.minute);
    }
};

vector<int> pay_rate(24, 0);

struct Bill
{
    int month;
    string start_time;
    string end_time;
    double cost;
    int minute_count=0;
    Bill(string st, string et)
    {
        month = stod(st.substr(0,2));
        start_time = st.substr(3);
        end_time = et.substr(3);
        computeCost(start_time, end_time);
    }
    void computeCost(string st, string et)
    {
        cost=0;
        Time start(st);
        Time end(et);
        while(start < end)
        {
            cost += pay_rate[start.hour];
            ++start;
            minute_count++;
        }
        cost = cost/100;
    }
    bool operator<(const Bill& rhs)
    {
        return month < rhs.month || (month==rhs.month && start_time < rhs.start_time);
    }
};

struct Record
{
    string id;
    string time;
    string state;
    bool operator<(const Record& rhs)
    {
        return time < rhs.time;
    }
};



int main()
{
    for(int i=0; i < 24; ++i)
    {
        cin >> pay_rate[i];
    }
    int N = 0;
    cin >> N;
    map<string, string> on_hold_map;
    map<string, vector<Bill>> bills;
    vector<Record> records;
    for(int _=0; _ < N; ++_)
    {
        string id, time, state;
        cin >> id >> time >> state;
        records.push_back(Record{id, time, state});
    }
    sort(records.begin(), records.end());
    for(int _=0; _ < N; ++_)
    {
        string id = records[_].id;
        string time = records[_].time;
        string state = records[_].state;
        if(state == "on-line")
        {
            on_hold_map[id] = time;
        }
        else if(on_hold_map[id] != "" && state == "off-line")
        {
            bills[id].push_back(Bill(on_hold_map[id], time));
            on_hold_map[id] = "";
        }
    }
    for(auto i=bills.begin(); i != bills.end(); ++i)
    {
        string name = i->first;
        vector<Bill>& b = i->second;
        sort(b.begin(), b.end());
        int month = 0;
        double total_cost = 0;
        for(Bill& i : b)
        {
            if(i.month > month)
            {
                if(total_cost > 0)
                {
                    cout << total_cost << endl;
                }
                month = i.month;
                total_cost = 0;
                cout << name << " " << setiosflags(ios::fixed) << setw(2) << setfill('0') << month << endl;
            }
            total_cost += i.cost;
            cout << i.start_time << " " << i.end_time << " " << i.minute_count << " $" << setiosflags(ios::fixed) << setprecision(2) << i.cost << endl;
        }
        if(total_cost > 0)
        {
            cout << "Total amount: $" << setiosflags(ios::fixed) << setprecision(2) << total_cost << endl;
        }
    }
    return 0;
}