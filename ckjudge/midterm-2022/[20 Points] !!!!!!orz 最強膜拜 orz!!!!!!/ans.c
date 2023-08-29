
int N;
char str[MAX_LEN];
int mx = 0;
#include<string.h>
int min(int x, int y) {return (x > y ? y : x);}
void find_orz(int orz_position[], int *orz_num){
    int idx = 0;
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (i+3 <= n) {
            if (str[i] == 'o' && str[i+1] == 'r' && str[i+2] == 'z') {
                orz_position[idx++] = i;
            }
        } 
        // n-3, n-2, n-1
    }
    *orz_num = idx;
}
void calculate_worship(int worship_amount[], int range_index, int left_orz_position, int right_orz_position){
    int num[26];
    memset(num, 0, sizeof num);
    for (int i = left_orz_position+3; i < right_orz_position; i++) num[str[i]-'a'] ++;
    int ttl = 0;
    for (int i = 0; i < 26; i++) if (num[i] != 0) ttl++;
    worship_amount[range_index] = ttl * (right_orz_position - (left_orz_position+3));
}
int find_max_worship_range(int value, int *range_L, int *range_R, int left_orz_position, int right_orz_position){
    if (value > mx) {
        mx = value;
        *range_L = left_orz_position+1;
        *range_R = right_orz_position+1;
    }
    return mx;
}