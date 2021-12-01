#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

time_t t;
struct tm *TIME;

/*出缺勤資料結構*/
typedef struct attendance{
    int in_out;                  /*紀錄打上班卡或下班卡，0為上班，1為下班*/
    int clock_time[6] = {0};  /*紀錄打卡的時間 年月日時分秒*/
}ATTENDANCE;

void clock_in(vector<ATTENDANCE> v[]);  /*上班打卡函式*/
void clock_out(vector<ATTENDANCE> v[]); /*下班打卡函式，同上*/
void check(vector<ATTENDANCE> v[]);     /*查詢員工打卡紀錄*/

int main(){
    vector<ATTENDANCE> staff[50];   /*50位員工出缺勤出勤資料，以vector陣列表示*/
    char op;

    while(1){
        cout << "=== 打卡鐘系統 ===" << endl;
        cout << "(1)打上班卡" << endl;
        cout << "(2)打下班卡" << endl;
        cout << "(3)查詢出缺勤" << endl << "> ";
        cin >> op;
        switch(op){
            case '1':
                clock_in(staff);
                break;
            case '2':
                clock_out(staff);
                break;
            case '3':
                check(staff);
                break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}

void clock_in(vector<ATTENDANCE> v[]){
    ATTENDANCE temp;
    int number;

    while(1){
        cout << "請輸入員工編號(1~50): ";
        cin >> number;
        if(number>50 || number<=0){
            cout << "查無員工編號，請重新輸入" << endl;
        }
        else{
            break;
        }
    }

    time(&t);
    TIME = localtime(&t);

    temp.in_out = 0;
    temp.clock_time[0] = TIME->tm_year+1900; /*紀錄時間陣列*/
    temp.clock_time[1] = TIME->tm_mon+1;
    temp.clock_time[2] = TIME->tm_mday;
    temp.clock_time[3] = TIME->tm_hour;
    temp.clock_time[4] = TIME->tm_min;
    temp.clock_time[5] = TIME->tm_sec;

    cout << "上班打卡時間: " << temp.clock_time[0] << "/" << temp.clock_time[1] << "/" << temp.clock_time[2] << " "
         << temp.clock_time[3] << ":" << temp.clock_time[4] << ":" << temp.clock_time[5] << endl;

    v[number-1].push_back(temp);
}

void clock_out(vector<ATTENDANCE> v[]){
    vector<ATTENDANCE>::iterator it;
    ATTENDANCE temp;
    int number;

    while(1){
        cout << "請輸入員工編號(1~50): ";
        cin >> number;
        if(number>50 || number<=0){
            cout << "查無員工編號，請重新輸入" << endl;
        }
        else{
            break;
        }
    }

    time(&t);
    TIME = localtime(&t);

    temp.in_out = 1;
    temp.clock_time[0] = TIME->tm_year+1900; /*紀錄時間陣列*/
    temp.clock_time[1] = TIME->tm_mon+1;
    temp.clock_time[2] = TIME->tm_mday;
    temp.clock_time[3] = TIME->tm_hour;
    temp.clock_time[4] = TIME->tm_min;
    temp.clock_time[5] = TIME->tm_sec;

    /*
    it = v[number-1].end()-1;
    for(int i=0;i<6;i++){
        it->clock_out_time[i] = temp.clock_out_time[i];
    }
    */

    cout << "下班打卡時間: " << temp.clock_time[0] << "/" << temp.clock_time[1] << "/" << temp.clock_time[2] << " "
         << temp.clock_time[3] << ":" << temp.clock_time[4] << ":" << temp.clock_time[5] << endl;

    v[number-1].push_back(temp);
}

void check(vector<ATTENDANCE> v[]){
    int number;
    vector<ATTENDANCE>::iterator it;

    while(1){
        cout << "請輸入員工編號(1~50): ";
        cin >> number;
        if(number>50 || number<=0){
            cout << "查無員工編號，請重新輸入" << endl;
        }
        else{
            break;
        }
    }


    for(it=v[number-1].begin(); it!=v[number-1].end(); it++){
        if(it->in_out == 0)
            cout << "上班打卡時間: ";
        else
            cout << "下班打卡時間: ";
        cout << it->clock_time[0] << "/" << it->clock_time[1] << "/" << it->clock_time[2] << " "
        << it->clock_time[3] << ":" << it->clock_time[4] << ":" << it->clock_time[5] << endl;
    }
}
