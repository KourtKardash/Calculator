#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
///поменять картинку с хрюшкой!///
using namespace std;
using namespace sf;
Font font;
struct node {
    int coefficient;
    int degree;
    node *next;
};
struct NODE{
    int number;
    node *spisok;
    NODE *next;
};
bool chi_wnd = true;
int number_of_list = 1;
void ins_before(node*& List, int x, int y) {
    node* q = new node;
    *q = *List;
    List->next = q;
    List->coefficient = x;
    List->degree = y;
    return;
}
void ins_after(node*& List, int x, int y){
    node *q = new node;
    q->coefficient = x;
    q->degree = y;
    q->next = List->next;
    List->next = q;
    return;
}
void ins_head(node*&List, int x, int y) {
    node* p = new node;
    p->coefficient = x;
    p->degree = y;
    p->next = List;
    List = p;
    return;
}
void error(string s);
string write_mnogochlen(node* ans_skl);
string perevod_coeff(int a);
int adding() {
    Text t;
    t.setFont(font); t.setPosition(15 , 0); t.setFillColor(Color(239, 169, 74));
    t.setCharacterSize(28); t.setString("Введите номер\n  многочлена,\n который нужно\n     выбрать.\n\n\n Нажмите Enter.");
    Image i; i.loadFromFile("choose-removebg-preview.png");
    Texture te; te.loadFromImage(i);
    Sprite s(te); s.setPosition(200, 0);
    RectangleShape f;
    int a = 60, b = 27;
    f.setSize(Vector2f(a, b));
    f.setPosition(80, 150);
    f.setOutlineThickness(2);
    f.setOutlineColor(Color(238, 118, 33));
    f.setFillColor(Color::White);
    Text vvod; vvod.setPosition(84, 145); vvod.setFont(font); vvod.setFillColor(Color(239, 169, 74));
    vvod.setCharacterSize(28);
    string st;
    int ind = 0, x = 0;
    RenderWindow w(VideoMode(500, 250), "Add");
    while(w.isOpen()){
        Event e;
        while(w.pollEvent(e)){
            switch(e.type){
            case Event::Closed:
                w.close();
            case Event::TextEntered:
                if (e.text.unicode <= '9' && e.text.unicode >= '0') {
                    if(ind<2){
                        st+=e.text.unicode; ++ind;
                        vvod.setString(st);
                        x = x*10+(e.text.unicode-'0');
                    }
                }
            case Event::KeyPressed:
                if (e.key.code == Keyboard::Backspace) {
                    if(ind>-1) {
                        --ind;
                        st.erase(ind , 1);
                        vvod.setString(st);
                        x /= 10;
                    }
                }
                if(e.key.code == Keyboard::Enter) return x;
            }
        }
        w.clear(Color(255, 246, 143));
        w.draw(t); w.draw(s); w.draw(f); w.draw(vvod);
        w.display();
    }
}
int deleting() {
    Text t;
    t.setFont(font); t.setPosition(15 , 0); t.setFillColor(Color(239, 169, 74));
    t.setCharacterSize(28); t.setString("Введите номер\n  многочлена,\n который нужно\n     удалить.\n\n\n Нажмите Enter.");
    Image i; i.loadFromFile("del-removebg-preview.png");
    Texture te; te.loadFromImage(i);
    Sprite s(te); s.setPosition(180, 0);
    RectangleShape f;
    int a = 60, b = 27;
    f.setSize(Vector2f(a, b));
    f.setPosition(80, 150);
    f.setOutlineThickness(2);
    f.setOutlineColor(Color(238, 118, 33));
    f.setFillColor(Color::White);
    Text vvod; vvod.setPosition(84, 145); vvod.setFont(font); vvod.setFillColor(Color(239, 169, 74));
    vvod.setCharacterSize(28);
    string st;
    int ind = 0, x = 0;
    RenderWindow w(VideoMode(500, 250), "Delete");
    while(w.isOpen()){
        Event e;
        while(w.pollEvent(e)){
            switch(e.type){
            case Event::Closed:
                w.close();
            case Event::TextEntered:
                if (e.text.unicode <= '9' && e.text.unicode >= '0') {
                    if(ind<2){
                        st+=e.text.unicode; ++ind;
                        vvod.setString(st);
                        x = x*10+(e.text.unicode-'0');
                    }
                }
            case Event::KeyPressed:
                if (e.key.code == Keyboard::Backspace) {
                    if(ind>-1) {
                        --ind;
                        st.erase(ind , 1);
                        vvod.setString(st);
                        x /= 10;
                    }
                }
                if(e.key.code == Keyboard::Enter) return x;
            }
        }
        w.clear(Color(255, 246, 143));
        w.draw(t); w.draw(s); w.draw(f); w.draw(vvod);
        w.display();
    }
}
int return_coefficient(string s, int &i) {
    if(s[i] == '0') return 0;
    int a = 0;
    while(s[i]!='x' && s[i]!='+' && s[i]!='-' && i!=s.size()) {
        a = a*10+s[i]-'0';
        ++i;
    }
    return ((a==0) ? 1 : a);
}
int baasaa(NODE* B, NODE* BH) {
    Image i;
    i.loadFromFile("original-removebg-preview.PNG");
    Texture i1;
    i1.loadFromImage(i);
    Sprite minion(i1);
    minion.setPosition(350, 400);
    B = BH;
    int kount = 0;
    string s, s_for_vivod;
    while(B!=NULL) {
        s += perevod_coeff(B->number); s+='.'; s += ' ';
        s += write_mnogochlen(B->spisok); s+='\n';
        B = B->next;
        ++kount;
    }
    B = BH;
    Text text, t, td;
    text.setFillColor(Color(239, 169, 74));
    text.setPosition(0, 0);
    text.setFont(font);
    if(kount <= 13) text.setString(s);
    else {
        int k = 0;
        for(int j = 0; j < s.size(); ++j) {
            if(s[j] == '\n') ++k;
            if(k == 13) {s_for_vivod = s.substr(0, j+1); text.setString(s_for_vivod); break;}
        }
    }
    text.setCharacterSize(28);
    t.setCharacterSize(20); t.setString("Удалить"); t.setFont(font);
    t.setFillColor(Color(239, 169, 74)); t.setPosition(100, 530); t.setStyle(Text::Underlined);
    td.setCharacterSize(20); td.setString("Добавить"); td.setFont(font);
    td.setFillColor(Color(239, 169, 74)); td.setPosition(95, 560); td.setStyle(Text::Underlined);
    RenderWindow wnd(VideoMode(500 , 600) , "Base");
    while(wnd.isOpen()) {
        Event e;
        while(wnd.pollEvent(e)) {
            switch(e.type) {
                case Event::Closed:
                wnd.close();
                case Event::MouseButtonPressed:
                    if (IntRect(100 , 530 , 90 , 20).contains(Mouse::getPosition(wnd))){
                        int x = deleting();
                        if(x!=0){
                            kount = 0; --number_of_list;
                            if(x == 1) {
                                NODE* Q = BH;
                                BH = BH->next;
                                B = BH;
                                delete Q;
                                while(B!=NULL) {
                                    --B->number;
                                    B = B->next;
                                }
                                B = BH;
                            }
                            else{
                                for(int i = 1; i < x-1; ++i) B = B->next;
                                NODE* Q = B->next;
                                B->next = B->next->next;
                                delete Q;
                                B = B->next;
                                while(B!=NULL) {
                                    --B->number;
                                    B = B->next;
                                }
                                B = BH;
                            }
                            s.clear();
                            while(B!=NULL) {
                                s += perevod_coeff(B->number); s+='.'; s += ' ';
                                s += write_mnogochlen(B->spisok); s+='\n';
                                B = B->next;
                                ++kount;
                            }
                            B = BH;
                            if(kount <= 13) text.setString(s);
                            else {
                                int k = 0;
                                for(int j = 0; j < s.size(); ++j) {
                                    if(s[j] == '\n') ++k;
                                    if(k == 13) {s_for_vivod = s.substr(0, j+1); text.setString(s_for_vivod); break;}
                                }
                            }
                        }
                    }
                    if (IntRect(95 , 560 , 90 , 20).contains(Mouse::getPosition(wnd))){
                        int y = adding();
                        return y;
                    }
                case Event::KeyPressed:
                    if(kount>13){
                        if(e.key.code == Keyboard::Up) {
                            if(s_for_vivod[0]!='1') {
                                int h = s.find(s_for_vivod); h-=2; int k = 1;
                                while(s[h] != '\n') {
                                    if(h == 0) {++k; --h; break;}
                                    --h; ++k;
                                } ++h;
                                int kk = 0;
                                s_for_vivod = s.substr(h, k+s_for_vivod.size());
                                for(int f = 0; f < s_for_vivod.size(); ++f) {
                                    if(s_for_vivod[f] == '\n') ++kk;
                                    if(kk == 13) {
                                        s_for_vivod = s_for_vivod.substr(0, f+1);
                                        break;
                                    }
                                }
                                text.setString(s_for_vivod);
                            }
                        }
                        if(e.key.code == Keyboard::Down) {
                            int h = s.find(s_for_vivod)+s_for_vivod.size();
                            for(int j = h; j < s.size(); ++j){
                                if(s[j] == '\n') {
                                    s_for_vivod += s.substr(h, j-h+1);
                                    break;
                                }
                            }
                            h = s_for_vivod.find('\n');
                            s_for_vivod = s_for_vivod.substr(h+1);
                            text.setString(s_for_vivod);
                        }
                    }
                }
            }
        if (IntRect(100 , 530 , 90 , 20).contains(Mouse::getPosition(wnd))) t.setColor(Color(238, 118, 33));
        else t.setColor(Color(239, 169, 74));
        if (IntRect(95 , 560 , 90 , 20).contains(Mouse::getPosition(wnd))) td.setColor(Color(238, 118, 33));
        else td.setColor(Color(239, 169, 74));
        wnd.clear(Color(255, 246, 143));
        wnd.draw(minion);
        wnd.draw(text); wnd.draw(t); wnd.draw(td);
        wnd.display();
    }
    return 0;
}
bool normal_symbols(string s, int i) {
    return (s[i] == 'x' || s[i] == '+' || s[i] == '-' || s[i] == '^' || isdigit(s[i]));
}
bool flag = true;
void error(string str) {
    Image i;
    i.loadFromFile("wp5347456-removebg-preview-removebg-preview.png");
    Texture t;
    t.loadFromImage(i);
    Sprite s(t);
    s.setPosition(0 , 0);
    Text text;
    text.setFillColor(Color(239, 169, 74));
    text.setPosition(200, 0);
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(28);
    RenderWindow w(VideoMode(400, 220), "ERROR");
    while (w.isOpen()) {
        Event e;
        while(w.pollEvent(e)) {
            switch (e.type) {
            case Event::Closed:
                w.close();
            }
        }
        w.clear(Color(255, 246, 143));
        w.draw(s);
        w.draw(text);
        w.display();
    }
    return;
}
///СОХРАНЕНИЕ В БАЗУ - ВОПРОС///
bool saving(){
    Image i; i.loadFromFile("вопрос-removebg-preview.png");
    Texture t; t.loadFromImage(i);
    Sprite s(t); s.setPosition(0, 0);
    Text te, t_yes, t_no; te.setFillColor(Color(239, 169, 74)); te.setFont(font);
    te.setCharacterSize(33); te.setPosition(290, 0); te.setString("Сохранить\nмногочлен\n  в базу?");
    t_yes.setFillColor(Color(239, 169, 74)); t_yes.setFont(font); t_yes.setStyle(Text::Underlined|Text::Bold);
    t_yes.setCharacterSize(33); t_yes.setPosition(290, 130); t_yes.setString("Да");
    t_no.setFillColor(Color(239, 169, 74)); t_no.setFont(font); t_no.setStyle(Text::Underlined|Text::Bold);
    t_no.setCharacterSize(33); t_no.setPosition(370, 130); t_no.setString("Неть");
    RenderWindow w(VideoMode(500, 250), "Save?");
    while(w.isOpen()) {
        Event e;
        while(w.pollEvent(e)) {
            switch (e.type) {
            case Event::Closed:
                w.close();
            case Event::MouseButtonPressed:
                if(IntRect(290 , 130 , 50 , 35).contains(Mouse::getPosition(w))) return true;
                if(IntRect(370 , 130 , 75 , 35).contains(Mouse::getPosition(w))) return false;
            }
        }
        if (IntRect(290 , 130 , 50 , 35).contains(Mouse::getPosition(w))) t_yes.setColor(Color(238, 118, 33));
        else t_yes.setColor(Color(239, 169, 74));
        if (IntRect(370 , 130 , 75 , 35).contains(Mouse::getPosition(w))) t_no.setColor(Color(238, 118, 33));
        else t_no.setColor(Color(239, 169, 74));
        w.clear(Color(255, 246, 143));
        w.draw(s); w.draw(te); w.draw(t_yes); w.draw(t_no);
        w.display();
    }
}
int argument() {
    string s = "Найти значение\nмногочлена\nв точке ";
    Text text, tet;
    text.setFillColor(Color(239, 169, 74)); tet.setFillColor(Color(239, 169, 74));
    text.setPosition(10, 0); tet.setPosition(50,120);
    text.setFont(font); tet.setFont(font);
    text.setCharacterSize(28); tet.setCharacterSize(35);
    text.setString(s); tet.setString("Найти!"); tet.setStyle(Text::Bold);
    RectangleShape f;
    int a = 115, b = 50;
    f.setSize(Vector2f(a, b));
    f.setPosition(50, 120);
    f.setOutlineThickness(2);
    f.setOutlineColor(Color(238, 118, 33));
    f.setFillColor(Color(255, 246, 143));
    Image im;
    im.loadFromFile("Dave-removebg-preview.png");
    Texture t;
    t.loadFromImage(im);
    Sprite sp(t);
    sp.setPosition(250 , 0);
    RectangleShape p;
    a = 80, b = 27;
    int i = 33, x = 0;
    p.setSize(Vector2f(a , b));
    p.setPosition(112, 70);
    p.setOutlineColor(Color(239, 169, 74));
    p.setFillColor(Color(255 , 255 , 255));
    p.setOutlineThickness(2);
    bool v = true;
    RenderWindow w(VideoMode(400, 200) , "Argument");
    while (w.isOpen()) {
        Event e;
        while(w.pollEvent(e)) {
            switch (e.type) {
            case Event::Closed:
                w.close();
            case Event::TextEntered:
                if(e.text.unicode == '-') {
                    v = false;
                    s+=e.text.unicode; ++i;
                    text.setString(s);
                }
                if (e.text.unicode <= '9' && e.text.unicode >= '0') {
                    if(i<38){
                        s+=e.text.unicode; ++i;
                        text.setString(s);
                        x = x*10+(e.text.unicode-'0');
                    }
                }
            case Event::KeyPressed:
                if (e.key.code == Keyboard::Backspace) {
                    if(i>33) {
                        s.erase(i , 1); --i;
                        text.setString(s);
                        x /= 10;
                    }
                }
            case Event::MouseButtonPressed:
                if(IntRect(50 , 120 , 105 , 48).contains(Mouse::getPosition(w))){
                    if(!v)return -1*x; else return x;
                }
            }
        }
        if (IntRect(50 , 120 , 105 , 48).contains(Mouse::getPosition(w))) tet.setColor(Color(238, 118, 33));
        else tet.setColor(Color(239, 169, 74));
        w.clear(Color(255, 246, 143));
        w.draw(p); w.draw(f);
        w.draw(text);
        w.draw(sp); w.draw(tet);
        w.display();
    }
}
int poryadok_proizvodnoy() {
    string s = "   Введите\n  циферку -\n   порядок\nпроизводной\n";
    Text t, text;
    t.setFillColor(Color(239, 169, 74)); text.setFillColor(Color(239, 169, 74));
    t.setFont(font); text.setFont(font);
    t.setCharacterSize(28); text.setCharacterSize(28);
    t.setPosition(10, 0); text.setPosition(68, 130);
    t.setString(s);
    RectangleShape q;
    q.setOutlineThickness(2);
    q.setOutlineColor(Color(238, 118, 33));
    q.setFillColor(Color::White);
    int a = 60, b = 27;
    q.setSize(Vector2f(a, b));
    q.setPosition(60, 134);
    Image i;
    i.loadFromFile("хрюшка-removebg-preview.png");
    Texture te;
    te.loadFromImage(i);
    Sprite sp(te);
    sp.setPosition(230 , 0);
    int in = 0, x = 0; string st;
    RectangleShape f;
    a = 117, b = 40;
    f.setSize(Vector2f(a, b));
    f.setPosition(40, 174);
    f.setOutlineThickness(2);
    f.setOutlineColor(Color(238, 118, 33));
    f.setFillColor(Color(255, 246, 143));

    Text tet;
    tet.setFillColor(Color(239, 169, 74));
    tet.setCharacterSize(35);
    tet.setString("Найти!"); tet.setStyle(Text::Bold);
    tet.setFont(font);
    tet.setPosition(43, 174);
    RenderWindow w(VideoMode(400, 230) , "Poryadok");
    while (w.isOpen()) {
        Event e;
        while(w.pollEvent(e)) {
            switch (e.type) {
            case Event::Closed:
                w.close();
            case Event::TextEntered:
                if (e.text.unicode <= '9' && e.text.unicode >= '0') {
                    if(in<2){
                        st+=e.text.unicode; ++in;
                        text.setString(st);
                        x = x*10+(e.text.unicode-'0');
                    }
                }
            case Event::KeyPressed:
                if (e.key.code == Keyboard::Backspace) {
                    if(in>-1) { --in;
                        st.erase(in , 1);
                        text.setString(st);
                        x /= 10;

                    }
                }
            case Event::MouseButtonPressed:
                if(IntRect(40 , 174 , 115 , 40).contains(Mouse::getPosition(w))) return x;
            }
        }
        if (IntRect(40 , 174 , 115 , 40).contains(Mouse::getPosition(w))) tet.setColor(Color(238, 118, 33));
        else tet.setColor(Color(239, 169, 74));
        w.clear(Color(255, 246, 143));
        w.draw(q); w.draw(f); w.draw(tet);
        w.draw(t);
        w.draw(sp); w.draw(text);
        w.display();
    }
}
node* rahuvaty_proiz(node*& a, node*& a_head) {
    while(a!=NULL) {
        a->coefficient*=a->degree;
        a->degree -= 1;
        a = a->next;
    }
    a = a_head;
    return a;
}
int number_of_calls = 0;
void automat(string s) {
    try{
        ++number_of_calls;
        int i = 0;
        int minus = s.find('-'); if(minus == -1) minus = 100500;
        int plus = s.find('+'); if(plus == -1) plus = 100500;
        if (plus == 0) {
            cout << number_of_calls;
            if(number_of_calls == 1) throw "Зачем вы\nначинаете\nстроку с\nплюса?";
            else throw "Зачем вы\nпоставили\nлишний плюс?";
        }
        if(minus == 0 && number_of_calls != 1) throw "Зачем вы\nпоставили\nлишний\nминус?";
        if(abs(plus-minus) == 1) throw "Я не готов\nбыл увидеть\n2 знака\nподряд.";
        int znak = min(plus, minus);
        if(plus != minus) {
            while(i < znak) {
                if(!isdigit(s[i])) break;
                ++i;
            }
            if(i == znak) {
                automat(s.substr(i+1));
                return;
            }
            else {
                if(!normal_symbols(s, i)) {
                    string strok = "Неопознанный\nсимвол "; strok+=s[i];
                    throw strok;
                }
                else if(s[i] == 'x') ++i;
                else {
                    string strok = "Я не ожидал\nувидедеть\nзнак "; strok+=s[i];
                    throw strok;
                }
            }
            if(i == znak) {
                automat(s.substr(i+1));
                return;
            }
            else {
                if(!normal_symbols(s, i)) {
                    string strok = "Неопознанный\nсимвол "; strok+=s[i];
                    throw strok;
                }
                else if(s[i] == '^') {
                    ++i;
                    if(s[i] == '-') throw "Степень икса\nдолжна быть\nнатуральной";
                    if(s[i] == '+') throw "Я знаю, что\nстепень\nмногочлена\nнатуральное\nчисло!\nУберите плюс!";
                }
                else throw "После икса\nя ожидал\nувидеть\nзнак степени\nили +, или -";
            }
            while(i < znak) {
                if(!isdigit(s[i])) break;
                ++i;
            }
            if(i == znak) {
                automat(s.substr(i+1));
                return;
            }
            else {
                if(!normal_symbols(s, i)) {
                    string strok = "Неопознанный\nсимвол "; strok+=s[i];
                    throw strok;
                }
                else throw "Некорректно\nвведена\nстепень икса";
            }
        }
        else
        {
            if(s.empty()) throw "Почему знак\nзавершает\nмногочлен?";
            while(i < s.size()) {
                if(!isdigit(s[i])) break;
                ++i;
            }
            if(i == s.size()) return;
            else {
                if(!normal_symbols(s, i)) {
                    string strok = "Неопознанный\nсимвол "; strok+=s[i];
                    throw strok;
                }
                else if(s[i] == 'x') ++i;
                else {
                    string strok = "Я не ожидал\nувидедеть\nзнак "; strok+=s[i];
                    throw strok;
                }
            }
            if(i == s.size()) return;
            else
            {
                if(!normal_symbols(s, i)) {
                    string strok = "Неопознанный\nсимвол "; strok+=s[i];
                    throw strok;
                }
                else if(s[i] == '^') {
                    ++i;
                    if(s[i] == '-') throw "Степень икса\nдолжна быть\nнатуральной";
                    if(s[i] == '+') throw "Я знаю, что\nстепень\nмногочлена\nнатуральное\nчисло!\nУберите плюс!";
                }
                else throw "После икса\nя ожидал\nувидеть\nзнак степени\nили +, или -";
            }
            while(i < s.size()) {
                if(!isdigit(s[i])) break;
                ++i;
            }
            if(i == s.size()) return;
            else {
                if(!normal_symbols(s, i)) {
                    string strok = "Неопознанный\nсимвол "; strok+=s[i];
                    throw strok;
                }
                else throw "Некорректно\nвведена\nстепень икса";
            }
        }
    }
    catch (const char* strok) {
        if(chi_wnd) error(strok);
        flag = false;
        return;
    }
    catch(string stro) {
        if(chi_wnd) error(stro);
        flag = false;
        return;
    }
}
void returning_numbers(string s, node*&L, node*&List) {
    int j = 1, x , y;
    if(s[0] == '-') x = -1*return_coefficient(s, j);
    else x = return_coefficient(s, j);
    if(s[j] == 'x') {
        if(s[j+1] == '^') {
            j+=2;
            y = return_coefficient(s, j);
        }
        else {
            y = 1; ++j;
        }
    }
    else y = 0;
    if(List == NULL) {
        ins_head(List, x, y);
        L = List;
        if(s[j] == '+' || s[j] == '-') returning_numbers(s.substr(j), L, List);
    }
    while(List->next != NULL){
        if(List->degree == y) {
            List->coefficient += x;
            List = L;
            if(s[j] == '+' || s[j] == '-') returning_numbers(s.substr(j), L, List);
            return;
        }
        if(List->degree < y) {
            if(List == L) {
                ins_head(L, x, y);
                List = L;
                if(s[j] == '+' || s[j] == '-') returning_numbers(s.substr(j), L, List);
                return;
            }
            else {
                ins_before(List, x, y);
                List = L;
                if(s[j] == '+' || s[j] == '-') returning_numbers(s.substr(j), L, List);
                return;
            }
        }
        List = List->next;
    }
    if(List->degree == y) {
        List->coefficient += x;
        List = L;
        if(s[j] == '+' || s[j] == '-') returning_numbers(s.substr(j), L, List);
        return;
    }
    if(List->degree < y) {
        if(List == L) {
            ins_head(L, x, y);
            List = L;
            if(s[j] == '+' || s[j] == '-') returning_numbers(s.substr(j), L, List);
            return;
        }
        else {
            ins_before(List, x, y);
            List = L;
            if(s[j] == '+' || s[j] == '-') returning_numbers(s.substr(j), L, List);
            return;
        }
    }
    ins_after(List, x , y);
    List = L;
    if(s[j] == '+' || s[j] == '-') returning_numbers(s.substr(j), L, List);
    return;
}
void delete_nols(node*& List, node*& L){
    while(List->next!=NULL) {
        if(List->next->coefficient == 0) {
            node* q = new node;
            q = List->next;
            List->next = List->next->next;
            delete q;
        }
        else List = List->next;
    }
    if(L->coefficient == 0) {
        node* q = new node;
        q = L;
        L = L->next;
        delete q;
    }
    return;
}
inline node* skladennya(node* List, node* List1) {
    node* merged_lists = NULL;
    if(List == NULL && List1 == NULL) {
        ins_head(merged_lists, 0, 0);
        return merged_lists;
    }
    else if(List == NULL) return List1;
    else if(List1 == NULL) return List;
    if(List->degree > List1->degree) {
        merged_lists = List;
        merged_lists->next = skladennya(List->next, List1);
    }
    else if(List->degree == List1->degree) {
        merged_lists = List;
        merged_lists->coefficient += List1->coefficient;
        merged_lists->next = skladennya(List->next, List1->next);
    }
    else {
        merged_lists = List1;
        merged_lists->next = skladennya(List, List1->next);
    }
    return merged_lists;
}
void multiplication(node*& a, node*& b, int x, int y) {                  /////now/////
    while(a->next != NULL){
        if(a->degree == y) {
            a->coefficient += x;
            a = b;
            return;
        }
        if(a->degree < y) {
            if(a == b) {
                ins_head(b, x, y);
                a=b;
                return;
            }
            else {
                ins_before(a, x, y);
                a=b;
                return;
            }
        }
        a = a->next;
    }
    if(a->degree == y) a->coefficient += x;
    else if(a->degree < y) {
        if(a == b) ins_head(b, x, y);
        else ins_before(a, x, y);
    }
    else ins_after(a, x , y);
    a=b;
    return;
}
string perevod_coeff(int a) {
    string s;
    if(a == 0) return s+='0';
    int b = a, ko = 0;;
    while(b != 0) {
        b/=10;
        ++ko;
    }
    for(int i = 0; i < ko; ++i) {
        char x = a/pow(10, ko-i-1)+'0';
        s += x;
        int j = 1;
		for(int h = 0; h < ko-i-1; ++h) j*=10;
		a = a%j;
    }
    return s;
}
string write_mnogochlen(node* ans_skl) {
    string viv;
    if(ans_skl == NULL) return viv+='0';
    if(abs(ans_skl->coefficient) == 1) {
        if(ans_skl->degree == 0) {
            if(ans_skl->coefficient == 1) viv+='1';
            else {viv+='-'; viv+='1';}
        }
        if(ans_skl->degree != 0 && ans_skl->coefficient == -1) viv+='-';
    }
    else {
        if(ans_skl->coefficient < 0) viv+='-';
        viv+=perevod_coeff(abs(ans_skl->coefficient));
    }
    if(ans_skl->degree == 1) {
        viv+='x';
        ans_skl = ans_skl->next;
    }
    else if(ans_skl->degree == 0) ans_skl = ans_skl->next;
    else {
        viv+='x'; viv+='^';
        viv+=perevod_coeff(ans_skl->degree);
        ans_skl = ans_skl->next;
    }
    for(node* it = ans_skl; it != NULL; it=it->next) {
        if(abs(ans_skl->coefficient) == 1) {
            if(ans_skl->degree == 0 && ans_skl->coefficient == 1) {viv+='+'; viv+='1';}
            if(ans_skl->degree == 0 && ans_skl->coefficient == -1) {viv+='-'; viv+='1';}
            if(ans_skl->degree != 0 && ans_skl->coefficient == -1) viv+='-';
            if(ans_skl->degree != 0 && ans_skl->coefficient == 1) viv+='+';
        }
        else {
            if(ans_skl->coefficient > 0) viv+='+';
            if(ans_skl->coefficient < 0) viv+='-';
            viv+=perevod_coeff(abs(ans_skl->coefficient));
        }
        if(ans_skl->degree == 1) {
            viv+='x';
            ans_skl = ans_skl->next;
        }
        else if(ans_skl->degree == 0) ans_skl = ans_skl->next;
        else {
            viv+='x'; viv+='^';
            viv+=perevod_coeff(ans_skl->degree);
            ans_skl = ans_skl->next;
        }
    }
    return viv;
}
int pow(int c, int d) {
    if(d == 0) return 1;
    if(d == 1) return c;
    int x = c;
    for(int i = 1; i < d; ++i) x *= c;
    return x;
}
int znachennya_ukrapki(node*List, int a) {
    int x = 0;
    while(List!=NULL){
        x += pow(a, List->degree)*List->coefficient;
        List = List->next;
    }
    return x;
}

