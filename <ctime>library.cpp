// #include<iostream>
// #include<fstream>
// #include<ctime>
// using namespace std;

// int main(){
//     // ofstream Myfiles("filename.txt");
//     // Myfiles<<"Files can be tricky, but it is fun enough!";

//     // Myfiles.close();

//     // string myText;
//     // ifstream MyReadFile("filename.txt");
//     // while(getline(MyReadFile,myText)){
//     //     cout<<myText;
//     // }
//     // MyReadFile.close();

//     time_t curr_time=time(NULL);
//     // time(&curr_time);
//     cout<<ctime(&curr_time);
// }


#include<iostream>
#include<ctime>
using namespace std;

int main(){
    // struct tm datetime;
    // time_t timestamp;

    // datetime.tm_year=2025-1900;
    // datetime.tm_mon=12-7;
    // datetime.tm_mday=23;
    // datetime.tm_hour=8;
    // datetime.tm_min=19;
    // datetime.tm_sec=1;
    // datetime.tm_isdst=-1;

    // timestamp=mktime(&datetime);
    // cout<<ctime(&timestamp)<<endl;

    // string weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    // cout << "The date is on a " << weekdays[datetime.tm_wday];
    
    // time_t timestamp=time(&timestamp);
    // struct tm datetime = *localtime(&timestamp);
    // // cout<<ctime(&timestamp);
    // cout<<asctime(&datetime);
    // char output[50];
    // strftime(output, 50, "%B %e, %Y", &datetime);
    // cout << output << "\n";
    // strftime(output, 50, "%I:%M:%S %p", &datetime);
    // cout << output << "\n";
    // strftime(output, 50, "%m/%d/%Y", &datetime);
    // cout << output << "\n";
    // strftime(output, 50, "%a %b %e %H:%M:%S %Y", &datetime);
    // cout << output << "\n";

    // time_t now;
    // time_t nxt;
    // struct tm datetime;

    // now=time(NULL);
    // datetime=*localtime(&now);

    // for(int i=0;i<1e9;++i){

    // }
    // for(int i=0;i<1e9;++i){

    // }
    // for(int i=0;i<1e9;++i){

    // }
    // for(int i=0;i<1e9;++i){

    // }
    // for(int i=0;i<1e9;++i){

    // }

    // nxt=time(NULL);
    // datetime=*localtime(&nxt);

    // int diff=difftime(nxt,now);
    // cout<<diff;

    clock_t before=clock();
    for(int i=0;i<1e9;++i) {}
    clock_t dur=clock()-before;
    cout<<"Duration: "<<(float)dur / CLOCKS_PER_SEC ;
    return 0;
}
