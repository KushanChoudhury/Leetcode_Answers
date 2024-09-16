class Solution {
public:
    struct Time {
        int hour;
        int minute;
    };
    Time stringToTime(const string& timeString) {
        Time time;
        size_t colonPos = timeString.find(':');
        time.hour = std::stoi(timeString.substr(0, colonPos));
        time.minute = std::stoi(timeString.substr(colonPos + 1));
        return time;
    }
    int timeToMinutes(const Time& t) {
        return t.hour * 60 + t.minute;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(auto& timePoint:timePoints){
            Time t = stringToTime(timePoint);
            minutes.push_back(timeToMinutes(t));
        }
        sort(minutes.begin(), minutes.end());
        int mindiff = INT_MAX;
        for (int i = 1; i < minutes.size(); ++i) {
            mindiff = min(mindiff, minutes[i] - minutes[i - 1]);
        }
        int wrapAroundDiff = (1440 - minutes.back()) + minutes[0];
        mindiff = min(mindiff, wrapAroundDiff);
        return mindiff;
    }
};