void write(node* List) {
    for(node* it = List; it != NULL; it = it->next) cout << it->coefficient << " " << it->degree << "\n";
    return;
}

node *dilyty(node *&List, node *&L, node *&List1, node *&L1) {
    node *ans = NULL, *ans_h = NULL;
    while(L->degree >= L1->degree) {
        int x = List->coefficient/List1->coefficient;
        int y = List->degree-List1->degree;
        if(List->coefficient%List1->coefficient != 0) {
            //List = L;
            break;
        }
        if(ans == NULL) {
            ins_head(ans, x, y);
            ans_h = ans;
        }
        else {
            ins_after(ans, x, y);
            ans = ans->next;
        }
        while(List1!=NULL){
            List1->coefficient*=x;
            List1->degree+=y;
            List1 = List1->next;
        }
        List1 = L1;
        while(List != NULL) {
            if(List1 == NULL) break;
            else {
                if(List->degree == List1->degree) {
                    List->coefficient -= List1->coefficient;
                    List = List->next; List1 = List1->next;
                }
                else if(List->degree > List1->degree) List = List->next;
                else {
                    ins_before(List, -List1->coefficient, List1->degree);
                    List = List->next; List1 = List1->next;
                }
            }
        }
        if(List == NULL&&List1 != NULL) {
            List = L;
            while(List->next != NULL) List = List->next;
            while(List1!=NULL) {
                ins_after(List, -List1->coefficient, List1->degree);
                List = List->next; List1 = List1->next;
            }
        }
        List = L; List1 = L1;
        while(List1 != NULL) {
            List1->coefficient /= x;
            List1->degree -= y;
            List1 = List1->next;
        }
        List1 = L1;
        delete_nols(List, L);
        List = L;
        if(L == NULL) {
            break;
        }
        //write_mnogochlen(L); cout << "\n";
    }
    return ans_h;
}

