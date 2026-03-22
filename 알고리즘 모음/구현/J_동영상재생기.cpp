#include <string>
#include <vector>
#include <sstream>

using namespace std;

// string을 int로 바꾸고 시간을 초단위로 바꿈
int converTime(string t){
    string mm = "";
    string ss = "";
    int total;
    
    stringstream time(t);
    getline(time, mm, ':');
    getline(time, ss, ':');
    int min = stoi(mm);
    int sec = stoi(ss);
    total = (min * 60) + sec;
    return total;
}


string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int pos_t,vid_t,op_s,op_e;
    pos_t = converTime(pos); 
    vid_t = converTime(video_len); 
    op_s = converTime(op_start); 
    op_e = converTime(op_end);  

    for (int i = 0; i < commands.size(); i++){
        // 건너뛰기 검사
        if(pos_t >= op_s && pos_t <= op_e){
            pos_t = op_e;
        }
        
        // 10초 후로 이동
        if(commands[i] == "next"){
            pos_t += 10;
            
            // 오프닝 건너뛰기 검사
            if(pos_t >= op_s && pos_t <= op_e){
                pos_t = op_e;
            }
            
            //동영상의 남은 시간이 10초 미만일 경우
            if(vid_t - pos_t < 10 ){
                pos_t = vid_t;
            }  
        }
        
        // 10초 전으로 이동
        else if (commands[i] == "prev"){
            pos_t -= 10;
            
            //오프닝 건너뛰기 검사
            if(pos_t >= op_s && pos_t <= op_e){
                pos_t = op_e;
            }
            
            // 현재 위치가 10초 미만인 경우
            if(pos_t < 10){
                pos_t = 0;
            }  
        }
    }
    
    string min = "";
    string sec = "";
    
    // 분, 초가 한 자리일 경우
    if ((pos_t / 60) < 10){
        min = "0" + to_string(pos_t / 60);
    }else{
        min = to_string(pos_t / 60);
    }
    
    if ((pos_t % 60) < 10){
        sec = "0" + to_string(pos_t % 60);
    }else{
        sec = to_string(pos_t % 60);
    }
    
    answer = min + ":" + sec ;
    
    
    
    return answer;
}