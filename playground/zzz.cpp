#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define TEST 0

using namespace std;

void input(int &n, int &m, vector<int> &p);
vector<vector<int> > process(int &n, int &m, int &hit, vector<int> &p, vector<int> &hitv);
void output(vector<int> &p, vector<int> &hitv, vector<vector<int> > &a, int &m, int &hit);

int main()
{
    int n, m, hit = 0;
    vector<int> p;
    vector<int> hitv(m);

    switch (TEST) // TEST 가 1이면 dummy input
    {
        case 0:
            input(n, m, p);
            break;

        case 1:
            n = 3;
            m = 5;
            p = {1,2,2,3,4};

        default:
            break;
    }

    vector<vector<int> > a = process(n, m, hit, p, hitv);
    output(p, hitv, a, m, hit);
}

void input(int &n, int &m, vector<int> &p)
{
    int max_index;
    int process;

    cout << "Enter number of frames\n";
    cin >> n;

    cout << "Enter number of processes\n";
    cin >> m;

    // vector<int> d(m);
    // vector<int> p; // 원소의 개수가 프로세스수 만큼의 백터를 만들고, 0으로 초기화

    cout << "Enter processes\n";
    for (int i = 0; i < m; i++)
    {
        cin >> process;
        p.push_back(process);
    }
}

vector<vector<int> > process(int &n, int &m, int &hit, vector<int> &p, vector<int> &hitv)
{

    vector<vector<int> > a(n, vector<int>(m, -1)); // 백터를 넣는 백터a를 만들고 그안에 n개의 자리가 있으며 그것을 백터로 초기화 하는데 이 백터의 길이는m 개이며 -1로 초기화.\
     즉 이중배열 백터를 만든거임, 지금 a[][] 이런 게 있는거임.
    vector<int> mp(n);                             //페이지 참조 횟수 테이블, 참조안되면 ++ 되면 0으로 바꾸고 나머지 ++, 그리고 몇번째 프레임인지 확인하기 위해서 가장 큰 index값 반환.해서 그곳에 replacement 발생시킴
    map<int, int> lfmp;                            //맵 mp 와 lfmp 두개가 생김

    // 프로세스 하나씩 확인하기 시작함.
    //--------------------------------------------여기부터 프레임에 넣기 시작함
    for (int i = 0; i < m; i++) //프로세스 배열
    {
        for (int j = 0; j < n; j++) //프레임 배열
        {
            if (a[j][i] == -1) // 페이지 폴트이며, 프레임에 아무것도 없음
            {
                a[j][i] = p[i];
                for (int z = 0; z < n; z++)
                {
                    mp[z]++;
                }
                mp[j] = 0;
                break;
            }
            else if (a[j][i] != -1 && a[j][i] != p[i]) //페이지 폴트가 발생, 프레임에 페이지가 들어가있을시
            {
                int max_index = max_element(mp.begin(), mp.end()) - mp.begin(); // 페이지중 사용이 젤 적게 된, 즉 가장 높은 값을 가진 mp의 인덱스를 반환
                cout << max_index << endl;
                a[max_index][i] = p[i];
                for (int h = 0; h < n; h++)
                {
                    mp[h]++;
                }
                mp[max_index] = 0;
                break;
            }
            if (a[j][i] == p[i]) // 페이지 히트가 발생
            {
                for (int z = 0; z < n; z++)
                {
                    mp[z]++;
                }
                mp[j] = 0;
            }
        }
    }
    //------------------------프로세스 히트 검색
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i] == a[j][i - 1])
            {
                hit++;
                hitv[i] = 1;
                break;
            }
        }
    }
    return a;
    //----------------------------------------------여기부터 출력임
}

void output(vector<int> &p, vector<int> &hitv, vector<vector<int> > &a, int &m, int &hit)
{
    cout << "Process ";
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < a.size(); i++)
    {
        cout << "Frame " << i << ":";
        for (int j = 0; j < a[i].size() ; j++)
        {
            if (a[i][j] == -1)
                cout << "E ";
            else
                cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "HIT     ";
    for (int i = 0; i < hitv.size(); i++)
    {
        if (hitv[i] == 0)
            cout << "  ";
        else
            cout << hitv[i] << " ";
    }
    cout << "\n";
    cout << "Hit : " << hit << '\n'
         << "Page Fault : " << m - hit << '\n'
         << "Page Fault Rate : " << float(m - hit) / float(m) << endl;
}



