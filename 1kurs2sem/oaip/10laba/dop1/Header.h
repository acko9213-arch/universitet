#pragma once

struct Steak {
    int data;
    Steak* next;
};

void input(Steak*& head, int x);
void clear(Steak*& head);
void output(Steak*& head);
void formStack(Steak* head1, Steak* head2, Steak*& result);
void saveToFile(Steak* head);
void loadFromFile(Steak*& head);
