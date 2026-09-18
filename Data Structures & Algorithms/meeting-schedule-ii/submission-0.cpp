/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b){
                return a.start < b.start;
            });

        int rooms = 0;
        priority_queue<int, vector<int>, greater<>> pq;

        for (auto& i : intervals) {
            if (pq.size() > 0 && pq.top() <= i.start) pq.pop();
            pq.push(i.end);

            rooms = max(rooms, static_cast<int>(pq.size()));
        }

        return rooms;
    }
};
