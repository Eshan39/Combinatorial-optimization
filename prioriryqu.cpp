#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct client{
    string name;
    int priority;
};

struct Compare{
    bool operator()(const client& a,const client& b)
    {
        return a.priority > b.priority;
    }
};


int main(void)
{
    priority_queue<client,vector<client>,Compare>  q;

    client c;

    c.name="rifad";
    c.priority=1;
    q.push(c);

    c.name="niraj";
    c.priority=5;
    q.push(c);

    c.name="musa";
    c.priority=3;
    q.push(c);

    while(!q.empty())
    {
        client cl=q.top();
        cout<<cl.name<<" "<<cl.priority<<endl;
        q.pop();
    }
    return 0;
}
