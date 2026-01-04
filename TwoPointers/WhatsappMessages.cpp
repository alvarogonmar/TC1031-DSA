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
{
    vector<Message> history;
    history.reserve(n);

    vector<string> sampleTexts = {
        "Hola", "¿Cómo estás?", "Todo bien", "Ok", "Nos vemos",
        "¿Dónde estás?", "Manda ubicación", "Ya voy", "Adiós", "👍"};

    for (int i = 0; i < n; i++)
    {
        Message msg;
        msg.id = i + 1;
