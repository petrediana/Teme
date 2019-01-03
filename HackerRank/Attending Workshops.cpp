#include<bits/stdc++.h>

using namespace std;
struct Workshop{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops{
    int N;
    vector<Workshop> WS;
};

Available_Workshops* initialize(int *start_time, int *duration, int n){
    Available_Workshops *ptr = new Available_Workshops();

    for(int i = 0; i < n; i++){
        Workshop w;
        w.start_time = start_time[i];
        w.duration = duration[i];
        w.end_time = start_time[i] + duration[i];
        ptr->WS.push_back(w);
    }
    return ptr;
}

bool compare(Workshop w1, Workshop w2){
    return (w1.end_time < w2.end_time);
}


int CalculateMaxWorkshops(Available_Workshops *ptr){
    sort(ptr->WS.begin(), ptr->WS.end(), compare);
    //sort the ws by their end times

    int end_time = 0;
    int count_ws = 0;

    for(Workshop &i : ptr->WS){ //for each workshop

        if(i.start_time >= end_time){
            count_ws ++;
            end_time = i.end_time;
        }
    }
    return count_ws;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
