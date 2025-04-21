#include <stdio.h>
#include <time.h>

void fill_time(char* time_buffer, char* date_buffer, char* islamic_date_buffer);
void print_stylish_time(const char* time_str, const char* date_str, const char* islamic_date_str);

int main() {
    char time_buffer[100], date_buffer[100], islamic_date_buffer[100];
    fill_time(time_buffer, date_buffer, islamic_date_buffer);
    print_stylish_time(time_buffer, date_buffer, islamic_date_buffer);
    return 0;
}

void fill_time(char* time_buffer, char* date_buffer, char* islamic_date_buffer) {
    time_t t;
    struct tm* tm_info;
    
    time(&t);
    tm_info = localtime(&t);
    
    strftime(time_buffer, 100, "%I:%M:%S %p", tm_info);
    strftime(date_buffer, 100, "%A, %d %B %Y", tm_info);
    
    // Approximate Islamic date calculation (may vary slightly)
    int hijri_day = tm_info->tm_mday - 2; // Rough conversion
    int hijri_month = (tm_info->tm_mon + 1) - 1; // Adjusted for Islamic calendar (approximate)
    char* hijri_months[] = {"Muharram", "Safar", "Rabi' al-Awwal", "Rabi' al-Thani", "Jumada al-Awwal", "Jumada al-Thani", "Rajab", "Sha'ban", "Ramadan", "Shawwal", "Dhul-Qi'dah", "Dhul-Hijjah"};
    
    if (hijri_day <= 0) {
        hijri_day += 30; // Adjust for previous month
        hijri_month = (hijri_month == 0) ? 11 : hijri_month - 1;
    }
    
    sprintf(islamic_date_buffer, "%d %s", hijri_day, hijri_months[hijri_month]);
}

void print_stylish_time(const char* time_str, const char* date_str, const char* islamic_date_str) {
    printf("************************************\n");
    printf("*            \033[1;34mTIME\033[0m                   *\n");
    printf("************************************\n");
    printf("*       \033[1;32m%s\033[0m                 *\n", time_str);
    printf("************************************\n");
    printf("*    \033[1;33m%s\033[0m         *\n", date_str);
    printf("************************************\n");
    printf("*    \033[1;36mIslamic Date: %s\033[0m *\n", islamic_date_str);
    printf("************************************\n");
}
