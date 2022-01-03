#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long long ll;
struct med {
    ll dropOffTime;
    ll timeTaken;
};
struct compareMed {
    bool operator()(const med& a, const med& b) {
        if (a.dropOffTime != b.dropOffTime) 
            return a.dropOffTime > b.dropOffTime;
        return a.timeTaken > b.timeTaken;
    }
};
struct compareWorker {
    bool operator()(const ll& a, const ll& b) {
        return a > b;
    }
};

void helper(priority_queue<med, vector<med>, compareMed>& Q, 
            priority_queue<ll, vector<ll>, compareWorker>& W, ll& total) {
    ll time = W.top();
    med currMed = Q.top();
    if (currMed.dropOffTime < time) {
        total += (time + currMed.timeTaken - currMed.dropOffTime);
        W.pop();
        W.push(time + currMed.timeTaken);
    } else {
        total += currMed.timeTaken;
        W.pop();
        W.push(currMed.dropOffTime + currMed.timeTaken);
    }
    Q.pop();
}

int main() {
    //freopen("sample002.in","r",stdin);
    ll n, t; cin >> n >> t;
    if (t == 0) {
        cout << std::fixed;
        cout << std::setprecision(6);
        cout << 0.0 << " " << 0.0;
        return 0;
    }
    priority_queue<med, vector<med>, compareMed> instore;  //instore pq
    priority_queue<med, vector<med>, compareMed> remote;   //remote pq
    priority_queue<ll, vector<ll>, compareWorker> technician;  //next available time of technicians
    ll instoreCount = 0.0, remoteCount = 0.0;
    ll instoreTotalTime = 0.0, remoteTotalTime = 0.0;
    for (int i=0; i<n; i++) {
        med newMed; char type;
        cin >> newMed.dropOffTime >> type >> newMed.timeTaken;
        if (type == 'R') {
            remote.push(newMed);
            remoteCount++;
        }
        if (type == 'S') {
            instore.push(newMed);
            instoreCount++;
        }
    }
    for (int i=0; i<t; i++) {
        technician.push(0);
    }
        
    while (!instore.empty() && !remote.empty()) {
        ll time = technician.top();
        ll instoreTime = instore.top().dropOffTime;
        ll remoteTime = remote.top().dropOffTime;
        if (remoteTime <= time && instoreTime <= time) {
            helper(instore, technician, instoreTotalTime);
            continue;               
        }
        if (remoteTime > time || instoreTime > time) {
            if (instoreTime <= remoteTime) {
                helper(instore, technician, instoreTotalTime);
            } else {
                helper(remote, technician, remoteTotalTime);
            }
        }
    }
    while (!instore.empty()) {
        helper(instore, technician, instoreTotalTime);
    }
    while (!remote.empty()) {
        helper(remote, technician, remoteTotalTime);
    }

    if (instoreCount == 0)
        instoreCount = 1;
    if (remoteCount == 0)
        remoteCount = 1;
    cout << std::fixed;
    cout << std::setprecision(6);
    cout << (long double)instoreTotalTime/instoreCount << " " << (long double)remoteTotalTime/remoteCount;
}
