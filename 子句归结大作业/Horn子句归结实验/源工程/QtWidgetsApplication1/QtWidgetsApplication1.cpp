#pragma execution_character_set("utf-8")
#include "QtWidgetsApplication1.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

static int t_num = 1;

class dot {
public:
	bool ne = false;
	char name;
	int length = 0;
	char list[10];
	char flist[10];

	dot operator=(dot t) {
		this->ne = t.ne;
		this->name = t.name;
		this->length = t.length;
		for (int i = 0; i < 10; i++) {
			this->list[i] = t.list[i];
			this->flist[i] = t.flist[i];
		}
		return *this;
	}
	void inn(char temp[]) {
		int i = 0;
		if (temp[0] == '~') {
			ne = true;
			i++;
		}
		name = temp[i];
		for (i += 2; temp[i] != ')' && temp[i] != '\0'; i++) {
			if (temp[i] >= 'A' && temp[i] <= 'Z') {
				list[length] = temp[i];
				length++;
				i++;
			}
			if (temp[i] == 'x') {
				i++;
				list[length] = temp[i];
				length++;
				i++;
			}
			if (temp[i] >= 'a' && temp[i] <= 'z') {
				list[length] = temp[i];
				length++;
				i += 2;
				if (temp[i] >= 'A' && temp[i] <= 'Z') {
					flist[length - 1] = temp[i];
					i++;
				}
				if (temp[i] == 'x') {
					i++;
					flist[length - 1] = temp[i];
					i++;
				}
				i++;
			}
		}
	}
	bool is_fit(dot a, char change[], char changef[]) {
		char temp, temp2;
		char f1, f2;
		if (this->ne == a.ne) {
			return false;
		}
		if (this->name != a.name) {
			return false;
		}
		if (this->length != a.length) {
			return false;
		}
		for (int i = 0; i < this->length; i++) {
			if (this->list[i] == a.list[i]) {
				if (this->list[i] >= 'a' && this->list[i] <= 'z') {
					if (this->flist[i] == a.flist[i]) {
						continue;
					}
					if (this->flist[i] >= '0' && this->flist[i] <= '9') {
						if (change[this->flist[i] - '0'] == '?') {
							change[this->flist[i] - '0'] = a.flist[i];
							continue;
						}
						else {
							temp = this->flist[i];
							for (;;) {
								temp = change[temp - '0'];
								if (temp >= 'A' && temp <= 'Z') {
									break;
								}
							}
							if (temp == a.flist[i]) {
								continue;
							}
							if (a.flist[i] >= '0' && a.flist[i] <= '9') {
								if (change[a.flist[i] - '0' == '?']) {
									change[a.flist[i] - '0'] = temp;
									continue;
								}
								temp2 = a.flist[i];
								for (;;) {
									temp2 = change[temp2 - '0'];
									if (temp2 >= 'A' && temp2 <= 'Z') {
										break;
									}
								}
								if (temp == temp2) {
									continue;
								}
								else {
									return false;
								}
							}
							return false;
						}
					}
					return false;
				}
				continue;
			}
			if (this->list[i] >= '0' && this->list[i] <= '9') {
				if (change[this->list[i] - '0'] == '?') {
					change[this->list[i] - '0'] = a.list[i];
					if (a.list[i] >= 'a' && a.list[i] <= 'z') {
						changef[this->list[i] - '0'] = a.flist[i];
					}
					continue;
				}
				temp = this->list[i];
				f1 = '?';
				for (; temp >= '0' && temp <= '9';) {
					f1 = changef[temp - '0'];
					temp = change[temp - '0'];
				}
				if (a.list[i] >= '0' && a.list[i] <= '9') {
					if (change[a.list[i] - '0'] == '?') {
						change[a.list[i] - '0'] = temp;
						if (temp >= 'a' && temp <= 'z') {
							changef[a.list[i] - '0'] = f1;
						}
						continue;
					}
					temp2 = a.list[i];
					f2 = '?';
					for (; temp2 >= '0' && temp2 <= '9';) {
						f2 = changef[temp2 - '0'];
						temp2 = change[temp2 - '0'];
					}
				}
				temp2 = a.list[i];
				f2 = '?';
				if (temp == temp2) {
					if (temp >= 'a' && temp <= 'z') {
						if (f1 == f2) {
							continue;
						}
						if (f1 >= '0' && f1 <= '9') {
							if (change[f1 - '0'] == '?') {
								change[f1 - '0'] = f2;
								continue;
							}
							for (; f1 >= '0' && f1 <= '9';) {
								f1 = change[f1 - '0'];
							}
							if (f2 >= '0' && f2 <= '9') {
								if (change[f2 - '0'] == '?') {
									change[f2 - '0'] = f1;
									continue;
								}
								for (; f2 >= '0' && f2 <= '9';) {
									f2 = change[f2 - '0'];
								}
							}
							if (f1 == f2) {
								continue;
							}
							return false;
						}
						return false;
					}
					continue;
				}
				return false;
			}
			if (a.list[i] >= '0' && a.list[i] <= '9') {
				if (change[a.list[i] - '0'] == '?') {
					change[a.list[i] - '0'] = this->list[i];
					if (this->list[i] >= 'a' && this->list[i] <= 'z') {
						changef[a.list[i] - '0'] = this->flist[i];
					}
					continue;
				}
				temp2 = a.list[i];
				f2 = '?';
				for (; temp2 >= '0' && temp2 <= '9';) {
					f2 = changef[temp2 - '0'];
					temp2 = change[temp2 - '0'];
				}
				temp = this->list[i];
				f1 = (temp >= 'a' && temp <= 'z') ? this->flist[i] : '?';
				if (temp == temp2) {
					if (temp >= 'a' && temp <= 'z') {
						if (f1 == f2) {
							continue;
						}
						if (f1 >= '0' && f1 <= '9') {
							if (change[f1 - '0'] == '?') {
								change[f1 - '0'] = f2;
								continue;
							}
							for (; f1 >= '0' && f1 <= '9';) {
								f1 = change[f1 - '0'];
							}
							if (f2 >= '0' && f2 <= '9') {
								if (change[f2 - '0'] == '?') {
									change[f2 - '0'] = f1;
									continue;
								}
								for (; f2 >= '0' && f2 <= '9';) {
									f2 = change[f2 - '0'];
								}
							}
							if (f1 == f2) {
								continue;
							}
							return false;
						}
						return false;
					}
					continue;
				}
				return false;
			}
			return false;
		}
		return true;
	}

