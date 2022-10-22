class Solution {
public:
    struct Event {
        int tm; // x-axis position.
        int index; // pointer to the rectangle in the given array.
        bool isStart; // This is the left edge of the rectangle, otherwise, right edge.
        Event(int t, int id, bool isS): tm(t), index(id), isStart(isS) {}
    };

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        auto compPQ = [&](Event* e1, Event* e2) {
            if(e1->tm != e2->tm) return e1->tm > e2->tm;
            else return rectangles[e1->index][0] > rectangles[e2->index][0];
        };
        priority_queue<Event*, vector<Event*>, decltype(compPQ)> pq(compPQ);
        int bottom = INT_MAX, roof = INT_MIN; 
        for(int i = 0; i < rectangles.size(); i++) {
            const vector<int>& rec = rectangles[i];
            Event* e1 = new Event(rec[0], i, true);
            Event* e2 = new Event(rec[2], i, false);
            pq.push(e1); pq.push(e2);
            bottom = min(bottom, rec[1]);
            roof = max(roof, rec[3]);
        }
        auto compSet = [&](Event* e1, Event* e2) {
            if(rectangles[e1->index][3] <= rectangles[e2->index][1]) return true;
            else return false;
        };
        set<Event*, decltype(compSet)> mySet(compSet);
        int yRange = 0;
        while(!pq.empty()) {
            int tm = pq.top()->tm;
            while(!pq.empty() && tm == pq.top()->tm) {
                Event* event = pq.top(); pq.pop();
                const vector<int>& rec = rectangles[event->index]; 
                if(event->isStart) {
                    auto rt = mySet.insert(event);
                    if(!rt.second) return false; // overlapping!!!
                    yRange += rec[3] - rec[1];
                }
                else {
                    mySet.erase(event);
                    yRange -= rec[3] - rec[1];
                }
            }
            if(!pq.empty() && yRange != roof - bottom) return false;
        }
        return true;
    }
};