#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Message
{
    int id;
    string sender;
    string text;
    bool deleted;
};

vector<Message> generateChatHistory(int n)
