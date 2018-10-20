#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define Max 320000
using namespace std;

//------------------------------------------------
class HLPP
{
    struct Edge
    {
        int y, d, next;
    };
    Edge edge[Max];
    struct Node
    {
        int x, d;
        bool operator<(const Node &x) const
        {
            return d < x.d;
        }
    };
    priority_queue<Node> que;
    queue<int> Q;
    int gap[Max], high[Max], last[Max], prs[Max];
    int s, t, len, n, m;
    bool vis[Max];
    void Add(int x, int y, int d);
    void Gap(int h);
    void Push(int x);
    void Relable(int x);
    void PushFrist();
    bool Bfs();
    int Calc();

  public:
    void Init(int n, int m);
    void Build(int x, int y, int d);
    int operator()(int s, int t);
};

void HLPP::Init(int n, int m)
{
    this->n = n, this->m = m;
    len = 0;
    s = t = 0;
    memset(last, 0, sizeof last);
    memset(gap, 0, sizeof gap);
    memset(high, 0, sizeof high);
    memset(prs, 0, sizeof prs);
    memset(edge, 0, sizeof edge);
    memset(vis, 0, sizeof vis);
    while (!que.empty())
        que.pop();
}

void HLPP::Add(int x, int y, int d)
{
    len++;
    edge[len] = Edge{y, d, last[x]};
    last[x] = len;
}

void HLPP::Build(int x, int y, int d)
{
    Add(x, y, d);
    Add(y, x, 0);
}

int HLPP::operator()(int s, int t)
{
    this->s = s, this->t = t;
    return Calc();
}

void HLPP::Gap(int h)
{
    for (int i = 1; i <= n; i++)
        if (i != s && i != t && high[i] > h && high[i] <= n)
            high[i] = n + 1;
}

void HLPP::Push(int x)
{
    for (int i = last[x], y = edge[i].y; i; i = edge[i].next, y = edge[i].y)
    {
        if (high[x] == high[y] + 1 && edge[i].d != 0)
        {
            int d = min(prs[x], edge[i].d);
            edge[i].d -= d, edge[i ^ 1].d += d;
            prs[x] -= d, prs[y] += d;
            if (y != s && y != t && vis[y] == 0)
                vis[y] = 1, que.push(Node{y, high[y]});
            if (edge[i].d == 0)
                return;
        }
    }
}

void HLPP::Relable(int x)
{
    high[x] = INF;
    for (int i = last[x], y = edge[i].y; i; i = edge[i].next, y = edge[i].y)
        if (edge[i].d != 0 && high[x] > high[y] + 1)
            high[x] = high[y] + 1;
}

bool HLPP::Bfs()
{
    memset(high, 0x3f, sizeof high);
    high[t] = 0;
    while (!Q.empty())
        que.pop();
    Q.push(t);
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for (int i = last[x], y = edge[i].y; i; i = edge[i].next, y = edge[i].y)
            if (high[y] > high[x] + 1 && edge[i^1].d)
                high[y] = high[x] + 1, Q.push(y);
    }
    return high[s] != 0x3f3f3f3f;
}

void HLPP::PushFrist()
{
    int d;
    for (int i = last[s], y = edge[i].y; i; i = edge[i].next, y = edge[i].y)
    {
        if (d = edge[i].d)
        {
            edge[i].d -= d, edge[i ^ 1].d += d;
            prs[s] -= d, prs[y] += d;
            if (y != s && y != t && vis[y] == 0)
                vis[y] = 1, que.push(Node{y, high[y]});
        }
    }
}

int HLPP::Calc()
{
    while (!que.empty())
        que.pop();
    memset(gap, 0, sizeof gap);
    memset(high, 0, sizeof high);
    memset(prs, 0, sizeof prs);
    if (Bfs() == false)
        return -1;
    high[s] = n;
    for (int i = 1; i <= n; i++)
        if (high[i] < 0x3f3f3f3f)
            gap[high[i]]++;
    PushFrist();
    while (!que.empty())
    {
        int x = que.top().x;
        que.pop();
        Push(x);
        if (prs[x] == 0)
            continue;
        if (x != s && x != t && prs[x])
        {
            if (--gap[high[x]] == 0)
                Gap(high[x]);
            Relable(x);
            ++gap[high[x]];
            que.push(Node{x, high[x]});
        }
    }
    return prs[t];
}
//------------------------------------------------