	void display(string& s) {
		if (ne) {
			s += '~';
		}
		s = s + name + '(';
		for (int i = 0; i < length; i++) {
			if (list[i] >= '0' && list[i] <= '9') {
				s += 'x';
			}
			s += list[i];
			if (list[i] >= 'a' && list[i] <= 'z') {
				s= s + '(' + flist[i] + ')';
			}
			if (i != length - 1) {
				s+= ',';
			}
		}
		s += ')';
	}

	bool operator==(dot b) {
		if (this->ne != b.ne || this->name != b.name) {
			return false;
		}
		if (this->length != b.length) {
			return false;
		}
		for (int i = 0; i < this->length; i++) {
			if (this->list[i] != b.list[i]) {
				return false;
			}
			if (this->list[i] >= 'a' && this->list[i] <= 'z') {
				if (this->flist[i] != b.flist[i]) {
					return false;
				}
			}
		}
		return true;
	}
};

class line {
public:
	dot dots[10];
	int num = 0;

	char type = 'C';
	short type_num = 0;
	line* p1 = NULL;
	line* p2 = NULL;

	void inn(char temp[]) {
		char bios[100];
		dot* p = NULL;
		int j = 0;
		for (int i = 0;; i++) {
			if (temp[i] == '|' || temp[i] == '\0') {
				bios[j] = '\0';
				bios[j + 1] = '\0';
				bios[j + 2] = '\0';
				p = new dot;
				p->inn(bios);
				dots[num] = *p;
				num++;
				delete p;
				j = 0;
				if (temp[i] == '\0') {
					break;
				}
			}
			else {
				bios[j] = temp[i];
				j++;
			}
		}
	}

