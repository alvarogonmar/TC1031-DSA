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
        msg.sender = (i % 2 == 0 ? "Alice" : "Bob");
        msg.text = sampleTexts[i % sampleTexts.size()];
        msg.deleted = (i % 17 == 0); // cada 17 mensajes, se elimina uno
        history.push_back(msg);
    }
    return history;
}
void compactHistory(vector<Message> &chat)
{
    int j = 0;
    for (int i = 0; i < chat.size(); i++)
    {
        if (chat[i].deleted == false)
        {
            chat[j] = chat[i];
            j++;
        }
    }

    while (j < chat.size())
    {
        chat[j].deleted = true;
        chat[j].text = "[NULL]";
        j++;
    }
}

int main()
{
    vector<Message> chat = generateChatHistory(50);
