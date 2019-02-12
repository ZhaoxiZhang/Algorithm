class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string>res;
        if (num > 8)    return res;
        int hourMax = min(3, num);
        for (int i = 0; i <= hourMax; i++){
            int hour[4] = {0};
            int minute[6] = {0};
            vector<int>hourRes;
            vector<int>minuteRes;
            hourHelper(hourRes, hour, 0, i, 0);
            minuteHelper(minuteRes, minute, 0, num - i, 0);
            
            for (auto hourVal : hourRes){
                for (auto minuteVal : minuteRes){
                    ostringstream buffer;
                    if (minuteVal < 10){
                        buffer << hourVal << ":0" << minuteVal;
                    }else{
                        buffer << hourVal << ":" << minuteVal;
                    }
                    res.push_back(buffer.str());
                    
                }
            }
        }
        
        return res;
    }
    
    void hourHelper(vector<int>&res, int hour[], int cur, int length, int cnt){
        if (cnt == length){
            int val = 8 * hour[3] + 4 * hour[2] + 2 * hour[1] + hour[0];
            if (val < 12){
                //cout << val << endl;
                res.push_back(val);
            }
            return;
        }else{
            for (int i = cur; i < 4; i++){
                hour[i] = 1;
                cnt++;
                hourHelper(res, hour, i + 1, length, cnt);
                hour[i] = 0;
                cnt--;
            }
        }
    }
    
    void minuteHelper(vector<int>&res, int minute[], int cur, int length, int cnt){
        if (cnt == length){
            int val = 32 * minute[5] + 16 * minute[4] + 8 * minute[3] + 4 * minute[2] + 2 * minute[1] + minute[0];
            if (val < 60){
                //cout << val << endl;
                res.push_back(val);
            }
            return;
        }else{
            for (int i = cur; i < 6; i++){
                minute[i] = 1;
                cnt++;
                minuteHelper(res, minute, i + 1, length, cnt);
                minute[i] = 0;
                cnt--;
            }
        }
    }
};