	line match(line& a) {
		char change[10] = {
			'?','?','?','?','?','?','?','?','?','?'
		};
		char changef[10] = {
			'?','?','?','?','?','?','?','?','?','?'
		};
		char temp, f;
		for (int i = 0; i < this->num; i++) {
			for (int j = 0; j < a.num; j++) {
				for (int uhi = 0; uhi < 10; uhi++) {
					change[uhi] = '?';
					changef[uhi] = '?';
				}
				if (this->dots[i].is_fit(a.dots[j], change, changef)) {
					line ans;
					ans.num = 0;
					for (int o = 0; o < this->num; o++) {
						if (o == i) {
							continue;
						}
						dot m;
						m = this->dots[o];
						for (int u = 0; u < m.length; u++) {
							temp = m.list[u];
							f = m.flist[u];
							if (temp >= '0' && temp <= '9') {
								for (; temp >= '0' && temp <= '9' && change[temp - '0'] != '?';) {
									f = changef[temp - '0'];
									temp = change[temp - '0'];
								}
							}
							if (f >= '0' && f <= '9') {
								for (; f >= '0' && f <= '9' && change[f - '0'] != '?';) {
									f = change[f - '0'];
								}
							}
							m.flist[u] = f;
							m.list[u] = temp;
						}
						ans.dots[ans.num] = m;
						ans.num++;
					}
					for (int o = 0; o < a.num; o++) {
						if (o == j) {
							continue;
						}
						dot m;
						m = a.dots[o];
						for (int u = 0; u < m.length; u++) {
							temp = m.list[u];
							f = m.flist[u];
							if (temp >= '0' && temp <= '9') {
								for (; temp >= '0' && temp <= '9' && change[temp - '0'] != '?';) {
									f = changef[temp - '0'];
									temp = change[temp - '0'];
								}
							}
							if (f >= '0' && f <= '9') {
								for (; f >= '0' && f <= '9' && change[f - '0'] != '?';) {
									f = change[f - '0'];
								}
							}
							m.flist[u] = f;
							m.list[u] = temp;
						}
						ans.dots[ans.num] = m;
						ans.num++;
					}
					return ans;
				}
			}
		}
		line err;
		err.num = -1;
		err.type_num = -1;
		return err;
	}

	void display(string &s) {
		s =s+ type + to_string(type_num) + ':' + '(' + p1->type + to_string(p1->type_num) + ',' + p2->type + to_string(p2->type_num) + ')' + ' ';
		for (int i = 0; i < num; i++) {
			dots[i].display(s);
			if (i != num - 1) {
				s+='|';
			}
		}
	}
};

vector<line> lines;
static int c_num = 1;
line l_t0;
line l_c0;

vector<line*> lines_p;

void inn_lines(string x, string y) {
	l_c0.type = 'C';
	l_c0.type_num = 0;
	int i=0,j= 0;
	char temp[200];
	while (x[i]) {
		if (x[i] != '\n' && x!="#") {
			temp[j] = x[i];
			j++;
		}
		if (x == "#")
			break;
		if (x[i] == '\n') {
			line lt;
			lt.inn(temp);
			lt.p1 = &l_c0;
			lt.p2 = &l_c0;
			lt.type = 'C';
			lt.type_num = c_num;
			c_num++;
			lines.push_back(lt);
			for (int k = 0; k < 200; k++)
				temp[k] = NULL;
			j = 0;
		}
		i++;
	}

	l_t0.type = 'T';
	l_t0.type_num = 0;

	for (int i = 0; y[i]; i++) {
		temp[i] = y[i];
	}

	char bios[100];
	dot* p = NULL;
	j = 0;
	for (int i = 0;; i++) {
		if (temp[i] == '|' || temp[i] == '\0') {
			bios[j] = '\0';
			bios[j + 1] = '\0';
			bios[j + 2] = '\0';
			p = new dot;
			p->inn(bios);
			p->ne = !p->ne;

			line lt;
			lt.dots[0] = *p;
			lt.num = 1;
			lt.p1 = &l_t0;
			lt.p2 = &l_t0;
			lt.type = 'T';
			lt.type_num = t_num;
			t_num++;
			lines.push_back(lt);

			delete p;
			j = 0;
			if (temp[i] == '\0') {
				break;
			}
		}
		else {
			bios[j] = temp[i];
			j++;
		}
	}
}

