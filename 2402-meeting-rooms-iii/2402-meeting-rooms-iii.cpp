
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> availableRooms;

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busyRooms;

        vector<int> meetingCount(n, 0);

        for (int i = 0; i < n; i++) {
            availableRooms.push(i);
        }

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            while (!busyRooms.empty() &&
                   busyRooms.top().first <= start) {
                availableRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            int room;

            if (!availableRooms.empty()) {
                room = availableRooms.top();
                availableRooms.pop();

                busyRooms.push({end, room});
            } else {
                auto current = busyRooms.top();
                busyRooms.pop();

                room = current.second;
                long long newEnd = current.first + duration;

                busyRooms.push({newEnd, room});
            }

            meetingCount[room]++;
        }

        int answer = 0;

        for (int i = 1; i < n; i++) {
            if (meetingCount[i] > meetingCount[answer]) {
                answer = i;
            }
        }

        return answer;
    }
};
