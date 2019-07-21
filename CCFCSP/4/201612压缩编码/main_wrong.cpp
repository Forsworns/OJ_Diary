#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 1005;
const int MAXT = 10005;

struct Node{
	int index, freq, level;
	Node* left, *right;
	Node() :index(-1), freq(MAXT), level(0),left(nullptr), right(nullptr){}
	Node(int i, int f) :index(i), freq(f), level(0), left(nullptr), right(nullptr) {}
	Node(int i, int f, int l, Node* le, Node* ri) :index(i), freq(f), level(l), left(le), right(ri) {}
};


vector<Node*> nodes;
vector<Node*> tree;

int main()
{
	freopen("test.txt","r",stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n;++i) {
		int freq;
		cin >> freq;
		nodes.emplace_back(new Node(i, freq));
	}

	int maxLevel = 0;
	while (nodes.size()>1) { // ��Ȼ�е�δ�ϲ������ƹ���������ֻ��ע��Ҷ�ӽ����ֵ���
		sort(nodes.begin(), nodes.end(), [](Node* x, Node* y) {return x->freq < y->freq; });
		Node* nowL = nodes[0];
		Node* nowR = nullptr;
		for (int i = 1; i < nodes.size(); ++i) {
			if (nodes[i]->index == nowL->index + 1 || nodes[i]->index == -1) { // ���ǹ���������ֱ��ȡ�ڶ�����Ϊ�ҽ���ˣ���������ֻ��ȡ�ֵ�����һ��������-1�Ľ��
				nowR = nodes[i];
				nodes.erase(nodes.begin()+i);
				break;
			}
		}
		nodes.erase(nodes.begin());
		int level = max(nowL->level, nowR->level);
		maxLevel = max(maxLevel, level);
		nowL->level = level;
		nowR->level = level;
		nodes.push_back(new Node(-1, nowL->freq + nowR->freq, level + 1, nowL, nowR));
		tree.push_back(nowL);
		tree.push_back(nowR);
	}

	long long ans = 0;
	for (int i = 0; i < tree.size(); ++i) {
		if (tree[i]->index!=-1) {
			ans += (tree[i]->freq*(maxLevel - tree[i]->level)); // ��Ϊʵ�ֵ����⣬���·���level��������͵ģ������ڼ���ʱ����
		}
	}
	cout << ans;
	return 0;
}