double znachennya(node *List, double x) {
    double y = 0;
    while(List != NULL) {
        y += pow(x, List->degree) * List->coefficient;
        List = List->next;
    }
    return y;
}
void cicl(Uint32 pix[600][600] , int x , int y) {
    for (y = 0; y < 600; ++y) {
        for (x = 0; x < 600; ++x) {
            pix[y][x] = 0;
        }
    }
    return;
}
///ГРАФИК///
void graph(node *List) {
    Image im;
    im.loadFromFile("mmm-removebg-preview.png");
    Texture te;
    te.loadFromImage(im);
    Sprite spr(te);
    spr.setPosition(430,426);
    double x1, y1, doub = 1.0 , x2 , y2;
    int x, y, razmer;
    razmer = 30;
    int k = 0;
    ///int color_line = 1384322608;
    int color_line = 3000000000;     ///1й цвет
    int color_line1 = 7894023651;
    int color_line2 = 6524700000;
    int os_x = 300; int os_y = 300;

    RenderWindow wnd (VideoMode(600, 600), "Graphic");
    Uint32 pix[600][600];
    Texture tx;
    tx.create(600, 600);
    Sprite sprite(tx);
    sprite.setPosition(0, 0);
    Text text; //ось1
    Text txt;  //ось2
    cicl(pix, x, y);
    while (wnd.isOpen()) {
        Event event;
        while (wnd.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    cicl(pix, x, y);
                    wnd.close();
                case Event::MouseButtonPressed:
                    if((Mouse::getPosition(wnd).x<595)*(Mouse::getPosition(wnd).x>545)*(Mouse::getPosition(wnd).y<55)*(Mouse::getPosition(wnd).y>5)) {
                        ++razmer;
                        cicl(pix , x , y);
                    }
                    if((Mouse::getPosition(wnd).x<540)*(Mouse::getPosition(wnd).x>490)*(Mouse::getPosition(wnd).y<55)*(Mouse::getPosition(wnd).y>5)) {
                        --razmer;
                        cicl(pix , x , y);
                    }
                    if(IntRect(430 ,426, 170, 180).contains(Mouse::getPosition(wnd))) cicl(pix, x, y);
                case Event::KeyPressed:
                if (event.key.code == Keyboard::Enter) ++k;
                if (event.key.code == Keyboard::Up) {
                    cicl(pix , x , y);
                    os_x += 5;
                }
                if (event.key.code == Keyboard::Down) {
                    os_x -= 5;
                    cicl(pix , x , y);
                }
                if (event.key.code == Keyboard::Right) {
                    os_y -= 5;
                    cicl(pix , x , y);
                }
                if (event.key.code == Keyboard::Left) {
                    os_y += 5;
                    cicl(pix , x , y);
                }
                default:
                    break;
            }
        }
        wnd.clear();
        Texture herotexture;
        herotexture.loadFromFile("1680699.jpg");
        Sprite herosprite;
        herosprite.setTexture(herotexture);
        herosprite.setPosition(545, 5);
        Texture herotexture1;
        herotexture1.loadFromFile("1680699-.jpg");
        Sprite herosprite1;
        herosprite1.setTexture(herotexture1);
        herosprite1.setPosition(490, 5);
        RectangleShape t;
        t.setSize(Vector2f(razmer,razmer));
        t.setFillColor(Color(255,255,184));
        t.setOutlineThickness(1);
        t.setOutlineColor(Color(0,0,0));
        for (int i = os_x; i <= 600 ; i+=razmer) {
            for (int j = os_y; j+razmer > 0 ; j-=razmer) {
                t.setPosition(j , i);
                wnd.draw(t);
            }
        }
        for (int i = os_x; i <= 600 ; i+=razmer) {
            for (int j = os_y; j <= 600 ; j+=razmer) {
                t.setPosition(j , i);
                wnd.draw(t);
            }
        }
        for (int i = os_x; i+razmer > 0 ; i-=razmer) {
            for (int j = os_y; j+razmer > 0 ; j-=razmer) {
                t.setPosition(j , i);
                wnd.draw(t);
            }
        }
        for (int i = os_x; i+razmer > 0 ; i-=razmer) {
            for (int j = os_y; j <= 600 ; j+=razmer) {
                t.setPosition(j , i);
                wnd.draw(t);
            }
        }
        RectangleShape q;
        q.setSize(Vector2f(600.f,2.f));
        q.setPosition(0 , os_x);
        q.setFillColor(Color(0,0,0));
        wnd.draw(q);
        q.setSize(Vector2f(2.f,600.f));
        q.setPosition(os_y , 0);
        wnd.draw(q);
        Text text("x" , font , 24);
        text.setFillColor(Color::Black);
        text.setPosition(580,os_x);
        Text txt("y" , font , 24);
        txt.setFillColor(Color::Black);
        txt.setPosition(os_y-20,0);
        if (k%3 == 0) {
            for (y = 0; y < 600; ++y) {
                y1 = (os_x*doub - y)/razmer;
                for (x = 0; x < 600; ++x) {
                    x1 = (x - os_y*doub)/razmer;
                    double z = znachennya(List, x1);
                    if (z+0.3 >= y1 && z-0.3 <= y1) {
                        pix[y][x] = color_line;
                    }
                }
            }
        }
        else if (k%3 == 1){
            for (y = 0; y < 600; ++y) {
                y1 = (os_x*doub - y)/razmer;
                for (x = 0; x < 600; ++x) {
                    x1 = (x - os_y*doub)/razmer;
                    double z = znachennya(List, x1);
                    if (z+0.3 >= y1 && z-0.3 <= y1) {
                        pix[y][x] = color_line1;
                    }
                }
            }
        }
        else {
            for (y = 0; y < 600; ++y) {
                y1 = (os_x*doub - y)/razmer;
                for (x = 0; x < 600; ++x) {
                    x1 = (x - os_y*doub)/razmer;
                    double z = znachennya(List, x1);
                    if (z+0.3 >= y1 && z-0.3 <= y1) {
                        pix[y][x] = color_line2;
                    }
                }
            }
        }
        tx.update((Uint8*)pix, 600, 600, 0, 0);
        wnd.draw(sprite);
        wnd.draw(herosprite);
        wnd.draw(herosprite1);
        wnd.draw(text);
        wnd.draw(txt); wnd.draw(spr);
        wnd.display();
    }
    return;
}
int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int pos_b = 132 , index_stroki = -1;     //pos_b для вывода кнопок, индекс для вывода строки
    Texture t;
    t.loadFromFile("texture1.JPG");     //розочки
    Sprite s(t);
    char znak;
    Image buttons , s1200 , input , cancel , str; cancel.loadFromFile("cancel-1294426_1280-removebg-preview.png");
    buttons.loadFromFile("yellow.jpg");
    s1200.loadFromFile("oran.jpg");
    input.loadFromFile("orange.png");
    str.loadFromFile("28-removebg-preview.png");          //кнопки
    bool true_sign = false, adding_from_base = true;
    NODE* BASA = NULL; NODE* BASA_head;       ///base///
    Texture buttont , buttonx , inp , cancel1 , strelka; cancel1.loadFromImage(cancel);
    buttont.loadFromImage(buttons);
    buttonx.loadFromImage(s1200);
    inp.loadFromImage(input);
    strelka.loadFromImage(str);

    Sprite strrr(strelka);
    strrr.setPosition(500 , 40);
    Sprite cancel2(cancel1);
    cancel2.setPosition(540 , 40);
    Sprite in(inp);
    in.setPosition(155 , 335);

    Sprite b1(buttonx);
    b1.setPosition(15 , 110);
    Sprite b2(buttonx);
    b2.setPosition(15 , 223);

    Sprite button(buttont);
    button.setPosition(pos_b, 110);
    pos_b += 117;
    Sprite button1(buttont);
    button1.setPosition(pos_b, 110);
    pos_b+=117;
    Sprite button2(buttont);
    button2.setPosition(pos_b , 110);
    pos_b+=117;
    Sprite button3(buttont);
    button3.setPosition(pos_b , 110);
    pos_b = 132;

    Sprite button4(buttont);
    button4.setPosition(pos_b , 223);
    pos_b += 117;
    Sprite button5(buttont);
    button5.setPosition(pos_b , 223);
    pos_b += 117;
    Sprite button6(buttont);
    button6.setPosition(pos_b , 223);
    pos_b += 117;
    Sprite button7(buttont);
    button7.setPosition(pos_b , 223);
    pos_b += 117;
    font.loadFromFile("ArialRegular.ttf");
    Text plus , sign;
    plus.setFont(font); sign.setFont(font);
    plus.setString("+");
    plus.setCharacterSize(90); sign.setCharacterSize(50);
    plus.setPosition(155 , 100); sign.setPosition(286 , 482);
    plus.setFillColor(Color(255 , 140 , 0)); sign.setFillColor(Color(112 , 0 , 89));
    Text minus;
    minus.setFont(font);
    minus.setString("-");
    minus.setCharacterSize(95);
    minus.setPosition(285 , 90);
    minus.setFillColor(Color(255 , 140 , 0));
    Text umn;
    umn.setFont(font);
    umn.setString("*");
    umn.setCharacterSize(90);
    umn.setPosition(400 , 120);
    umn.setFillColor(Color(255 , 140 , 0));
    Text del;
    del.setFont(font);
    del.setString("/");
    del.setCharacterSize(85);
    del.setPosition(521 , 102);
    del.setFillColor(Color(255 , 140 , 0));
    Text proc;
    proc.setFont(font);
    proc.setString("f(x)");
    proc.setCharacterSize(60);
    proc.setPosition(140 , 229);
    proc.setFillColor(Color(255 , 140 , 0));
    Text proiz;
    proiz.setFont(font);
    proiz.setString("f'(x)");
    proiz.setCharacterSize(57);
    proiz.setPosition(254 , 232);
    proiz.setFillColor(Color(255 , 140 , 0));
    Text kor , nol;
    kor.setFont(font); nol.setFont(font);
    kor.setString("x"); nol.setString("o");
    kor.setCharacterSize(80); nol.setCharacterSize(45);
    kor.setPosition(395 , 215); nol.setPosition(436 , 260);
    kor.setFillColor(Color(255 , 140 , 0)); nol.setFillColor(Color(255 , 140 , 0));
    Text step;
    step.setFont(font);
    step.setString("file");
    step.setCharacterSize(50);
    step.setPosition(503 , 240);
    step.setFillColor(Color(255 , 140 , 0));

    Text x;
    x.setFont(font);
    x.setString("x");
    x.setCharacterSize(80);
    x.setPosition(45 , 100);
    x.setFillColor(Color(139,69,0));
    Text y;
    y.setFont(font);
    y.setString("^");
    y.setCharacterSize(80);
    y.setPosition(45 , 222);
    y.setFillColor(Color(139,69,0));

    Text i;
    i.setFont(font);
    i.setString("Input");
    i.setCharacterSize(60);
    i.setPosition(235 , 330);
    i.setFillColor(Color(139,69,0));

    Text understand , basa;
    understand.setFont(font); basa.setFont(font);
    understand.setString("Understand"); basa.setString("Base");
    understand.setCharacterSize(20); basa.setCharacterSize(20);
    understand.setPosition(250 , 700); basa.setPosition(283 , 723);
    understand.setFillColor(Color(205 , 102 , 0)); basa.setFillColor(Color(205,102,0));
    understand.setStyle(Text::Underlined); basa.setStyle(Text::Underlined);
    Text graphic; graphic.setFont(font); graphic.setString("Graph");
    graphic.setCharacterSize(20); graphic.setPosition(278 ,746); graphic.setFillColor(Color(205,102,0));
    graphic.setStyle(Text::Underlined);

    int a = 570; int b = 80;
    RectangleShape vvod;
    vvod.setSize(Vector2f(a,b));
    vvod.setPosition(15 , 15);
    vvod.setFillColor(Color(255 , 255 , 255));
    vvod.setOutlineColor(Color(205,102,0));
    vvod.setOutlineThickness(2);

    int c = 570 , d = 360;
    RectangleShape base;
    base.setSize(Vector2f(c,d));
    base.setPosition(15 , 420);
    base.setFillColor(Color(255, 255, 255, 128));
    //base.setFillColor(Color(183 , 120 , 248));
    base.setOutlineColor(Color(205,102,0));
    base.setOutlineThickness(2);

    bool p = false;
    string stroka, stroka_d;
    Text text;
    text.setPosition(Vector2f(20,28));
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(Color(205,102,0));

    int k = 0;
    Text text_base1 , text_base2;
    text_base1.setFont(font); text_base2.setFont(font);
    text_base1.setCharacterSize(35); text_base2.setCharacterSize(35);
    text_base1.setFillColor(Color(205,102,0)); text_base2.setFillColor(Color(205,102,0));
    text_base1.setPosition(Vector2f(20,430)); text_base2.setPosition(Vector2f(20,523));
    Text text_answer;
    text_answer.setFont(font);
    text_answer.setCharacterSize(35);
    text_answer.setFillColor(Color(205,102,0));
    text_answer.setPosition(Vector2f(20, 616));

    RenderWindow w(VideoMode(600 , 800) , "Calculator");
    while(w.isOpen()) {
        sf::Event event;
        while(w.pollEvent(event)) {
            switch(event.type) {
                case Event::Closed:
                w.close();
                case Event::TextEntered:
                    if (event.text.unicode <= '~' && event.text.unicode >= '!') {
                        stroka+=event.text.unicode; ++index_stroki;
                        text.setString(stroka);
                        if(index_stroki == 23) {
                            stroka_d += stroka[0];
                            stroka.erase(0, 1); --index_stroki;
                            text.setString(stroka);
                        }
                    }
                case sf::Event::KeyPressed:
                    if (event.key.code == Keyboard::Backspace) {
                        if(index_stroki>-1){stroka.erase(index_stroki , 1); --index_stroki;
                        text.setString(stroka);}
                    }
                    ///////////////****база****///////////////
                    if(event.key.code == Keyboard::Enter) baasaa(BASA, BASA_head);

                case Event::MouseButtonPressed:
                    node *List;
                    node *List1;
                    node *L;
                    node *L1;
                    node* Listforbase = NULL; node* Lforbase = NULL;
                    node *ans_skl, *ans_head;
                    //node *ans_skl;
                    //node *ans_head;
                    if (IntRect(132 , 110 , 102 , 98).contains(Mouse::getPosition(w))) {
                        if (p) {
                            true_sign = true;
                            stroka.insert(0 , 1 , 40);
                            stroka+=41; stroka+='+';
                            text_base1.setString(stroka);
                            stroka.erase(0); index_stroki = -1;
                            text.setString(stroka);
                            p = false;
                            znak = '+';
                        }
                        else {
                        stroka+='+'; ++index_stroki;
                        text.setString(stroka);}
                    }
                    if (IntRect(249 , 110 , 102 , 98).contains(Mouse::getPosition(w))) {
                        if (p) {
                            true_sign = true;
                            stroka.insert(0 , 1 , 40);
                            stroka += 41; stroka+='-';
                            text_base1.setString(stroka);
                            stroka.erase(0); index_stroki = -1;
                            text.setString(stroka);
                            p = false;
                            znak = '-';
                        }
                        else{
                        stroka+='-'; ++index_stroki;
                        text.setString(stroka);}
                    }
                    if(IntRect(132, 223, 102, 98).contains(Mouse::getPosition(w))) {
                        --k;
                        int a = argument();
                        stroka.clear(); index_stroki = -1;
                        text.setString(stroka);
                        stroka = "Значение многочлена в точке ";
                        if(a < 0) stroka += '-';
                        stroka+=perevod_coeff(abs(a)); stroka += ':';
                        text_base2.setString(stroka);
                        stroka.clear(); index_stroki = -1;
                        int b = znachennya_ukrapki(List, a);
                        if(b<0) stroka = '-';
                        stroka += perevod_coeff(abs(b));
                        text_answer.setString(stroka);
                        stroka.clear(); index_stroki = -1;
                    }
                    if (IntRect(366 , 110 , 102 , 98).contains(Mouse::getPosition(w))) {
                        if(p) {
                            true_sign = true;
                            znak = '*';
                            stroka.insert(0 , 1 , 40); stroka+=41;
                            stroka+='*';
                            text_base1.setString(stroka);
                            stroka.clear(); index_stroki = -1;
                            text.setString(stroka);
                            p = false;
                        }
                    }
                    if (IntRect(483 , 110 , 102 , 98).contains(Mouse::getPosition(w))) {
                        if(p) {
                            true_sign = true;
                            stroka.insert(0 , 1 , 40);
                            stroka +=41;
                            stroka+='/';
                            znak = '/';
                            text_base1.setString(stroka);
                            stroka.clear(); index_stroki = -1;
                            text.setString(stroka);
                            p = false;
                        }
                    }
                    if (IntRect(336 , 223 , 102 , 98).contains(Mouse::getPosition(w))) { ///ЦЕЛЫЕ КОРНИ///
                        --k;
                        stroka.clear(); index_stroki = -1;
                        text.setString(stroka);
                        stroka = "Целые корни многочлена:";
                        text_base2.setString(stroka);
                        stroka.clear();
                        List = L;
                        while(List->next!=NULL) List = List->next;
                        if(List->degree != 0) {stroka+='0'; stroka+=','; stroka+=' ';}
                        int x = abs(List->coefficient);
                        List = L;
                        for(int i = 1; i <= x; ++i) {
                            if(x%i == 0) {
                                if(znachennya_ukrapki(List, i) == 0) {
                                    stroka+=perevod_coeff(i); List = L; stroka += ','; stroka += ' ';
                                }
                                if(znachennya_ukrapki(List, -i) == 0) {
                                    stroka+='-'; stroka+=perevod_coeff(i); List = L; stroka += ','; stroka += ' ';
                                }
                            }
                        }
                        if(!stroka.empty()) stroka.erase(stroka.size()-2, 2);
                        else stroka = "Целых корней нет";
                        text_answer.setString(stroka);
                        stroka.clear();
                    }
                    if (IntRect(483 , 223 , 102 , 98).contains(Mouse::getPosition(w))) { ///FOR GRAPHIC///
                        ifstream fin("полиномы.txt"); string file_str; chi_wnd = false;
                        while(getline(fin, file_str)) {
                            for(int j = 0; j < file_str.size(); ++j){
                                if (file_str[j] == ' '){
                                    file_str.erase(j, 1);
                                    --j;
                                }
                            }
                            automat(file_str);
                            if(flag) {
                                node* b = NULL, *bh;
                                int i , x , y;
                                if(file_str[0] == '-') {
                                    i = 1;
                                    x = -1*return_coefficient(file_str, i);
                                } else {
                                    i = 0;
                                    x = return_coefficient(file_str, i);
                                }
                                if(file_str[i] == 'x') {
                                    if(file_str[i+1] == '^') {
                                        i+=2;
                                        y = return_coefficient(file_str, i);
                                    } else {
                                        y = 1; ++i;
                                    }
                                }
                                else y = 0;
                                node* p1 = new node;
                                p1->coefficient = x;
                                p1->degree = y;
                                p1->next = b;
                                b = p1;
                                bh = b;
                                if(file_str[i] == '+' || file_str[i] == '-') returning_numbers(file_str.substr(i), bh, b);
                                b = bh;
                                delete_nols(b, bh); b = bh;
                                if(number_of_list == 1) {
                                    NODE* Q = new NODE;
                                    Q->spisok = b;
                                    Q->number = number_of_list;
                                    Q->next = BASA;
                                    BASA = Q;
                                    BASA_head = BASA;
                                    ++number_of_list;
                                }
                                else {
                                    NODE *P = new NODE;
                                    P->spisok = b;
                                    P->number = number_of_list;
                                    P->next = BASA->next;
                                    BASA->next = P;
                                    BASA = BASA->next;
                                    ++number_of_list;
                                }
                            }
                            else flag = true;
                        }
                        chi_wnd = true;
                    }
                    if (IntRect(15 , 110 , 102 , 98).contains(Mouse::getPosition(w))) {
                        stroka+='x'; ++index_stroki;
                        text.setString(stroka);
                    }
                    if (IntRect(15 , 223 , 102 , 98).contains(Mouse::getPosition(w))) {
                        stroka+='^'; ++index_stroki;
                        text.setString(stroka);
                    }
                    if (IntRect(249 , 223 , 102 , 98).contains(Mouse::getPosition(w))) { ///Производная///
                        --k;
                        true_sign = true;
                        stroka.clear(); index_stroki = -1;
                        text.setString(stroka);
                        stroka = "Производная ";
                        int x = poryadok_proizvodnoy();
                        stroka+=perevod_coeff(x);
                        stroka+=" порядка равна:";
                        text_base2.setString(stroka);
                        stroka.clear(); index_stroki = -1;
                        node* ans = List; node* a_head = L;
                        for(int i = 0; i < x; ++i){
                            ans = rahuvaty_proiz(ans, a_head);
                            delete_nols(ans, a_head);
                            ans = a_head;
                            if(a_head == NULL) break;
                        }
                        stroka = write_mnogochlen(ans);
                        text_answer.setString(stroka);
                        stroka.clear(); index_stroki = -1;
                        ans_skl = ans; ans_head = a_head;
                    }

                    if (IntRect(540 , 40 , 31 , 30).contains(Mouse::getPosition(w))) {
                        stroka.erase(0); index_stroki = -1;
                        text.setString(stroka);

                    }
                    if (IntRect(500 , 40 , 31 , 31).contains(Mouse::getPosition(w))) {
                        if(index_stroki>-1){stroka.erase(index_stroki , 1); --index_stroki;
                        text.setString(stroka);}
                    }
                    if (IntRect(150 , 330 , 310 , 78).contains(Mouse::getPosition(w))) {
                        ++k;
                        if(!stroka_d.empty()) {
                            stroka_d += stroka;
                            stroka = stroka_d; stroka_d.clear();
                        }
                        if(k%2 != 0) {
                            automat(stroka);
                            number_of_calls = 0;
                            if(flag) {
                                List = NULL;
                                p = true;
                                int i , x , y;
                                if(stroka[0] == '-') {
                                    i = 1;
                                    x = -1*return_coefficient(stroka, i);
                                }
                                else {
                                    i = 0;
                                    x = return_coefficient(stroka, i);
                                }
                                if(stroka[i] == 'x') {
                                    if(stroka[i+1] == '^') {
                                        i+=2;
                                        y = return_coefficient(stroka, i);
                                    }
                                    else {
                                        y = 1; ++i;
                                    }
                                }
                                else y = 0;
                                node* p1 = new node;
                                p1->coefficient = x;
                                p1->degree = y;
                                p1->next = List;
                                List = p1;
                                L = List;
                                if(stroka[i] == '+' || stroka[i] == '-') returning_numbers(stroka.substr(i), L, List);
                                List = L;
                                delete_nols(List, L); List = L;

                                    ///РАЗБИРАЕМСЯ С КОПИЕЙ СПИСКА///
                                //if(L != NULL) {
                                    if(adding_from_base){
                                        ins_head(Listforbase, List->coefficient, List->degree);
                                        Lforbase = Listforbase;
                                        List = List->next;
                                        while(List!=NULL) {
                                            ins_after(Listforbase, List->coefficient, List->degree);
                                            Listforbase = Listforbase->next;
                                            List = List->next;
                                        }
                                        List = L;
                                        Listforbase = Lforbase;
                                        if(number_of_list == 1) {
                                            NODE* Q = new NODE;
                                            Q->spisok = Listforbase;
                                            Q->number = number_of_list;
                                            Q->next = BASA;
                                            BASA = Q;
                                            BASA_head = BASA;
                                            ++number_of_list;
                                        }
                                        else {
                                            NODE *P = new NODE;
                                            P->spisok = Listforbase;
                                            P->number = number_of_list;
                                            P->next = BASA->next;
                                            BASA->next = P;
                                            BASA = BASA->next;
                                            ++number_of_list;
                                        }
                                    }
                                //}
                                //sp = NULL;
                                stroka = write_mnogochlen(List); List = L;
                                if(stroka.size()>28){
                                    for(int j = 27; j > -1; --j) {
                                        if(stroka[j] == '+' || stroka[j] == '-') {
                                            stroka.insert(j+1, 1, '\n');
                                            break;
                                        }
                                    }
                                }
                                text_base1.setString(stroka);
                            }
                            else {
                                flag = true; --k;
                            }
                        }
                        else if(k%2 == 0) {
                            automat(stroka);
                            number_of_calls = 0;
                            if(flag) {
                                List1 = NULL;
                                int i , x , y;
                                if(stroka[0] == '-') {
                                    i = 1;
                                    x = -1*return_coefficient(stroka, i);
                                }
                                else {
                                    i = 0;
                                    x = return_coefficient(stroka, i);
                                }
                                if(stroka[i] == 'x') {
                                    if(stroka[i+1] == '^') {
                                        i+=2;
                                        y = return_coefficient(stroka, i);
                                    }
                                    else {
                                        y = 1; ++i;
                                    }
                                }
                                else y = 0;
                                node* q = new node;
                                q->coefficient = x;
                                q->degree = y;
                                q->next = List1;
                                List1 = q;
                                L1 = List1;
                                if(stroka[i] == '+' || stroka[i] == '-') returning_numbers(stroka.substr(i), L1, List1);
                                List1 = L1;
                                delete_nols(List1, L1); List1 = L1;
                                List1 = L1;
                                if(L1!=NULL){
                                    ins_head(Listforbase, List1->coefficient, List1->degree);
                                    Lforbase = Listforbase;
                                    List1 = List1->next;
                                    while(List1!=NULL){
                                        ins_after(Listforbase, List1->coefficient, List1->degree);
                                        Listforbase = Listforbase->next;
                                        List1 = List1->next;
                                    }
                                    List1 = L1;
                                    Listforbase = Lforbase;
                                    NODE *S = new NODE;
                                    S->spisok = Listforbase;
                                    S->number = number_of_list;
                                    S->next = BASA->next;
                                    BASA->next = S;
                                    BASA = BASA->next;
                                    ++number_of_list;
                                }
                                stroka = write_mnogochlen(List1); List1 = L1;
                                if(stroka.size()>28){
                                    for(int j = 27; j > -1; --j) {
                                        if(stroka[j] == '+' || stroka[j] == '-') {
                                            stroka.insert(j+1, 1, '\n');
                                            break;
                                        }
                                    }
                                }
                                stroka.insert(0 , 1 , 40);
                                stroka +=41; stroka += 61; text_base2.setString(stroka);
                                if(znak == '+' || znak == '-') {
                                    if(znak == '-') {
                                        while(List1 != NULL) {
                                            List1->coefficient *= -1;
                                            List1 = List1->next;
                                        }
                                    }
                                    List1 = L1;
                                    ans_skl = skladennya(List, List1);        //список об'явлю глобально
                                    List = L; List1 = L1;
                                    ans_head = ans_skl;
                                    delete_nols(ans_skl, ans_head);
                                    stroka = write_mnogochlen(ans_head);
                                    if(stroka.size()>28){
                                        for(int j = 27; j > -1; --j) {
                                            if(stroka[j] == '+' || stroka[j] == '-') {
                                                stroka.insert(j+1, 1, '\n');
                                                break;
                                            }
                                        }
                                    }
                                    text_answer.setString(stroka);
                                    if(znak == '-') {
                                        while(List1 != NULL) {
                                            List1->coefficient *= -1;
                                            List1 = List1->next;
                                        }
                                    }
                                    List1 = L1;
                                    stroka.clear(); index_stroki = -1;
                                    text.setString(stroka);
                                }
                                if(znak == '*') {
                                    List = L; List1 = L1; node* a = NULL; node *ah = NULL;
                                    if(List != NULL && List1 != NULL) {
                                        int x = (List->coefficient)*(List1->coefficient);
                                        int y = (List->degree)+(List1->degree);
                                        ins_head(a, x, y);
                                        ah = a;
                                        List1 = List1->next;
                                        while(List!=NULL) {
                                            while(List1!=NULL) {
                                                int x = (List->coefficient)*(List1->coefficient);
                                                int y = (List->degree)+(List1->degree);
                                                multiplication(a, ah, x, y);
                                                List1 = List1->next;
                                            }
                                            List = List->next;
                                            List1 = L1;
                                        }
                                        a = ah;
                                        delete_nols(a, ah);
                                        a = ah;
                                    }
                                    else ah = NULL;
                                    stroka = write_mnogochlen(ah);
                                    if(stroka.size()>28){
                                        for(int j = 27; j > -1; --j) {
                                            if(stroka[j] == '+' || stroka[j] == '-') {
                                                stroka.insert(j+1, 1, '\n');
                                                break;
                                            }
                                        }
                                    }
                                    text_answer.setString(stroka);
                                    stroka.clear(); index_stroki = -1; text.setString(stroka);
                                    ans_skl = a; ans_head = ah;
                                }
                                if(znak == '/') {
                                    List = L; List1 = L1; node* a = NULL; node *ah = NULL;
                                    if(List != NULL && List1 != NULL) {
                                        ah = dilyty(List, L, List1, L1);
                                        a = ah;
                                    }
                                    else {
                                        if(L1 == NULL) {
                                            error("Вы сдурели\nна ноль\nделить?");
                                            stroka.clear(); index_stroki = -1;
                                            text_base1.setString(stroka); text_base2.setString(stroka);
                                            text.setString(stroka);
                                        }
                                        else if(L == NULL) ah = NULL;
                                    }
                                    if(L1!=NULL) {
                                        stroka = write_mnogochlen(ah); stroka += ' ';
                                        stroka += '('; stroka += write_mnogochlen(L); stroka+=')';
                                        if(stroka.size()>28){
                                            for(int j = 27; j > -1; --j) {
                                                if(stroka[j] == '+' || stroka[j] == '-') {
                                                    stroka.insert(j+1, 1, '\n');
                                                    break;
                                                }
                                            }
                                        }
                                        text_answer.setString(stroka);
                                        stroka.clear(); index_stroki = -1; text.setString(stroka);
                                        ans_skl = a; ans_head = ah;
                                    }
                                }
                            }
                            else {flag = true; --k;}
                        }
                    }
                    if (IntRect(283 , 723 , 54 , 20).contains(Mouse::getPosition(w))) {
                        int y = baasaa(BASA, BASA_head);
                        BASA = BASA_head;
                        if(y != 0) {
                            adding_from_base = false;
                            for(int i = 1; i < y; ++i) BASA = BASA->next;
                            stroka = write_mnogochlen(BASA->spisok);
                            text.setString(stroka);
                            index_stroki = stroka.size();
                        }
                        while(BASA->next!=NULL) BASA = BASA->next;
                    }
                    if (IntRect(250 , 700 , 105 , 20).contains(Mouse::getPosition(w))) {
                        text_base1.setString(stroka);
                        text_base2.setString(stroka);
                        text_answer.setString(stroka);
                        if(true_sign) {
                            true_sign = false;
                            ///ВЫЗВАТЬ ФУНКЦИЮ ВОПРОСА О СОХРАНЕНИИ МНОГОЧЛЕНА///
                            if(saving()) {
                                NODE *P = new NODE;
                                P->spisok = ans_head;         ///МЕНЯТЬ СПИСОК///
                                P->number = number_of_list;
                                P->next = BASA->next;
                                BASA->next = P;
                                BASA = BASA->next;
                                ++number_of_list;
                            }
                        }
                    }
                    if(IntRect(278 ,746, 60, 20).contains(Mouse::getPosition(w))) {
                        if(k%2!=0){
                            graph(List);
                            --k;
                            stroka.clear(); index_stroki = -1;
                            text.setString(stroka); text_base1.setString(stroka);
                        }
                    }
                }
            }
        w.clear(Color(112 , 0 , 89));

        if (IntRect(249 , 110 , 102 , 98).contains(Mouse::getPosition(w))) button1.setColor(Color(255,193,37));
        else button1.setColor(Color(255 , 255 , 255));
        if (IntRect(366 , 110 , 102 , 98).contains(Mouse::getPosition(w))) button2.setColor(Color(255,193,37));
        else button2.setColor(Color(255 , 255 , 255));
        if (IntRect(483 , 110 , 102 , 98).contains(Mouse::getPosition(w))) button3.setColor(Color(255,193,37));
        else button3.setColor(Color(255 , 255 , 255));

        if (IntRect(132 , 223 , 102 , 98).contains(Mouse::getPosition(w))) button4.setColor(Color(255,193,37));
        else button4.setColor(Color(255 , 255 , 255));
        if (IntRect(249 , 223 , 102 , 98).contains(Mouse::getPosition(w))) button5.setColor(Color(255,193,37));
        else button5.setColor(Color(255 , 255 , 255));
        if (IntRect(366 , 223 , 102 , 98).contains(Mouse::getPosition(w))) button6.setColor(Color(255,193,37));
        else button6.setColor(Color(255 , 255 , 255));
        if (IntRect(483 , 223 , 102 , 98).contains(Mouse::getPosition(w))) button7.setColor(Color(255,193,37));
        else button7.setColor(Color(255 , 255 , 255));

        if (IntRect(15 , 110 , 102 , 98).contains(Mouse::getPosition(w))) b1.setColor(Color(205,102,0));     //x
        else b1.setColor(Color(255 , 255 , 255));
        if (IntRect(15 , 223 , 102 , 98).contains(Mouse::getPosition(w))) b2.setColor(Color(205,102,0));     //y
        else b2.setColor(Color(255 , 255 , 255));

        if (IntRect(150 , 330 , 310 , 78).contains(Mouse::getPosition(w))) in.setColor(Color(205,102,0));     //input
        else in.setColor(Color(255 , 255 , 255));

        w.draw(s);
        w.draw(vvod); w.draw(base);

        w.draw(button); w.draw(button1); w.draw(button2); w.draw(button3);
        w.draw(button4); w.draw(button5); w.draw(button6); w.draw(button7);

        w.draw(plus); w.draw(minus); w.draw(umn);
        w.draw(del); w.draw(proc);w.draw(proiz);
        w.draw(kor); w.draw(nol);
        w.draw(step);
        w.draw(b1); w.draw(b2);
        w.draw(x); w.draw(y);
        w.draw(in); w.draw(i);
        w.draw(cancel2); w.draw(strrr);
        w.draw(text); w.draw(text_base1); w.draw(text_base2); w.draw(understand); w.draw(basa); w.draw(text_answer);
        w.draw(graphic);

        if (IntRect(540 , 40 , 31 , 30).contains(Mouse::getPosition(w)))         //крестик
            cancel2.setColor(Color(178 , 34 , 34));
        else cancel2.setColor(Color(255 , 255 , 255));

        if (IntRect(500 , 40 , 31 , 31).contains(Mouse::getPosition(w)))           //стрелочка-стёрка
            strrr.setColor(Color(178 , 34 , 34));
        else strrr.setColor(Color(255 , 255 , 255));

        if (IntRect(132 , 110 , 102 , 98).contains(Mouse::getPosition(w)))
            button.setColor(Color(255,193,37));
        else button.setColor(Color(255 , 255 , 255)); //выделение цвета первой кнопки

        if (IntRect(250 , 700 , 105 , 20).contains(Mouse::getPosition(w))) understand.setColor(Color(139,69,0));
        else understand.setColor(Color(205,102,0));
        if (IntRect(283 , 723 , 54 , 20).contains(Mouse::getPosition(w))) basa.setColor(Color(139,69,0));
        else basa.setColor(Color(205,102,0));
        if (IntRect(278 ,746, 60, 20).contains(Mouse::getPosition(w))) graphic.setColor(Color(139,69,0));
        else graphic.setColor(Color(205,102,0));

        w.display();
    }
    return 0;
}
