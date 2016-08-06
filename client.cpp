/*
Teddy Williams
*/
#include <vector>
#include <iostream>

using namespace std;


int solution(int K, vector<int> &C, vector<int> &D) {
    // wrote code in C++11 (g++ 4.8.2)
    //Keeping track of clean pairs.
    int cleanPairs = 0;
    //Keeping track of single clean pairs.
    vector<int> singleCleanSocks;
    //Keeping track of single dirty pairs.
    vector<int> singleDirtySocks;
    //Going through all of the clean socks.
    for(int i = 0; i < C.size(); i++)
    {
        //Going through all of the single clean socks to find pairs.
        for(int j = 0; j < singleCleanSocks.size(); j++)
        {
            /*If pair is found adds to the number of clean pairs,
            deletes the sock from single's list, and breaks from
            for loop.*/
            if(singleCleanSocks[j] == C[i])
            {
                cleanPairs++;
                singleCleanSocks.erase(singleCleanSocks.begin() + j);
                //Breaking by increasing j to for loop condition.
                j = j + singleCleanSocks.size();
            }
        }
        //If it has no pair it is added to the single clean socks' list.
        singleCleanSocks.push_back(C[i]);
    }
    //Keeping track of dirty socks that can be paired to clean ones.
    int dirtyCleanPairs = 0;
    //Going through all of the dirty socks.
    for(int k = 0; k < D.size(); k++)
    {
        //Going through all single clean socks to find matching dirty socks.
       for(int l = 0; l < singleCleanSocks.size(); l++)
       {
           /*If a dirty sock matches a clean single sock it adds to the number
           of matching dirty clean sock pairs, erases the single clean sock
           from the single clean sock list, and breaks from the for loop.*/
           if(D[k] == singleCleanSocks[l])
           {
               dirtyCleanPairs++;
               singleCleanSocks.erase(singleCleanSocks.begin() + l);
               //Breaking by increasing l to for loop condition.
               l = l + singleCleanSocks.size();
           }
       }
    }
    /*Now knowing the number matching dirty sock paris
    we can how many we could wash. Dividing by 2 to find
    out how many dirty socks can be washed.*/
    //Keeping track of the maximum number of socks that can be washed.
    int maxWash = 0;
    /*If the number of socks that need to be washed are less than the
    the number the washer can handle, the max amount that
    will be washed is the number of socks that needed to be washed.
    */
    if((dirtyCleanPairs/2) < K)
    {
        maxWash = dirtyCleanPairs/2;
    }
    else
    {
    /*If the number of socks that need to be washed are greater than the
    the number the washer can handle, the max amount that
    will be washed is the number of socks that the washer can handle.
    */
        maxWash = K;
    }
    return(maxWash+cleanPairs);
}

int main()
{
  vector<int> C;
  C.push_back(1);
  C.push_back(2);
  C.push_back(1);
  C.push_back(1);
  vector<int> D;
  D.push_back(1);
  D.push_back(4);
  D.push_back(3);
  D.push_back(2);
  D.push_back(4);
  cout << solution(2, C, D) << endl;
}
