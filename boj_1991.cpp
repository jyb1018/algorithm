#include <iostream>

using namespace std;

//[parent], first == leftchild, second == rightchild
pair<int, int> node[26];

int N;


void preorder(int n) 
{
    if(n == -1)
        return;
    cout << (char)(n + 'A');
    preorder(node[n].first);
    preorder(node[n].second);
}

void inorder(int n) 
{
    if(n == -1)
        return;
    inorder(node[n].first);
    cout << (char)(n + 'A');
    inorder(node[n].second);
}

void postorder(int n)
{
    if(n == -1)
        return;
    postorder(node[n].first);
    postorder(node[n].second);
    cout << (char)(n + 'A');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    //init
    for(int i = 0; i<26; i++)
    {
        node[i].first = -1;
        node[i].second = -1;
    }

    cin >> N;
    string dump;
    getline(cin, dump);
    for(int i = 0; i<N; i++)
    {
        string line;
        getline(cin, line);
        int parent = line.at(0)- 'A';
        int child1 = line.at(2) != '.' ? line.at(2) - 'A' : -1;
        int child2 = line.at(4) != '.' ? line.at(4) - 'A' : -1;

        node[parent].first = child1;
        node[parent].second = child2;
    }

    preorder(0);
    cout << "\n";  
    inorder(0);
    cout << "\n";
    postorder(0);

}