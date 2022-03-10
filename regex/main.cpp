#include <Windows.h>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <regex>
#include <time.h>

void CheckDuration(std::chrono::duration<int> seconds)
{
    auto start = std::chrono::system_clock::now() + seconds;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto stop = std::chrono::system_clock::now();

    std::cout << "Difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
}

int main()
{
    // CheckDuration(std::chrono::duration<int>(0)); // Difference = 1
    // CheckDuration(std::chrono::duration<int>(1)); // Difference = 0
    // CheckDuration(std::chrono::duration<int>(2)); // Difference = 0 <=== ???
    // CheckDuration(std::chrono::duration<int>(3)); // Difference = -1
    char str[1024] = {0};
    std::string url = "";

    printf("str length %d \n", sizeof(str));
    printf("url length %d \n", sizeof(url));

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(now);
    // std::cout << localtime(&tt) << std::endl;
    struct tm *tmNow = localtime(&tt);
    char date[20] = {0};
    sprintf(date, "%d-%02d-%02d%02d:%02d:%02d", (int)tmNow->tm_year + 1900, (int)tmNow->tm_mon + 1, (int)tmNow->tm_mday, (int)tmNow->tm_hour + 7, (int)tmNow->tm_min, (int)tmNow->tm_sec);
    std::string timeNow(date);
    std::cout << timeNow << "\n"
              << std::endl;

    SYSTEMTIME time;
    GetLocalTime(&time);
    std::cout << time.wMonth << "\n"
              << std::endl;

    if (str[0] == '\0')
    {
        printf("str is null \n");
    }

    std::string ip = "192.168.";
    std::regex ip_regex("(.*)://(.*?)@((\\d|[1-9]\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\.){3}(1\\d\\d|2[0-4]\\d|25[0-5]|[1-9]\\d|\\d)");
    std::smatch match_results;

    if (!std::regex_match(ip,match_results,ip_regex))
    {
        printf("failed");
    }
    else{
        printf("suc");
    }
    printf("\n size=%d",match_results.size());

    return 0;
}