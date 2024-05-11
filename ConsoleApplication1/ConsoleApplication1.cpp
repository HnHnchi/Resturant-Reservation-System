#include <iostream>
#include <list>

using namespace std;

class PQob {
private:
    list<int> PQ;
public:
    bool isempty() {
        return PQ.empty();
    }

    int size() {
        return PQ.size();
    }

    void insert(int e) {
        PQ.push_back(e);
    }

    int min() {
        int min = PQ.front();
        for (auto it : PQ) {
            if (min > it) {
                min = it;
            }
        }
        return min;
    }

    void removel() {
        int e = min();
        PQ.remove(e);
    }

    void readytogo(PQob order) {
        while (!(order.isempty())) {
            cout << "Order number " << order.min() << " is ready" << endl;
            order.removel();
        }
    }
};

int main() {
    PQob order;
    int t = 1, j = 20, s = 30, s2 = 40;
    cout << "Hello! May we know how many of you will order? ";
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Pick your order: " << endl << "1) Drink" << endl << "2) Food" << endl;
        int n;
        cin >> n;
        if (n == 1) {
            cout << " 1) Tea" << endl << " 2) Juice" << endl;
            int m;
            cin >> m;
            if (m == 1) {
                cout << "Your tea will be ready in 5 minutes. Enjoy! :D" << endl;
                order.insert(t);
                cout << "Your order number is " << t << endl;
                t++;
            }
            if (m == 2) {
                cout << "Your juice will be ready in 10 minutes. Have fun!" << endl;
                order.insert(j);
                cout << "Your order number is " << j << endl;
                j++;
            }
        }
        if (n == 2) {
            cout << " 1) Sandwich" << endl << "2) Snacks" << endl;
            int q;
            cin >> q;
            if (q == 1) {
                cout << "Your sandwich will be ready in 15 minutes. Use this time to relax!" << endl;
                order.insert(s);
                cout << "Your order number is " << s << endl;
                s++;
            }
            if (q == 2) {
                cout << "Your snacks will come in 3 minutes! Very fast, right?" << endl;
                order.insert(s2);
                cout << "Your order number is " << s2 << endl;
                s2++;
            }
        }
    }
    order.readytogo(order);
    return 0;
}
