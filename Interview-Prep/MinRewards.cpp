#include <vector>
using namespace std;

int minRewards(vector<int> scores)
{
  vector<int> reward(scores.size(), 1);
  for (int i = 1; i < scores.size(); i++)
  {
    if (scores[i] < scores[i - 1])
    {
      for (int j = i - 1; j >= 0 && scores[j] > scores[j + 1]; j--)
        reward[j] = max(reward[j + 1] + 1, reward[j]);
    }
    else
      reward[i] = reward[i - 1] + 1;
  }
  for (int rewards : reward)
    cout << rewards << " ";
  cout << endl;
  return accumulate(reward.begin(), reward.end(), 0);
}
