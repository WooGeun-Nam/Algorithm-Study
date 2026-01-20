#include <string>
#include <vector>

using namespace std;

int timeGenerater(string time)
{
    size_t timeSpace = time.find(':');
        
    int minute = stoi(time.substr(0, timeSpace));
    int second = stoi(time.substr(timeSpace + 1));
    
    int timeInt = (minute * 60) + second;
    
    return timeInt;
}

string timeIntToString(int time)
{
    string minute = to_string(time / 60);
    if(time/60 < 10) minute = "0" + minute;
    string second = to_string(time % 60);
    if(time%60 < 10) second = "0" + second;
    
    return minute + ":" + second;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    
    int intPos = timeGenerater(pos);
    int intOpStart = timeGenerater(op_start);
    int intOpEnd = timeGenerater(op_end);
    int intVideoLen = timeGenerater(video_len);
        
    // 최초 위치 오프닝 판별
    if(intPos >= intOpStart 
       && intPos <= intOpEnd) intPos = intOpEnd;
    
    for(int i=0; i<commands.size(); i++)
    {
        if(commands[i] == "next")
        {
            intPos += 10;
            if(intPos > intVideoLen) intPos = intVideoLen;
        }
        else if(commands[i] == "prev") 
        {
            intPos -= 10;
            if(intPos < 0) intPos = 0;
        }
            
        // 커맨드 계산 후 오프닝 판별
        if(intPos >= intOpStart 
           && intPos <= intOpEnd) intPos = intOpEnd;
    }
    
    return timeIntToString(intPos);
}