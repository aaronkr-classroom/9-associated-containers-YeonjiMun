//chp7ex7.cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "split.h"

using namespace std;

//�Է¿��� �� �ܾ ������ ��� ���� ã��
map<string, vector<int> >xref(
	istream& in,
	vector<string> find_words(const string&) = split)
{
	string line;

	int line_num = 0;
	map<string, vector<int> > ret;

		//���� ���� ����
		while (getline(in, line)) {
			++line_num;

			//�Է��� ���� �ܾ�� ����
			vector<string> words = find_words(line);

			//���� �࿡ ������ ��� �ܾ ����
			for (vector<string>::const_iterator it = words.begin();
				it != words.end(); ++it) {

				if (find(ret[*it].begin(), ret[*it].end(), line_num) == ret[*it].end()) {
					ret[*it].push_back(line_num);
				}
			}
		}
		return ret;
	}
	
	int main() {
	//�⺻ �μ��� split �Լ��� ����Ͽ� xref�Լ��� ȣ��
	map<string, vector<int> > ret = xref(cin);

	//����� ���
	for (map<string, vector<int> >::const_iterator it = ret.begin();
		it != ret.end(); ++it) {
		//�ܾ ���
		cout << "\"" << it->first << "\" is on line(s): ";

		cout << ((it->second.size() == 1) ? "line: " : "lines: ");

		//�̾ �ϳ� �̻��� �� ��ȣ�� ���
		vector<int>::const_iterator line_it = it->second.begin();

		//�ش� �ܾ ����� ù ��° �� ��ȣ�� ���
		cout << *line_it;
		++line_it;

		//�� ��ȣ�� �� ������ ���� ���
		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
		//�� �ܾ ���� �ܾ�� �����Ϸ��� ���ο� ���� ���
		cout << endl;
	}
	return 0;
}