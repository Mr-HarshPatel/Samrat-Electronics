#include <bits/stdc++.h> 
using namespace std;

// Hash Multiplier
int p = 31;
//	power size	modulo
const int N = 1e5 + 7, m = 1e9 + 7;
// power calculations
vector<long long> power(N);

int main()
{
    string s, t;
    cout << "enter the text \n";
    cin >> t;
    cout << "enter the text to be matched \n";
    cin >> s;
    // string s = "dhruv";
    // string t = "dhruvisgoodboydhruv";
    int T = t.size(), S = s.size();

    power[0] = 1;
    // power calculations
    for (int i = 1; i < N; i++)
    { // applying modulo so that integer doesn't overflow
        power[i] = (power[i - 1] * p) % m;
    }

    //	size , initialize
    vector<long long> h(T + 1, 0);
    // hashing the text
    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * power[i]) % m;
    }

    long long h_s = 0;
    // hashing the text to be matched
    for (int i = 0; i < S; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * power[i]) % m;
    }

    int flag = 0;
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i + S] - h[i] + m) % m; // rolling hashing

        // compare text hash and text to be matched hash
        if (cur_h == (h_s * power[i]) % m)
        {
            flag = 1;
            cout << "Found at index : " << i << "\n";
        }
    }
    if (flag == 0)
    {
        cout << "text is not matched";
    }

    return 0;
}
