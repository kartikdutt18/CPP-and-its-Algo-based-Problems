#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxGifts(vector<int> verses, int timeLimit)
{
    auto compare = [verses](int &a, int &b) {
        return verses[a] < verses[b];
    };
    priority_queue<int, vector<int>, decltype(compare)> pq(compare);
    int curTime = 0;
    int curVerseNo = 0;
    int totalVerses = verses.size();
    int popped = 0;
    int skippedVerse = -1;
    while (curVerseNo < totalVerses && popped <= 1 && curTime <= timeLimit)
    {
        curTime += verses[curVerseNo];
        pq.emplace(curVerseNo);
        if (curTime > timeLimit)
        {
            curTime -= verses[pq.top()];

            if (popped == 0)
                skippedVerse = pq.top() + 1;
            pq.pop();
            popped++;
        }
        curVerseNo++;
    }

    return skippedVerse == -1 ? 0 : skippedVerse;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int totalVerses, timeLimit;
        cin >> totalVerses >> timeLimit;
        vector<int> verses(totalVerses);
        for (int i = 0; i < totalVerses; i++)
        {
            cin >> verses[i];
        }
        cout << maxGifts(verses, timeLimit) << endl;
    }
}