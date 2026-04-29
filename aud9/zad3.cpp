//
// Created by ema on 27.4.26.
//
#include<iostream>
#include<cstring>
using namespace std;

class QuizAttempt {
protected:
    char ID[7];

public:
    QuizAttempt(char *id) {
        strcpy(this->ID, id);
    }

    virtual void print() = 0;

    virtual double score() = 0;

    bool operator>=(QuizAttempt &attempt) {
        return this->score() >= attempt.score();
    }
};

class MCQuizAttempt : public QuizAttempt {
private:
    char correct[11];
    char answers[11];

public:
    MCQuizAttempt(char *id, char *correct, char *answers) : QuizAttempt(id) {
        strcpy(this->correct, correct);
        strcpy(this->answers, answers);
    }

    void print() override {
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". " << "Correct: " << correct[i] << " Answer: " << answers[i] << " Points: "
                    << (correct[i] == answers[i] ? 1 : -0.25) << endl;
        }
        cout << "Total score: " << score() << endl;
    }

    double score() override {
        double total = 0;
        for (int i = 0; i < 10; i++) {
            if (correct[i] == answers[i]) {
                total += 1;
            } else {
                total -= 0.25;
            }
        }
        return total;
    }
};

class TFQuizAttempt : public QuizAttempt {
private:
    bool correct[10];
    bool answers[10];

public:
    TFQuizAttempt(char *id, bool *correct, bool *answers) : QuizAttempt(id) {
        for (int i = 0; i < 10; i++) {
            this->correct[i] = correct[i];
            this->answers[i] = answers[i];
        }
    }

    void print() override {
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". " << "Correct: " << (correct[i] ? "True" : "False") << " Answer: "
                    << (answers[i] ? "Correct" : "False") << " Points: "
                    << (correct[i] == answers[i] ? 1 : -0.5) << endl;
        }
        cout << "Total score: " << score() << endl;
    }

    double score() override {
        double total = 0;
        for (int i = 0; i < 10; i++) {
            if (correct[i] == answers[i]) {
                total += 1;
            } else {
                total -= 0.5;
            }
        }
        return total;
    }
};

double averagePointsOfPassedStudents(QuizAttempt **attempts, int n) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (attempts[i]->score() >= 5.0) {
            sum += attempts[i]->score();
            count++;
        }
    }

    return sum / count;
}

QuizAttempt *readMCQuizAttempt() {
    char ID[7];
    char correct[11];
    char answers[11];

    cin >> ID >> correct >> answers;
    return new MCQuizAttempt(ID, correct, answers);
}

QuizAttempt *readTFQuizAttempt() {
    char ID[7];
    bool correct[10];
    bool answers[10];
    cin >> ID;
    for (int i = 0; i < 10; i++) {
        cin >> correct[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> answers[i];
    }

    return new TFQuizAttempt(ID, correct, answers);
}


int main() {
    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "Test MCQuizAttempt" << endl;
        QuizAttempt *attempt = readMCQuizAttempt();
        cout << "Score: " << attempt->score() << endl;
        attempt->print();
    } else if (testCase == 2) {
        cout << "Test TFQuizAttempt" << endl;
        QuizAttempt *attempt = readTFQuizAttempt();
        cout << "Score: " << attempt->score() << endl;
        attempt->print();
    } else if (testCase == 3) {
        cout << "Test operator >=" << endl;
        int n;
        cin >> n;
        QuizAttempt **attempts = new QuizAttempt *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                attempts[i] = readMCQuizAttempt();
            } else {
                attempts[i] = readTFQuizAttempt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if ((*attempts[i]) >= (*attempts[j])) {
                        cout << i << " >= " << j << endl;
                    } else {
                        cout << i << " < " << j << endl;
                    }
                }
            }
        }
    } else {
        int n;
        cin >> n;
        QuizAttempt **attempts = new QuizAttempt *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                attempts[i] = readMCQuizAttempt();
            } else {
                attempts[i] = readTFQuizAttempt();
            }
            attempts[i]->print();
            cout << endl;
        }

        cout << "Average score of passed students is: " << averagePointsOfPassedStudents(attempts, n) << endl;
    }

    return 0;
}
