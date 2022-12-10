//-----------------------------------------------------------
//Граф задан набором ориентированных дуг. Для каждой вершины 
//графа определить число заходящих в нее дуг.
//-----------------------------------------------------------

#include <iostream>//принята
#include <map>
#include <vector>

typedef std::map<int, int>::value_type value_type;

namespace std
{
    ostream& operator << (ostream& out, const value_type& r)
    {
        out << r.first << ": " << r.second << endl;
        return out;
    }
}

using namespace std;

struct KEdge
{
    int begin, end;
    
    friend istream& operator >> (istream& in, KEdge& edge)
    {
        in >> edge.begin >> edge.end;
        return in;
    }
};

int main()
{
    map<int, int> mSets;
    vector<KEdge> vEdges;
    cout << "Enter seq. Edges:\n";
    copy(istream_iterator<KEdge>(cin), istream_iterator<KEdge>(), back_inserter(vEdges));

    for(auto it = vEdges.begin(); it != vEdges.end(); it++){ if(!mSets[it->begin]){ mSets[it->begin] = 0;} mSets[it->end]++;}

    cout << "\nAmount of incoming edges:\n";
    copy(mSets.begin(), mSets.end(), ostream_iterator<value_type>(cout, "\n"));
}