HLPP h;
int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    h.Init(n, m);
    for (int i = 1, x, y, d; i <= m; i++)
        cin >> x >> y >> d, h.Build(x, y, d);
    cout << h(s, t);
    return 0;
}
//一堆bug
/**
#                       _oo0oo_
#                      o8888888o
#                      88" . "88
#                      (| -_- |)
#                      0\  =  /0
#                    ___/`---'\___
#                  .' \\|     |// '.
#                 / \\|||  :  |||// \
#                / _||||| -:- |||||- \
#               |   | \\\  -  /// |   |
#               | \_|  ''\---/''  |_/ |
#               \  .-\__  '-'  ___/-. /
#             ___'. .'  /--.--\  `. .'___
#          ."" '<  `.___\_<|>_/___.' >' "".
#         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
#         \  \ `_.   \_ __\ /__ _/   .-` /  /
#     =====`-.____`.___ \_____/___.-`___.-'=====
#                       `=---='
#
#
#     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
#               佛祖保佑         永无BUG
* _ooOoo_
* o8888888o
* 88" . "88
* (| -_- |)
*  O\ = /O
* ___/`---'\____
* .   ' \\| |// `.
* / \\||| : |||// \
* / _||||| -:- |||||- \
* | | \\\ - /// | |
* | \_| ''\---/'' | |
* \ .-\__ `-` ___/-. /
* ___`. .' /--.--\ `. . __
* ."" '< `.___\_<|>_/___.' >'"".
* | | : `- \`.;`\ _ /`;.`/ - ` : | |
* \ \ `-. \_ __\ /__ _/ .-` / /
* ======`-.____`-.___\_____/___.-`____.-'======
* `=---='
*     .............................................
*           佛曰：bug泛滥，我已瘫痪！
#
# 　　　┏┓　　　┏┓
# 　　┏┛┻━━━┛┻┓
# 　　┃　　　　　　　 ┃
# 　　┃　　　━　　　 ┃
# 　　┃　┳┛　┗┳　┃
# 　　┃　　　　　　　 ┃
# 　　┃　　　┻　　　 ┃
# 　　┃　　　　　　　 ┃
# 　　┗━┓　　　┏━┛Codes are far away from bugs with the animal protecting
# 　　　　┃　　　┃    神兽保佑,代码无bug
# 　　　　┃　　　┃
# 　　　　┃　　　┗━━━┓
# 　　　　┃　　　　　 ┣┓
# 　　　　┃　　　　 ┏┛
# 　　　　┗┓┓┏━┳┓┏┛
# 　　　　　┃┫┫　┃┫┫
# 　　　　　┗┻┛　┗┻┛
#
# 　　　┏┓　　　┏┓
# 　　┏┛┻━━━┛┻┓
# 　　┃　　　　　　　 ┃ 　
# 　　┃　　　━　　　 ┃
# 　　┃　＞　　　＜┃
# 　　┃　　　　　　　 ┃
# 　　┃ . ⌒　..┃
# 　　┃　　　　　　　 ┃
# 　　┗━┓　　　┏━┛
# 　　　　┃　　　┃　Codes are far away from bugs with the animal protecting　　　　　　　
# 　　　　┃　　　┃ 神兽保佑,代码无bug
# 　　　　┃　　　┃　　　　　　　　　　　
# 　　　　┃　　　┃ 　　　　　　
# 　　　　┃　　　┃
# 　　　　┃　　　┃　　　　　　　　　　　
# 　　　　┃　　　┗━━━┓
# 　　　　┃　　　　　　　┣┓
# 　　　　┃　　　　　　　┏┛
# 　　　　┗┓┓┏━┳┓┏┛
# 　　　　　┃┫┫　┃┫┫
# 　　　　　┗┻┛　┗┻┛
#        ┏┓　　　┏┓+ +
#　　　┏┛┻━━━┛┻┓ + +
#　　　┃　　　　　　　┃ 　
#　　　┃　　　━　　　┃ ++ + + +
#　　 ████━████ ┃+
#　　　┃　　　　　　　┃ +
#　　　┃　　　┻　　　┃
#　　　┃　　　　　　　┃ + +
#　　　┗━┓　　　┏━┛
#　　　　　┃　　　┃　　　　　　　　　　　
#　　　　　┃　　　┃ + + + +
#　　　　　┃　　　┃　　　　Codes are far away from bugs with the animal protecting　　　
#　　　　　┃　　　┃ + 　　　　神兽保佑,代码无bug　　
#　　　　　┃　　　┃
#　　　　　┃　　　┃　　+　　　　　　　　　
#　　　　　┃　 　　┗━━━┓ + +
#　　　　　┃ 　　　　　　　┣┓
#　　　　　┃ 　　　　　　　┏┛
#　　　　　┗┓┓┏━┳┓┏┛ + + + +
#　　　　　　┃┫┫　┃┫┫
#　　　　　　┗┻┛　┗┻┛+ + + +
#                      d*##$.
# zP"""""$e.           $"    $o
#4$       '$          $"      $
#'$        '$        J$       $F
# 'b        $k       $>       $
#  $k        $r     J$       d$
#  '$         $     $"       $~
#   '$        "$   '$E       $
#    $         $L   $"      $F ...
#     $.       4B   $      $$$*"""*b
#     '$        $.  $$     $$      $F
#      "$       R$  $F     $"      $
#       $k      ?$ u*     dF      .$
#       ^$.      $$"     z$      u$$$$e
#        #$b             $E.dW@e$"    ?$
#         #$           .o$$# d$$$$c    ?F
#          $      .d$$#" . zo$>   #$r .uF
#          $L .u$*"      $&$$$k   .$$d$$F
#           $$"            ""^"$$$P"$P9$
#          JP              .o$$$$u:$P $$
#          $          ..ue$"      ""  $"
#         d$          $F              $
#         $$     ....udE             4B
#          #$    """"` $r            @$
#           ^$L        '$            $F
#             RN        4N           $
#              *$b                  d$
#               $$k                 $F
#               $$b                $F
#                 $""               $F
#                 '$                $
#                  $L               $
#                  '$               $
#                   $               $
#
#
#         ┌─┐       ┌─┐
#      ┌──┘ ┴───────┘ ┴──┐
#      │                 │
#      │       ───       │
#      │  ─┬┘       └┬─  │
#      │                 │
#      │       ─┴─       │
#      │                 │
#      └───┐         ┌───┘
#          │         │
#          │         │
#          │         │
#          │         └──────────────┐
#          │                        │
#          │                        ├─┐
#          │                        ┌─┘
#          │                        │
#          └─┐  ┐  ┌───────┬──┐  ┌──┘
#            │ ─┤ ─┤       │ ─┤ ─┤
#            └──┴──┘       └──┴──┘
#                神兽保佑
#                代码无BUG!
#
#                  ___====-_  _-====___
#            _--^^^#####//      \\#####^^^--_
#         _-^##########// (    ) \\##########^-_
#        -############//  |\^^/|  \\############-
#      _/############//   (@::@)   \\############\_
#     /#############((     \\//     ))#############\
#    -###############\\    (oo)    //###############-
#   -#################\\  / VV \  //#################-
#  -###################\\/      \//###################-
# _#/|##########/\######(   /\   )######/\##########|\#_
# |/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|
# `  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '
#    `   `  `      `   / | |  | | \   '      '  '   '
#                     (  | |  | |  )
#                    __\ | |  | | /__
#                   (vvv(VVV)(VVV)vvv)
#                  神兽保佑
#                代码无BUG!
#                                                    __----~~~~~~~~~~~------___
#                                   .  .   ~~//====......          __--~ ~~
#                   -.            \_|//     |||\\  ~~~~~~::::... /~
#                ___-==_       _-~o~  \/    |||  \\            _/~~-
#        __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
#    _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
#  .~       .~       |   \\ -_    /  /-   /   ||      \   /
# /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
# |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
#          '         ~-|      /|    |-~\~~       __--~~
#                      |-~~-_/ |    |   ~\_   _-~            /\
#                           /  \     \__   \/~                \__
#                       _--~ _/ | .-~~____--~-/                  ~~==.
#                      ((->/~   '.|||' -_|    ~~-/ ,              . _||
#                                 -_     ~\      ~~---l__i__i__i--~~_/
#                                 _-~-__   ~)  \--______________--~~
#                               //.-~~~-~_--~- |-------~~~~~~~~
#                                      //.-~~~--\
#                  神兽保佑
#                代码无BUG!
#      ,----------------,              ,---------,
#         ,-----------------------,          ,"        ,"|
#       ,"                      ,"|        ,"        ,"  |
#      +-----------------------+  |      ,"        ,"    |
#      |  .-----------------.  |  |     +---------+      |
#      |  |                 |  |  |     | -==----'|      |
#      |  |  I LOVE DOS!    |  |  |     |         |      |
#      |  |  Bad command or |  |  |/----|`---=    |      |
#      |  |  C:\>_          |  |  |   ,/|==== ooo |      ;
#      |  |                 |  |  |  // |(((( [33]|    ,"
#      |  `-----------------'  |," .;'| |((((     |  ,"
#      +-----------------------+  ;;  | |         |,"
#         /_)______________(_/  //'   | +---------+
#    ___________________________/___  `,
#   /  oooooooooooooooo  .o.  oooo /,   \,"-----------
#  / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,"
# /_==__==========__==_ooo__ooo=_/'   /___________,"
#
#                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
#             __.'              ~.   .~              `.__
#           .'//                  \./                  \\`.
#         .'//                     |                     \\`.
#       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \\`.
#     .'//.-"                 `-.  |  .-'                 "-.\\`.
#   .'//______.============-..   \ | /   ..-============.______\\`.
# .'______________________________\|/______________________________`.
*/