bool judge_two(line a, line b) {
	bool flag;
	for (int i = 0; i < a.num; i++) {
		flag = true;
		for (int j = 0; j < b.num; j++) {
			if (a.dots[i] == b.dots[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return false;
		}
	}
	return true;
}

bool judge(line q) {
	for (int i = 0; i < lines.size(); i++) {
		if (judge_two(lines[i], q)) {
			return true;
		}
	}
	return false;
}

void search(string &s) {
	line* p;
	int i, j;
	for (i = 0; i < lines.size(); i++) {
		for (j = 0; j < lines.size(); j++) {
			if (i == j) {
				continue;
			}
			line q = lines[i].match(lines[j]);
			if (q.num == 0) {
				q.p1 = &lines[i];
				q.p2 = &lines[j];
				q.type = 'T';
				q.type_num = t_num;
				s=s+ q.type + to_string(q.type_num) + ':' + '(' + q.p1->type + to_string(q.p1->type_num) + ',' + q.p2->type + to_string(q.p2->type_num) + ')' + ' ';
				s+="□";
				s += "\n";
				lines.push_back(q);
				p = &lines[lines.size() - 1];
				lines_p.push_back(p);
				s+= "归结成功！！！！！！！！！！！！\n";
				return;
			}
			if (q.num == -1) {
				continue;
			}
			if (q.num > 3) {
				continue;
			}
			if (judge(q)) {
				continue;
			}
			q.p1 = &lines[i];
			q.p2 = &lines[j];
			q.type = 'T';
			q.type_num = t_num;
			t_num++;

			q.display(s);

			if (q.num == 1 && q.dots[0].name == 'E') {
				char fun, inn, outt;
				if (q.dots[0].list[0] >= 'a' && q.dots[0].list[0] <= 'z') {
					fun = q.dots[0].list[0];
					inn = q.dots[0].flist[0];
					outt = q.dots[0].list[1];
					for (int uhi = 0; uhi < lines.size(); uhi++) {
						for (int uhj = 0; uhj < lines[uhi].num; uhj++) {
							for (int uhk = 0; uhk < lines[uhi].dots[uhj].length; uhk++) {
								if (lines[uhi].dots[uhj].list[uhk] == fun && lines[uhi].dots[uhj].flist[uhk] == inn) {
									lines[uhi].dots[uhj].list[uhk] = outt;
									lines[uhi].dots[uhj].flist[uhk] = '?';
								}
							}
						}
					}
					s+="                       //对已有子句集进行了一次EQUAL替换";
				}
			}

			s += "\n";
			lines.push_back(q);
		}
	}
	s+= "归结失败！！！！！！！！！！！！\n" ;
	return;
}

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
	//ui = new Ui::QtWidgetsApplication1;
    ui.setupUi(this);
	// connect函数
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(start()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(restart()));
}

void QtWidgetsApplication1::start()
{

	ui.textBrowser->clear();
	t_num = 1;
	c_num = 1;
	lines.clear();
	//  获取输入框的内容；
	QString content = ui.textEdit->toPlainText();
	string content_char = content.toLatin1().data(); 

	QString content2 = ui.textEdit_2->toPlainText();
	string content_char2 = content2.toLatin1().data(); 

	QString result;
	string reschar;
	inn_lines(content_char, content_char2);
	for (int i = 0; i < lines.size(); i++) {
		lines[i].display(reschar);
	}
	reschar += '\n';
	search(reschar);
	result = QString::fromStdString(reschar);
	ui.textBrowser->append(result);    // 将结果输出到结果区域
}


void QtWidgetsApplication1::restart() {
	ui.textBrowser->clear(); 
	ui.textEdit->clear();
	ui.textEdit_2->clear();
	t_num = 1;
	c_num = 1;
	lines.clear();
}
